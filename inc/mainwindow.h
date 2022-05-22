#pragma once

#include <QMainWindow>


#include "processingmethods.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    ProcessingMethods process;


private:
    Ui::MainWindow *ui;
};
