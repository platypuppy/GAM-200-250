# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/platypuppy/GitHub/GAM-200-250/_game/subsystems/ObjectSerilazation

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/platypuppy/GitHub/GAM-200-250/_game/subsystems/ObjectSerilazation

# Include any dependencies generated for this target.
include CMakeFiles/executeTests.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/executeTests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/executeTests.dir/flags.make

CMakeFiles/executeTests.dir/_unit_test.cpp.o: CMakeFiles/executeTests.dir/flags.make
CMakeFiles/executeTests.dir/_unit_test.cpp.o: _unit_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/platypuppy/GitHub/GAM-200-250/_game/subsystems/ObjectSerilazation/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/executeTests.dir/_unit_test.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/executeTests.dir/_unit_test.cpp.o -c /home/platypuppy/GitHub/GAM-200-250/_game/subsystems/ObjectSerilazation/_unit_test.cpp

CMakeFiles/executeTests.dir/_unit_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/executeTests.dir/_unit_test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/platypuppy/GitHub/GAM-200-250/_game/subsystems/ObjectSerilazation/_unit_test.cpp > CMakeFiles/executeTests.dir/_unit_test.cpp.i

CMakeFiles/executeTests.dir/_unit_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/executeTests.dir/_unit_test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/platypuppy/GitHub/GAM-200-250/_game/subsystems/ObjectSerilazation/_unit_test.cpp -o CMakeFiles/executeTests.dir/_unit_test.cpp.s

CMakeFiles/executeTests.dir/_unit_test.cpp.o.requires:

.PHONY : CMakeFiles/executeTests.dir/_unit_test.cpp.o.requires

CMakeFiles/executeTests.dir/_unit_test.cpp.o.provides: CMakeFiles/executeTests.dir/_unit_test.cpp.o.requires
	$(MAKE) -f CMakeFiles/executeTests.dir/build.make CMakeFiles/executeTests.dir/_unit_test.cpp.o.provides.build
.PHONY : CMakeFiles/executeTests.dir/_unit_test.cpp.o.provides

CMakeFiles/executeTests.dir/_unit_test.cpp.o.provides.build: CMakeFiles/executeTests.dir/_unit_test.cpp.o


CMakeFiles/executeTests.dir/ObjectDeSerialization_private.cpp.o: CMakeFiles/executeTests.dir/flags.make
CMakeFiles/executeTests.dir/ObjectDeSerialization_private.cpp.o: ObjectDeSerialization_private.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/platypuppy/GitHub/GAM-200-250/_game/subsystems/ObjectSerilazation/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/executeTests.dir/ObjectDeSerialization_private.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/executeTests.dir/ObjectDeSerialization_private.cpp.o -c /home/platypuppy/GitHub/GAM-200-250/_game/subsystems/ObjectSerilazation/ObjectDeSerialization_private.cpp

CMakeFiles/executeTests.dir/ObjectDeSerialization_private.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/executeTests.dir/ObjectDeSerialization_private.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/platypuppy/GitHub/GAM-200-250/_game/subsystems/ObjectSerilazation/ObjectDeSerialization_private.cpp > CMakeFiles/executeTests.dir/ObjectDeSerialization_private.cpp.i

CMakeFiles/executeTests.dir/ObjectDeSerialization_private.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/executeTests.dir/ObjectDeSerialization_private.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/platypuppy/GitHub/GAM-200-250/_game/subsystems/ObjectSerilazation/ObjectDeSerialization_private.cpp -o CMakeFiles/executeTests.dir/ObjectDeSerialization_private.cpp.s

CMakeFiles/executeTests.dir/ObjectDeSerialization_private.cpp.o.requires:

.PHONY : CMakeFiles/executeTests.dir/ObjectDeSerialization_private.cpp.o.requires

CMakeFiles/executeTests.dir/ObjectDeSerialization_private.cpp.o.provides: CMakeFiles/executeTests.dir/ObjectDeSerialization_private.cpp.o.requires
	$(MAKE) -f CMakeFiles/executeTests.dir/build.make CMakeFiles/executeTests.dir/ObjectDeSerialization_private.cpp.o.provides.build
.PHONY : CMakeFiles/executeTests.dir/ObjectDeSerialization_private.cpp.o.provides

