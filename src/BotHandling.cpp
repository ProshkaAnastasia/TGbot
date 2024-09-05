#include "../include/BotHandling.h"
#include "../include/Queries.h"
#include <regex>
/*
 Список возможных команд бота:
 Команды обычного пользователя:
    Встать в очередь            BASIC
    Выйти из очереди            BASIC
    Узнать позицию в очереди    BASIC
    Посмотреть список           BASIC
    Поменяться местами          BASIC
    Выйти                       Любое состояние
    Подтвердить                 ANSWER
    Отмена                      ANSWER
 Команды администратора:
    Добавить предмет            BASIC
    Удалить предмет             BASIC
    Добавить студента в группу  BASIC
    Удалить студента из группы  BASIC
    Очистить чат                BASIC
 Другие команды (команды ввода данных)
    Для добавления предмета: "Название предмета" "день недели" "время начала" "время конца"                 ADD_SUBJECT
    Для добавления студента: "ФИО" "номер ISU"                                                              ADD_STUDENT
    Для разных команд (например, поменяться местами, очистить чат, а также при регистрации): "Номер ISU"    SWAP_ISU, CLEAR_CHAT, REGISTRATION, DELETE_STUDENT
    Для команд изменения очереди: "название предмета из базы данных"                                        JOIN, EXIT, SHOW, LIST, SWAP, DELETE_SUBJECT
*/

std::mutex m;

Handler::Handler(std::string token) {
    bot = new TgBot::Bot(token);
}

std::string Handler::getAnswer(TgBot::Message::Ptr &message, DataBase &db, TgBot::ReplyKeyboardMarkup::Ptr &mkp) {
    if (message->text == "/help"){
        return "С помощью этого бота можно автоматизировать процесс управления очередями.\n"
               "Вот несколько правил: \n"
               "1. Очередь на каждый предмет обновляется за один день до начала занятия. Это сделано для того, чтобы каждый мог вовремя определиться, готов ли он сдавать лабораторную работу. \n"
               "2. Если возникает необходимость выйти из учетной записи, помните, что все данные о Ваших позициях в очередях будут утеряны. \n"
               "3. Убедительная просьба не входить в учетную запись другого студента. Данные об этом все равно будут получены администратором, а позиции в очередях будут утеряны. Пожалуйста, уважайте друг друга. \n"
               "4. Если Вы договорились поменяться местами с другим студентом, такая возможность существует. (Функция не отлажена в полной мере. Лучше пользоваться ей в случае крайней необходимости, а если используете ее, не вводите, пожалуйста, команды, не указанные на виртуальной клавиатуре. Это может привести к неожиданному поведению и зависанию бота.)\n"
               "5. Также во время занятия можно пропустить свою очередь или сообщить о завершении сдачи лабораторной. Пожалуйста, не забывайте делать это вовремя, чтобы процесс мог идти своим чередом.\n"
               "Спасибо, что пользуетесь нашим ботом!";
    }
    int status = db.getStatus(message->chat->id);
    if (!queryApproval(message, db)){
        mkp = std::make_shared<TgBot::ReplyKeyboardMarkup>(getMarkup(status, db.isAdmin(message->chat->id), db));
        return getRefuseMessage(message, db);
    }
    std::string answer = db.getAnswer(message);
    db.changeStatus(message, status);
    if (db.getStatus(message->chat->id) == Query::WAITING){
        db.sendApproval(message, *bot);
    }
    if (message->text == "Следующий" || message->text == "Пропустить очередь"){
        if (answer == "Сейчас только Вы стоите в очереди по этому предмету.") {
            db.sendQuery("UPDATE " + db.schema + ".students SET query_status = " + std::to_string(Query::BASIC_NOW) + " WHERE chat_id = " + std::to_string(message->chat->id));
        }
        else {
            int next = db.getFirst().first;
            int chat = db.getChat(next);
            int st = db.getStatus(chat);
            if (next != 0) {
                auto newMkp = getMarkup(st, db.isAdmin(chat), db);
                bot->getApi().sendMessage(db.getChat(next), "Ваша позиция в очереди - 1.", false, 0,
                                          std::make_shared<RKMarkup>(newMkp));
            }
        }
    }
    if (answer == "Сейчас только Вы стоите в очереди по этому предмету.") {
        db.sendQuery("UPDATE " + db.schema + ".students SET query_status = " + std::to_string(Query::BASIC_NOW) + " WHERE chat_id = " + std::to_string(message->chat->id));
    }
    mkp = std::make_shared<TgBot::ReplyKeyboardMarkup>(getMarkup(db.getStatus(message->chat->id), db.isAdmin(message->chat->id), db));
    if (message->text == "Подтверждаю" || message->text == "Отмена"){
        int replyChat = db.getReplyChat(message->chat->id);
        bot->getApi().sendMessage(replyChat, answer, false, 0, std::make_shared<RKMarkup>(getMarkup(Query::BASIC, db.isAdmin(replyChat), db)));
        db.sendQuery("UPDATE " + db.schema + ".students SET query_status = " + std::to_string(Query::BASIC) + " WHERE chat_id = " + std::to_string(db.getReplyChat(message->chat->id)));
        db.sendQuery("UPDATE " + db.schema + ".students SET query_status = " + std::to_string(Query::BASIC) + " WHERE chat_id = " + std::to_string(message->chat->id));
        db.sendQuery("DELETE FROM " + db.schema + ".subject_name WHERE chat_id = " + std::to_string(replyChat));
        db.sendQuery("DELETE FROM " + db.schema + ".subject_name WHERE chat_id = " + std::to_string(message->chat->id));
    }
    return answer;
}

