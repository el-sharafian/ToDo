# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/f/5/10/todo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/f/5/10/todo/build

# Include any dependencies generated for this target.
include CMakeFiles/todo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/todo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/todo.dir/flags.make

CMakeFiles/todo.dir/src/main.cpp.o: CMakeFiles/todo.dir/flags.make
CMakeFiles/todo.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/f/5/10/todo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/todo.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/todo.dir/src/main.cpp.o -c /mnt/f/5/10/todo/src/main.cpp

CMakeFiles/todo.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/todo.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/f/5/10/todo/src/main.cpp > CMakeFiles/todo.dir/src/main.cpp.i

CMakeFiles/todo.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/todo.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/f/5/10/todo/src/main.cpp -o CMakeFiles/todo.dir/src/main.cpp.s

CMakeFiles/todo.dir/src/icon.cpp.o: CMakeFiles/todo.dir/flags.make
CMakeFiles/todo.dir/src/icon.cpp.o: ../src/icon.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/f/5/10/todo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/todo.dir/src/icon.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/todo.dir/src/icon.cpp.o -c /mnt/f/5/10/todo/src/icon.cpp

CMakeFiles/todo.dir/src/icon.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/todo.dir/src/icon.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/f/5/10/todo/src/icon.cpp > CMakeFiles/todo.dir/src/icon.cpp.i

CMakeFiles/todo.dir/src/icon.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/todo.dir/src/icon.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/f/5/10/todo/src/icon.cpp -o CMakeFiles/todo.dir/src/icon.cpp.s

CMakeFiles/todo.dir/src/ToDo.cpp.o: CMakeFiles/todo.dir/flags.make
CMakeFiles/todo.dir/src/ToDo.cpp.o: ../src/ToDo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/f/5/10/todo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/todo.dir/src/ToDo.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/todo.dir/src/ToDo.cpp.o -c /mnt/f/5/10/todo/src/ToDo.cpp

CMakeFiles/todo.dir/src/ToDo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/todo.dir/src/ToDo.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/f/5/10/todo/src/ToDo.cpp > CMakeFiles/todo.dir/src/ToDo.cpp.i

CMakeFiles/todo.dir/src/ToDo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/todo.dir/src/ToDo.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/f/5/10/todo/src/ToDo.cpp -o CMakeFiles/todo.dir/src/ToDo.cpp.s

CMakeFiles/todo.dir/src/task.cpp.o: CMakeFiles/todo.dir/flags.make
CMakeFiles/todo.dir/src/task.cpp.o: ../src/task.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/f/5/10/todo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/todo.dir/src/task.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/todo.dir/src/task.cpp.o -c /mnt/f/5/10/todo/src/task.cpp

CMakeFiles/todo.dir/src/task.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/todo.dir/src/task.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/f/5/10/todo/src/task.cpp > CMakeFiles/todo.dir/src/task.cpp.i

CMakeFiles/todo.dir/src/task.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/todo.dir/src/task.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/f/5/10/todo/src/task.cpp -o CMakeFiles/todo.dir/src/task.cpp.s

CMakeFiles/todo.dir/src/AddButton.cpp.o: CMakeFiles/todo.dir/flags.make
CMakeFiles/todo.dir/src/AddButton.cpp.o: ../src/AddButton.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/f/5/10/todo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/todo.dir/src/AddButton.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/todo.dir/src/AddButton.cpp.o -c /mnt/f/5/10/todo/src/AddButton.cpp

CMakeFiles/todo.dir/src/AddButton.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/todo.dir/src/AddButton.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/f/5/10/todo/src/AddButton.cpp > CMakeFiles/todo.dir/src/AddButton.cpp.i

CMakeFiles/todo.dir/src/AddButton.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/todo.dir/src/AddButton.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/f/5/10/todo/src/AddButton.cpp -o CMakeFiles/todo.dir/src/AddButton.cpp.s

CMakeFiles/todo.dir/src/vector.cpp.o: CMakeFiles/todo.dir/flags.make
CMakeFiles/todo.dir/src/vector.cpp.o: ../src/vector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/f/5/10/todo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/todo.dir/src/vector.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/todo.dir/src/vector.cpp.o -c /mnt/f/5/10/todo/src/vector.cpp

