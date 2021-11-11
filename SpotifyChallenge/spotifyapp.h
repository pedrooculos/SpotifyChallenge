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
        void authentication();
        void search();

        void setAccessToken(const QString&);
        const QString getAccessToken();

    private:
        QString accessToken;
};

#endif // SPOTIFYAPP_H
