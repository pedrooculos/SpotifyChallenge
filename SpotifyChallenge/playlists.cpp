#include "playlists.h"

Playlists::Playlists()
{

}

void Playlists::addTrackToPlaylist(const std::string& trackId)
{
    playlist.push_back(trackId);
}

void Playlists::deletTrackFromPlaylist(const std::string& trackId)
{
    std::vector<std::string>::iterator positionToDelet;

    positionToDelet = std::find(this->playlist.begin(), this->playlist.end(),trackId);

    playlist.erase(positionToDelet);
}


const std::vector<std::string> Playlists::getPlaylist()
{
    return this->playlist;
}


