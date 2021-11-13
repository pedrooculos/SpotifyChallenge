#include <iostream>
#include "spotifyapp.h"

int main(int argc, char *argv[])
{
    SpotifyApp spotifyApp;

    spotifyApp.createPlaylist("Minha Play");
    spotifyApp.addTrackToPlaylist("6tfPsgvkgbGHWGwq2PpzCI","Minhaplay");

    std::vector<Playlists> playlists = spotifyApp.getPlaylists();

    std::cout << playlists[0].getName() << std::endl;

    QJsonObject track = playlists[0].getPlaylist()[0];


    std::cout << track["id"].toString().toStdString() << std::endl;

    return 0;
}
