cmake_minimum_required(VERSION 3.24)
project(TelegramBot)

set(CMAKE_CXX_STANDARD 20)
message(STATUS ${CMAKE_CXX_STANDARD})

set(OPENSSL_ROOT_DIR /Users/anastasiapronina/OpenSSL)
set(OPENSSL_LIBRARIES /Users/anastasiapronina/OpenSSL/lib)
set(OPENSSL_INCLUDE_DIR /Users/anastasiapronina/OpenSSL/include)
set(OPENSSL_CRYPTO_LIBRARY /Users/anastasiapronina/OpenSSL/lib/libcrypto.a)
set(OPENSSL_SSL_LIBRARY /Users/anastasiapronina/OpenSSL/lib/libssl.a)

set(Boost_INCLUDE_DIR /opt/homebrew/Cellar/boost/1.80.0/include)
set(Boost_LIBRARY_DIR /opt/homebrew/Cellar/boost/1.80.0/lib)

set(SOCI_POSTGRESQL ON)
set(WITH_POSTGRESQL ON)
set(POSTGRESQL_INCLUDE_DIR /Library/PostgreSQL/15/include)
set(POSTGRESQL_LIBRARY /Library/PostgreSQL/15/lib/libpq.a)

find_package(OpenSSL REQUIRED)
find_package(Boost COMPONENTS system REQUIRED)

include_directories(${OPENSSL_INCLUDE_DIR})

add_executable(TelegramBot main.cpp include/DataBase.h src/DataBase.cpp include/Queries.h include/BotHandling.h src/BotHandling.cpp)

include_directories(${Boost_INCLUDE_DIR} /Library/PostgreSQL/15/include)
link_directories(${Boost_LIBRARY_DIR})

add_subdirectory(tgbot-cpp)
add_subdirectory(Soci)

set_property(TARGET TelegramBot PROPERTY CXX_STANDARD 20 CXX_STANDARD_REQUIRED 20)

target_link_libraries(${PROJECT_NAME}
        PRIVATE
        OpenSSL::SSL
        OpenSSL::Crypto
        TgBot
        Soci::core_static
        Soci::postgresql_static
        /opt/homebrew/Cellar/libpq/15.1/lib/libpq.a
        /opt/homebrew/Cellar/libpq/15.1/lib/libpgcommon.a
        /opt/homebrew/Cellar/libpq/15.1/lib/libpgport.a
        /Users/anastasiapronina/gss/lib/libgss.a
        )


