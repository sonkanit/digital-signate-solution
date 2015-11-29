#include <json-glib/json-glib.h>
#include <vector>

#include "PlaySchedule.h"
#include "HttpDownloader.h"
#include "Media.h"
#include "Config.h"

PlaySchedule::PlaySchedule()
{
    //ctor
}

PlaySchedule::~PlaySchedule()
{
    //dtor
}

void PlaySchedule::update()
{
    HttpDownloader downloader;
    downloader.download(Config::scheduleServer + Config::schedulePath);
    std::vector<unsigned char>& data = downloader.getData();
    parse(data);
}

void PlaySchedule::parse(std::vector<unsigned char>& data)
{
    m_playList.clear();
    JsonParser* parser = json_parser_new();
    if(json_parser_load_from_data(parser, (gchar*)&data[0], data.size(), 0))
    {
        JsonNode* root = json_parser_get_root(parser);
        JsonArray* jsonItems = json_node_get_array(root);
        int numItems = json_array_get_length(jsonItems);
        for(int i = 0; i < numItems; i++)
        {
            JsonNode* jsonItemNode = json_array_get_element(jsonItems, i);
            JsonObject* jsonItem = json_node_get_object(jsonItemNode);
            std::shared_ptr<ScheduleItem> item = std::make_shared<ScheduleItem>();
            std::string url(json_object_get_string_member(jsonItem, "resource"));
            std::shared_ptr<Media> media = std::make_shared<Media>();
            media->setUrl(Config::mediaServer + url);
            item->pMedia = media;
            m_playList.push_back(item);
        }
    }
}

void PlaySchedule::start()
{
    for(size_t i = 0; i < m_playList.size(); i++)
    {
        std::shared_ptr<ScheduleItem> item = m_playList[i];
        item->pMedia->play();
    }
}

void PlaySchedule::stop()
{
}
