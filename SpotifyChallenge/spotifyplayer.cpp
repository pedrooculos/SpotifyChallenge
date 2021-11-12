#include "spotifyplayer.h"

struct memory
{
    char* response;
    size_t size;
};

size_t callbackFunctionNew(void* data,size_t size, size_t nmemb, void* userp)
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


SpotifyPlayer::SpotifyPlayer()
{}



void SpotifyPlayer::startPlayback(const QString accessToken)
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
    std::string strHeader = "Authorization: Bearer " + accessToken.toStdString();

    std::string resumePlaybackUrl = baseUrl + "/play";

    struct memory requestResponse= {0};
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &callbackFunctionNew);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&requestResponse);
    curl_easy_setopt(curl, CURLOPT_URL, resumePlaybackUrl.c_str());
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, header);
    curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);

    response = curl_easy_perform(curl);
    if (response != CURLE_OK)
    {
       std::cout << "Request Error" << std::endl;
    }

    std::cout << requestResponse.response << std::endl;


}
