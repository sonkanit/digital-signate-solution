#ifndef HTTPDOWNLOADER_H
#define HTTPDOWNLOADER_H

#include <string>
#include <vector>
#include <curl/curl.h>

class HttpDownloader
{
    public:
        HttpDownloader();
        virtual ~HttpDownloader();

        virtual void download(std::string url);
        std::vector<unsigned char>& getData();

        static void init();
    protected:
        std::vector<unsigned char> m_vData;
    private:
        static bool ms_bInitialized;
        static CURL* ms_pHandle;
        static size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata);
};

#endif // HTTPDOWNLOADER_H
