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
include CMakeFiles/perf_chr.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/perf_chr.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/perf_chr.dir/flags.make

CMakeFiles/perf_chr.dir/perf/chr.c.obj: CMakeFiles/perf_chr.dir/flags.make
CMakeFiles/perf_chr.dir/perf/chr.c.obj: ../perf/chr.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Matt\source\repos\Benchmark C++ commands\Benchmark C++ commands\libmill-1.18\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/perf_chr.dir/perf/chr.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\perf_chr.dir\perf\chr.c.obj   -c "C:\Users\Matt\source\repos\Benchmark C++ commands\Benchmark C++ commands\libmill-1.18\perf\chr.c"

CMakeFiles/perf_chr.dir/perf/chr.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/perf_chr.dir/perf/chr.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Matt\source\repos\Benchmark C++ commands\Benchmark C++ commands\libmill-1.18\perf\chr.c" > CMakeFiles\perf_chr.dir\perf\chr.c.i

CMakeFiles/perf_chr.dir/perf/chr.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/perf_chr.dir/perf/chr.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Matt\source\repos\Benchmark C++ commands\Benchmark C++ commands\libmill-1.18\perf\chr.c" -o CMakeFiles\perf_chr.dir\perf\chr.c.s

# Object files for target perf_chr
perf_chr_OBJECTS = \
"CMakeFiles/perf_chr.dir/perf/chr.c.obj"

# External object files for target perf_chr
perf_chr_EXTERNAL_OBJECTS =

perf/chr.exe: CMakeFiles/perf_chr.dir/perf/chr.c.obj
perf/chr.exe: CMakeFiles/perf_chr.dir/build.make
perf/chr.exe: libmill.a
perf/chr.exe: CMakeFiles/perf_chr.dir/linklibs.rsp
perf/chr.exe: CMakeFiles/perf_chr.dir/objects1.rsp
perf/chr.exe: CMakeFiles/perf_chr.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Matt\source\repos\Benchmark C++ commands\Benchmark C++ commands\libmill-1.18\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable perf\chr.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\perf_chr.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/perf_chr.dir/build: perf/chr.exe

.PHONY : CMakeFiles/perf_chr.dir/build

CMakeFiles/perf_chr.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\perf_chr.dir\cmake_clean.cmake
.PHONY : CMakeFiles/perf_chr.dir/clean

CMakeFiles/perf_chr.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Matt\source\repos\Benchmark C++ commands\Benchmark C++ commands\libmill-1.18" "C:\Users\Matt\source\repos\Benchmark C++ commands\Benchmark C++ commands\libmill-1.18" "C:\Users\Matt\source\repos\Benchmark C++ commands\Benchmark C++ commands\libmill-1.18\build" "C:\Users\Matt\source\repos\Benchmark C++ commands\Benchmark C++ commands\libmill-1.18\build" "C:\Users\Matt\source\repos\Benchmark C++ commands\Benchmark C++ commands\libmill-1.18\build\CMakeFiles\perf_chr.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/perf_chr.dir/depend

