#ifndef SPOTIFYPLAYER_H
#define SPOTIFYPLAYER_H

#include <string>
#include <curl/curl.h>
#include <QJsonObject>
#include <QJsonDocument>
#include <QString>
#include <iostream>

class SpotifyPlayer
{
public:
    SpotifyPlayer();
    void startPlayback(const QString);

private:
    const std::string baseUrl = "https://api.spotify.com/v1/me/player";
};

#endif // SPOTIFYPLAYER_H
