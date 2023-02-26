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
#include "include/jsonhandler.h"
#include "include/playlists.h"

class SpotifyApp
{
    public:
        SpotifyApp();
        ~SpotifyApp();

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
        std::string search(const std::string& musicName);


        void createPlaylist(const std::string& playlistName);
        void addTrackToPlaylist(const std::string& id, const std::string& playlistName);
        void deleteTrackFromPlaylist(const std::string& trackName, const std::string& playlistName);

        std::string printPlaylist(const std::string& playlistName);

        QString getAccessToken();
        std::vector<Playlists> getPlaylists();

        void setAccessToken(const QString&);

    private:
        QJsonObject getTrack(const std::string& id);
        void addPlaylist(const Playlists& playlist);
        void takePlaylistsFromJsonArray(const QJsonArray& playlistsJsonArray);

        QJsonArray playlistToJsonArray();
        void savePlaylistsInFile(const QJsonArray& playlistsJsonArray,const std::string& fileName);

    private:
        QString accessToken;
        std::vector<Playlists> playlists;
};

#endif // SPOTIFYAPP_H
