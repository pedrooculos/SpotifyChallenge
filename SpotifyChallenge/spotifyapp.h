#ifndef SPOTIFYAPP_H
#define SPOTIFYAPP_H

#include <curl/curl.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <QJsonObject>
#include <QString>
#include <algorithm>
#include "jsonhandler.h"

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
        const std::string search(const std::string&);

        void setAccessToken(const QString&);
        const QString getAccessToken();

    private:
        QString accessToken;
};

#endif // SPOTIFYAPP_H
