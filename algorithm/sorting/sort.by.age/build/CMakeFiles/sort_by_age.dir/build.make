# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.26

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\kimmi\Desktop\MyCode\algorithm\sorting\sort.by.age

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\kimmi\Desktop\MyCode\algorithm\sorting\sort.by.age\build

# Include any dependencies generated for this target.
include CMakeFiles/sort_by_age.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/sort_by_age.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/sort_by_age.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sort_by_age.dir/flags.make

CMakeFiles/sort_by_age.dir/main.cpp.obj: CMakeFiles/sort_by_age.dir/flags.make
CMakeFiles/sort_by_age.dir/main.cpp.obj: C:/Users/kimmi/Desktop/MyCode/algorithm/sorting/sort.by.age/main.cpp
CMakeFiles/sort_by_age.dir/main.cpp.obj: CMakeFiles/sort_by_age.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\kimmi\Desktop\MyCode\algorithm\sorting\sort.by.age\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sort_by_age.dir/main.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sort_by_age.dir/main.cpp.obj -MF CMakeFiles\sort_by_age.dir\main.cpp.obj.d -o CMakeFiles\sort_by_age.dir\main.cpp.obj -c C:\Users\kimmi\Desktop\MyCode\algorithm\sorting\sort.by.age\main.cpp

CMakeFiles/sort_by_age.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sort_by_age.dir/main.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\kimmi\Desktop\MyCode\algorithm\sorting\sort.by.age\main.cpp > CMakeFiles\sort_by_age.dir\main.cpp.i

CMakeFiles/sort_by_age.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sort_by_age.dir/main.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\kimmi\Desktop\MyCode\algorithm\sorting\sort.by.age\main.cpp -o CMakeFiles\sort_by_age.dir\main.cpp.s

CMakeFiles/sort_by_age.dir/file.io/file.io.cpp.obj: CMakeFiles/sort_by_age.dir/flags.make
CMakeFiles/sort_by_age.dir/file.io/file.io.cpp.obj: C:/Users/kimmi/Desktop/MyCode/algorithm/sorting/sort.by.age/file.io/file.io.cpp
CMakeFiles/sort_by_age.dir/file.io/file.io.cpp.obj: CMakeFiles/sort_by_age.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\kimmi\Desktop\MyCode\algorithm\sorting\sort.by.age\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/sort_by_age.dir/file.io/file.io.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sort_by_age.dir/file.io/file.io.cpp.obj -MF CMakeFiles\sort_by_age.dir\file.io\file.io.cpp.obj.d -o CMakeFiles\sort_by_age.dir\file.io\file.io.cpp.obj -c C:\Users\kimmi\Desktop\MyCode\algorithm\sorting\sort.by.age\file.io\file.io.cpp

CMakeFiles/sort_by_age.dir/file.io/file.io.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sort_by_age.dir/file.io/file.io.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\kimmi\Desktop\MyCode\algorithm\sorting\sort.by.age\file.io\file.io.cpp > CMakeFiles\sort_by_age.dir\file.io\file.io.cpp.i

CMakeFiles/sort_by_age.dir/file.io/file.io.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sort_by_age.dir/file.io/file.io.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\kimmi\Desktop\MyCode\algorithm\sorting\sort.by.age\file.io\file.io.cpp -o CMakeFiles\sort_by_age.dir\file.io\file.io.cpp.s

# Object files for target sort_by_age
sort_by_age_OBJECTS = \
"CMakeFiles/sort_by_age.dir/main.cpp.obj" \
"CMakeFiles/sort_by_age.dir/file.io/file.io.cpp.obj"

# External object files for target sort_by_age
sort_by_age_EXTERNAL_OBJECTS =

sort_by_age.exe: CMakeFiles/sort_by_age.dir/main.cpp.obj
sort_by_age.exe: CMakeFiles/sort_by_age.dir/file.io/file.io.cpp.obj
sort_by_age.exe: CMakeFiles/sort_by_age.dir/build.make
sort_by_age.exe: CMakeFiles/sort_by_age.dir/linkLibs.rsp
sort_by_age.exe: CMakeFiles/sort_by_age.dir/objects1.rsp
sort_by_age.exe: CMakeFiles/sort_by_age.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\kimmi\Desktop\MyCode\algorithm\sorting\sort.by.age\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable sort_by_age.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\sort_by_age.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sort_by_age.dir/build: sort_by_age.exe
.PHONY : CMakeFiles/sort_by_age.dir/build

CMakeFiles/sort_by_age.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\sort_by_age.dir\cmake_clean.cmake
.PHONY : CMakeFiles/sort_by_age.dir/clean

CMakeFiles/sort_by_age.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\kimmi\Desktop\MyCode\algorithm\sorting\sort.by.age C:\Users\kimmi\Desktop\MyCode\algorithm\sorting\sort.by.age C:\Users\kimmi\Desktop\MyCode\algorithm\sorting\sort.by.age\build C:\Users\kimmi\Desktop\MyCode\algorithm\sorting\sort.by.age\build C:\Users\kimmi\Desktop\MyCode\algorithm\sorting\sort.by.age\build\CMakeFiles\sort_by_age.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sort_by_age.dir/depend

