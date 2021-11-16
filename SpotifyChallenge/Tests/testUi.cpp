#include <iostream>
#include <QApplication>
#include "include/myspotify.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MySpotify mySpotify;
    mySpotify.show();
    return a.exec();
    return 0;
}
