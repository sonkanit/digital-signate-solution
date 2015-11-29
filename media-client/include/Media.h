#ifndef MEDIA_H
#define MEDIA_H

#include <string>

class Media
{
    public:
        Media();
        virtual ~Media();
        void setUrl(std::string url)
        {
            m_strUrl = url;
        }
        virtual void play();
        virtual void stop();
    protected:
        virtual void download();
    private:
        std::string m_strUrl;
        std::string m_strResourceFileName;
};

#endif // MEDIA_H
