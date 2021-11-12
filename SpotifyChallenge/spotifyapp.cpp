#include "spotifyapp.h"
#include "curlhandler.h"

/*struct memory
{
    char* response;
    size_t size;
};

size_t callbackFunction(void* data,size_t size, size_t nmemb, void* userp)
{
    size_t realsize = size * nmemb;
    struct memory *mem = (struct memory *)userp;

    char *ptr = (char*)realloc(mem->response, mem->size + realsize + 1);
    if(ptr == NULL)
        return 0;  /* out of memory! */

/*    mem->response = ptr;
    memcpy(&(mem->response[mem->size]), data, realsize);
    mem->size += realsize;
    mem->response[mem->size] = 0;

    return realsize;
}*/



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

    QString responseQStr;
    responseQStr = responseQStr.fromStdString(responseStdString);
    QJsonDocument responseJsonDocument =  QJsonDocument::fromJson(responseQStr.toUtf8());
    QJsonObject responseJsonObject = responseJsonDocument.object();
    QString accessToken = responseJsonObject["access_token"].toString();

    setAccessToken(accessToken);
}

void SpotifyApp::search()
{
    CurlHandler curl;

    std::string searchString = "https://api.spotify.com/v1/search";
    searchString += "?q=Ramsey-Goodbye";
    searchString += "&type=track";
    searchString += "&market=ES";
    searchString += "&limit=1";
    searchString += "&offset=0";

    std::string authenticationStr ="Authorization: Bearer " + getAccessToken().toStdString();

    std::string responseStdString = curl.getOperation(searchString,authenticationStr);

    std::cout << responseStdString << std::endl;
}

const QString SpotifyApp::getAccessToken()
{
    return this->accessToken;
}

void SpotifyApp::setAccessToken(const QString& accessToken)
{
    this->accessToken = accessToken;
}


