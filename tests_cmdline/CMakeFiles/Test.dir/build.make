# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
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
CMAKE_COMMAND = "/Applications/CMake 2.8-4.app/Contents/bin/cmake"

# The command to remove a file.
RM = "/Applications/CMake 2.8-4.app/Contents/bin/cmake" -E remove -f

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = "/Applications/CMake 2.8-4.app/Contents/bin/ccmake"

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/stephanie/dev/panneau-led/Code/Serial_port/tests_arroway

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/stephanie/dev/panneau-led/Code/Serial_port/tests_arroway

# Include any dependencies generated for this target.
include CMakeFiles/Test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Test.dir/flags.make

CMakeFiles/Test.dir/board_control_test.c.o: CMakeFiles/Test.dir/flags.make
CMakeFiles/Test.dir/board_control_test.c.o: board_control_test.c
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/stephanie/dev/panneau-led/Code/Serial_port/tests_arroway/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/Test.dir/board_control_test.c.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/Test.dir/board_control_test.c.o   -c /Users/stephanie/dev/panneau-led/Code/Serial_port/tests_arroway/board_control_test.c

CMakeFiles/Test.dir/board_control_test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Test.dir/board_control_test.c.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /Users/stephanie/dev/panneau-led/Code/Serial_port/tests_arroway/board_control_test.c > CMakeFiles/Test.dir/board_control_test.c.i

CMakeFiles/Test.dir/board_control_test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Test.dir/board_control_test.c.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /Users/stephanie/dev/panneau-led/Code/Serial_port/tests_arroway/board_control_test.c -o CMakeFiles/Test.dir/board_control_test.c.s

CMakeFiles/Test.dir/board_control_test.c.o.requires:
.PHONY : CMakeFiles/Test.dir/board_control_test.c.o.requires

CMakeFiles/Test.dir/board_control_test.c.o.provides: CMakeFiles/Test.dir/board_control_test.c.o.requires
	$(MAKE) -f CMakeFiles/Test.dir/build.make CMakeFiles/Test.dir/board_control_test.c.o.provides.build
.PHONY : CMakeFiles/Test.dir/board_control_test.c.o.provides

CMakeFiles/Test.dir/board_control_test.c.o.provides.build: CMakeFiles/Test.dir/board_control_test.c.o

CMakeFiles/Test.dir/check_arguments.c.o: CMakeFiles/Test.dir/flags.make
CMakeFiles/Test.dir/check_arguments.c.o: check_arguments.c
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/stephanie/dev/panneau-led/Code/Serial_port/tests_arroway/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/Test.dir/check_arguments.c.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/Test.dir/check_arguments.c.o   -c /Users/stephanie/dev/panneau-led/Code/Serial_port/tests_arroway/check_arguments.c

CMakeFiles/Test.dir/check_arguments.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Test.dir/check_arguments.c.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /Users/stephanie/dev/panneau-led/Code/Serial_port/tests_arroway/check_arguments.c > CMakeFiles/Test.dir/check_arguments.c.i

CMakeFiles/Test.dir/check_arguments.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Test.dir/check_arguments.c.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /Users/stephanie/dev/panneau-led/Code/Serial_port/tests_arroway/check_arguments.c -o CMakeFiles/Test.dir/check_arguments.c.s

CMakeFiles/Test.dir/check_arguments.c.o.requires:
.PHONY : CMakeFiles/Test.dir/check_arguments.c.o.requires

CMakeFiles/Test.dir/check_arguments.c.o.provides: CMakeFiles/Test.dir/check_arguments.c.o.requires
	$(MAKE) -f CMakeFiles/Test.dir/build.make CMakeFiles/Test.dir/check_arguments.c.o.provides.build
.PHONY : CMakeFiles/Test.dir/check_arguments.c.o.provides

CMakeFiles/Test.dir/check_arguments.c.o.provides.build: CMakeFiles/Test.dir/check_arguments.c.o

CMakeFiles/Test.dir/parse_command_line.c.o: CMakeFiles/Test.dir/flags.make
CMakeFiles/Test.dir/parse_command_line.c.o: parse_command_line.c
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/stephanie/dev/panneau-led/Code/Serial_port/tests_arroway/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/Test.dir/parse_command_line.c.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/Test.dir/parse_command_line.c.o   -c /Users/stephanie/dev/panneau-led/Code/Serial_port/tests_arroway/parse_command_line.c

CMakeFiles/Test.dir/parse_command_line.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Test.dir/parse_command_line.c.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /Users/stephanie/dev/panneau-led/Code/Serial_port/tests_arroway/parse_command_line.c > CMakeFiles/Test.dir/parse_command_line.c.i

