#include "playlists.h"

Playlists::Playlists(std::string playlistName)
{
    this->playlistName = playlistName;
}

void Playlists::addTrackToPlaylist(const QJsonObject& track)
{
    playlist.push_back(track);
}

void Playlists::deleteTrackFromPlaylist(const std::string& trackNameToDelete)
{
    int positionToDelete;
    bool trackFounded = false;
    for(int i = 0; i < playlist.size(); i++)
    {
        std::string trackName = playlist.at(i).toObject()["name"].toString().toStdString();
        if (trackNameToDelete.compare(trackName) == 0)
        {
            positionToDelete = i;
            trackFounded = true;
            break;
        }
    }
    if(trackFounded)
        playlist.erase(playlist.begin() + positionToDelete);
}

const std::string Playlists::printPlaylist()
{
    std::string strToPrint;
    for(int j = 0; j < this->playlist.size(); j++)
    {
        QJsonObject track = this->playlist[j].toObject();
        strToPrint += "Music: " + track["name"].toString().toStdString()+ "\n";
    }

    return strToPrint;
}


const QJsonArray Playlists::getPlaylist()
{
    return this->playlist;
}

const std::string Playlists::getName()
{
    return this->playlistName;
}


