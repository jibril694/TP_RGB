/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QSlider *sliderD;
    QSpinBox *spinBoxG;
    QSpinBox *spinBoxD;
    QSpinBox *spinBoxC;
    QLabel *labelcolor;
    QSlider *sliderC;
    QSlider *sliderG;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(294, 366);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(10, 0, 271, 321));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        sliderD = new QSlider(horizontalLayoutWidget);
        sliderD->setObjectName("sliderD");
        sliderD->setMaximum(255);
        sliderD->setOrientation(Qt::Orientation::Vertical);

        gridLayout->addWidget(sliderD, 1, 2, 1, 1);

        spinBoxG = new QSpinBox(horizontalLayoutWidget);
        spinBoxG->setObjectName("spinBoxG");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(spinBoxG->sizePolicy().hasHeightForWidth());
        spinBoxG->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(14);
        spinBoxG->setFont(font);
        spinBoxG->setMaximum(255);

        gridLayout->addWidget(spinBoxG, 3, 0, 1, 1);

        spinBoxD = new QSpinBox(horizontalLayoutWidget);
        spinBoxD->setObjectName("spinBoxD");
        sizePolicy.setHeightForWidth(spinBoxD->sizePolicy().hasHeightForWidth());
        spinBoxD->setSizePolicy(sizePolicy);
        spinBoxD->setFont(font);
        spinBoxD->setMaximum(255);

        gridLayout->addWidget(spinBoxD, 3, 2, 1, 1);

        spinBoxC = new QSpinBox(horizontalLayoutWidget);
        spinBoxC->setObjectName("spinBoxC");
        sizePolicy.setHeightForWidth(spinBoxC->sizePolicy().hasHeightForWidth());
        spinBoxC->setSizePolicy(sizePolicy);
        spinBoxC->setFont(font);
        spinBoxC->setMaximum(255);

        gridLayout->addWidget(spinBoxC, 3, 1, 1, 1);

        labelcolor = new QLabel(horizontalLayoutWidget);
        labelcolor->setObjectName("labelcolor");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setPointSize(18);
        font1.setBold(true);
        labelcolor->setFont(font1);
        labelcolor->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(labelcolor, 4, 0, 1, 3);

        sliderC = new QSlider(horizontalLayoutWidget);
        sliderC->setObjectName("sliderC");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(sliderC->sizePolicy().hasHeightForWidth());
        sliderC->setSizePolicy(sizePolicy1);
        sliderC->setMaximum(255);
        sliderC->setOrientation(Qt::Orientation::Vertical);

        gridLayout->addWidget(sliderC, 1, 1, 1, 1);

        sliderG = new QSlider(horizontalLayoutWidget);
        sliderG->setObjectName("sliderG");
        sliderG->setEnabled(true);
        sizePolicy1.setHeightForWidth(sliderG->sizePolicy().hasHeightForWidth());
        sliderG->setSizePolicy(sizePolicy1);
        sliderG->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        sliderG->setStyleSheet(QString::fromUtf8("/* pour le slider rouge */\n"
"sliderD->setStyleSheet(\"QSlider::handle:vertical {background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop:1 red);border: 1px solid #999999;border-radius: 5px;}\")"));
        sliderG->setMaximum(255);
        sliderG->setOrientation(Qt::Orientation::Vertical);
        sliderG->setTickPosition(QSlider::TickPosition::NoTicks);

        gridLayout->addWidget(sliderG, 1, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 294, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(sliderD, &QSlider::valueChanged, spinBoxD, &QSpinBox::setValue);
        QObject::connect(spinBoxD, &QSpinBox::valueChanged, sliderD, &QSlider::setValue);
        QObject::connect(sliderG, &QSlider::valueChanged, spinBoxG, &QSpinBox::setValue);
        QObject::connect(spinBoxG, &QSpinBox::valueChanged, sliderG, &QSlider::setValue);
        QObject::connect(spinBoxC, &QSpinBox::valueChanged, sliderC, &QSlider::setValue);
        QObject::connect(sliderC, &QSlider::valueChanged, spinBoxC, &QSpinBox::setValue);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        labelcolor->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
