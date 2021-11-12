#ifndef SPOTIFYAPP_H
#define SPOTIFYAPP_H

#include <curl/curl.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <QJsonObject>
#include <QJsonDocument>
#include <QString>

class SpotifyApp
{
    public:
        SpotifyApp();

        /* Function:
            Authenticate the user for spotify's API
            - take the access token for 1 hour
        */
        void authentication();

        /* Function:
            Search a track using the name
           Return:
            Return Spotify's response
        */
        const std::string search();

        void setAccessToken(const QString&);
        const QString getAccessToken();

    private:
        QString accessToken;
};

#endif // SPOTIFYAPP_H
