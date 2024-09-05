#ifndef TELEGRAMBOT_DATABASE_H
#define TELEGRAMBOT_DATABASE_H
#include <vector>
#include "soci/soci.h"
#include "soci/postgresql/soci-postgresql.h"
#include "tgbot/types/Message.h"
#include "Queries.h"
#include "tgbot/Bot.h"

class Handler;

class DataBase{
private:
    int getPosition(int chatID, std::string subject);
    std::map <std::string, std::string (DataBase::*) (TgBot::Message::Ptr &)> dict;
    soci::session *psql;
    std::string schema;

    void changeStatus(TgBot::Message::Ptr message, int currentStatus);
    int getReplyChat(int chatID);
    std::string start(TgBot::Message::Ptr &message);
    std::string joinQueue(TgBot::Message::Ptr &message);
    std::string leaveQueue(TgBot::Message::Ptr &message);
    std::string showPosition(TgBot::Message::Ptr &message);
    std::string showList(TgBot::Message::Ptr &message);
    std::string swap(TgBot::Message::Ptr &message);
    std::string addSubject(TgBot::Message::Ptr &message);
    std::string deleteSubject(TgBot::Message::Ptr &message);
    std::string addStudent(TgBot::Message::Ptr &message);
    std::string deleteStudent(TgBot::Message::Ptr &message);
    std::string clear(TgBot::Message::Ptr &message);
    std::string exit(TgBot::Message::Ptr &message);
    std::string getAnswer(TgBot::Message::Ptr &message);
    std::string registration(TgBot::Message::Ptr &message);
    std::string approve(TgBot::Message::Ptr &message);
    std::string next(TgBot::Message::Ptr &message);
    std::string skip(TgBot::Message::Ptr &message);
    bool chatIsBusy(int isu);
    std::string getSubjectName(int chat_id);
    std::string getCommand(int chat_id);
    std::string getName(int chat_id);
    int getISU(int chat_id);
    int getChat(int isu);
    std::string getDate(int chatID, std::string subject);
    int dayOfWeek(std::string day);
public:
    bool isFirst(int isu_number);
    void sendMessageToFirst();
    void deleteData(std::string name, std::string table, std::string where = "");
    bool dayBefore(std::string subject);
    std::string parityWeek(tm time);
    std::pair <int, std::string> getFirst();
    template<typename T>
    void updateValue(std::string field, std::string table, std::string where, T value){
        *psql << "UPDATE " + schema + "." + table + " SET " + field + " = :value " + where, soci::use(value);
    }
    template<typename T>
    T getValue(std::string field, std::string table, std::string where = "", std::string order = ""){
        T value;
        *psql << "SELECT " + field + " FROM " + schema + "." + table + " " + where + " " + order, soci::into(value);
        return value;
    }
    bool first(int chatID);
    void sendApproval(TgBot::Message::Ptr &message, TgBot::Bot &bot);
    static std::string tableName(std::string name);
    DataBase(const std::string &connectionString, const std::string &_schema);
    soci::row getRow(const std::string &names, const std::string &argument);
    int getStatus(int chatID);
    bool findUser(int ISU);
    void sendQuery(std::string message);
    bool isAdmin(int chatID);
    template<typename T>
    std::vector<T> getData(std::string field, std::string table, std::string add = "", std::string order = "") {
        int size;
        *psql << "SELECT COUNT(" + field + ") FROM " + schema + "." + table + " " + add, soci::into(size);
        std::vector <T> data(size);
        size_t begin = 0;
        size_t end = size;
        if (size != 0)
            *psql << "SELECT " + field + " FROM " + schema + "." + table + " " + add + " " + order, soci::into(data, begin, end);
        return data;
    }
    static std::vector <std::string> getWords(std::string str);
    friend class Handler;
};

#endif //TELEGRAMBOT_DATABASE_H