CMakeFiles/Test.dir/parse_command_line.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Test.dir/parse_command_line.c.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /Users/stephanie/dev/panneau-led/Code/Serial_port/tests_arroway/parse_command_line.c -o CMakeFiles/Test.dir/parse_command_line.c.s

CMakeFiles/Test.dir/parse_command_line.c.o.requires:
.PHONY : CMakeFiles/Test.dir/parse_command_line.c.o.requires

CMakeFiles/Test.dir/parse_command_line.c.o.provides: CMakeFiles/Test.dir/parse_command_line.c.o.requires
	$(MAKE) -f CMakeFiles/Test.dir/build.make CMakeFiles/Test.dir/parse_command_line.c.o.provides.build
.PHONY : CMakeFiles/Test.dir/parse_command_line.c.o.provides

CMakeFiles/Test.dir/parse_command_line.c.o.provides.build: CMakeFiles/Test.dir/parse_command_line.c.o

CMakeFiles/Test.dir/open_port.c.o: CMakeFiles/Test.dir/flags.make
CMakeFiles/Test.dir/open_port.c.o: open_port.c
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/stephanie/dev/panneau-led/Code/Serial_port/tests_arroway/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/Test.dir/open_port.c.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/Test.dir/open_port.c.o   -c /Users/stephanie/dev/panneau-led/Code/Serial_port/tests_arroway/open_port.c

CMakeFiles/Test.dir/open_port.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Test.dir/open_port.c.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /Users/stephanie/dev/panneau-led/Code/Serial_port/tests_arroway/open_port.c > CMakeFiles/Test.dir/open_port.c.i

CMakeFiles/Test.dir/open_port.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Test.dir/open_port.c.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /Users/stephanie/dev/panneau-led/Code/Serial_port/tests_arroway/open_port.c -o CMakeFiles/Test.dir/open_port.c.s

CMakeFiles/Test.dir/open_port.c.o.requires:
.PHONY : CMakeFiles/Test.dir/open_port.c.o.requires

CMakeFiles/Test.dir/open_port.c.o.provides: CMakeFiles/Test.dir/open_port.c.o.requires
	$(MAKE) -f CMakeFiles/Test.dir/build.make CMakeFiles/Test.dir/open_port.c.o.provides.build
.PHONY : CMakeFiles/Test.dir/open_port.c.o.provides

CMakeFiles/Test.dir/open_port.c.o.provides.build: CMakeFiles/Test.dir/open_port.c.o

# Object files for target Test
Test_OBJECTS = \
"CMakeFiles/Test.dir/board_control_test.c.o" \
"CMakeFiles/Test.dir/check_arguments.c.o" \
"CMakeFiles/Test.dir/parse_command_line.c.o" \
"CMakeFiles/Test.dir/open_port.c.o"

# External object files for target Test
Test_EXTERNAL_OBJECTS =

Test: CMakeFiles/Test.dir/board_control_test.c.o
Test: CMakeFiles/Test.dir/check_arguments.c.o
Test: CMakeFiles/Test.dir/parse_command_line.c.o
Test: CMakeFiles/Test.dir/open_port.c.o
Test: CMakeFiles/Test.dir/build.make
Test: CMakeFiles/Test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable Test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Test.dir/build: Test
.PHONY : CMakeFiles/Test.dir/build

CMakeFiles/Test.dir/requires: CMakeFiles/Test.dir/board_control_test.c.o.requires
CMakeFiles/Test.dir/requires: CMakeFiles/Test.dir/check_arguments.c.o.requires
CMakeFiles/Test.dir/requires: CMakeFiles/Test.dir/parse_command_line.c.o.requires
CMakeFiles/Test.dir/requires: CMakeFiles/Test.dir/open_port.c.o.requires
.PHONY : CMakeFiles/Test.dir/requires

CMakeFiles/Test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Test.dir/clean

CMakeFiles/Test.dir/depend:
	cd /Users/stephanie/dev/panneau-led/Code/Serial_port/tests_arroway && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/stephanie/dev/panneau-led/Code/Serial_port/tests_arroway /Users/stephanie/dev/panneau-led/Code/Serial_port/tests_arroway /Users/stephanie/dev/panneau-led/Code/Serial_port/tests_arroway /Users/stephanie/dev/panneau-led/Code/Serial_port/tests_arroway /Users/stephanie/dev/panneau-led/Code/Serial_port/tests_arroway/CMakeFiles/Test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Test.dir/depend
