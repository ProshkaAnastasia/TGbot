#include "../include/DataBase.h"
#include "../include/BotHandling.h"
#include <iostream>
#include <sstream>
#include <regex>
#include <set>
#include <iomanip>

soci::row DataBase::getRow(const std::string &names, const std::string &argument) {

}

int DataBase::getStatus(int chatID) {
    int answer = Query::UNKNOWN;
    std::string query = "SELECT query_status FROM " + schema + ".students WHERE chat_id = " + std::to_string(chatID);
    *psql << query, soci::into(answer);
    if (answer == Query::UNKNOWN){
        query = "SELECT query_status FROM " + schema + ".register WHERE chat_id = " + std::to_string(chatID);
        *psql << query, soci::into(answer);
    }
    return answer;
}

void DataBase::sendQuery(std::string message) {
    *psql << message;
}

bool DataBase::findUser(int ISU) {
    int size;
    *psql << "SELECT COUNT(isu_number) FROM " + schema + ".students", soci::into(size);
    std::vector <int> data;
    size_t begin = 0;
    size_t end = size;
    if (size != 0) {
        data.resize(size);
        *psql << "SELECT isu_number FROM " + schema + ".students", soci::into(data, begin, end);
    }
    if (std::find(data.begin(), data.end(), ISU) == data.end()){
        return false;
    }
    else{
        return true;
    }
}

bool DataBase::isAdmin(int chatID) {
    std::string query = "SELECT admin FROM " + schema + ".students WHERE chat_id = " + std::to_string(chatID);
    int admin;
    *psql << query, soci::into(admin);
    return admin;
}

std::string DataBase::tableName(std::string name) {
    std::regex re(" ");
    std::string tableName = std::regex_replace(name, re, "_");
    return tableName;
}

int DataBase::getISU(int chat_id) {
    int isu = 0;
    *psql << "SELECT isu_number FROM " + schema + ".students WHERE chat_id = " + std::to_string(chat_id), soci::into(isu);
    return isu;
}

void DataBase::changeStatus(TgBot::Message::Ptr message, int currentStatus) {
    int status = currentStatus;
    if (status == Query::UNKNOWN){
        sendQuery("DELETE FROM public.register WHERE chat_id = " + std::to_string(message->chat->id));
        sendQuery("INSERT INTO public.register VALUES (" + std::to_string(message->chat->id) + ", " + std::to_string(Query::REGISTRATION) + ");");
        return;
    } else if (status == Query::REGISTRATION){
        status = Query::BASIC;
    } else if (message->text == "/start"){
        if (isFirst(getISU(message->chat->id)))
            status = Query::BASIC_NOW;
        else
            status = Query::BASIC;
    } else if (message->text == "Выйти"){
        if (status == BASIC){
            status = Query::UNKNOWN;
        }
        else {
            if (isFirst(getISU(message->chat->id)))
                status = Query::BASIC_NOW;
            else
                status = Query::BASIC;
        }
    } else if (message->text == "Встать в очередь"){
        status = Query::JOIN;
    } else if (message->text == "Выйти из очереди"){
        status = Query::EXIT;
    } else if (message->text == "Узнать позицию в очереди"){
        status = Query::SHOW;
    } else if (message->text == "Посмотреть список"){
        status = Query::LIST;
    } else if (message->text == "Поменяться местами"){
        status = Query::SWAP;
    } else if (message->text == "Следующий"){
        status = Query::BASIC;
    } else if (message->text == "Пропустить очередь"){
        status = Query::BASIC;
    } else if (message->text == "Добавить предмет"){
        status = Query::ADD_SUBJECT;
    } else if (message->text == "Удалить предмет"){
        status = Query::DELETE_SUBJECT;
    } else if (message->text == "Добавить студента в группу"){
        status = Query::ADD_STUDENT;
    } else if (message->text == "Удалить студента из группы"){
        status = Query::DELETE_STUDENT;
    } else if (message->text == "Очистить чат"){
        status = Query::CLEAR_CHAT;
    } else if (message->text == "Следующий" || message->text == "Пропустить очередь"){
        status = Query::BASIC;
    } else if (getStatus(message->chat->id) == Query::SWAP){
        status = Query::SWAP_ISU;
    } else if (getStatus(message->chat->id) == Query::SWAP_ISU){
        status = Query::WAITING;
    } else if (getStatus(message->chat->id) == Query::ANSWER){
        if (isFirst(getISU(message->chat->id)))
            status = Query::BASIC_NOW;
        else
            status = Query::BASIC;
    } else if (getStatus(message->chat->id) == Query::CLEAR_CHAT || getStatus(message->chat->id) == Query::ADD_SUBJECT
        || getStatus(message->chat->id) == Query::DELETE_STUDENT || getStatus(message->chat->id) == Query::ADD_STUDENT
        || getStatus(message->chat->id) == Query::DELETE_SUBJECT || getStatus(message->chat->id) == Query::SWAP_ISU){
        if (isFirst(getISU(message->chat->id)))
            status = Query::BASIC_NOW;
        else
            status = Query::BASIC;
    } else if (getStatus(message->chat->id) == Query::JOIN || getStatus(message->chat->id) == Query::SHOW
        || getStatus(message->chat->id) == Query::EXIT || getStatus(message->chat->id) == Query::LIST){
        if (isFirst(getISU(message->chat->id)))
            status = Query::BASIC_NOW;
        else
            status = Query::BASIC;
    }
    sendQuery("UPDATE " + schema + ".students SET query_status = " + std::to_string(status) + " WHERE chat_id = " + std::to_string(message->chat->id));
}

