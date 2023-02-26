#include "include/myspotify.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MySpotify mySpotify;
    mySpotify.show();
    return a.exec();
}
