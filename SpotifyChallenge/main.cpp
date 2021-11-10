#include "myspotify.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MySpotify w;
    w.show();
    return a.exec();
}
