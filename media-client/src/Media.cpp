#include "Media.h"
#include "HttpDownloader.h"
#include "Config.h"
#include <iostream>
#include <fstream>

Media::Media()
{
    //ctor
    m_strResourceFileName = "resource.mkv";
}

Media::~Media()
{
    //dtor
}

void Media::play()
{
    download();
    system((Config::avplayPath + " -fs -autoexit " + Config::mediaStoragePath + "/" + m_strResourceFileName).c_str());
}

void Media::stop()
{
}

void Media::download()
{
    HttpDownloader downloader;
    downloader.download(m_strUrl);
    std::vector<unsigned char>& data = downloader.getData();
    std::ofstream file;
    file.open(Config::mediaStoragePath + "/" + m_strResourceFileName, std::ios::binary);
    for(size_t i = 0; i < data.size(); i++)
    {
        file << data[i];
    }
    file.close();
}
