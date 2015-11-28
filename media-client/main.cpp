#include <iostream>
#include "HttpDownloader.h"
#include "PlaySchedule.h"

using namespace std;

int main()
{
    HttpDownloader::init();
    PlaySchedule player;
    player.Update();
    return 0;
}
