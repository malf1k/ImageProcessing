#pragma once
#include <QImage>

class ProcessingMethods
{
public:
    ProcessingMethods();

    QImage linear(QImage& image);
    QImage nonLinear(QImage& image);
    QImage eqalization(QImage& image, int k = 8);
    QImage degrees(QImage& image, double degree = 0.5);
    QImage logarithmic(QImage& image, int constant = 20);
    QImage negative(QImage& image);
    void channels(QImage& inImage,
                  QImage& rChannel,
                  QImage& gChannel,
                  QImage& bChannel);
    void negativeChannels(QImage& inImage,
                          QImage& inversRChannel,
                          QImage& inversGChannel,
                          QImage& inversBChannel);

    QImage grayScale(QImage& inImage);

    void getImageParametrs(const QImage& image);

private:
    uint width = 0;
    uint height = 0;
    qsizetype bytesPerLine;
    QImage::Format format;
    uint size = 0;

};

/*
Разработать приложение для линейной фильтрации изображений (3х3, 5х5)
Разработать приложение для нелинейной фильтрации изображений (3х3, 5х5)
Разработать приложение для улучшения изображения путем эквализации;
Разработать приложение для степенного преобразования (гамма коррекция);
Разработать приложения для логарифмического преобразования изображения;
Разработать приложение для преобразования изображения в негатив;
Разработать приложение для получения и инвертирования цветовых каналов (R,G,B) изображений (замена цветовых каналов: R→G,G→B,B→R);
Разработать приложение для получения и отображения цветовых каналов (R,G,B) изображений;
Разработать приложение преобразования цветного изображения в черно-белое (градации серого);
*/
