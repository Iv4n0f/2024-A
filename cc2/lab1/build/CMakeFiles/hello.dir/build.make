# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ivan/Code/3_semestre/cc2/lab1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ivan/Code/3_semestre/cc2/lab1/build

# Include any dependencies generated for this target.
include CMakeFiles/hello.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/hello.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/hello.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hello.dir/flags.make

CMakeFiles/hello.dir/helloW.cpp.o: CMakeFiles/hello.dir/flags.make
CMakeFiles/hello.dir/helloW.cpp.o: /home/ivan/Code/3_semestre/cc2/lab1/helloW.cpp
CMakeFiles/hello.dir/helloW.cpp.o: CMakeFiles/hello.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ivan/Code/3_semestre/cc2/lab1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hello.dir/helloW.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hello.dir/helloW.cpp.o -MF CMakeFiles/hello.dir/helloW.cpp.o.d -o CMakeFiles/hello.dir/helloW.cpp.o -c /home/ivan/Code/3_semestre/cc2/lab1/helloW.cpp

CMakeFiles/hello.dir/helloW.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/hello.dir/helloW.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivan/Code/3_semestre/cc2/lab1/helloW.cpp > CMakeFiles/hello.dir/helloW.cpp.i

CMakeFiles/hello.dir/helloW.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/hello.dir/helloW.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivan/Code/3_semestre/cc2/lab1/helloW.cpp -o CMakeFiles/hello.dir/helloW.cpp.s

# Object files for target hello
hello_OBJECTS = \
"CMakeFiles/hello.dir/helloW.cpp.o"

# External object files for target hello
hello_EXTERNAL_OBJECTS =

hello: CMakeFiles/hello.dir/helloW.cpp.o
hello: CMakeFiles/hello.dir/build.make
hello: CMakeFiles/hello.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/ivan/Code/3_semestre/cc2/lab1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable hello"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hello.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hello.dir/build: hello
.PHONY : CMakeFiles/hello.dir/build

CMakeFiles/hello.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hello.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hello.dir/clean

CMakeFiles/hello.dir/depend:
	cd /home/ivan/Code/3_semestre/cc2/lab1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ivan/Code/3_semestre/cc2/lab1 /home/ivan/Code/3_semestre/cc2/lab1 /home/ivan/Code/3_semestre/cc2/lab1/build /home/ivan/Code/3_semestre/cc2/lab1/build /home/ivan/Code/3_semestre/cc2/lab1/build/CMakeFiles/hello.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/hello.dir/depend

