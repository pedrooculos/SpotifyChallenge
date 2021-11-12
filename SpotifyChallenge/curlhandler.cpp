#include "curlhandler.h"

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

CurlHandler::CurlHandler()
{
    this->curlObject = curl_easy_init();

    if(!curlObject)
    {
           std::cerr << "Could not initiate cURL" << std::endl;
           return;
    }
}

CurlHandler::~CurlHandler()
{
    curl_easy_cleanup(curlObject);
}


void CurlHandler::putOperation()
{

}

const std::string CurlHandler::postOperation(const std::string& postURL,const std::string& postData)
{
    struct memory requestResponse = {0};
    curl_easy_setopt(curlObject, CURLOPT_WRITEFUNCTION, &callbackFunction);
    curl_easy_setopt(curlObject, CURLOPT_WRITEDATA, (void *)&requestResponse);
    curl_easy_setopt(curlObject, CURLOPT_URL, postURL.c_str());
    curl_easy_setopt(curlObject, CURLOPT_SSL_VERIFYPEER, false);
    curl_easy_setopt(curlObject, CURLOPT_CUSTOMREQUEST, "POST");
    curl_easy_setopt(curlObject, CURLOPT_POSTFIELDS, postData.c_str());

    CURLcode response;
    response = curl_easy_perform(curlObject);
    if (response != CURLE_OK)
    {
       std::cout << "Request Error" << std::endl;
    }

    return requestResponse.response;

}

const std::string CurlHandler::getOperation(const std::string& url, const std::string& authentication)
{
    CURLcode response;
    struct curl_slist* header = NULL;
    header = curl_slist_append(header, "Content-Type: application/json");
    header = curl_slist_append(header, authentication.c_str());

    struct memory requestResponse= {0};
    curl_easy_setopt(curlObject, CURLOPT_WRITEFUNCTION, &callbackFunction);
    curl_easy_setopt(curlObject, CURLOPT_WRITEDATA, (void *)&requestResponse);
    curl_easy_setopt(curlObject, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curlObject, CURLOPT_SSL_VERIFYPEER, false);
    curl_easy_setopt(curlObject, CURLOPT_HTTPHEADER, header);
    curl_easy_setopt(curlObject, CURLOPT_HTTPGET, 1L);

    response = curl_easy_perform(curlObject);
    if (response != CURLE_OK)
    {
       std::cout << "Request Error" << std::endl;
    }

    return requestResponse.response;

}





