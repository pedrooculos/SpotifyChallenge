#ifndef PLAYLISTS_H
#define PLAYLISTS_H

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <QJsonObject>
#include <QJsonArray>

class Playlists
{
    public:
        Playlists(std::string Name);

        void addTrackToPlaylist(const QJsonObject& trackObject);

        void deleteTrackFromPlaylist(const std::string& trackName);

        std::string printPlaylist();

        QJsonArray getPlaylist();
        void setPlaylist(const QJsonArray& playlistJsonArray);

        std::string getName();

        QJsonObject playlistToJsonObject();

    private:
        std::string playlistName;
        QJsonArray playlist;
};

#endif // PLAYLISTS_H
