#include "PlaySchedule.h"
#include "HttpDownloader.h"

PlaySchedule::PlaySchedule()
{
    //ctor
}

PlaySchedule::~PlaySchedule()
{
    //dtor
}

void PlaySchedule::Update()
{
    Schedule newSchedule;
    //download
    HttpDownloader<Schedule> downloader;
    downloader.download("http://127.0.0.1:8080", newSchedule);
    //update
}

void PlaySchedule::Start()
{
}

void PlaySchedule::Stop()
{
}
