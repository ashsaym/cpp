# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\s49166\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\192.6817.18\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\s49166\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\192.6817.18\bin\cmake\win\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\s49166\CLionProjects\cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\s49166\CLionProjects\cpp\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/cpp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cpp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cpp.dir/flags.make

CMakeFiles/cpp.dir/main.cpp.obj: CMakeFiles/cpp.dir/flags.make
CMakeFiles/cpp.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\s49166\CLionProjects\cpp\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cpp.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\cpp.dir\main.cpp.obj -c C:\Users\s49166\CLionProjects\cpp\main.cpp

CMakeFiles/cpp.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpp.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\s49166\CLionProjects\cpp\main.cpp > CMakeFiles\cpp.dir\main.cpp.i

CMakeFiles/cpp.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpp.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\s49166\CLionProjects\cpp\main.cpp -o CMakeFiles\cpp.dir\main.cpp.s

# Object files for target cpp
cpp_OBJECTS = \
"CMakeFiles/cpp.dir/main.cpp.obj"

# External object files for target cpp
cpp_EXTERNAL_OBJECTS =

cpp.exe: CMakeFiles/cpp.dir/main.cpp.obj
cpp.exe: CMakeFiles/cpp.dir/build.make
cpp.exe: CMakeFiles/cpp.dir/linklibs.rsp
cpp.exe: CMakeFiles/cpp.dir/objects1.rsp
cpp.exe: CMakeFiles/cpp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\s49166\CLionProjects\cpp\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable cpp.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\cpp.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cpp.dir/build: cpp.exe

.PHONY : CMakeFiles/cpp.dir/build

CMakeFiles/cpp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\cpp.dir\cmake_clean.cmake
.PHONY : CMakeFiles/cpp.dir/clean

CMakeFiles/cpp.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\s49166\CLionProjects\cpp C:\Users\s49166\CLionProjects\cpp C:\Users\s49166\CLionProjects\cpp\cmake-build-debug C:\Users\s49166\CLionProjects\cpp\cmake-build-debug C:\Users\s49166\CLionProjects\cpp\cmake-build-debug\CMakeFiles\cpp.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cpp.dir/depend

