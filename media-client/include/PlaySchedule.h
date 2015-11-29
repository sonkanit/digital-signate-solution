#ifndef PLAYSCHEDULE_H
#define PLAYSCHEDULE_H

#include <vector>
#include <memory>
#include <time.h>

class Media;

class ScheduleItem
{
    public:
        time_t time;
        std::shared_ptr<Media> pMedia;
};

class PlaySchedule
{
    public:
        PlaySchedule();
        virtual ~PlaySchedule();

        void update();
        void start();
        void stop();
    protected:

    private:
        void parse(std::vector<unsigned char>& data);
        std::vector<std::shared_ptr<ScheduleItem> > m_playList;
};

#endif // PLAYSCHEDULE_H
