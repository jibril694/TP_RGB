#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_sliderD_actionTriggered(int value);

    void on_sliderG_actionTriggered(int value);

    void on_sliderC_actionTriggered(int value);

    void RGBAdjust() {

    }

    void RedAdjust(int value) {
        RGBAdjust();
    }

    void GreenAdjust(int value) {
        RGBAdjust();
    }

    void BlueAdjust(int value) {
        RGBAdjust();
    }

    void on_labelcolor_linkActivated(const QString &link);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
