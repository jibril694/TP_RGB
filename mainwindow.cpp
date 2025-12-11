#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{    /* pour le slider rouge */
    ui->sliderD->setStyleSheet("QSlider::handle:vertical {background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop:1 red);border: 1px solid #999999;border-radius: 5px;}");
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_sliderD_actionTriggered(int action)
{

}

