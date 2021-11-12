#include <iostream>
#include "playlists.h"


int main(int argc, char *argv[])
{
    Playlists playlistTest;

    playlistTest.addTrackToPlaylist("7pwF2SFF9LUeqD0f5wWrSR");

    std::cout << playlistTest.getPlaylist()[0] << std::endl;

    playlistTest.addTrackToPlaylist("7pwF2SFFrglnqrnggqgr");

    playlistTest.deletTrackFromPlaylist("7pwF2SFF9LUeqD0f5wWrSR");

    std::cout << "new: " + playlistTest.getPlaylist()[0] << std::endl;

    return 0;
}
