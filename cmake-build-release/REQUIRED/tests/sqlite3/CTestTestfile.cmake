# CMake generated Testfile for 
# Source directory: /Users/anastasiapronina/C++Projects/TelegramBot/Soci/tests/sqlite3
# Build directory: /Users/anastasiapronina/C++Projects/TelegramBot/cmake-build-release/REQUIRED/tests/sqlite3
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test([=[soci_sqlite3_test]=] "/Users/anastasiapronina/C++Projects/TelegramBot/cmake-build-release/bin/soci_sqlite3_test" ":memory:" "--invisibles")
set_tests_properties([=[soci_sqlite3_test]=] PROPERTIES  _BACKTRACE_TRIPLES "/Users/anastasiapronina/C++Projects/TelegramBot/Soci/cmake/SociBackend.cmake;349;add_test;/Users/anastasiapronina/C++Projects/TelegramBot/Soci/tests/sqlite3/CMakeLists.txt;12;soci_backend_test;/Users/anastasiapronina/C++Projects/TelegramBot/Soci/tests/sqlite3/CMakeLists.txt;0;")
add_test([=[soci_sqlite3_test_static]=] "/Users/anastasiapronina/C++Projects/TelegramBot/cmake-build-release/bin/soci_sqlite3_test_static" ":memory:" "--invisibles")
set_tests_properties([=[soci_sqlite3_test_static]=] PROPERTIES  _BACKTRACE_TRIPLES "/Users/anastasiapronina/C++Projects/TelegramBot/Soci/cmake/SociBackend.cmake;371;add_test;/Users/anastasiapronina/C++Projects/TelegramBot/Soci/tests/sqlite3/CMakeLists.txt;12;soci_backend_test;/Users/anastasiapronina/C++Projects/TelegramBot/Soci/tests/sqlite3/CMakeLists.txt;0;")
