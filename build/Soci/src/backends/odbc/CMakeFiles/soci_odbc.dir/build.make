# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.29.3/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.29.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/anastasiapronina/C++Projects/TelegramBot

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/anastasiapronina/C++Projects/TelegramBot/build

# Include any dependencies generated for this target.
include Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/compiler_depend.make

# Include the progress variables for this target.
include Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/progress.make

# Include the compile flags for this target's objects.
include Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/flags.make

Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/blob.cpp.o: Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/flags.make
Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/blob.cpp.o: /Users/anastasiapronina/C++Projects/TelegramBot/Soci/src/backends/odbc/blob.cpp
Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/blob.cpp.o: Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/anastasiapronina/C++Projects/TelegramBot/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/blob.cpp.o"
	cd /Users/anastasiapronina/C++Projects/TelegramBot/build/Soci/src/backends/odbc && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/blob.cpp.o -MF CMakeFiles/soci_odbc.dir/blob.cpp.o.d -o CMakeFiles/soci_odbc.dir/blob.cpp.o -c /Users/anastasiapronina/C++Projects/TelegramBot/Soci/src/backends/odbc/blob.cpp

Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/blob.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/soci_odbc.dir/blob.cpp.i"
	cd /Users/anastasiapronina/C++Projects/TelegramBot/build/Soci/src/backends/odbc && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/anastasiapronina/C++Projects/TelegramBot/Soci/src/backends/odbc/blob.cpp > CMakeFiles/soci_odbc.dir/blob.cpp.i

Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/blob.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/soci_odbc.dir/blob.cpp.s"
	cd /Users/anastasiapronina/C++Projects/TelegramBot/build/Soci/src/backends/odbc && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/anastasiapronina/C++Projects/TelegramBot/Soci/src/backends/odbc/blob.cpp -o CMakeFiles/soci_odbc.dir/blob.cpp.s

Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/factory.cpp.o: Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/flags.make
Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/factory.cpp.o: /Users/anastasiapronina/C++Projects/TelegramBot/Soci/src/backends/odbc/factory.cpp
Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/factory.cpp.o: Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/anastasiapronina/C++Projects/TelegramBot/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/factory.cpp.o"
	cd /Users/anastasiapronina/C++Projects/TelegramBot/build/Soci/src/backends/odbc && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/factory.cpp.o -MF CMakeFiles/soci_odbc.dir/factory.cpp.o.d -o CMakeFiles/soci_odbc.dir/factory.cpp.o -c /Users/anastasiapronina/C++Projects/TelegramBot/Soci/src/backends/odbc/factory.cpp

Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/factory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/soci_odbc.dir/factory.cpp.i"
	cd /Users/anastasiapronina/C++Projects/TelegramBot/build/Soci/src/backends/odbc && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/anastasiapronina/C++Projects/TelegramBot/Soci/src/backends/odbc/factory.cpp > CMakeFiles/soci_odbc.dir/factory.cpp.i

Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/factory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/soci_odbc.dir/factory.cpp.s"
	cd /Users/anastasiapronina/C++Projects/TelegramBot/build/Soci/src/backends/odbc && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/anastasiapronina/C++Projects/TelegramBot/Soci/src/backends/odbc/factory.cpp -o CMakeFiles/soci_odbc.dir/factory.cpp.s

Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/row-id.cpp.o: Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/flags.make
Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/row-id.cpp.o: /Users/anastasiapronina/C++Projects/TelegramBot/Soci/src/backends/odbc/row-id.cpp
Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/row-id.cpp.o: Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/anastasiapronina/C++Projects/TelegramBot/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/row-id.cpp.o"
	cd /Users/anastasiapronina/C++Projects/TelegramBot/build/Soci/src/backends/odbc && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/row-id.cpp.o -MF CMakeFiles/soci_odbc.dir/row-id.cpp.o.d -o CMakeFiles/soci_odbc.dir/row-id.cpp.o -c /Users/anastasiapronina/C++Projects/TelegramBot/Soci/src/backends/odbc/row-id.cpp

Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/row-id.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/soci_odbc.dir/row-id.cpp.i"
	cd /Users/anastasiapronina/C++Projects/TelegramBot/build/Soci/src/backends/odbc && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/anastasiapronina/C++Projects/TelegramBot/Soci/src/backends/odbc/row-id.cpp > CMakeFiles/soci_odbc.dir/row-id.cpp.i

Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/row-id.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/soci_odbc.dir/row-id.cpp.s"
	cd /Users/anastasiapronina/C++Projects/TelegramBot/build/Soci/src/backends/odbc && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/anastasiapronina/C++Projects/TelegramBot/Soci/src/backends/odbc/row-id.cpp -o CMakeFiles/soci_odbc.dir/row-id.cpp.s

Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/session.cpp.o: Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/flags.make
Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/session.cpp.o: /Users/anastasiapronina/C++Projects/TelegramBot/Soci/src/backends/odbc/session.cpp
Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/session.cpp.o: Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/anastasiapronina/C++Projects/TelegramBot/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/session.cpp.o"
	cd /Users/anastasiapronina/C++Projects/TelegramBot/build/Soci/src/backends/odbc && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/session.cpp.o -MF CMakeFiles/soci_odbc.dir/session.cpp.o.d -o CMakeFiles/soci_odbc.dir/session.cpp.o -c /Users/anastasiapronina/C++Projects/TelegramBot/Soci/src/backends/odbc/session.cpp

Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/session.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/soci_odbc.dir/session.cpp.i"
	cd /Users/anastasiapronina/C++Projects/TelegramBot/build/Soci/src/backends/odbc && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/anastasiapronina/C++Projects/TelegramBot/Soci/src/backends/odbc/session.cpp > CMakeFiles/soci_odbc.dir/session.cpp.i

Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/session.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/soci_odbc.dir/session.cpp.s"
	cd /Users/anastasiapronina/C++Projects/TelegramBot/build/Soci/src/backends/odbc && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/anastasiapronina/C++Projects/TelegramBot/Soci/src/backends/odbc/session.cpp -o CMakeFiles/soci_odbc.dir/session.cpp.s

Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/standard-into-type.cpp.o: Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/flags.make
Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/standard-into-type.cpp.o: /Users/anastasiapronina/C++Projects/TelegramBot/Soci/src/backends/odbc/standard-into-type.cpp
Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/standard-into-type.cpp.o: Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/anastasiapronina/C++Projects/TelegramBot/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/standard-into-type.cpp.o"
	cd /Users/anastasiapronina/C++Projects/TelegramBot/build/Soci/src/backends/odbc && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/standard-into-type.cpp.o -MF CMakeFiles/soci_odbc.dir/standard-into-type.cpp.o.d -o CMakeFiles/soci_odbc.dir/standard-into-type.cpp.o -c /Users/anastasiapronina/C++Projects/TelegramBot/Soci/src/backends/odbc/standard-into-type.cpp

Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/standard-into-type.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/soci_odbc.dir/standard-into-type.cpp.i"
	cd /Users/anastasiapronina/C++Projects/TelegramBot/build/Soci/src/backends/odbc && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/anastasiapronina/C++Projects/TelegramBot/Soci/src/backends/odbc/standard-into-type.cpp > CMakeFiles/soci_odbc.dir/standard-into-type.cpp.i

Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/standard-into-type.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/soci_odbc.dir/standard-into-type.cpp.s"
	cd /Users/anastasiapronina/C++Projects/TelegramBot/build/Soci/src/backends/odbc && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/anastasiapronina/C++Projects/TelegramBot/Soci/src/backends/odbc/standard-into-type.cpp -o CMakeFiles/soci_odbc.dir/standard-into-type.cpp.s

Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/standard-use-type.cpp.o: Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/flags.make
Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/standard-use-type.cpp.o: /Users/anastasiapronina/C++Projects/TelegramBot/Soci/src/backends/odbc/standard-use-type.cpp
Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/standard-use-type.cpp.o: Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/anastasiapronina/C++Projects/TelegramBot/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/standard-use-type.cpp.o"
	cd /Users/anastasiapronina/C++Projects/TelegramBot/build/Soci/src/backends/odbc && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/standard-use-type.cpp.o -MF CMakeFiles/soci_odbc.dir/standard-use-type.cpp.o.d -o CMakeFiles/soci_odbc.dir/standard-use-type.cpp.o -c /Users/anastasiapronina/C++Projects/TelegramBot/Soci/src/backends/odbc/standard-use-type.cpp

Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/standard-use-type.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/soci_odbc.dir/standard-use-type.cpp.i"
	cd /Users/anastasiapronina/C++Projects/TelegramBot/build/Soci/src/backends/odbc && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/anastasiapronina/C++Projects/TelegramBot/Soci/src/backends/odbc/standard-use-type.cpp > CMakeFiles/soci_odbc.dir/standard-use-type.cpp.i

Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/standard-use-type.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/soci_odbc.dir/standard-use-type.cpp.s"
	cd /Users/anastasiapronina/C++Projects/TelegramBot/build/Soci/src/backends/odbc && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/anastasiapronina/C++Projects/TelegramBot/Soci/src/backends/odbc/standard-use-type.cpp -o CMakeFiles/soci_odbc.dir/standard-use-type.cpp.s

Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/statement.cpp.o: Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/flags.make
Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/statement.cpp.o: /Users/anastasiapronina/C++Projects/TelegramBot/Soci/src/backends/odbc/statement.cpp
Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/statement.cpp.o: Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/anastasiapronina/C++Projects/TelegramBot/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/statement.cpp.o"
	cd /Users/anastasiapronina/C++Projects/TelegramBot/build/Soci/src/backends/odbc && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/statement.cpp.o -MF CMakeFiles/soci_odbc.dir/statement.cpp.o.d -o CMakeFiles/soci_odbc.dir/statement.cpp.o -c /Users/anastasiapronina/C++Projects/TelegramBot/Soci/src/backends/odbc/statement.cpp

Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/statement.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/soci_odbc.dir/statement.cpp.i"
	cd /Users/anastasiapronina/C++Projects/TelegramBot/build/Soci/src/backends/odbc && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/anastasiapronina/C++Projects/TelegramBot/Soci/src/backends/odbc/statement.cpp > CMakeFiles/soci_odbc.dir/statement.cpp.i

Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/statement.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/soci_odbc.dir/statement.cpp.s"
	cd /Users/anastasiapronina/C++Projects/TelegramBot/build/Soci/src/backends/odbc && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/anastasiapronina/C++Projects/TelegramBot/Soci/src/backends/odbc/statement.cpp -o CMakeFiles/soci_odbc.dir/statement.cpp.s

Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/vector-into-type.cpp.o: Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/flags.make
Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/vector-into-type.cpp.o: /Users/anastasiapronina/C++Projects/TelegramBot/Soci/src/backends/odbc/vector-into-type.cpp
Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/vector-into-type.cpp.o: Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/anastasiapronina/C++Projects/TelegramBot/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/vector-into-type.cpp.o"
	cd /Users/anastasiapronina/C++Projects/TelegramBot/build/Soci/src/backends/odbc && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/vector-into-type.cpp.o -MF CMakeFiles/soci_odbc.dir/vector-into-type.cpp.o.d -o CMakeFiles/soci_odbc.dir/vector-into-type.cpp.o -c /Users/anastasiapronina/C++Projects/TelegramBot/Soci/src/backends/odbc/vector-into-type.cpp

Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/vector-into-type.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/soci_odbc.dir/vector-into-type.cpp.i"
	cd /Users/anastasiapronina/C++Projects/TelegramBot/build/Soci/src/backends/odbc && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/anastasiapronina/C++Projects/TelegramBot/Soci/src/backends/odbc/vector-into-type.cpp > CMakeFiles/soci_odbc.dir/vector-into-type.cpp.i

Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/vector-into-type.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/soci_odbc.dir/vector-into-type.cpp.s"
	cd /Users/anastasiapronina/C++Projects/TelegramBot/build/Soci/src/backends/odbc && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/anastasiapronina/C++Projects/TelegramBot/Soci/src/backends/odbc/vector-into-type.cpp -o CMakeFiles/soci_odbc.dir/vector-into-type.cpp.s

Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/vector-use-type.cpp.o: Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/flags.make
Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/vector-use-type.cpp.o: /Users/anastasiapronina/C++Projects/TelegramBot/Soci/src/backends/odbc/vector-use-type.cpp
Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/vector-use-type.cpp.o: Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/anastasiapronina/C++Projects/TelegramBot/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/vector-use-type.cpp.o"
	cd /Users/anastasiapronina/C++Projects/TelegramBot/build/Soci/src/backends/odbc && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/vector-use-type.cpp.o -MF CMakeFiles/soci_odbc.dir/vector-use-type.cpp.o.d -o CMakeFiles/soci_odbc.dir/vector-use-type.cpp.o -c /Users/anastasiapronina/C++Projects/TelegramBot/Soci/src/backends/odbc/vector-use-type.cpp

Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/vector-use-type.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/soci_odbc.dir/vector-use-type.cpp.i"
	cd /Users/anastasiapronina/C++Projects/TelegramBot/build/Soci/src/backends/odbc && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/anastasiapronina/C++Projects/TelegramBot/Soci/src/backends/odbc/vector-use-type.cpp > CMakeFiles/soci_odbc.dir/vector-use-type.cpp.i

Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/vector-use-type.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/soci_odbc.dir/vector-use-type.cpp.s"
	cd /Users/anastasiapronina/C++Projects/TelegramBot/build/Soci/src/backends/odbc && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/anastasiapronina/C++Projects/TelegramBot/Soci/src/backends/odbc/vector-use-type.cpp -o CMakeFiles/soci_odbc.dir/vector-use-type.cpp.s