DataBase::DataBase(const std::string &connectionString, const std::string &_schema) {
    psql = new soci::session(soci::postgresql, connectionString);
    schema = _schema;
    dict["Встать в очередь"] = &DataBase::joinQueue;
    dict["Выйти из очереди"] = &DataBase::leaveQueue;
    dict["Узнать позицию в очереди"] = &DataBase::showPosition;
    dict["Посмотреть список"] = &DataBase::showList;
    dict["Поменяться местами"] = &DataBase::swap;
    dict["Добавить предмет"] = &DataBase::addSubject;
    dict["Удалить предмет"] = &DataBase::deleteSubject;
    dict["Добавить студента в группу"] = &DataBase::addStudent;
    dict["Удалить студента из группы"] = &DataBase::deleteStudent;
    dict["Очистить чат"] = &DataBase::clear;
    dict["Выйти"] = &DataBase::exit;
    dict["/start"] = &DataBase::start;
    dict["Регистрация"] = &DataBase::registration;
    dict["Подтверждение"] = &DataBase::approve;
    dict["Пропустить очередь"] = &DataBase::skip;
    dict["Следующий"] = &DataBase::next;
}

bool DataBase::isFirst(int isu_number) {
    int isu = getFirst().first;
    return isu_number == isu;
    auto data = getData<std::string>("name", "subject");
    /*std::vector <int> numbers;
    for (auto d : data){
        int isu;
        std::tm begin{};
        std::tm end{};
        *psql << "SELECT isu_number FROM " + schema + "." + d + "ORDER BY reg_date LIMIT 1", soci::into(isu);
        *psql << "SELECT begin, end FROM " + schema + ".subject WHERE name = " + d, soci::into(begin), soci::into(end);
    }*/
}

std::string DataBase::joinQueue(TgBot::Message::Ptr &message) {
    std::string subject = tableName(message->text);
    auto data = getData<int>("isu_number", subject, "WHERE isu_number = " + std::to_string(getISU(message->chat->id)));
    if (data.empty())
        *psql << "INSERT INTO " + schema + "." + subject + " VALUES (" + std::to_string(getISU(message->chat->id)) +
            ", CURRENT_TIMESTAMP)";
    sendQuery("DELETE FROM " + schema + ".subject_name WHERE chat_id = " + std::to_string(message->chat->id));
    return !data.empty() ? "Вы уже стоите в очереди на данный предмет." : "Вы успешно встали в очередь на " + message->text + ".";
}

