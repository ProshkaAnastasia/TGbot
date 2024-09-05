#include <iostream>
#include "tgbot/tgbot.h"
#include "tgbot/types/ReplyKeyboardMarkup.h"
#include "soci/soci.h"
#include "include/DataBase.h"
#include <vector>
#include <algorithm>
#include <string>
#include "include/Queries.h"
#include "include/BotHandling.h"
#include <thread>

typedef TgBot::ReplyKeyboardMarkup RKMarkup;
typedef TgBot::KeyboardButton KButton;
typedef TgBot::ReplyKeyboardRemove RKRemove;

template <typename T>
std::ostream &operator << (std::ostream &out, const std::vector <T> &v){
    for (auto i = 0; i < v.size(); i++){
        out << v[i] << " ";
    }
    out << std::endl;
    return out;
}

void renewCurrentMarkup(DataBase &db, Handler &handler){
    int lastFirst = 0;
    while(true){
        std::this_thread::sleep_for(std::chrono::seconds(10));
        m.lock();
        auto first = db.getFirst();
        m.unlock();
        if (first.first != 0 && lastFirst == 0){
            handler.notifyFirst(db, lastFirst);
        }
        if (first.first == 0 && lastFirst != 0){
            handler.stopNotifying(db, lastFirst);
        }
        lastFirst = first.first;
    }
    /*
    while(true) {
        std::this_thread::sleep_for(std::chrono::seconds(10));
        int first;
        first = handler.notifyFirst(db, lastFirst);
        if (first != lastFirst && lastFirst != 0)
            handler.stopNotifying(db, lastFirst);
        lastFirst = first;
    }
     */
}

void renewDataBase(DataBase &db){
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(10));
        m.lock();
        auto subjects = db.getData<std::string>("name", "subject");
        for (auto subject: subjects) {
            if (db.dayBefore(subject)) {
                db.deleteData("", db.tableName(subject));
            }
        }
        m.unlock();
    }
}

int main() {
    TgBot::Bot bot("5940973398:AAFljTrY314uaqNmBxh5v3CU-hgsjNYrSgI");
    Handler handler("5940973398:AAFljTrY314uaqNmBxh5v3CU-hgsjNYrSgI");
    DataBase db("host=127.0.0.1 dbname=anastasiapronina user=anastasiapronina password='***'", "public");
    //std::ofstream file("last.txt");
    std::thread updateDataBase = std::thread(renewDataBase, std::ref(db));
    std::thread changeMarkup = std::thread(renewCurrentMarkup, std::ref(db), std::ref(handler));
    //renewDataBase(db, bot);


    bot.getEvents().onCommand("start", [&bot, &db, &handler](TgBot::Message::Ptr message) {
        RKMarkup::Ptr mkp;
        RKRemove::Ptr remove = std::make_shared<RKRemove>(RKRemove());
        m.lock();
        std::string answer = handler.getAnswer(message, db, mkp);
        m.unlock();
        mkp->resizeKeyboard = false;
        mkp->oneTimeKeyboard = false;
        TgBot::Message::Ptr msg;
        if (mkp->keyboard.empty())
            msg = bot.getApi().sendMessage(message->chat->id, answer, false, 0);
        else
            msg = bot.getApi().sendMessage(message->chat->id, answer, false, 0, mkp);
        m.lock();
        //bot.getApi().editMessageText("Hello", msg->chat->id, msg->messageId);
        db.updateValue<int>("last_message_id", "students", "WHERE chat_id = " + std::to_string(message->chat->id), msg->messageId);
        m.unlock();
    });

    bot.getEvents().onCommand("help", [&bot, &db, &handler](TgBot::Message::Ptr message) {
        RKMarkup::Ptr mkp;
        m.lock();
        std::string answer = handler.getAnswer(message, db, mkp);
        m.unlock();
        bot.getApi().sendMessage(message->chat->id, answer, false, 0, mkp);
    });

    bot.getEvents().onNonCommandMessage([&bot, &db, &handler](TgBot::Message::Ptr message) {
        RKMarkup::Ptr mkp;
        RKRemove::Ptr remove = std::make_shared<RKRemove>(RKRemove());
        m.lock();
        std::string answer = handler.getAnswer(message, db, mkp);
        mkp->resizeKeyboard = false;
        mkp->oneTimeKeyboard = false;
        TgBot::Message::Ptr msg;
        if (message->text == "Выйти" && db.getStatus(message->chat->id) == Query::UNKNOWN){
            msg = bot.getApi().sendMessage(message->chat->id, answer, false, 0, remove);
        }
        else{
            msg = bot.getApi().sendMessage(message->chat->id, answer, false, 0, mkp);
        }
        std::cout << message->text << " | " << msg->text << std::endl;
        db.updateValue<int>("last_message_id", "students", "WHERE chat_id = " + std::to_string(message->chat->id), msg->messageId);
        m.unlock();
    });

    try {
        printf("Bot username: %s\n", bot.getApi().getMe()->username.c_str());
        TgBot::TgLongPoll longPoll(bot);
        while (true) {
            printf("Long poll started\n");
            longPoll.start();
        }
    } catch (TgBot::TgException& e) {
        printf("error: %s\n", e.what());
    }
}