CMakeFiles/todo.dir/src/vector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/todo.dir/src/vector.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/f/5/10/todo/src/vector.cpp > CMakeFiles/todo.dir/src/vector.cpp.i

CMakeFiles/todo.dir/src/vector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/todo.dir/src/vector.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/f/5/10/todo/src/vector.cpp -o CMakeFiles/todo.dir/src/vector.cpp.s

CMakeFiles/todo.dir/src/editButton.cpp.o: CMakeFiles/todo.dir/flags.make
CMakeFiles/todo.dir/src/editButton.cpp.o: ../src/editButton.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/f/5/10/todo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/todo.dir/src/editButton.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/todo.dir/src/editButton.cpp.o -c /mnt/f/5/10/todo/src/editButton.cpp

CMakeFiles/todo.dir/src/editButton.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/todo.dir/src/editButton.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/f/5/10/todo/src/editButton.cpp > CMakeFiles/todo.dir/src/editButton.cpp.i

CMakeFiles/todo.dir/src/editButton.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/todo.dir/src/editButton.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/f/5/10/todo/src/editButton.cpp -o CMakeFiles/todo.dir/src/editButton.cpp.s

CMakeFiles/todo.dir/src/deleteButton.cpp.o: CMakeFiles/todo.dir/flags.make
CMakeFiles/todo.dir/src/deleteButton.cpp.o: ../src/deleteButton.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/f/5/10/todo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/todo.dir/src/deleteButton.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/todo.dir/src/deleteButton.cpp.o -c /mnt/f/5/10/todo/src/deleteButton.cpp

CMakeFiles/todo.dir/src/deleteButton.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/todo.dir/src/deleteButton.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/f/5/10/todo/src/deleteButton.cpp > CMakeFiles/todo.dir/src/deleteButton.cpp.i

CMakeFiles/todo.dir/src/deleteButton.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/todo.dir/src/deleteButton.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/f/5/10/todo/src/deleteButton.cpp -o CMakeFiles/todo.dir/src/deleteButton.cpp.s

CMakeFiles/todo.dir/src/Button.cpp.o: CMakeFiles/todo.dir/flags.make
CMakeFiles/todo.dir/src/Button.cpp.o: ../src/Button.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/f/5/10/todo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/todo.dir/src/Button.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/todo.dir/src/Button.cpp.o -c /mnt/f/5/10/todo/src/Button.cpp

CMakeFiles/todo.dir/src/Button.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/todo.dir/src/Button.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/f/5/10/todo/src/Button.cpp > CMakeFiles/todo.dir/src/Button.cpp.i

CMakeFiles/todo.dir/src/Button.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/todo.dir/src/Button.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/f/5/10/todo/src/Button.cpp -o CMakeFiles/todo.dir/src/Button.cpp.s

CMakeFiles/todo.dir/src/set.cpp.o: CMakeFiles/todo.dir/flags.make
CMakeFiles/todo.dir/src/set.cpp.o: ../src/set.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/f/5/10/todo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/todo.dir/src/set.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/todo.dir/src/set.cpp.o -c /mnt/f/5/10/todo/src/set.cpp

CMakeFiles/todo.dir/src/set.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/todo.dir/src/set.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/f/5/10/todo/src/set.cpp > CMakeFiles/todo.dir/src/set.cpp.i

CMakeFiles/todo.dir/src/set.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/todo.dir/src/set.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/f/5/10/todo/src/set.cpp -o CMakeFiles/todo.dir/src/set.cpp.s

CMakeFiles/todo.dir/src/favoriteButton.cpp.o: CMakeFiles/todo.dir/flags.make
CMakeFiles/todo.dir/src/favoriteButton.cpp.o: ../src/favoriteButton.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/f/5/10/todo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/todo.dir/src/favoriteButton.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/todo.dir/src/favoriteButton.cpp.o -c /mnt/f/5/10/todo/src/favoriteButton.cpp

CMakeFiles/todo.dir/src/favoriteButton.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/todo.dir/src/favoriteButton.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/f/5/10/todo/src/favoriteButton.cpp > CMakeFiles/todo.dir/src/favoriteButton.cpp.i

CMakeFiles/todo.dir/src/favoriteButton.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/todo.dir/src/favoriteButton.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/f/5/10/todo/src/favoriteButton.cpp -o CMakeFiles/todo.dir/src/favoriteButton.cpp.s

