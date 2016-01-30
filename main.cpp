#include "ddscalc.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DDSCalc w;
    w.show();

    return a.exec();
}
