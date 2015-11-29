#include "HttpDownloader.h"
#include <memory.h>

bool HttpDownloader::ms_bInitialized = false;
CURL* HttpDownloader::ms_pHandle = 0;

HttpDownloader::HttpDownloader()
{
}

HttpDownloader::~HttpDownloader()
{
    //dtor
}


size_t HttpDownloader::write_callback(char *ptr, size_t size, size_t nmemb, void *userdata)
{
    HttpDownloader* self = static_cast<HttpDownloader*>(userdata);
    size_t writeSize = size * nmemb;
    self->m_vData.resize(self->m_vData.size() + writeSize);
    memcpy(&(self->m_vData[self->m_vData.size() - writeSize]), ptr, writeSize);
    return writeSize;
}

void HttpDownloader::download(std::string url)
{
    m_vData.clear();
    curl_easy_setopt(ms_pHandle, CURLOPT_URL, url.c_str());
    curl_easy_setopt(ms_pHandle, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(ms_pHandle, CURLOPT_WRITEDATA, this);
    curl_easy_perform(ms_pHandle);
}

void HttpDownloader::init()
{
    ms_bInitialized = true;
    curl_global_init(CURL_GLOBAL_ALL);
    ms_pHandle = curl_easy_init();
}

std::vector<unsigned char>& HttpDownloader::getData()
{
    return m_vData;
}
