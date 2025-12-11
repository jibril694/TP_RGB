#include "ihmdanger.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    IhmDanger w;
    w.show();
    return a.exec();
}