bool Handler::queryApproval(TgBot::Message::Ptr &message, DataBase &db) {
    auto valid = valueOf(message->text, db, message->chat->id);
    if (std::find(valid.begin(), valid.end(), db.getStatus(message->chat->id)) != valid.end()){
        return true;
    }
    else{
        return false;
    }
}

std::vector <int> Handler::valueOf(std::string message, DataBase &db, int chat_id) {
    //Проверка обычных команд
    if (message == "Встать в очередь" || message == "Выйти из очереди" || message == "Узнать позицию в очереди"
            || message == "Посмотреть список" || message == "Поменяться местами"){
        if (!db.getData<std::string>("name", "subject").empty())
            return {Query::BASIC, Query::BASIC_NOW};
        else
            return {};
    }
    //Проверка команд для первого в очереди
    if (message == "Следующий" || message == "Пропустить очередь"){
        return {Query::BASIC_NOW};
    }
    //Проверка команд администратора
    if (message == "Добавить предмет" || message == "Удалить предмет" || message == "Добавить студента в группу"
            || message == "Удалить студента из группы" || message == "Очистить чат"){
        if (db.isAdmin(chat_id)){
            return {Query::BASIC, Query::BASIC_NOW};
        }
        else {
            return {};
        }
    }
    if (message == "Подтверждаю" || message == "Отмена"){
        return {Query::ANSWER};
    }
    //Проверка команды, содержащей название предмета
    std::vector <std::string> data1 = db.getData<std::string>("name", "subject");
    if (std::find(data1.begin(), data1.end(), message) != data1.end()){
        if (db.isAdmin(chat_id))
            return {Query::JOIN, Query::EXIT, Query::SHOW, Query::LIST, Query::SWAP, Query::DELETE_SUBJECT};
        else
            return {Query::JOIN, Query::EXIT, Query::SHOW, Query::LIST, Query::SWAP};
    }
    //Проверка стартовой команды
    if (message == "/start"){
        return {Query::BASIC, Query::UNKNOWN, Query::BASIC_NOW};
    }
    //Проверка команды выхода
    if (message == "Выйти"){
        return {Query::BASIC, Query::BASIC_NOW, Query::LIST, Query::SHOW, Query::EXIT, Query::JOIN, Query::SWAP, Query::WAITING,
                Query::SWAP_ISU, Query::ADD_SUBJECT, Query::DELETE_SUBJECT, Query::ADD_STUDENT, Query::DELETE_STUDENT, Query::CLEAR_CHAT};
    }
    //Проверка команды с вводом номера ISU
    std::regex r1("\\d{6}");
    if (std::regex_match(message, r1)) {
        std::vector<int> data2 = db.getData<int>("isu_number", "students");
        if (std::find(data2.begin(), data2.end(), std::stoi(message)) != data2.end()) {
            if (!db.chatIsBusy(std::stoi(message))){
                if (db.isAdmin(chat_id))
                    return {Query::REGISTRATION, Query::DELETE_STUDENT};
                else
                    return {Query::REGISTRATION};
            }
            else{
                if (db.getCommand(chat_id) == "Поменяться местами"){
                    std::string subject = db.tableName(db.getSubjectName(chat_id));
                    auto numbers = db.getData<int>("isu_number", subject);
                    if (std::find(numbers.begin(), numbers.end(), std::stoi(message)) != numbers.end()){
                        return {Query::SWAP_ISU};
                    }
                    else {
                        return {};
                    }
                }
                if (db.isAdmin(chat_id))
                    return {Query::DELETE_STUDENT, Query::CLEAR_CHAT};
                else
                    return {};
            }
        }
    }
    //Проверка для строки, соответствующей добавлению предмета в базу данных
    std::regex r2("([A-Za-zА-Яа-прстуфхцчшщъыьэюяЁё]+\\s+)+(\\d{1,2}[:]\\d{2})\\s+(\\d{1,2}[:]\\d{2})\\s+(четная|нечетная|чётная|нечётная)\\s*");
    if (std::regex_match(message, r2)){
        std::regex day("([Пп]онедельник|[Вв]торник|[Сс]реда|[Чч]етверг|[Пп]ятница|[Сс]уббота)(?=\\s+(\\d{1,2}:\\d{2}\\s+\\d{1,2}:\\d{2})\\s*)");
        std::match_results<std::string::const_iterator> dayMatch;
        if (std::regex_search(message, dayMatch, day)){
            if (db.isAdmin(chat_id)){
                return {Query::ADD_SUBJECT, Query::DELETE_SUBJECT};
            }
            /*std::regex name("([A-Za-zА-Яа-яЁё]+\\s*?)+(?=\\s*" + dayMatch.str() + ")");
            std::match_results<std::string::const_iterator> nameMatch;
            std::regex_search(message, nameMatch, name);
            std::regex time("\\d{1,2}:\\d{2}");
            std::match_results<std::string::const_iterator> timeMatch;
            std::regex_search(message, timeMatch, time);
            std::string */
        }
    }
    //Проверка для строки, соответствующей добавлению студента в базу данных
    std::regex r3("([А-Я]{2}[а-прстуфхцчшщъыьэюя]+(-[А-Я]{2}[а-прстуфхцчшщъыьэюя]+)?)\\s+([А-Я]{2}[а-прстуфхцчшщъыьэюя]+\\s+){1,2}\\d{6}\\s*(admin)?");
    if (std::regex_match(message, r3)){
        if (db.isAdmin(chat_id)){
            return {ADD_STUDENT};
        }
    }
    //Если строка не соответствует ни одному из предыдущих шаблонов
    return {};
}

