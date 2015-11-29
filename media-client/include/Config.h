#ifndef CONFIG_H
#define CONFIG_H

#include <string>

class Config
{
    public:
        static void init(std::string file);
        static std::string scheduleServer;
        static std::string schedulePath;
        static std::string mediaServer;
        static std::string mediaStoragePath;
        static std::string avplayPath;
};

#endif // CONFIG_H
