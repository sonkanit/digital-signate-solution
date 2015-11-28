#include "HttpDownloader.h"

bool HttpDownloader::ms_bInitialized = false;
CURL* HttpDownloader::ms_pHandle = 0;

HttpDownloader::HttpDownloader()
{
}

HttpDownloader::~HttpDownloader()
{
    //dtor
}

void HttpDownloader::download(std::string url)
{
    curl_easy_setopt(ms_pHandle, CURLOPT_URL, url.c_str());
    //curl_easy_setopt(ms_pHandle, CURLOPT_WRITEDATA, pObject);
    curl_easy_perform(ms_pHandle);
}

void HttpDownloader::init()
{
    ms_bInitialized = true;
    curl_global_init(CURL_GLOBAL_ALL);
    ms_pHandle = curl_easy_init();
}
