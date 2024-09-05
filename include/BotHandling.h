#ifndef TELEGRAMBOT_BOTHANDLING_H
#define TELEGRAMBOT_BOTHANDLING_H
#include "tgbot/tgbot.h"
#include "DataBase.h"
#include <vector>
#include <map>

extern std::mutex m;

typedef TgBot::ReplyKeyboardMarkup RKMarkup;
typedef TgBot::KeyboardButton KButton;

class Handler{
private:
    TgBot::Bot *bot;
public:
    static RKMarkup getNowMurkup(DataBase &db);
    void notifyFirst(DataBase &db, int &lastFirst);
    void stopNotifying(DataBase &db, int isu);
    bool queryApproval(TgBot::Message::Ptr &message, DataBase &db);
    std::vector<int> valueOf(std::string message, DataBase &db, int chat_id);
    explicit Handler(std::string token);
    std::string getRefuseMessage(TgBot::Message::Ptr &message, DataBase &db);
    std::string getAnswer(TgBot::Message::Ptr &message, DataBase &db, TgBot::ReplyKeyboardMarkup::Ptr &mkp);
    static RKMarkup getMarkup(int currentStatus, bool admin, DataBase db);
};

#endif //TELEGRAMBOT_BOTHANDLING_H
