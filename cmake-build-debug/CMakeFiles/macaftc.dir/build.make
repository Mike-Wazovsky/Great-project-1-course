# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /snap/clion/151/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/151/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/osboxes/project/Great-project-1-course

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/osboxes/project/Great-project-1-course/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/macaftc.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/macaftc.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/macaftc.dir/flags.make

CMakeFiles/macaftc.dir/src/main.cpp.o: CMakeFiles/macaftc.dir/flags.make
CMakeFiles/macaftc.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/osboxes/project/Great-project-1-course/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/macaftc.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/macaftc.dir/src/main.cpp.o -c /home/osboxes/project/Great-project-1-course/src/main.cpp

CMakeFiles/macaftc.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/macaftc.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/osboxes/project/Great-project-1-course/src/main.cpp > CMakeFiles/macaftc.dir/src/main.cpp.i

CMakeFiles/macaftc.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/macaftc.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/osboxes/project/Great-project-1-course/src/main.cpp -o CMakeFiles/macaftc.dir/src/main.cpp.s

CMakeFiles/macaftc.dir/src/game.cpp.o: CMakeFiles/macaftc.dir/flags.make
CMakeFiles/macaftc.dir/src/game.cpp.o: ../src/game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/osboxes/project/Great-project-1-course/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/macaftc.dir/src/game.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/macaftc.dir/src/game.cpp.o -c /home/osboxes/project/Great-project-1-course/src/game.cpp

CMakeFiles/macaftc.dir/src/game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/macaftc.dir/src/game.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/osboxes/project/Great-project-1-course/src/game.cpp > CMakeFiles/macaftc.dir/src/game.cpp.i

CMakeFiles/macaftc.dir/src/game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/macaftc.dir/src/game.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/osboxes/project/Great-project-1-course/src/game.cpp -o CMakeFiles/macaftc.dir/src/game.cpp.s

CMakeFiles/macaftc.dir/src/view.cpp.o: CMakeFiles/macaftc.dir/flags.make
CMakeFiles/macaftc.dir/src/view.cpp.o: ../src/view.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/osboxes/project/Great-project-1-course/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/macaftc.dir/src/view.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/macaftc.dir/src/view.cpp.o -c /home/osboxes/project/Great-project-1-course/src/view.cpp

CMakeFiles/macaftc.dir/src/view.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/macaftc.dir/src/view.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/osboxes/project/Great-project-1-course/src/view.cpp > CMakeFiles/macaftc.dir/src/view.cpp.i

CMakeFiles/macaftc.dir/src/view.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/macaftc.dir/src/view.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/osboxes/project/Great-project-1-course/src/view.cpp -o CMakeFiles/macaftc.dir/src/view.cpp.s

CMakeFiles/macaftc.dir/src/controller.cpp.o: CMakeFiles/macaftc.dir/flags.make
CMakeFiles/macaftc.dir/src/controller.cpp.o: ../src/controller.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/osboxes/project/Great-project-1-course/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/macaftc.dir/src/controller.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/macaftc.dir/src/controller.cpp.o -c /home/osboxes/project/Great-project-1-course/src/controller.cpp

CMakeFiles/macaftc.dir/src/controller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/macaftc.dir/src/controller.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/osboxes/project/Great-project-1-course/src/controller.cpp > CMakeFiles/macaftc.dir/src/controller.cpp.i

CMakeFiles/macaftc.dir/src/controller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/macaftc.dir/src/controller.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/osboxes/project/Great-project-1-course/src/controller.cpp -o CMakeFiles/macaftc.dir/src/controller.cpp.s

CMakeFiles/macaftc.dir/src/uml.cpp.o: CMakeFiles/macaftc.dir/flags.make
CMakeFiles/macaftc.dir/src/uml.cpp.o: ../src/uml.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/osboxes/project/Great-project-1-course/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/macaftc.dir/src/uml.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/macaftc.dir/src/uml.cpp.o -c /home/osboxes/project/Great-project-1-course/src/uml.cpp

CMakeFiles/macaftc.dir/src/uml.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/macaftc.dir/src/uml.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/osboxes/project/Great-project-1-course/src/uml.cpp > CMakeFiles/macaftc.dir/src/uml.cpp.i

CMakeFiles/macaftc.dir/src/uml.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/macaftc.dir/src/uml.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/osboxes/project/Great-project-1-course/src/uml.cpp -o CMakeFiles/macaftc.dir/src/uml.cpp.s

# Object files for target macaftc
macaftc_OBJECTS = \
"CMakeFiles/macaftc.dir/src/main.cpp.o" \
"CMakeFiles/macaftc.dir/src/game.cpp.o" \
"CMakeFiles/macaftc.dir/src/view.cpp.o" \
"CMakeFiles/macaftc.dir/src/controller.cpp.o" \
"CMakeFiles/macaftc.dir/src/uml.cpp.o"

# External object files for target macaftc
macaftc_EXTERNAL_OBJECTS =

macaftc: CMakeFiles/macaftc.dir/src/main.cpp.o
macaftc: CMakeFiles/macaftc.dir/src/game.cpp.o
macaftc: CMakeFiles/macaftc.dir/src/view.cpp.o
macaftc: CMakeFiles/macaftc.dir/src/controller.cpp.o
macaftc: CMakeFiles/macaftc.dir/src/uml.cpp.o
macaftc: CMakeFiles/macaftc.dir/build.make
macaftc: CMakeFiles/macaftc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/osboxes/project/Great-project-1-course/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable macaftc"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/macaftc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/macaftc.dir/build: macaftc

.PHONY : CMakeFiles/macaftc.dir/build

CMakeFiles/macaftc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/macaftc.dir/cmake_clean.cmake
.PHONY : CMakeFiles/macaftc.dir/clean

CMakeFiles/macaftc.dir/depend:
	cd /home/osboxes/project/Great-project-1-course/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/osboxes/project/Great-project-1-course /home/osboxes/project/Great-project-1-course /home/osboxes/project/Great-project-1-course/cmake-build-debug /home/osboxes/project/Great-project-1-course/cmake-build-debug /home/osboxes/project/Great-project-1-course/cmake-build-debug/CMakeFiles/macaftc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/macaftc.dir/depend

