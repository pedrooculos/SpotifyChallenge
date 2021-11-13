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

        void deletTrackFromPlaylist(const std::string& trackName);

        const QJsonArray getPlaylist();
        const std::string getName();

    private:
        std::string playlistName;
        QJsonArray playlist;
};

#endif // PLAYLISTS_H