std::string DataBase::leaveQueue(TgBot::Message::Ptr &message) {
    std::string subject = tableName(message->text);
    auto data = getData<int>("isu_number", subject, "WHERE isu_number = " + std::to_string(getISU(message->chat->id)));
    if (!data.empty())
        *psql << "DELETE FROM " + schema + "." + subject + " WHERE isu_number = " + std::to_string(getISU(message->chat->id));
    sendQuery("DELETE FROM " + schema + ".subject_name WHERE chat_id = " + std::to_string(message->chat->id));
    return data.empty() ? "Вы не стоите в очереди на " + message->text + "." : "Вы успешно покинули очередь.";
}

std::string DataBase::showPosition(TgBot::Message::Ptr &message) {
    std::string subject = tableName(message->text);
    int position = -1;
    int isu = getISU(message->chat->id);
    auto data = getData<int>("isu_number", subject, "","ORDER BY reg_date");
    for (int i = 0; i < data.size(); i++){
        if (data[i] == getISU(message->chat->id)){
            position = i + 1;
            break;
        }
    }
    sendQuery("DELETE FROM " + schema + ".subject_name WHERE chat_id = " + std::to_string(message->chat->id));
    return position == -1 ? "Вы не стоите в очереди на данный предмет." : "Ваш номер в очереди: " + std::to_string(position);
}

std::string DataBase::showList(TgBot::Message::Ptr &message) {
    std::string subject = tableName(message->text);
    std::string answer;
    int isu = getISU(message->chat->id);
    auto data = getData<int>("isu_number", subject, "","ORDER BY reg_date");
    for (int i = 0; i < data.size(); i++){
        std::string fullName;
        *psql << "SELECT full_name FROM " + schema + ".students WHERE isu_number = " + std::to_string(data[i]), soci::into(fullName);
        if (i == data.size() - 1){
            answer += std::to_string(i + 1) + ".\t" + fullName;
            break;
        }
        answer += std::to_string(i + 1) + ".\t" + fullName + "\n";
    }
    sendQuery("DELETE FROM " + schema + ".subject_name WHERE chat_id = " + std::to_string(message->chat->id));
    return answer.empty() ? "Очередь пуста." : answer;
}

std::string DataBase::swap(TgBot::Message::Ptr &message) {
    sendQuery("UPDATE " + schema + ".subject_name SET command_name = 'Ожидание', isu_number = " + message->text + " WHERE chat_id = " + std::to_string(message->chat->id));
    return "Ожидаем подтверждения...";
}

std::string DataBase::addSubject(TgBot::Message::Ptr &message) {
    auto data = getWords(message->text);
    int i = data.size() - 1;
    std::string week = data[i];
    std::string begin = data[i - 2];
    std::string end = data[i - 1];
    std::string name;
    std::string day = data[i - 3];
    for (auto j = 0; j < i - 3; j++){
        name += data[j];
        name += j == i - 4 ? "" : " ";
    }
    data = getData<std::string>("name", "subject", "WHERE name = '" + name + "'");
    if (data.empty()) {
        *psql << "INSERT INTO " + schema +
                 ".subject (name, day, begin_time, end_time, week) VALUES (:name, :day, :begin, :end, :week)", soci::use(name),
                    soci::use(dayOfWeek(day)), soci::use(begin), soci::use(end), soci::use(week);
        std::string query = "CREATE TABLE IF NOT EXISTS " + schema + "." + tableName(name) +
                            " (isu_number INT PRIMARY KEY, reg_date TIMESTAMP WITHOUT TIME ZONE);";
        *psql << query;
    }
    sendQuery("DELETE FROM " + schema + ".subject_name WHERE chat_id = " + std::to_string(message->chat->id));
    return data.empty() ? "Предмет добавлен в базу данных." : "Предмет уже существует";
}

