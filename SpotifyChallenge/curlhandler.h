#ifndef CURLHANDLER_H
#define CURLHANDLER_H
#include <curl/curl.h>
#include <iostream>

class CurlHandler
{
    public:
        CurlHandler();
        ~CurlHandler();

        void putOperation();
        const std::string postOperation(const std::string&,const std::string&);

    private:
        CURL* curlObject;
};

#endif // CURLHANDLER_H
