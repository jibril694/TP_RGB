#ifndef IHMDANGER_H
#define IHMDANGER_H

#include <QWidget>
#include<QSerialPort>

QT_BEGIN_NAMESPACE
namespace Ui { class IhmDanger; }
QT_END_NAMESPACE

class IhmDanger : public QWidget
{
    Q_OBJECT

public:
    IhmDanger(QWidget *parent = nullptr);
    ~IhmDanger();

private slots:
    void on_QPushButtonConnexion_clicked();
    void on_QPushButtonDeconnexion_clicked();
    void on_PushButtonLed1_clicked();
    void on_PushButtonLed2_clicked();
    void on_PushButtonAfficher_clicked();
    void on_PushButtonEteindre_clicked();
    void reception();


private:
    Ui::IhmDanger *ui;
    QSerialPort *portserie;
};
#endif // IHMDANGER_H