# Object files for target soci_odbc
soci_odbc_OBJECTS = \
"CMakeFiles/soci_odbc.dir/blob.cpp.o" \
"CMakeFiles/soci_odbc.dir/factory.cpp.o" \
"CMakeFiles/soci_odbc.dir/row-id.cpp.o" \
"CMakeFiles/soci_odbc.dir/session.cpp.o" \
"CMakeFiles/soci_odbc.dir/standard-into-type.cpp.o" \
"CMakeFiles/soci_odbc.dir/standard-use-type.cpp.o" \
"CMakeFiles/soci_odbc.dir/statement.cpp.o" \
"CMakeFiles/soci_odbc.dir/vector-into-type.cpp.o" \
"CMakeFiles/soci_odbc.dir/vector-use-type.cpp.o"

# External object files for target soci_odbc
soci_odbc_EXTERNAL_OBJECTS =

lib/libsoci_odbc.4.1.0.dylib: Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/blob.cpp.o
lib/libsoci_odbc.4.1.0.dylib: Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/factory.cpp.o
lib/libsoci_odbc.4.1.0.dylib: Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/row-id.cpp.o
lib/libsoci_odbc.4.1.0.dylib: Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/session.cpp.o
lib/libsoci_odbc.4.1.0.dylib: Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/standard-into-type.cpp.o
lib/libsoci_odbc.4.1.0.dylib: Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/standard-use-type.cpp.o
lib/libsoci_odbc.4.1.0.dylib: Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/statement.cpp.o
lib/libsoci_odbc.4.1.0.dylib: Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/vector-into-type.cpp.o
lib/libsoci_odbc.4.1.0.dylib: Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/vector-use-type.cpp.o
lib/libsoci_odbc.4.1.0.dylib: Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/build.make
lib/libsoci_odbc.4.1.0.dylib: lib/libsoci_core.4.1.0.dylib
lib/libsoci_odbc.4.1.0.dylib: /opt/homebrew/lib/libodbc.dylib
lib/libsoci_odbc.4.1.0.dylib: /opt/homebrew/lib/libodbc.dylib
lib/libsoci_odbc.4.1.0.dylib: /Library/Developer/CommandLineTools/SDKs/MacOSX12.3.sdk/usr/lib/libdl.tbd
lib/libsoci_odbc.4.1.0.dylib: /opt/homebrew/lib/libboost_date_time-mt.dylib
lib/libsoci_odbc.4.1.0.dylib: Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/anastasiapronina/C++Projects/TelegramBot/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX shared library ../../../../lib/libsoci_odbc.dylib"
	cd /Users/anastasiapronina/C++Projects/TelegramBot/build/Soci/src/backends/odbc && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/soci_odbc.dir/link.txt --verbose=$(VERBOSE)
	cd /Users/anastasiapronina/C++Projects/TelegramBot/build/Soci/src/backends/odbc && $(CMAKE_COMMAND) -E cmake_symlink_library ../../../../lib/libsoci_odbc.4.1.0.dylib ../../../../lib/libsoci_odbc.4.1.dylib ../../../../lib/libsoci_odbc.dylib

