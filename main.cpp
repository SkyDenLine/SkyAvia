#include "listofflight.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ListOfFlight w;
    w.show();

    return a.exec();
}
