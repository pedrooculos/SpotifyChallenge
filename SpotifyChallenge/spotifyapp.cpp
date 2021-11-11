#include "spotifyapp.h"

struct memory
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

    mem->response = ptr;
    memcpy(&(mem->response[mem->size]), data, realsize);
    mem->size += realsize;
    mem->response[mem->size] = 0;

    return realsize;
}



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
    CURL* curl;
    curl = curl_easy_init();

    if(!curl)
    {
           std::cerr << "Could not initiate cURL" << std::endl;
           return;
    }

    struct memory tokenBuffer= {0};
    std::string clientId = getStringFromFile("D:\\QtProject\\SpotifyChallenge\\SpotifyChallenge\\Credentials\\client_id.txt");
    std::string clientSecret = getStringFromFile("D:\\QtProject\\SpotifyChallenge\\SpotifyChallenge\\Credentials\\client_secret.txt");

    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &callbackFunction);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&tokenBuffer);   
    curl_easy_setopt(curl, CURLOPT_URL, "https://accounts.spotify.com/api/token");
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);
    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
    std::string postData = "grant_type=client_credentials&client_id=" + clientId + "&client_secret="+clientSecret;
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postData.c_str());

    CURLcode response;
    response = curl_easy_perform(curl);
    if (response != CURLE_OK)
    {
       std::cout << "Request Error" << std::endl;
    }
    curl_easy_cleanup(curl);

    QString responseStr = tokenBuffer.response;
    QJsonDocument responseJsonDocument =  QJsonDocument::fromJson(responseStr.toUtf8());
    QJsonObject responseJsonObject = responseJsonDocument.object();
    QString accessToken = responseJsonObject["access_token"].toString();

    setAccessToken(accessToken);
}

void SpotifyApp::search()
{
    CURL* curl;
    curl = curl_easy_init();

    if(!curl)
    {
           std::cerr << "Could not initiate cURL" << std::endl;
           return;
    }

    CURLcode response;

    struct curl_slist* header = NULL;
    std::string strHeader = "Authorization: Bearer " + getAccessToken().toStdString();

    header = curl_slist_append(header, "Content-Type: application/json");
    header = curl_slist_append(header, strHeader.c_str());

    std::string searchString = "https://api.spotify.com/v1/search";
    searchString += "?q=Aurora";
    searchString += "&type=track%2Cartist";
    searchString += "&market=ES";
    searchString += "&limit=10";
    searchString += "&offset=5";


    struct memory requestResponse= {0};
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &callbackFunction);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&requestResponse);
    curl_easy_setopt(curl, CURLOPT_URL, searchString.c_str());
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, header);
    curl_easy_setopt(curl, CURLOPT_HTTPGET, 1L);


    response = curl_easy_perform(curl);
    if (response != CURLE_OK)
    {
       std::cout << "Request Error" << std::endl;
    }
    curl_easy_cleanup(curl);

    std::cout << requestResponse.response << std::endl;

}

const QString SpotifyApp::getAccessToken()
{
    return this->accessToken;
}

void SpotifyApp::setAccessToken(const QString& accessToken)
{
    this->accessToken = accessToken;
}


