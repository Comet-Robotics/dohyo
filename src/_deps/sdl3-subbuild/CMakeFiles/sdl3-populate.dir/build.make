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
CMAKE_SOURCE_DIR = /home/evanwu03/projects/dohyo-template/src/_deps/sdl3-subbuild

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/evanwu03/projects/dohyo-template/src/_deps/sdl3-subbuild

# Utility rule file for sdl3-populate.

# Include any custom commands dependencies for this target.
include CMakeFiles/sdl3-populate.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/sdl3-populate.dir/progress.make

CMakeFiles/sdl3-populate: CMakeFiles/sdl3-populate-complete

CMakeFiles/sdl3-populate-complete: sdl3-populate-prefix/src/sdl3-populate-stamp/sdl3-populate-install
CMakeFiles/sdl3-populate-complete: sdl3-populate-prefix/src/sdl3-populate-stamp/sdl3-populate-mkdir
CMakeFiles/sdl3-populate-complete: sdl3-populate-prefix/src/sdl3-populate-stamp/sdl3-populate-download
CMakeFiles/sdl3-populate-complete: sdl3-populate-prefix/src/sdl3-populate-stamp/sdl3-populate-update
CMakeFiles/sdl3-populate-complete: sdl3-populate-prefix/src/sdl3-populate-stamp/sdl3-populate-patch
CMakeFiles/sdl3-populate-complete: sdl3-populate-prefix/src/sdl3-populate-stamp/sdl3-populate-configure
CMakeFiles/sdl3-populate-complete: sdl3-populate-prefix/src/sdl3-populate-stamp/sdl3-populate-build
CMakeFiles/sdl3-populate-complete: sdl3-populate-prefix/src/sdl3-populate-stamp/sdl3-populate-install
CMakeFiles/sdl3-populate-complete: sdl3-populate-prefix/src/sdl3-populate-stamp/sdl3-populate-test
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/evanwu03/projects/dohyo-template/src/_deps/sdl3-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Completed 'sdl3-populate'"
	/usr/bin/cmake -E make_directory /home/evanwu03/projects/dohyo-template/src/_deps/sdl3-subbuild/CMakeFiles
	/usr/bin/cmake -E touch /home/evanwu03/projects/dohyo-template/src/_deps/sdl3-subbuild/CMakeFiles/sdl3-populate-complete
	/usr/bin/cmake -E touch /home/evanwu03/projects/dohyo-template/src/_deps/sdl3-subbuild/sdl3-populate-prefix/src/sdl3-populate-stamp/sdl3-populate-done

sdl3-populate-prefix/src/sdl3-populate-stamp/sdl3-populate-update:
.PHONY : sdl3-populate-prefix/src/sdl3-populate-stamp/sdl3-populate-update

sdl3-populate-prefix/src/sdl3-populate-stamp/sdl3-populate-build: sdl3-populate-prefix/src/sdl3-populate-stamp/sdl3-populate-configure
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/evanwu03/projects/dohyo-template/src/_deps/sdl3-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "No build step for 'sdl3-populate'"
	cd /home/evanwu03/projects/dohyo-template/src/_deps/sdl3-build && /usr/bin/cmake -E echo_append
	cd /home/evanwu03/projects/dohyo-template/src/_deps/sdl3-build && /usr/bin/cmake -E touch /home/evanwu03/projects/dohyo-template/src/_deps/sdl3-subbuild/sdl3-populate-prefix/src/sdl3-populate-stamp/sdl3-populate-build

