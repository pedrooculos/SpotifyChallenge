#ifndef CURLHANDLER_H
#define CURLHANDLER_H
#include <curl/curl.h>
#include <iostream>

class CurlHandler
{
    public:
        CurlHandler();
        ~CurlHandler();

        const std::string postOperation(const std::string& url, const std::string& data);
        const std::string getOperation(const std::string& url, const std::string& authentication);

    private:
        CURL* curlObject;
};

#endif // CURLHANDLER_H