CMakeFiles/todo.dir/src/isDoneButton.cpp.o: CMakeFiles/todo.dir/flags.make
CMakeFiles/todo.dir/src/isDoneButton.cpp.o: ../src/isDoneButton.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/f/5/10/todo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/todo.dir/src/isDoneButton.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/todo.dir/src/isDoneButton.cpp.o -c /mnt/f/5/10/todo/src/isDoneButton.cpp

CMakeFiles/todo.dir/src/isDoneButton.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/todo.dir/src/isDoneButton.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/f/5/10/todo/src/isDoneButton.cpp > CMakeFiles/todo.dir/src/isDoneButton.cpp.i

CMakeFiles/todo.dir/src/isDoneButton.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/todo.dir/src/isDoneButton.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/f/5/10/todo/src/isDoneButton.cpp -o CMakeFiles/todo.dir/src/isDoneButton.cpp.s

CMakeFiles/todo.dir/src/file.cpp.o: CMakeFiles/todo.dir/flags.make
CMakeFiles/todo.dir/src/file.cpp.o: ../src/file.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/f/5/10/todo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/todo.dir/src/file.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/todo.dir/src/file.cpp.o -c /mnt/f/5/10/todo/src/file.cpp

CMakeFiles/todo.dir/src/file.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/todo.dir/src/file.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/f/5/10/todo/src/file.cpp > CMakeFiles/todo.dir/src/file.cpp.i

CMakeFiles/todo.dir/src/file.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/todo.dir/src/file.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/f/5/10/todo/src/file.cpp -o CMakeFiles/todo.dir/src/file.cpp.s

# Object files for target todo
todo_OBJECTS = \
"CMakeFiles/todo.dir/src/main.cpp.o" \
"CMakeFiles/todo.dir/src/icon.cpp.o" \
"CMakeFiles/todo.dir/src/ToDo.cpp.o" \
"CMakeFiles/todo.dir/src/task.cpp.o" \
"CMakeFiles/todo.dir/src/AddButton.cpp.o" \
"CMakeFiles/todo.dir/src/vector.cpp.o" \
"CMakeFiles/todo.dir/src/editButton.cpp.o" \
"CMakeFiles/todo.dir/src/deleteButton.cpp.o" \
"CMakeFiles/todo.dir/src/Button.cpp.o" \
"CMakeFiles/todo.dir/src/set.cpp.o" \
"CMakeFiles/todo.dir/src/favoriteButton.cpp.o" \
"CMakeFiles/todo.dir/src/isDoneButton.cpp.o" \
"CMakeFiles/todo.dir/src/file.cpp.o"

# External object files for target todo
todo_EXTERNAL_OBJECTS =

todo: CMakeFiles/todo.dir/src/main.cpp.o
todo: CMakeFiles/todo.dir/src/icon.cpp.o
todo: CMakeFiles/todo.dir/src/ToDo.cpp.o
todo: CMakeFiles/todo.dir/src/task.cpp.o
todo: CMakeFiles/todo.dir/src/AddButton.cpp.o
todo: CMakeFiles/todo.dir/src/vector.cpp.o
todo: CMakeFiles/todo.dir/src/editButton.cpp.o
todo: CMakeFiles/todo.dir/src/deleteButton.cpp.o
todo: CMakeFiles/todo.dir/src/Button.cpp.o
todo: CMakeFiles/todo.dir/src/set.cpp.o
todo: CMakeFiles/todo.dir/src/favoriteButton.cpp.o
todo: CMakeFiles/todo.dir/src/isDoneButton.cpp.o
todo: CMakeFiles/todo.dir/src/file.cpp.o
todo: CMakeFiles/todo.dir/build.make
todo: CMakeFiles/todo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/f/5/10/todo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Linking CXX executable todo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/todo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/todo.dir/build: todo

.PHONY : CMakeFiles/todo.dir/build

CMakeFiles/todo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/todo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/todo.dir/clean

CMakeFiles/todo.dir/depend:
	cd /mnt/f/5/10/todo/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/f/5/10/todo /mnt/f/5/10/todo /mnt/f/5/10/todo/build /mnt/f/5/10/todo/build /mnt/f/5/10/todo/build/CMakeFiles/todo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/todo.dir/depend