lib/libsoci_odbc.4.1.dylib: lib/libsoci_odbc.4.1.0.dylib
	@$(CMAKE_COMMAND) -E touch_nocreate lib/libsoci_odbc.4.1.dylib

lib/libsoci_odbc.dylib: lib/libsoci_odbc.4.1.0.dylib
	@$(CMAKE_COMMAND) -E touch_nocreate lib/libsoci_odbc.dylib

# Rule to build all files generated by this target.
Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/build: lib/libsoci_odbc.dylib
.PHONY : Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/build

Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/clean:
	cd /Users/anastasiapronina/C++Projects/TelegramBot/build/Soci/src/backends/odbc && $(CMAKE_COMMAND) -P CMakeFiles/soci_odbc.dir/cmake_clean.cmake
.PHONY : Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/clean

Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/depend:
	cd /Users/anastasiapronina/C++Projects/TelegramBot/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/anastasiapronina/C++Projects/TelegramBot /Users/anastasiapronina/C++Projects/TelegramBot/Soci/src/backends/odbc /Users/anastasiapronina/C++Projects/TelegramBot/build /Users/anastasiapronina/C++Projects/TelegramBot/build/Soci/src/backends/odbc /Users/anastasiapronina/C++Projects/TelegramBot/build/Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : Soci/src/backends/odbc/CMakeFiles/soci_odbc.dir/depend