sdl3-populate-prefix/src/sdl3-populate-stamp/sdl3-populate-configure: sdl3-populate-prefix/tmp/sdl3-populate-cfgcmd.txt
sdl3-populate-prefix/src/sdl3-populate-stamp/sdl3-populate-configure: sdl3-populate-prefix/src/sdl3-populate-stamp/sdl3-populate-patch
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/evanwu03/projects/dohyo-template/src/_deps/sdl3-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "No configure step for 'sdl3-populate'"
	cd /home/evanwu03/projects/dohyo-template/src/_deps/sdl3-build && /usr/bin/cmake -E echo_append
	cd /home/evanwu03/projects/dohyo-template/src/_deps/sdl3-build && /usr/bin/cmake -E touch /home/evanwu03/projects/dohyo-template/src/_deps/sdl3-subbuild/sdl3-populate-prefix/src/sdl3-populate-stamp/sdl3-populate-configure

sdl3-populate-prefix/src/sdl3-populate-stamp/sdl3-populate-download: sdl3-populate-prefix/src/sdl3-populate-stamp/sdl3-populate-gitinfo.txt
sdl3-populate-prefix/src/sdl3-populate-stamp/sdl3-populate-download: sdl3-populate-prefix/src/sdl3-populate-stamp/sdl3-populate-mkdir
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/evanwu03/projects/dohyo-template/src/_deps/sdl3-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Performing download step (git clone) for 'sdl3-populate'"
	cd /home/evanwu03/projects/dohyo-template/src/_deps && /usr/bin/cmake -P /home/evanwu03/projects/dohyo-template/src/_deps/sdl3-subbuild/sdl3-populate-prefix/tmp/sdl3-populate-gitclone.cmake
	cd /home/evanwu03/projects/dohyo-template/src/_deps && /usr/bin/cmake -E touch /home/evanwu03/projects/dohyo-template/src/_deps/sdl3-subbuild/sdl3-populate-prefix/src/sdl3-populate-stamp/sdl3-populate-download

sdl3-populate-prefix/src/sdl3-populate-stamp/sdl3-populate-install: sdl3-populate-prefix/src/sdl3-populate-stamp/sdl3-populate-build
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/evanwu03/projects/dohyo-template/src/_deps/sdl3-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "No install step for 'sdl3-populate'"
	cd /home/evanwu03/projects/dohyo-template/src/_deps/sdl3-build && /usr/bin/cmake -E echo_append
	cd /home/evanwu03/projects/dohyo-template/src/_deps/sdl3-build && /usr/bin/cmake -E touch /home/evanwu03/projects/dohyo-template/src/_deps/sdl3-subbuild/sdl3-populate-prefix/src/sdl3-populate-stamp/sdl3-populate-install

sdl3-populate-prefix/src/sdl3-populate-stamp/sdl3-populate-mkdir:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/evanwu03/projects/dohyo-template/src/_deps/sdl3-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Creating directories for 'sdl3-populate'"
	/usr/bin/cmake -Dcfgdir= -P /home/evanwu03/projects/dohyo-template/src/_deps/sdl3-subbuild/sdl3-populate-prefix/tmp/sdl3-populate-mkdirs.cmake
	/usr/bin/cmake -E touch /home/evanwu03/projects/dohyo-template/src/_deps/sdl3-subbuild/sdl3-populate-prefix/src/sdl3-populate-stamp/sdl3-populate-mkdir

sdl3-populate-prefix/src/sdl3-populate-stamp/sdl3-populate-patch: sdl3-populate-prefix/src/sdl3-populate-stamp/sdl3-populate-patch-info.txt
sdl3-populate-prefix/src/sdl3-populate-stamp/sdl3-populate-patch: sdl3-populate-prefix/src/sdl3-populate-stamp/sdl3-populate-update
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/evanwu03/projects/dohyo-template/src/_deps/sdl3-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "No patch step for 'sdl3-populate'"
	/usr/bin/cmake -E echo_append
	/usr/bin/cmake -E touch /home/evanwu03/projects/dohyo-template/src/_deps/sdl3-subbuild/sdl3-populate-prefix/src/sdl3-populate-stamp/sdl3-populate-patch

sdl3-populate-prefix/src/sdl3-populate-stamp/sdl3-populate-update:
.PHONY : sdl3-populate-prefix/src/sdl3-populate-stamp/sdl3-populate-update