std::string DataBase::deleteSubject(TgBot::Message::Ptr &message) {
    auto data = getData<std::string>("name", "subject", "WHERE name = '" + message->text + "'");
    std::string query = "DROP TABLE IF EXISTS " + schema + "." + tableName(message->text) + ";";
    *psql << query;
    query = "DELETE FROM " + schema + ".subject WHERE name = '" + message->text + "'";
    *psql << query;
    sendQuery("DELETE FROM " + schema + ".subject_name WHERE chat_id = " + std::to_string(message->chat->id));
    return "Предмет успешно удален.";
}

std::string DataBase::addStudent(TgBot::Message::Ptr &message) {
    auto data = getWords(message->text);
    int i = data.size() - 1;
    int admin = 0;
    if (data[i] == "admin"){
        admin = 1;
        i--;
    }
    int isu = std::stoi(data[i]);
    std::string name;
    for (auto j = 0; j < i; j++){
        name += data[j];
        name += j == i - 1 ? "" : " ";
    }
    auto numbers = getData<int>("isu_number", "students", "WHERE isu_number = '" + data[i] + "'");
    if (numbers.empty()) {
        *psql << "INSERT INTO " + schema +
                 ".students (full_name, isu_number, admin) VALUES (:name, :isu, :admin)", soci::use(name), soci::use(isu), soci::use(admin);
    }
    sendQuery("DELETE FROM " + schema + ".subject_name WHERE chat_id = " + std::to_string(message->chat->id));
    return numbers.empty() ? "Студент добавлен в группу" : "Студент уже состоит в группе";
}

std::string DataBase::deleteStudent(TgBot::Message::Ptr &message) {
    auto data = getData<int>("isu_number", "students", "WHERE isu_number = " + message->text);
    int chat_id = getChat(std::stoi(message->text));
    if (!data.empty()) {
        if (message->text == "368696") {
            sendQuery("DELETE FROM " + schema + ".subject_name WHERE chat_id = " + std::to_string(message->chat->id));
            return "Студент не может быть удален";
        }
        sendQuery("DELETE FROM " + schema + ".register WHERE chat_id = " + std::to_string(chat_id));
        auto subjects = getData<std::string>("name", "subject");
        for (auto subject : subjects){
            sendQuery("DELETE FROM " + schema + "." + tableName(subject) + " WHERE isu_number = " + message->text);
        }
        sendQuery("DELETE FROM " + schema + ".students WHERE isu_number = " + message->text);
    }
    sendQuery("DELETE FROM " + schema + ".subject_name WHERE chat_id = " + std::to_string(message->chat->id));
    return !data.empty() ? "Студент удален из группы" : "Студента с таким номером ISU не существует";
}



std::string DataBase::clear(TgBot::Message::Ptr &message) {
    int chat_id;
    chat_id = getChat(std::stoi(message->text));
    auto data = getData<std::string>("name", "subject");
    for (auto subject : data){
        sendQuery("DELETE FROM " + schema + "." + tableName(subject) + " WHERE isu_number = " + message->text);
    }
    sendQuery("DELETE FROM " + schema + ".register WHERE chat_id = " + std::to_string(chat_id));
    sendQuery("DELETE FROM " + schema + ".subject_name WHERE chat_id = " + std::to_string(chat_id));
    sendQuery("UPDATE " + schema + ".students SET query_status = " + std::to_string(Query::UNKNOWN) + " WHERE chat_id = " + std::to_string(chat_id));
    sendQuery("UPDATE " + schema + ".students SET chat_id = 0 WHERE chat_id = " + std::to_string(chat_id));
    return "Чат очищен.";
}

