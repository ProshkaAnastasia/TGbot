# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/anastasiapronina/C++Projects/TelegramBot

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/anastasiapronina/C++Projects/TelegramBot/cmake-build-debug

# Include any dependencies generated for this target.
include Soci/tests/odbc/CMakeFiles/soci_odbc_test_mysql.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Soci/tests/odbc/CMakeFiles/soci_odbc_test_mysql.dir/compiler_depend.make

# Include the progress variables for this target.
include Soci/tests/odbc/CMakeFiles/soci_odbc_test_mysql.dir/progress.make

# Include the compile flags for this target's objects.
include Soci/tests/odbc/CMakeFiles/soci_odbc_test_mysql.dir/flags.make

Soci/tests/odbc/CMakeFiles/soci_odbc_test_mysql.dir/test-odbc-mysql.cpp.o: Soci/tests/odbc/CMakeFiles/soci_odbc_test_mysql.dir/flags.make
Soci/tests/odbc/CMakeFiles/soci_odbc_test_mysql.dir/test-odbc-mysql.cpp.o: /Users/anastasiapronina/C++Projects/TelegramBot/Soci/tests/odbc/test-odbc-mysql.cpp
Soci/tests/odbc/CMakeFiles/soci_odbc_test_mysql.dir/test-odbc-mysql.cpp.o: Soci/tests/odbc/CMakeFiles/soci_odbc_test_mysql.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/anastasiapronina/C++Projects/TelegramBot/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Soci/tests/odbc/CMakeFiles/soci_odbc_test_mysql.dir/test-odbc-mysql.cpp.o"
	cd /Users/anastasiapronina/C++Projects/TelegramBot/cmake-build-debug/Soci/tests/odbc && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Soci/tests/odbc/CMakeFiles/soci_odbc_test_mysql.dir/test-odbc-mysql.cpp.o -MF CMakeFiles/soci_odbc_test_mysql.dir/test-odbc-mysql.cpp.o.d -o CMakeFiles/soci_odbc_test_mysql.dir/test-odbc-mysql.cpp.o -c /Users/anastasiapronina/C++Projects/TelegramBot/Soci/tests/odbc/test-odbc-mysql.cpp

Soci/tests/odbc/CMakeFiles/soci_odbc_test_mysql.dir/test-odbc-mysql.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/soci_odbc_test_mysql.dir/test-odbc-mysql.cpp.i"
	cd /Users/anastasiapronina/C++Projects/TelegramBot/cmake-build-debug/Soci/tests/odbc && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/anastasiapronina/C++Projects/TelegramBot/Soci/tests/odbc/test-odbc-mysql.cpp > CMakeFiles/soci_odbc_test_mysql.dir/test-odbc-mysql.cpp.i

Soci/tests/odbc/CMakeFiles/soci_odbc_test_mysql.dir/test-odbc-mysql.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/soci_odbc_test_mysql.dir/test-odbc-mysql.cpp.s"
	cd /Users/anastasiapronina/C++Projects/TelegramBot/cmake-build-debug/Soci/tests/odbc && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/anastasiapronina/C++Projects/TelegramBot/Soci/tests/odbc/test-odbc-mysql.cpp -o CMakeFiles/soci_odbc_test_mysql.dir/test-odbc-mysql.cpp.s

# Object files for target soci_odbc_test_mysql
soci_odbc_test_mysql_OBJECTS = \
"CMakeFiles/soci_odbc_test_mysql.dir/test-odbc-mysql.cpp.o"

# External object files for target soci_odbc_test_mysql
soci_odbc_test_mysql_EXTERNAL_OBJECTS =

bin/soci_odbc_test_mysql: Soci/tests/odbc/CMakeFiles/soci_odbc_test_mysql.dir/test-odbc-mysql.cpp.o
bin/soci_odbc_test_mysql: Soci/tests/odbc/CMakeFiles/soci_odbc_test_mysql.dir/build.make
bin/soci_odbc_test_mysql: /Library/Developer/CommandLineTools/SDKs/MacOSX12.3.sdk/usr/lib/libdl.tbd
bin/soci_odbc_test_mysql: /Library/Developer/CommandLineTools/SDKs/MacOSX12.3.sdk/usr/lib/libiodbc.tbd
bin/soci_odbc_test_mysql: lib/libsoci_odbc.4.1.0.dylib
bin/soci_odbc_test_mysql: /Library/Developer/CommandLineTools/SDKs/MacOSX12.3.sdk/usr/lib/libiodbc.tbd
bin/soci_odbc_test_mysql: lib/libsoci_core.4.1.0.dylib
bin/soci_odbc_test_mysql: /Library/Developer/CommandLineTools/SDKs/MacOSX12.3.sdk/usr/lib/libdl.tbd
bin/soci_odbc_test_mysql: /opt/homebrew/lib/libboost_date_time-mt.dylib
bin/soci_odbc_test_mysql: Soci/tests/odbc/CMakeFiles/soci_odbc_test_mysql.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/anastasiapronina/C++Projects/TelegramBot/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../../bin/soci_odbc_test_mysql"
	cd /Users/anastasiapronina/C++Projects/TelegramBot/cmake-build-debug/Soci/tests/odbc && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/soci_odbc_test_mysql.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Soci/tests/odbc/CMakeFiles/soci_odbc_test_mysql.dir/build: bin/soci_odbc_test_mysql
.PHONY : Soci/tests/odbc/CMakeFiles/soci_odbc_test_mysql.dir/build

Soci/tests/odbc/CMakeFiles/soci_odbc_test_mysql.dir/clean:
	cd /Users/anastasiapronina/C++Projects/TelegramBot/cmake-build-debug/Soci/tests/odbc && $(CMAKE_COMMAND) -P CMakeFiles/soci_odbc_test_mysql.dir/cmake_clean.cmake
.PHONY : Soci/tests/odbc/CMakeFiles/soci_odbc_test_mysql.dir/clean

Soci/tests/odbc/CMakeFiles/soci_odbc_test_mysql.dir/depend:
	cd /Users/anastasiapronina/C++Projects/TelegramBot/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/anastasiapronina/C++Projects/TelegramBot /Users/anastasiapronina/C++Projects/TelegramBot/Soci/tests/odbc /Users/anastasiapronina/C++Projects/TelegramBot/cmake-build-debug /Users/anastasiapronina/C++Projects/TelegramBot/cmake-build-debug/Soci/tests/odbc /Users/anastasiapronina/C++Projects/TelegramBot/cmake-build-debug/Soci/tests/odbc/CMakeFiles/soci_odbc_test_mysql.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Soci/tests/odbc/CMakeFiles/soci_odbc_test_mysql.dir/depend

