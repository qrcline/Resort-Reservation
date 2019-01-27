#include "reservation.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Reservation w;
    w.show();

    return a.exec();
}
