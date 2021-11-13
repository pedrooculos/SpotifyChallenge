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
        Playlists();
        void addTrackToPlaylist(const QJsonObject&);
        void deletTrackFromPlaylist(const std::string&);

        const std::vector<QJsonObject> getPlaylist();

    private:
        std::vector<QJsonObject> playlist;
};

#endif // PLAYLISTS_H
