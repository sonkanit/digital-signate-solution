#ifndef PLAYSCHEDULE_H
#define PLAYSCHEDULE_H

#include <vector>
#include <time.h>

class Media;

struct ScheduleItem
{
    time_t time;
    Media* pMedia;
};

struct Schedule
{
    int size;
    ScheduleItem* items;
};

class PlaySchedule
{
    public:
        PlaySchedule();
        virtual ~PlaySchedule();

        void Update();
        void Start();
        void Stop();
    protected:

    private:
        std::vector<ScheduleItem> m_playList;
};

#endif // PLAYSCHEDULE_H
