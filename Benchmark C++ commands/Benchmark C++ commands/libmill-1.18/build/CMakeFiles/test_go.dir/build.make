# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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


# Suppress display of executed commands.
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
CMAKE_SOURCE_DIR = "C:\Users\Matt\source\repos\Benchmark C++ commands\Benchmark C++ commands\libmill-1.18"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Matt\source\repos\Benchmark C++ commands\Benchmark C++ commands\libmill-1.18\build"

# Include any dependencies generated for this target.
include CMakeFiles/test_go.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_go.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_go.dir/flags.make

CMakeFiles/test_go.dir/tests/go.c.obj: CMakeFiles/test_go.dir/flags.make
CMakeFiles/test_go.dir/tests/go.c.obj: ../tests/go.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Matt\source\repos\Benchmark C++ commands\Benchmark C++ commands\libmill-1.18\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/test_go.dir/tests/go.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\test_go.dir\tests\go.c.obj   -c "C:\Users\Matt\source\repos\Benchmark C++ commands\Benchmark C++ commands\libmill-1.18\tests\go.c"

CMakeFiles/test_go.dir/tests/go.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_go.dir/tests/go.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Matt\source\repos\Benchmark C++ commands\Benchmark C++ commands\libmill-1.18\tests\go.c" > CMakeFiles\test_go.dir\tests\go.c.i

CMakeFiles/test_go.dir/tests/go.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_go.dir/tests/go.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Matt\source\repos\Benchmark C++ commands\Benchmark C++ commands\libmill-1.18\tests\go.c" -o CMakeFiles\test_go.dir\tests\go.c.s

# Object files for target test_go
test_go_OBJECTS = \
"CMakeFiles/test_go.dir/tests/go.c.obj"

# External object files for target test_go
test_go_EXTERNAL_OBJECTS =

tests/go.exe: CMakeFiles/test_go.dir/tests/go.c.obj
tests/go.exe: CMakeFiles/test_go.dir/build.make
tests/go.exe: libmill.a
tests/go.exe: CMakeFiles/test_go.dir/linklibs.rsp
tests/go.exe: CMakeFiles/test_go.dir/objects1.rsp
tests/go.exe: CMakeFiles/test_go.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Matt\source\repos\Benchmark C++ commands\Benchmark C++ commands\libmill-1.18\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable tests\go.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\test_go.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_go.dir/build: tests/go.exe

.PHONY : CMakeFiles/test_go.dir/build

CMakeFiles/test_go.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\test_go.dir\cmake_clean.cmake
.PHONY : CMakeFiles/test_go.dir/clean

CMakeFiles/test_go.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Matt\source\repos\Benchmark C++ commands\Benchmark C++ commands\libmill-1.18" "C:\Users\Matt\source\repos\Benchmark C++ commands\Benchmark C++ commands\libmill-1.18" "C:\Users\Matt\source\repos\Benchmark C++ commands\Benchmark C++ commands\libmill-1.18\build" "C:\Users\Matt\source\repos\Benchmark C++ commands\Benchmark C++ commands\libmill-1.18\build" "C:\Users\Matt\source\repos\Benchmark C++ commands\Benchmark C++ commands\libmill-1.18\build\CMakeFiles\test_go.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/test_go.dir/depend