std::string Handler::getRefuseMessage(TgBot::Message::Ptr &message, DataBase &db) {
    if (db.getStatus(message->chat->id) == Query::UNKNOWN){
        return "Для дальнейшей работы необходимо зарегистрироваться. Введите команду /start.";
    }
    std::regex r1("\\d{6}");
    if (std::regex_match(message->text, r1)){
        if (db.getStatus(message->chat->id) != Query::REGISTRATION && db.getStatus(message->chat->id) != Query::DELETE_STUDENT
            && db.getStatus(message->chat->id) != Query::SWAP_ISU && db.getStatus(message->chat->id) != Query::CLEAR_CHAT){
            return "Команда не найдена.";
        }
        if (db.getStatus(message->chat->id) == Query::REGISTRATION){
            if (db.findUser(std::stoi(message->text)))
                return "Данный пользователь уже зарегистрирован в системе. Обратитесь к администратору, чтобы решить проблему.";
            else
                return "Пользователь не найден. Убедитесь в правильности ввода.";
        }
        else{
            if (db.findUser(std::stoi(message->text))){
                if (db.chatIsBusy(std::stoi(message->text)))
                    return "К сожалению, я не могу распознать Вашу команду. Пожалуйста, попробуйте снова.";
                else
                    return "Пользователь не зарегистрирован в системе.";
            }
            else{
                return "Пользователь не найден. Убедитесь в правильности ввода.";
            }
        }
    }
    if (db.getStatus(message->chat->id) == Query::REGISTRATION){
        return "Пожалуйста, завершите регистрацию.";
    }
    //Базовый запрос может не быть вызван только по одной причине - статус пользователя не BASIC или BASIC_NOW
    if (message->text == "Встать в очередь" || message->text == "Выйти из очереди" || message->text == "Узнать позицию в очереди"
        || message->text == "Посмотреть список" || message->text == "Поменяться местами"){
        if (!db.getData<std::string>("name", "subject").empty())
            return "В данный момент невозможно выполнить запрос. Пожалуйста, завершите предыдущий и попробуйте снова.";
        else
            return "К сожалению, в базе данных сейчас нет доступных очередей. Пожалуйста, обратитесь к администратору.";
    }
    //Команды администратора могут не быть вызваны по двум причинам - не хватает прав или неправильный статус пользователя
    if (message->text == "Добавить предмет" || message->text == "Удалить предмет" || message->text == "Добавить студента в группу"
        || message->text == "Удалить студента из группы" || message->text == "Очистить чат"){
        if (db.getStatus(message->chat->id) == Query::BASIC || db.getStatus(message->chat->id) == Query::BASIC_NOW){
            return "Недостаточно прав для выполнения запроса.";
        }
        else{
            return "В данный момент невозможно выполнить запрос. Пожалуйста, завершите предыдущий и попробуйте снова.";
        }
    }
    std::regex r2("([A-Za-zА-Яа-прстуфхцчшщъыьэюяЁё]+\\s+)+(\\d{1,2}[.\\/:]\\d{2}\\s*){2}\\s*");
    if (std::regex_match(message->text, r2)){
        std::regex day("([Пп]онедельник|[Вв]торник|[Сс]реда|[Чч]етверг|[Пп]ятница|[Сс]уббота)(?=\\s+(\\d{1,2}:\\d{2}\\s+\\d{1,2}:\\d{2}))");
        if (std::regex_search(message->text, day)){
            return "К сожалению, я не могу распознать Вашу команду. Пожалуйста, попробуйте снова.";
        }
    }
    std::vector <std::string> data1 = db.getData<std::string>("name", "subject");
    if (std::find(data1.begin(), data1.end(), message->text) != data1.end()){
        return "К сожалению, я не могу распознать Вашу команду. Пожалуйста, попробуйте снова.";
    }



    int status = db.getStatus(message->chat->id);
    if (status == Query::UNKNOWN){
        return "Для дальнейшей работы необходимо зарегистрироваться. Введите команду /start.";
    }
    if (status == Query::REGISTRATION){
        return "К сожалению, я не смог найти Вас в базе группы. Пожалуйста, проверьте правильность ввода или обратитесь к администратору.";
    }
    if (status == Query::ADD_SUBJECT || status == Query::DELETE_SUBJECT){
        return "Некорректный ввод. Пожалуйста, попробуйте снова.";
    }
    if (status != Query::BASIC){
        return "К сожалению, Ваш запрос сейчас не может быть обработан. Пожалуйста, завершите предыдущий и попробуйте снова.";
    }
    return "К сожалению, я не могу распознать Вашу команду. Пожалуйста, попробуйте снова.";
}

