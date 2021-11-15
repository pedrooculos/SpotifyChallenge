#include "spotifyapp.h"
#include "curlhandler.h"


static std::string getStringFromFile(std::string path)
{
    std::ifstream input_file(path);
    if (!input_file.is_open()) {
        std::cerr << "Could not open the file - '"
             << path << "'" << std::endl;
        exit(EXIT_FAILURE);
    }
    return std::string((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>());
}


SpotifyApp::SpotifyApp()
{
    SpotifyApp::authentication();
}

void SpotifyApp::authentication()
{
    CurlHandler curl;

    std::string clientId = getStringFromFile("D:\\QtProject\\SpotifyChallenge\\SpotifyChallenge\\Credentials\\client_id.txt");
    std::string clientSecret = getStringFromFile("D:\\QtProject\\SpotifyChallenge\\SpotifyChallenge\\Credentials\\client_secret.txt");
    std::string postData = "grant_type=client_credentials&client_id=" + clientId + "&client_secret="+clientSecret;
    std::string postUrl = "https://accounts.spotify.com/api/token";

    std::string responseStdString = curl.postOperation(postUrl,postData);

    QJsonObject responseJsonObject = strToQjsonObj(responseStdString);

    QString accessToken = responseJsonObject["access_token"].toString();

    setAccessToken(accessToken);
}

const std::string SpotifyApp::search(const std::string& searchInput)
{
    CurlHandler curl;

    std::string searchString = "https://api.spotify.com/v1/search";
    searchString += "?q=" + searchInput;
    searchString += "&type=track";
    searchString += "&market=ES";
    searchString += "&limit=3";
    searchString += "&offset=0";

    std::string authenticationStr ="Authorization: Bearer " + getAccessToken().toStdString();
    std::string responseStdString = curl.getOperation(searchString,authenticationStr);

    return responseStdString;
}

const QJsonObject SpotifyApp::getTrack(const std::string& trackId)
{
    CurlHandler curl;
    std::string trackUrl = "https://api.spotify.com/v1/tracks/";
    trackUrl += trackId;

    std::string authenticationStr ="Authorization: Bearer " + getAccessToken().toStdString();
    std::string responseStdString = curl.getOperation(trackUrl,authenticationStr);

    QJsonObject trackObject = strToQjsonObj(responseStdString);

    return trackObject;
}

void SpotifyApp::addPlaylist(const Playlists& playlist)
{
    this->playlists.push_back(playlist);
}

void SpotifyApp::createPlaylist(const std::string &playlistName)
{
    Playlists playlist(playlistName);
    this->addPlaylist(playlist);
}

/*
const Track SpotifyApp::createTrackObject(const std::string& trackId, const QJsonObject& trackObject)
{
    Track track(trackId,trackObject);
    return track;
}*/

void SpotifyApp::addTrackToPlaylist(const std::string &id, const std::string &playlistName)
{
    QJsonObject trackJson = getTrack(id);
    bool playlistFound = false;
    for(int i=0; i < playlists.size(); i++)
    {
        if(playlists[i].getName().compare(playlistName) == 0)
        {
            this->playlists[i].addTrackToPlaylist(trackJson);
            playlistFound = true;
            break;
        }
    }
    if(playlistFound == false)
    {
        this->createPlaylist(playlistName);
        this->playlists[playlists.size() -1].addTrackToPlaylist(trackJson);
    }

}

const std::vector<Playlists> SpotifyApp::getPlaylists()
{
    return this->playlists;
}


const QString SpotifyApp::getAccessToken()
{
    return this->accessToken;
}

void SpotifyApp::setAccessToken(const QString& accessToken)
{
    this->accessToken = accessToken;
}


