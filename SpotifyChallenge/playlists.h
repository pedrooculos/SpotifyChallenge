#ifndef PLAYLISTS_H
#define PLAYLISTS_H

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

class Playlists
{
    public:
        Playlists();
        void addTrackToPlaylist(const std::string&);
        void deletTrackFromPlaylist(const std::string&);

        const std::vector<std::string> getPlaylist();

    private:
        std::vector<std::string> playlist;
};

#endif // PLAYLISTS_H
