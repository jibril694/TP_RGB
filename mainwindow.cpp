#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSlider>
#include <QSpinBox>
#include <QWidget>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{    /* pour le slider rouge */
    //ui->sliderD->setStyleSheet("QSlider::handle:vertical {background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop:1 red);border: 1px solid #999999;border-radius: 5px;}");

    ui->setupUi(this);

    QWidget *centralWidget = new QWidget;
    setCentralWidget(centralWidget);

    setWindowTitle("RGB viewer v1");
    setFixedSize(210,480);

}

MainWindow::~MainWindow()
{
    delete ui;

}



void MainWindow::on_sliderD_actionTriggered(int value)
{
    connect(ui->sliderD, SIGNAL(valueChanged(int)), ui->spinBoxD, SLOT(setValue(int)));
    connect(ui->spinBoxD, SIGNAL(valueChanged(int)), ui->sliderD, SLOT(setValue(int)));
    connect(ui->sliderD, SIGNAL(valueChanged(int)), this, SLOT(RedAdjust(int)));
}


void MainWindow::on_sliderC_actionTriggered(int value)
{
    connect(ui->sliderC, SIGNAL(valueChanged(int)), ui->spinBoxC, SLOT(setValue(int)));
    connect(ui->spinBoxC, SIGNAL(valueChanged(int)), ui->sliderC, SLOT(setValue(int)));
    connect(ui->sliderC, SIGNAL(valueChanged(int)), this, SLOT(GreenAdjust(int)));
}


void MainWindow::on_sliderG_actionTriggered(int value)
{
    connect(ui->sliderG, SIGNAL(valueChanged(int)), ui->spinBoxG, SLOT(setValue(int)));
    connect(ui->spinBoxG, SIGNAL(valueChanged(int)), ui->sliderG, SLOT(setValue(int)));
    connect(ui->sliderG, SIGNAL(valueChanged(int)), this, SLOT(BlueAdjust(int)));
}





void MainWindow::on_labelcolor_linkActivated(const QString &link)
{
    QColor color(ui->sliderG->value(), ui->sliderC->value(), ui->sliderD->value());
    QPalette palette;
    ui->labelcolor->setAutoFillBackground(true);
    palette.setColor(QPalette::Window, color);
    ui->labelcolor->setPalette(palette);
    ui->labelcolor->setText("#" + color.name().toUpper());
}

