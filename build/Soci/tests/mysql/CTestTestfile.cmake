# CMake generated Testfile for 
# Source directory: /Users/anastasiapronina/C++Projects/TelegramBot/Soci/tests/mysql
# Build directory: /Users/anastasiapronina/C++Projects/TelegramBot/build/Soci/tests/mysql
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test([=[soci_mysql_test]=] "/Users/anastasiapronina/C++Projects/TelegramBot/build/bin/soci_mysql_test" "db=soci_test" "--invisibles")
set_tests_properties([=[soci_mysql_test]=] PROPERTIES  _BACKTRACE_TRIPLES "/Users/anastasiapronina/C++Projects/TelegramBot/Soci/cmake/SociBackend.cmake;349;add_test;/Users/anastasiapronina/C++Projects/TelegramBot/Soci/tests/mysql/CMakeLists.txt;12;soci_backend_test;/Users/anastasiapronina/C++Projects/TelegramBot/Soci/tests/mysql/CMakeLists.txt;0;")
add_test([=[soci_mysql_test_static]=] "/Users/anastasiapronina/C++Projects/TelegramBot/build/bin/soci_mysql_test_static" "db=soci_test" "--invisibles")
set_tests_properties([=[soci_mysql_test_static]=] PROPERTIES  _BACKTRACE_TRIPLES "/Users/anastasiapronina/C++Projects/TelegramBot/Soci/cmake/SociBackend.cmake;371;add_test;/Users/anastasiapronina/C++Projects/TelegramBot/Soci/tests/mysql/CMakeLists.txt;12;soci_backend_test;/Users/anastasiapronina/C++Projects/TelegramBot/Soci/tests/mysql/CMakeLists.txt;0;")
