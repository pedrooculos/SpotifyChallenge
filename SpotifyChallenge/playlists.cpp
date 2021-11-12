#include "playlists.h"

Playlists::Playlists()
{

}

void Playlists::addTrackToPlaylist(const std::string& trackId)
{
    playlist.push_back(trackId);
}


const std::vector<std::string> Playlists::getPlaylist()
{
    return this->playlist;
}

