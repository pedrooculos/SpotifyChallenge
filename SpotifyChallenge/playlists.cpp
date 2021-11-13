#include "playlists.h"

Playlists::Playlists(std::string playlistName)
{
    this->playlistName = playlistName;
}

void Playlists::addTrackToPlaylist(const QJsonObject& track)
{
    playlist.push_back(track);
}

void Playlists::deletTrackFromPlaylist(const std::string& trackIdToDelete)
{
    int positionToDelet;

    for(int i = 0; i < playlist.size(); i++)
    {
        std::string trackId = playlist.at(i).toObject()["id"].toString().toStdString();
        if (trackIdToDelete.compare(trackId) == 0)
        {
            positionToDelet = i;
            break;
        }
    }
    playlist.erase(playlist.begin() + positionToDelet);
}


const QJsonArray Playlists::getPlaylist()
{
    return this->playlist;
}

const std::string Playlists::getName()
{
    return this->playlistName;
}