std::string DataBase::exit(TgBot::Message::Ptr &message) {
    sendQuery("DELETE FROM " + schema + ".subject_name WHERE chat_id = " + std::to_string(message->chat->id));
    if (getStatus(message->chat->id) == Query::BASIC || getStatus(message->chat->id) == Query::BASIC_NOW){
        auto data = getData<std::string>("name", "subject");
        for (auto subject : data){
            sendQuery("DELETE FROM " + schema + "." + tableName(subject) + " WHERE isu_number = " + std::to_string(getISU(message->chat->id)));
        }
        sendQuery("UPDATE " + schema + ".students SET query_status = " + std::to_string(Query::UNKNOWN) + " WHERE chat_id = " + std::to_string(message->chat->id));
        sendQuery("UPDATE " + schema + ".students SET chat_id = 0 WHERE chat_id = " + std::to_string(message->chat->id));
        return "Выход совершен успешно. Для дальнейшей работы введите /start.";
    }
    else{
        "UPDATE " + schema + ".students SET query_status = " + std::to_string(Query::BASIC) + " WHERE chat_id = " + std::to_string(message->chat->id);
        return "Запрос отменен.";
    }
}

std::string DataBase::getAnswer(TgBot::Message::Ptr &message) {
    if (dict.find(message->text) != dict.end()){
        sendQuery("INSERT INTO " + schema + ".subject_name VALUES (" + std::to_string(message->chat->id) + ", 'None', '" + message->text + "')");
        if (message->text == "Встать в очередь" || message->text == "Выйти из очереди" || message->text == "Узнать позицию в очереди"
                || message->text == "Посмотреть список" || message->text == "Поменяться местами"){
            return "Укажите название предмета";
        }
        if (message->text == "Добавить предмет"){
            return "Укажите сведения о предмете в формате \"название\" \"день недели\" \"время начала HH:MM\" \"время конца HH:MM\" \"четная/нечетная (неделя)\"";
        }
        if (message->text == "Удалить предмет"){
            return "Укажите название предмета";
        }
        if (message->text == "Добавить студента в группу"){
            return "Укажите сведения о студенте в формате \"ФИ(О*)\" \"номер ISU\" \"admin* (Необязательно)\"";
        }
        if (message->text == "Удалить студента из группы" || message->text == "Очистить чат"){
            return "Введите номер ISU.";
        }
        return (this->*dict.at(message->text))(message);
    }
    if (getStatus(message->chat->id) == Query::SWAP){
        sendQuery("UPDATE " + schema + ".subject_name SET subject_name = '" + message->text + "' WHERE chat_id = " + std::to_string(message->chat->id));
        return "Укажите номер ISU студента, с которым хотите поменяться местами.";
    }
    return (this->*dict.at(getCommand(message->chat->id)))(message);
}

std::string DataBase::start(TgBot::Message::Ptr &message) {
    if (getStatus(message->chat->id) == Query::UNKNOWN){
        sendQuery("UPDATE " + schema + ".subject_name SET command_name = 'Регистрация' WHERE chat_id = " + std::to_string(message->chat->id));
        return "Пожалуйста, войдите в систему под своим номером ISU";
    }
    sendQuery("DELETE FROM " + schema + ".subject_name WHERE chat_id = " + std::to_string(message->chat->id));
    return "Здравствуйте, " + getName(message->chat->id) + "! Я бот, который отвечает за создание очередей. Пожалуйста, воспользуйтесь виртуальной клавиатурой, чтобы я мог выполнить Ваш запрос.";
}

bool DataBase::chatIsBusy(int isu) {
    int chat_id;
    *psql << "SELECT chat_id FROM " + schema + ".students WHERE isu_number = " + std::to_string(isu), soci::into(chat_id);
    return chat_id != 0;
}

std::string DataBase::getSubjectName(int chat_id) {
    std::string subject;
    *psql << "SELECT subject_name FROM " + schema + ".subject_name WHERE chat_id = " + std::to_string(chat_id), soci::into(subject);
    return subject;
}

