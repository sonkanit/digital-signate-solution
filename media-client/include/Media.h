#ifndef MEDIA_H
#define MEDIA_H


class Media
{
    public:
        Media();
        virtual ~Media();
    protected:
        virtual void Play();
        virtual void Stop();
    private:
};

#endif // MEDIA_H