sdl3-populate-prefix/src/sdl3-populate-stamp/sdl3-populate-test: sdl3-populate-prefix/src/sdl3-populate-stamp/sdl3-populate-install
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/evanwu03/projects/dohyo-template/src/_deps/sdl3-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "No test step for 'sdl3-populate'"
	cd /home/evanwu03/projects/dohyo-template/src/_deps/sdl3-build && /usr/bin/cmake -E echo_append
	cd /home/evanwu03/projects/dohyo-template/src/_deps/sdl3-build && /usr/bin/cmake -E touch /home/evanwu03/projects/dohyo-template/src/_deps/sdl3-subbuild/sdl3-populate-prefix/src/sdl3-populate-stamp/sdl3-populate-test

sdl3-populate-prefix/src/sdl3-populate-stamp/sdl3-populate-update: sdl3-populate-prefix/tmp/sdl3-populate-gitupdate.cmake
sdl3-populate-prefix/src/sdl3-populate-stamp/sdl3-populate-update: sdl3-populate-prefix/src/sdl3-populate-stamp/sdl3-populate-update-info.txt
sdl3-populate-prefix/src/sdl3-populate-stamp/sdl3-populate-update: sdl3-populate-prefix/src/sdl3-populate-stamp/sdl3-populate-download
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/evanwu03/projects/dohyo-template/src/_deps/sdl3-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Performing update step for 'sdl3-populate'"
	cd /home/evanwu03/projects/dohyo-template/src/_deps/sdl3-src && /usr/bin/cmake -Dcan_fetch=YES -P /home/evanwu03/projects/dohyo-template/src/_deps/sdl3-subbuild/sdl3-populate-prefix/tmp/sdl3-populate-gitupdate.cmake

sdl3-populate: CMakeFiles/sdl3-populate
sdl3-populate: CMakeFiles/sdl3-populate-complete
sdl3-populate: sdl3-populate-prefix/src/sdl3-populate-stamp/sdl3-populate-build
sdl3-populate: sdl3-populate-prefix/src/sdl3-populate-stamp/sdl3-populate-configure
sdl3-populate: sdl3-populate-prefix/src/sdl3-populate-stamp/sdl3-populate-download
sdl3-populate: sdl3-populate-prefix/src/sdl3-populate-stamp/sdl3-populate-install
sdl3-populate: sdl3-populate-prefix/src/sdl3-populate-stamp/sdl3-populate-mkdir
sdl3-populate: sdl3-populate-prefix/src/sdl3-populate-stamp/sdl3-populate-patch
sdl3-populate: sdl3-populate-prefix/src/sdl3-populate-stamp/sdl3-populate-test
sdl3-populate: sdl3-populate-prefix/src/sdl3-populate-stamp/sdl3-populate-update
sdl3-populate: CMakeFiles/sdl3-populate.dir/build.make
.PHONY : sdl3-populate

# Rule to build all files generated by this target.
CMakeFiles/sdl3-populate.dir/build: sdl3-populate
.PHONY : CMakeFiles/sdl3-populate.dir/build

CMakeFiles/sdl3-populate.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sdl3-populate.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sdl3-populate.dir/clean

CMakeFiles/sdl3-populate.dir/depend:
	cd /home/evanwu03/projects/dohyo-template/src/_deps/sdl3-subbuild && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/evanwu03/projects/dohyo-template/src/_deps/sdl3-subbuild /home/evanwu03/projects/dohyo-template/src/_deps/sdl3-subbuild /home/evanwu03/projects/dohyo-template/src/_deps/sdl3-subbuild /home/evanwu03/projects/dohyo-template/src/_deps/sdl3-subbuild /home/evanwu03/projects/dohyo-template/src/_deps/sdl3-subbuild/CMakeFiles/sdl3-populate.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/sdl3-populate.dir/depend