TgBot::ReplyKeyboardMarkup Handler::getMarkup(int currentStatus, bool admin, DataBase db) {
    RKMarkup mkp;
    if (currentStatus == Query::UNKNOWN){
        //KButton::Ptr start = std::make_shared<KButton> (KButton());
        //start->text = "/start";
        //mkp.keyboard.push_back({start});
        return mkp;
    }
    if (currentStatus == Query::REGISTRATION){
        return mkp;
    }
    KButton::Ptr exit = std::make_shared<KButton> (KButton());
    exit->text = "Выйти";
    if (currentStatus == Query::ANSWER){
        KButton::Ptr ap = std::make_shared<KButton> (KButton());
        ap->text = "Подтверждаю";
        KButton::Ptr nap = std::make_shared<KButton> (KButton());
        nap->text = "Отмена";
        mkp.keyboard.push_back({ap});
        mkp.keyboard.push_back({nap});
        return mkp;
    }
    if (currentStatus == BASIC_NOW){
        mkp = getMarkup(Query::BASIC, admin, db);
        KButton::Ptr next = std::make_shared<KButton>(KButton());
        KButton::Ptr miss = std::make_shared<KButton>(KButton());
        next->text = "Следующий";
        miss->text = "Пропустить очередь";
        mkp.keyboard.insert(mkp.keyboard.begin(), {miss});
        mkp.keyboard.insert(mkp.keyboard.begin(), {next});
        return mkp;
    }
    if (currentStatus == Query::BASIC) {
        KButton::Ptr join = std::make_shared<KButton>(KButton());
        KButton::Ptr leave = std::make_shared<KButton>(KButton());
        KButton::Ptr get = std::make_shared<KButton>(KButton());
        KButton::Ptr view = std::make_shared<KButton>(KButton());
        KButton::Ptr swap = std::make_shared<KButton>(KButton());
        KButton::Ptr addSub = std::make_shared<KButton>(KButton());
        KButton::Ptr delSub = std::make_shared<KButton>(KButton());
        KButton::Ptr addStud = std::make_shared<KButton>(KButton());
        KButton::Ptr delStud = std::make_shared<KButton>(KButton());
        KButton::Ptr clear = std::make_shared<KButton>(KButton());
        join->text = "Встать в очередь";
        leave->text = "Выйти из очереди";
        get->text = "Узнать позицию в очереди";
        view->text = "Посмотреть список";
        swap->text = "Поменяться местами";
        addSub->text = "Добавить предмет";
        delSub->text = "Удалить предмет";
        addStud->text = "Добавить студента в группу";
        delStud->text = "Удалить студента из группы";
        clear->text = "Очистить чат";
        mkp.keyboard.push_back({join, leave});
        mkp.keyboard.push_back({get});
        mkp.keyboard.push_back({view});
        mkp.keyboard.push_back({swap});
        if (admin) {
            mkp.keyboard.push_back({addSub, delSub});
            mkp.keyboard.push_back({addStud, delStud});
            mkp.keyboard.push_back({clear});
        }
    }
    if (currentStatus == Query::SWAP || currentStatus == Query::SHOW || currentStatus == Query::LIST || currentStatus == Query::JOIN ||
                currentStatus == Query::EXIT || currentStatus == Query::DELETE_SUBJECT){
        std::vector <std::string> data = db.getData<std::string>("name", "subject");
        int n = 2;
        for (auto i = 0; i < data.size() / n; i++){
            std::vector <KButton::Ptr> keyboard;
            for (auto j = 0; j < n; j++){
                KButton::Ptr button = std::make_shared<KButton>(KButton());
                button->text = data[i * n + j];
                keyboard.push_back(button);
            }
            /*
            KButton::Ptr b1 = std::make_shared<KButton>(KButton());
            KButton::Ptr b2 = std::make_shared<KButton>(KButton());
            KButton::Ptr b3 = std::make_shared<KButton>(KButton());
            b1->text = data[i * n];
            b2->text = data[i * n + 1];
            b3->text = data[i * n + 2];*/
            mkp.keyboard.push_back(keyboard);
        }
        int j = data.size() % n;
        std::vector <KButton::Ptr> b = {};
        for (auto i = 0; i < j; i++){
            KButton::Ptr a = std::make_shared<KButton>(KButton());
            a->text = data[(data.size() / n) * n + i];
            b.push_back(a);
        }
        if (!b.empty())
            mkp.keyboard.push_back(b);
    }
    mkp.keyboard.push_back({exit});
    return mkp;
}