std::string DataBase::getCommand(int chat_id) {
    std::string command;
    *psql << "SELECT command_name FROM " + schema + ".subject_name WHERE chat_id = " + std::to_string(chat_id), soci::into(command);
    return command;
}

std::string DataBase::registration(TgBot::Message::Ptr &message) {
    sendQuery("DELETE FROM " + schema + ".subject_name WHERE chat_id = " + std::to_string(message->chat->id));
    sendQuery("DELETE FROM " + schema + ".register WHERE chat_id = " + std::to_string(message->chat->id));
    sendQuery("UPDATE " + schema + ".students SET chat_id = " + std::to_string(message->chat->id) + ", query_status = " + std::to_string(BASIC) + " WHERE isu_number = " + message->text + ";");
    return "Здравствуйте, " + getName(message->chat->id) + "! Я бот, который отвечает за создание очередей. Пожалуйста, воспользуйтесь виртуальной клавиатурой, чтобы я мог выполнить Ваш запрос.";
}

std::string DataBase::getName(int chat_id) {
    std::string fullName;
    *psql << "SELECT full_name FROM " + schema + ".students WHERE chat_id = " + std::to_string(chat_id), soci::into(fullName);
    auto words = getWords(fullName);
    return words[1];
}

std::vector<std::string> DataBase::getWords(std::string str) {
    std::vector <std::string> answer;
    std::string currentStr;
    for (auto i = 0; i < str.length(); i++){
        if (str[i] == ' '){
            if (!currentStr.empty()){
                answer.push_back(currentStr);
                currentStr = "";
            }
        }
        else{
            currentStr += str[i];
        }
    }
    if (!currentStr.empty()){
        answer.push_back(currentStr);
    }
    return answer;
}

void DataBase::sendApproval(TgBot::Message::Ptr &message, TgBot::Bot &bot) {
    int replyChat = getChat(std::stoi(message->text));
    std::string subject = getSubjectName(message->chat->id);
    sendQuery("UPDATE " + schema + ".students SET query_status = " + std::to_string(Query::ANSWER) + " WHERE chat_id = " + std::to_string(replyChat));
    *psql << "INSERT INTO " + schema + ".subject_name (chat_id, subject_name, command_name, isu_number) VALUES (" + std::to_string(replyChat) + ", '" + subject + "', 'Подтверждение', " + std::to_string(getISU(message->chat->id)) + ")";
    TgBot::ReplyKeyboardMarkup::Ptr mkp = std::make_shared<TgBot::ReplyKeyboardMarkup>(Handler::getMarkup(getStatus(replyChat), isAdmin(replyChat), *this));
    int position = getPosition(message->chat->id, subject);
    std::string query = "Пожалуйста, подтвердите запрос на смену позиции в очереди на " + subject + ". Новая позиция - " + std::to_string(position) + ".";
    bot.getApi().sendMessage(replyChat, query, false, 0, mkp);
}

int DataBase::getChat(int isu) {
    int chat = 0;
    *psql << "SELECT chat_id FROM " + schema + ".students WHERE isu_number = " + std::to_string(isu), soci::into(chat);
    return chat;
}

bool DataBase::first(int chatID) {
    auto data = getData<int>("chat_id", "chat", "WHERE chat_id = " + std::to_string(chatID));
    if (data.empty()){
        sendQuery("INSERT INTO " + schema + ".chat (chat_id) VALUES (" + std::to_string(chatID) + ")");
        return true;
    }
    else{
        return false;
    }
}

