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
#include "playlists.h"

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
        const std::string search(const std::string& musicName);


        void addPlaylist(const Playlists&);
        void createPlaylist(const std::string& playlistName);
        void addTrackToPlaylist(const std::string& id, const std::string& playlistName);


        const QString getAccessToken();
        const std::vector<Playlists> getPlaylists();

        void setAccessToken(const QString&);

        //const Track createTrackObject(const std::string& id, const QJsonObject& trackObject);

    private:
        const QJsonObject getTrack(const std::string& id);

    private:
        QString accessToken;
        std::vector<Playlists> playlists;
};

#endif // SPOTIFYAPP_H
