#include "ihmdanger.h"
#include "ui_ihmdanger.h"
#include<QMessageBox>
#include<QThread>

IhmDanger::IhmDanger(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::IhmDanger)
{
    ui->setupUi(this);
    // instanciation du port
    portserie=new QSerialPort(this);


    ui->labelInfoCom->setText("Non connecté");
    ui->lineEdit7seg->setValidator(new QIntValidator(0,99,ui->lineEdit7seg));
}

IhmDanger::~IhmDanger()
{
    delete portserie;
    delete ui;
}


void IhmDanger::on_QPushButtonConnexion_clicked()
{

    // paramètres de la communication
    portserie->setBaudRate(QSerialPort::Baud9600);
    portserie->setDataBits(QSerialPort::Data8);
    portserie->setParity(QSerialPort::NoParity);
    portserie->setStopBits(QSerialPort::OneStop);
    portserie->setFlowControl(QSerialPort::NoFlowControl);
    // sélection du numéro du port
    QString nomport= "COM"+QString::number(ui->spinBoxNumCom->value());
    portserie->setPortName(nomport);
    if (portserie->open(QIODevice::ReadWrite))
     {

        QMessageBox::information(this, "IHM série","connexion OK sur "+QString(nomport));
        //portserie->write("Communications etablies\n");
        ui->labelInfoCom->setText("Connecté "+QString(nomport));
        ui->labelInfoCom->setStyleSheet("background-color:#00aa00");
        connect(portserie,SIGNAL(readyRead()),this,SLOT(reception()));//
     }
    else
    {
        // probleme d'ouverture du port serie
         QMessageBox::critical(this, "IHM Danger    ", portserie->errorString());
    }
}

void IhmDanger::on_QPushButtonDeconnexion_clicked()
{
    if (portserie->isOpen())
     {
        portserie->close();
        QMessageBox::information(this,"IHM série","Déconnexion");
        ui->labelInfoCom->setText("Non connecté");
        ui->labelInfoCom->setStyleSheet("background-color:");
     }
}

void IhmDanger::on_PushButtonLed1_clicked()
{
    QString commande="$;led1;xxxx;xxxxx;xx;\n";
    portserie->write(commande.toLocal8Bit());
}

void IhmDanger::on_PushButtonLed2_clicked()
{
    QString commande="$;xxxx;led2;xxxxx;xx;\n";
    portserie->write(commande.toLatin1());
}

void IhmDanger::on_PushButtonAfficher_clicked()
{
    QString commande="$;XXXX;XXXX;segON;"+ui->lineEdit7seg->text()+";\n";
    portserie->write(commande.toLocal8Bit());
}

void IhmDanger::on_PushButtonEteindre_clicked()
{
    QString commande="$;XXXX;XXXX;segOF;XX;\n";
    portserie->write(commande.toLocal8Bit());
}

void IhmDanger::reception()
{
    //nb d'octets reçus
    ui->lineEdit->setText(QString::number(portserie->bytesAvailable()));
    QByteArray data = portserie->readAll();
    //nb octets lus
    ui->lineEdit_2->setText(QString::number(data.length()));
    static QByteArray octetsTrame;//trame stockée
    octetsTrame+=data;
    int nbByte = octetsTrame.length();
    ui->lineEdit_4->setText(QString::number(nbByte));
    // recherche position fin de trame
    int fintrame=octetsTrame.indexOf('\n');
    QByteArray trame=octetsTrame.left(fintrame+1);
    if (trame.startsWith('#')&&trame.endsWith('\n'))
        {
            trame=trame.mid(1,trame.length()-2);//retire les caractères debut et fin de trame
            ui->lineEdit_5->setText(trame);
            ui->lineEdit_3->setText(QString::number(trame.length()));
            QStringList fields = QString(trame).split(';'); // Split fields by semicolon
            if (fields.size() >= 5)
            {
                QString field0 = fields[0];
                QString field1 = fields[1];
                QString field2 = fields[2];
                QString field3 = fields[3];
                QString field4 = fields[4];
                QString field5 = fields[5];
                // Do something with the extracted fields
                // For example, display them in the text edit widget
                QString message = QString("slider1: %1\nslider2: %2\nslider3: %3\ntempérature: %4\nluminosité: %5")
                                .arg(field1)
                                .arg(field2)
                                .arg(field3)
                                .arg(field4)
                                .arg(field5);
                ui->TextEditafficheur->appendPlainText(message);
            }
        }
        octetsTrame.remove(0,fintrame+1);
}