std::string DataBase::approve(TgBot::Message::Ptr &message) {
    if (message->text == "Подтверждаю"){
        std::string subject = getSubjectName(message->chat->id);
        std::string thisDate;
        std::string newDate;
        *psql << "SELECT reg_date FROM " + schema + "." + tableName(subject) + " WHERE isu_number = " + std::to_string(getISU(message->chat->id)), soci::into(thisDate);
        *psql << "SELECT reg_date FROM " + schema + "." + tableName(subject) + " WHERE isu_number = " + std::to_string(getISU(getReplyChat(message->chat->id))), soci::into(newDate);
        sendQuery("UPDATE " + schema + "." + tableName(subject) + " SET reg_date = '" + newDate + "' WHERE isu_number = " + std::to_string(getISU(message->chat->id)));
        sendQuery("UPDATE " + schema + "." + tableName(subject) + " SET reg_date = '" + thisDate + "' WHERE isu_number = " + std::to_string(getISU(
                getReplyChat(message->chat->id))));
        return "Запрос подтвержден.";
    } else{
        return "Запрос отклонен.";
    }
}

int DataBase::getReplyChat(int chatID) {
    int isu;
    *psql << "SELECT isu_number FROM " + schema + ".subject_name " + "WHERE chat_id = " + std::to_string(chatID), soci::into(isu);
    return getChat(isu);
}

int DataBase::getPosition(int chatID, std::string subject) {
    int position = 0;
    auto data = getData<int>("isu_number", subject, "","ORDER BY reg_date");
    for (int i = 0; i < data.size(); i++){
        if (data[i] == getISU(chatID)){
            position = i + 1;
            break;
        }
    }
    return position;
}

std::string DataBase::getDate(int isu, std::string subject) {
    std::string date;
    *psql << "SELECT reg_date FROM " + schema + "." + subject + " WHERE isu_number = " + std::to_string(isu);
    return date;
}

std::pair <int, std::string> DataBase::getFirst() {
    auto subject = getData<std::string>("name", "subject");
    auto weekDay = getData<int>("day", "subject");
    auto beginTime = getData<std::tm>("begin_time", "subject");
    auto endTime = getData<std::tm>("end_time", "subject");
    auto week = getData<std::string>("week", "subject");
    std::time_t t = std::time(nullptr);
    std::tm now = *std::localtime(&t);
    for (auto i = 0; i < subject.size(); i++){
        if (getData<int>("isu_number", tableName(subject[i])).empty()){
            continue;
        }
        if (now.tm_wday == weekDay[i] && week[i] == parityWeek(now)){
            if (beginTime[i].tm_hour == endTime[i].tm_hour && beginTime[i].tm_hour == now.tm_hour){
                if (beginTime[i].tm_min <= now.tm_min && now.tm_min < endTime[i].tm_min) {
                    return std::make_pair(getValue<int>("isu_number", tableName(subject[i]), "", "ORDER BY reg_date LIMIT 1"), subject[i]);
                }
            } else if (beginTime[i].tm_hour < now.tm_hour && now.tm_hour < endTime[i].tm_hour){
                return std::make_pair(getValue<int>("isu_number", tableName(subject[i]), "", "ORDER BY reg_date LIMIT 1"), subject[i]);
            } else if (beginTime[i].tm_hour == now.tm_hour){
                if (now.tm_min >= beginTime[i].tm_min){
                    return std::make_pair(getValue<int>("isu_number", tableName(subject[i]), "", "ORDER BY reg_date LIMIT 1"), subject[i]);
                }
            } else if (now.tm_hour == endTime[i].tm_hour){
                if (now.tm_min < endTime[i].tm_min){
                    return std::make_pair(getValue<int>("isu_number", tableName(subject[i]), "", "ORDER BY reg_date LIMIT 1"), subject[i]);
                }
            }
        }
    }
    return std::make_pair(0, "");
}

int DataBase::dayOfWeek(std::string day) {
    if (day == "Воскресенье" || day == "воскресенье"){
        return 0;
    } else if (day == "Понедельник" || day == "понедельник"){
        return 1;
    } else if (day == "Вторник" || day == "вторник"){
        return 2;
    } else if (day == "Среда" || day == "среда"){
        return 3;
    } else if (day == "Четверг" || day == "четверг"){
        return 4;
    } else if (day == "Пятница" || day == "пятница"){
        return 5;
    } else if (day == "Суббота" || day == "суббота"){
        return 6;
    }
}