CMakeFiles/executeTests.dir/ObjectDeSerialization_private.cpp.o.provides.build: CMakeFiles/executeTests.dir/ObjectDeSerialization_private.cpp.o


CMakeFiles/executeTests.dir/DSObject.cpp.o: CMakeFiles/executeTests.dir/flags.make
CMakeFiles/executeTests.dir/DSObject.cpp.o: DSObject.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/platypuppy/GitHub/GAM-200-250/_game/subsystems/ObjectSerilazation/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/executeTests.dir/DSObject.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/executeTests.dir/DSObject.cpp.o -c /home/platypuppy/GitHub/GAM-200-250/_game/subsystems/ObjectSerilazation/DSObject.cpp

CMakeFiles/executeTests.dir/DSObject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/executeTests.dir/DSObject.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/platypuppy/GitHub/GAM-200-250/_game/subsystems/ObjectSerilazation/DSObject.cpp > CMakeFiles/executeTests.dir/DSObject.cpp.i

CMakeFiles/executeTests.dir/DSObject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/executeTests.dir/DSObject.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/platypuppy/GitHub/GAM-200-250/_game/subsystems/ObjectSerilazation/DSObject.cpp -o CMakeFiles/executeTests.dir/DSObject.cpp.s

CMakeFiles/executeTests.dir/DSObject.cpp.o.requires:

.PHONY : CMakeFiles/executeTests.dir/DSObject.cpp.o.requires

CMakeFiles/executeTests.dir/DSObject.cpp.o.provides: CMakeFiles/executeTests.dir/DSObject.cpp.o.requires
	$(MAKE) -f CMakeFiles/executeTests.dir/build.make CMakeFiles/executeTests.dir/DSObject.cpp.o.provides.build
.PHONY : CMakeFiles/executeTests.dir/DSObject.cpp.o.provides

CMakeFiles/executeTests.dir/DSObject.cpp.o.provides.build: CMakeFiles/executeTests.dir/DSObject.cpp.o


# Object files for target executeTests
executeTests_OBJECTS = \
"CMakeFiles/executeTests.dir/_unit_test.cpp.o" \
"CMakeFiles/executeTests.dir/ObjectDeSerialization_private.cpp.o" \
"CMakeFiles/executeTests.dir/DSObject.cpp.o"

# External object files for target executeTests
executeTests_EXTERNAL_OBJECTS =

executeTests: CMakeFiles/executeTests.dir/_unit_test.cpp.o
executeTests: CMakeFiles/executeTests.dir/ObjectDeSerialization_private.cpp.o
executeTests: CMakeFiles/executeTests.dir/DSObject.cpp.o
executeTests: CMakeFiles/executeTests.dir/build.make
executeTests: /usr/lib/libgtest.a
executeTests: CMakeFiles/executeTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/platypuppy/GitHub/GAM-200-250/_game/subsystems/ObjectSerilazation/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable executeTests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/executeTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/executeTests.dir/build: executeTests

.PHONY : CMakeFiles/executeTests.dir/build

CMakeFiles/executeTests.dir/requires: CMakeFiles/executeTests.dir/_unit_test.cpp.o.requires
CMakeFiles/executeTests.dir/requires: CMakeFiles/executeTests.dir/ObjectDeSerialization_private.cpp.o.requires
CMakeFiles/executeTests.dir/requires: CMakeFiles/executeTests.dir/DSObject.cpp.o.requires

.PHONY : CMakeFiles/executeTests.dir/requires

CMakeFiles/executeTests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/executeTests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/executeTests.dir/clean

CMakeFiles/executeTests.dir/depend:
	cd /home/platypuppy/GitHub/GAM-200-250/_game/subsystems/ObjectSerilazation && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/platypuppy/GitHub/GAM-200-250/_game/subsystems/ObjectSerilazation /home/platypuppy/GitHub/GAM-200-250/_game/subsystems/ObjectSerilazation /home/platypuppy/GitHub/GAM-200-250/_game/subsystems/ObjectSerilazation /home/platypuppy/GitHub/GAM-200-250/_game/subsystems/ObjectSerilazation /home/platypuppy/GitHub/GAM-200-250/_game/subsystems/ObjectSerilazation/CMakeFiles/executeTests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/executeTests.dir/depend

