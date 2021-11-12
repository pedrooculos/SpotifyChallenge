#include <iostream>
#include "spotifyapp.h"

int main(int argc, char *argv[])
{
    SpotifyApp spotifyApp;

    std::cout << spotifyApp.getAccessToken().toStdString() << std::endl;

    return 0;
}