// 0 - 1
// 1 - 0
// 2 - 6
// 3 - 5
// 4 - 4
// 5 - 3
// 6 - 2

std::string DataBase::parityWeek(tm time) {
    tm t = {};
    int parity;
    std::stringstream stream("01.01." + std::to_string(time.tm_year + 1900));
    stream >> std::get_time(&t, "%d.%m.%Y");
    std::mktime(&t);
    int difference = ((7 - t.tm_wday) % 7 + 1) % 7;
    int days = time.tm_yday;
    if (time.tm_yday < difference){
        return "четная";
    }
    if (difference == 0){
        parity = (days / 7) % 2;
    }
    else{
        parity = (((days - difference) / 7) % 2 + 1) % 2;
    }
    return parity ? "нечетная" : "четная";
}

bool DataBase::dayBefore(std::string subject) {
    auto weeks = getData<std::string>("week", "subject", "WHERE name = '" + subject + "'");
    auto days = getData<int>("day", "subject", "WHERE name = '" + subject + "'");
    std::time_t t = std::time(nullptr);
    std::tm now = *std::localtime(&t);
    if (!(now.tm_hour == 0 && now.tm_min <= 1)){
        return false;
    }
    for (auto i = 0; i < weeks.size(); i++){
        std::string week = weeks[i];
        int day = days[i];
        if (week == parityWeek(now)){
            if (day - now.tm_wday == 1 || day - now.tm_wday == -6){
                return true;
            }
        }
        else{
            if (day == 1 && now.tm_wday == 0){
                return true;
            }
        }
    }
    return false;
}

void DataBase::deleteData(std::string name, std::string table, std::string where) {
    sendQuery("DELETE " + name + " FROM " + schema + "." + table + " " + where);
}

void DataBase::sendMessageToFirst() {
    int isu = getFirst().first;
    updateValue("query_status", "students", "WHERE isu_number = " + std::to_string(isu), int(Query::BASIC_NOW));
}

std::string DataBase::skip(TgBot::Message::Ptr &message) {
    //auto data = getData<std::string>("name", "subject");
    std::string currentSubject = getFirst().second;
    /*
    for (auto subject : data){
        int first = getValue<int>("isu_number", tableName(subject), "", "ORDER BY reg_date LIMIT 1");
        if (first == getISU(message->chat->id)){
            currentSubject = subject;
            break;
        }
    }
     */

    auto time = getData<std::string>("reg_date", tableName(currentSubject), "", "ORDER BY reg_date LIMIT 2");
    auto students = getData<int>("isu_number", tableName(currentSubject), "", "ORDER BY reg_date LIMIT 2");
    if (time.size() == 2) {
        updateValue("reg_date", tableName(currentSubject), "WHERE isu_number = " + std::to_string(students[1]), time[0]);
        updateValue("reg_date", tableName(currentSubject), "WHERE isu_number = " + std::to_string(students[0]), time[1]);
        sendQuery("DELETE FROM " + schema + ".subject_name WHERE chat_id = " + std::to_string(message->chat->id));
        return "Ваша позиция в очереди - 2.";
    }
    else{
        sendQuery("DELETE FROM " + schema + ".subject_name WHERE chat_id = " + std::to_string(message->chat->id));
        return "Сейчас только Вы стоите в очереди по этому предмету.";
    }
}

std::string DataBase::next(TgBot::Message::Ptr &message) {
    std::string currentSubject = getFirst().second;
    if (!currentSubject.empty())
        sendQuery("DELETE FROM " + schema + "." + tableName(currentSubject) + " WHERE isu_number = " + std::to_string(getISU(message->chat->id)));
    sendQuery("DELETE FROM " + schema + ".subject_name WHERE chat_id = " + std::to_string(message->chat->id));
    return "Вы успешно покинули очередь.";
}









