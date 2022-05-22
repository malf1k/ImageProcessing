#include "processingmethods.h"
#include <QDebug>
#include <QPixmap>
#include "math.h"
//#include <QPixmap>

ProcessingMethods::ProcessingMethods()
{
    qDebug() << __FUNCTION__;

}

void ProcessingMethods::getImageParametrs(const QImage& image)
{
    width = image.width();
    height = image.height();
    bytesPerLine = image.bytesPerLine();
    format = image.format();
}

QImage ProcessingMethods::linear(QImage &image)
{
    qDebug() << __FUNCTION__;

    getImageParametrs(image);

    uchar* data = image.bits();
    size = width * height * bytesPerLine/width;
    qDebug() << data << size;

    uchar* outdata = new uchar[size];

    for (auto i = 0; i < size; i++)
    {
        auto pixel = data[i];
        outdata[i] = 255 - pixel;
    }

    QImage outImage(outdata, width, height, format);


    return outImage;
}

QImage ProcessingMethods::eqalization(QImage &image, int k)
{
    qDebug() << __FUNCTION__;

    getImageParametrs(image);
    auto L = pow(2, k);
    uchar* data = image.bits();
    size = width * height * bytesPerLine/width;
    qDebug() << data << size;

    uchar* outdata = new uchar[size];

    for (auto i = 0; i < size; i++)
    {
        auto pixel = data[i];
        outdata[i] = pow(pixel, 2)/(L -1);
    }

    QImage outImage(outdata, width, height, format);

    return outImage;

}

QImage ProcessingMethods::degrees(QImage &image, double degree)
{
    qDebug() << __FUNCTION__;
    if(degree < 0.01)
        degree = 0.01;
    if(degree > 25.0)
        degree = 25.0;

    getImageParametrs(image);

    uchar* data = image.bits();
    size = width * height * bytesPerLine/width;
    qDebug() << data << size;

    uchar* outdata = new uchar[size];

    for (auto i = 0; i < size; i++)
    {
        auto pixel = data[i];
        outdata[i] = pow(pixel, degree);
    }

    QImage outImage(outdata, width, height, format);

    return outImage;
}

QImage ProcessingMethods::logarithmic(QImage &image, int constant)
{
    getImageParametrs(image);

    uchar* data = image.bits();
    size = width * height * bytesPerLine/width;
    qDebug() << data << size;

    uchar* outdata = new uchar[size];

    for (auto i = 0; i < size; i++)
    {
        auto pixel = data[i];
        outdata[i] = constant * log(1+ pixel);
    }

    QImage outImage(outdata, width, height, format);

    return outImage;
}

QImage ProcessingMethods::negative(QImage &image)
{
    qDebug() << __FUNCTION__;

    getImageParametrs(image);

    uchar* data = image.bits();
    size = width * height * bytesPerLine/width;
    qDebug() << data << size;

    uchar* outdata = new uchar[size];

    for (auto i = 0; i < size; i += 3)
    {
        auto pixel_r = data[i + 0];
        auto pixel_g = data[i + 1];
        auto pixel_b = data[i + 2];

        outdata[i + 0] = 255 - pixel_r;
        outdata[i + 1] = 255 - pixel_g;
        outdata[i + 2] = 255 - pixel_b;
    }

    QImage outImage(outdata, width, height, format);
    return outImage;
}

void ProcessingMethods::channels(QImage &image, QImage &rChannel, QImage &gChannel, QImage &bChannel)
{
    getImageParametrs(image);

    uchar* data = image.bits();
    size = width * height * bytesPerLine/width;
    qDebug() << data << size;

    uchar* outdata_r = new uchar[size];
    uchar* outdata_g = new uchar[size];
    uchar* outdata_b = new uchar[size];
    for (auto i = 0; i < size; i += 3)
    {
        auto pixel_r = data[i + 0];
        auto pixel_g = data[i + 1];
        auto pixel_b = data[i + 2];

        outdata_r[i + 0] = pixel_r;
        outdata_r[i + 1] = pixel_r;
        outdata_r[i + 2] = pixel_r;

        outdata_g[i + 0] = pixel_g;
        outdata_g[i + 1] = pixel_g;
        outdata_g[i + 2] = pixel_g;

        outdata_b[i +0] = pixel_b;
        outdata_b[i +1] = pixel_b;
        outdata_b[i +2] = pixel_b;
    }

    rChannel = QImage(outdata_r, width, height, format);
    gChannel = QImage(outdata_g, width, height, format);
    bChannel = QImage(outdata_b, width, height, format);
}
