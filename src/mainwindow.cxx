#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QFileDialog>
#include <QHBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QLabel>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    auto name = QFileDialog::getOpenFileName(nullptr, "OpenFile",
                                                 "/Users/kirill/Desktop/"
                                             );
//    QString name = QString("/Users/kirill/Desktop/Снимок экрана 2022-02-05 в 16.24.05.png");
    QImage image = QImage(name);
    image = image.convertToFormat(QImage::Format_RGB32);

    auto negativeImage = QPixmap::fromImage(process.negative(image));
    auto degreeImage = QPixmap::fromImage(process.degrees(image, 1));
    auto logarithmicImage = QPixmap::fromImage(process.logarithmic(image, 44));
    auto image2 = logarithmicImage.toImage();
    auto eqalizationImage = QPixmap::fromImage(process.eqalization(image2, 8));

    QImage channel_r;
    QImage channel_g;
    QImage channel_b;

    process.channels(image, channel_r, channel_g, channel_b);

//    auto linFilterImage = process.linear(image);
//    auto imagePix = QPixmap::fromImage(linilterImage);

    show();

    ui->label->resize(this->size());
    ui->label_2->resize(this->size());
    ui->label_3->resize(this->size());
    ui->label_4->resize(this->size());
    ui->label_5->resize(this->size());
    ui->label_6->resize(this->size());
    ui->label_7->resize(this->size());

    ui->label->setText("ImageLabel");
    ui->label->setPixmap(degreeImage);
    ui->label_2->setPixmap(logarithmicImage);
    ui->label_3->setPixmap(eqalizationImage);
    ui->label_4->setPixmap(negativeImage);
    ui->label_5->setPixmap(QPixmap::fromImage(channel_r));
    ui->label_6->setPixmap(QPixmap::fromImage(channel_g));
    ui->label_7->setPixmap(QPixmap::fromImage(channel_b));









}

MainWindow::~MainWindow()
{
    delete ui;
}

