# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.25

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
CMAKE_SOURCE_DIR = "C:\Users\User\Documents\VS Projects\STLExercises"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\User\Documents\VS Projects\STLExercises\build"

# Include any dependencies generated for this target.
include test/CMakeFiles/StandartTests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/CMakeFiles/StandartTests.dir/compiler_depend.make

# Include the progress variables for this target.
include test/CMakeFiles/StandartTests.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/StandartTests.dir/flags.make

test/CMakeFiles/StandartTests.dir/MainTests.cpp.obj: test/CMakeFiles/StandartTests.dir/flags.make
test/CMakeFiles/StandartTests.dir/MainTests.cpp.obj: test/CMakeFiles/StandartTests.dir/includes_CXX.rsp
test/CMakeFiles/StandartTests.dir/MainTests.cpp.obj: C:/Users/User/Documents/VS\ Projects/STLExercises/test/MainTests.cpp
test/CMakeFiles/StandartTests.dir/MainTests.cpp.obj: test/CMakeFiles/StandartTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\User\Documents\VS Projects\STLExercises\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/StandartTests.dir/MainTests.cpp.obj"
	cd /d C:\Users\User\DOCUME~1\VSPROJ~1\STLEXE~1\build\test && C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/StandartTests.dir/MainTests.cpp.obj -MF CMakeFiles\StandartTests.dir\MainTests.cpp.obj.d -o CMakeFiles\StandartTests.dir\MainTests.cpp.obj -c "C:\Users\User\Documents\VS Projects\STLExercises\test\MainTests.cpp"

test/CMakeFiles/StandartTests.dir/MainTests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/StandartTests.dir/MainTests.cpp.i"
	cd /d C:\Users\User\DOCUME~1\VSPROJ~1\STLEXE~1\build\test && C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\User\Documents\VS Projects\STLExercises\test\MainTests.cpp" > CMakeFiles\StandartTests.dir\MainTests.cpp.i

test/CMakeFiles/StandartTests.dir/MainTests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/StandartTests.dir/MainTests.cpp.s"
	cd /d C:\Users\User\DOCUME~1\VSPROJ~1\STLEXE~1\build\test && C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\User\Documents\VS Projects\STLExercises\test\MainTests.cpp" -o CMakeFiles\StandartTests.dir\MainTests.cpp.s

# Object files for target StandartTests
StandartTests_OBJECTS = \
"CMakeFiles/StandartTests.dir/MainTests.cpp.obj"

# External object files for target StandartTests
StandartTests_EXTERNAL_OBJECTS =

test/StandartTests.exe: test/CMakeFiles/StandartTests.dir/MainTests.cpp.obj
test/StandartTests.exe: test/CMakeFiles/StandartTests.dir/build.make
test/StandartTests.exe: lib/libgtest_main.a
test/StandartTests.exe: libSTLExercises.a
test/StandartTests.exe: lib/libgtest.a
test/StandartTests.exe: test/CMakeFiles/StandartTests.dir/linkLibs.rsp
test/StandartTests.exe: test/CMakeFiles/StandartTests.dir/objects1
test/StandartTests.exe: test/CMakeFiles/StandartTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\User\Documents\VS Projects\STLExercises\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable StandartTests.exe"
	cd /d C:\Users\User\DOCUME~1\VSPROJ~1\STLEXE~1\build\test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\StandartTests.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/StandartTests.dir/build: test/StandartTests.exe
.PHONY : test/CMakeFiles/StandartTests.dir/build

test/CMakeFiles/StandartTests.dir/clean:
	cd /d C:\Users\User\DOCUME~1\VSPROJ~1\STLEXE~1\build\test && $(CMAKE_COMMAND) -P CMakeFiles\StandartTests.dir\cmake_clean.cmake
.PHONY : test/CMakeFiles/StandartTests.dir/clean

test/CMakeFiles/StandartTests.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\User\Documents\VS Projects\STLExercises" "C:\Users\User\Documents\VS Projects\STLExercises\test" "C:\Users\User\Documents\VS Projects\STLExercises\build" "C:\Users\User\Documents\VS Projects\STLExercises\build\test" "C:\Users\User\Documents\VS Projects\STLExercises\build\test\CMakeFiles\StandartTests.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : test/CMakeFiles/StandartTests.dir/depend