RKMarkup Handler::getNowMurkup(DataBase &db) {

}

void Handler::notifyFirst(DataBase &db, int &lastFirst) {
    if (lastFirst != 0){
        return;
    }
    m.lock();
    auto first = db.getFirst();
    int isu = first.first;
    if (isu == 0){
        m.unlock();
        return;
    }
    if (db.getStatus(db.getChat(isu)) == BASIC_NOW){
        m.unlock();
        return;
    }
    m.unlock();
    while(true) {
        m.lock();
        if (db.getStatus(db.getChat(isu)) == BASIC) {
            db.updateValue("query_status", "students", "WHERE isu_number = " + std::to_string(isu), int(Query::BASIC_NOW));
            m.unlock();
            break;
        }
        m.unlock();
    }
    //int messageId = db.getValue<int>("last_message_id", "students", "WHERE isu_number = " + std::to_string(isu));
    m.lock();
    int chat = db.getChat(isu);
    m.unlock();
    bot->getApi().sendMessage(chat, "Занятие началось. Ваша позиция в очереди - 1.", false, 0, std::make_shared<RKMarkup>(getMarkup(Query::BASIC_NOW, db.isAdmin(db.getChat(isu)), db)));
    //m.unlock();
}

void Handler::stopNotifying(DataBase &db, int isu) {
    m.lock();
    if (db.getStatus(db.getChat(isu)) == Query::BASIC_NOW){
        bot->getApi().sendMessage(db.getChat(isu), "Занятие завершено.", false, 0, std::make_shared<RKMarkup>(getMarkup(Query::BASIC, db.isAdmin(db.getChat(isu)), db)));
    }
    return;
    while(true) {
        m.lock();
        if (db.getValue<int>("query_status", "students", "WHERE isu_number = " + std::to_string(isu)) ==
            Query::BASIC_NOW) {
            int messageId = db.getValue<int>("last_message_id", "students", "WHERE isu_number = " + std::to_string(isu));
            db.updateValue("query_status", "students", "WHERE isu_number = " + std::to_string(isu), int(Query::BASIC));
            if (db.getFirst().first == 0)
                bot->getApi().sendMessage(db.getChat(isu), "Занятие завершено.", false, 0, std::make_shared<RKMarkup>(getMarkup(Query::BASIC, db.isAdmin(db.getChat(isu)), db)));
            else
                bot->getApi().sendMessage(db.getChat(isu), "Ваша очередь еще не подошла...", false, 0, std::make_shared<RKMarkup>(getMarkup(Query::BASIC, db.isAdmin(db.getChat(isu)), db)));
            m.unlock();
            break;
        }
        m.unlock();
    }
}
