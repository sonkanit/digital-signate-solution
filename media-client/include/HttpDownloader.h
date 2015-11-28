#ifndef HTTPDOWNLOADER_H
#define HTTPDOWNLOADER_H

#include <string>
#include <curl/curl.h>

template <class T>
class HttpDownloader
{
    public:
        HttpDownloader();
        virtual ~HttpDownloader();

        void download(std::string url, T& object);

        static void init();
    protected:
    private:
        static bool ms_bInitialized;
        static CURL* ms_pHandle;
};

#endif // HTTPDOWNLOADER_H
