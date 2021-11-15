#include <iostream>
#include <QString>
#include <QJsonObject>
#include "playlists.h"


QJsonObject createObject(std::string name)
{
    QJsonObject trackTest;

    trackTest.insert("name", name.c_str());
    return trackTest;
};


int main(int argc, char *argv[])
{
    Playlists playlist("Minha Play");

    QJsonObject track = createObject("test1");

    playlist.addTrackToPlaylist(track);

    std::cout << playlist.printPlaylist() << std::endl;

    QJsonObject track2 = createObject("test2");

    playlist.addTrackToPlaylist(track2);

    std::cout << playlist.printPlaylist() << std::endl;

    playlist.deleteTrackFromPlaylist("test1");

    std::cout << playlist.printPlaylist() << std::endl;


    return 0;
}
