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

template class<T>
void HttpDownloader::download(std::string url, T& object)
{
    curl_easy_setopt(ms_pHandle, CURLOPT_URL, url.c_str());
    curl_easy_setopt(ms_pHandle, CURLOPT_WRITEDATA, pObject);
}

void HttpDownloader::init()
{
    ms_bInitialized = true;
    curl_global_init(CURL_GLOBAL_ALL);
    ms_pHandle = curl_easy_init();
}
