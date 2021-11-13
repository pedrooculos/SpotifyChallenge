#ifndef PLAYLISTS_H
#define PLAYLISTS_H

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <QJsonObject>

class Playlists
{
    public:
        Playlists(std::string Name);

        void addTrackToPlaylist(const QJsonObject& trackObject);

        void deletTrackFromPlaylist(const std::string& trackName);

        const std::vector<QJsonObject> getPlaylist();
        const std::string getName();

    private:
        std::string playlistName;
        std::vector<QJsonObject> playlist;
};

#endif // PLAYLISTS_H
