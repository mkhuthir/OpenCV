# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/mkhuthir/openCV

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mkhuthir/openCV

# Include any dependencies generated for this target.
include CMakeFiles/info.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/info.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/info.dir/flags.make

CMakeFiles/info.dir/src/info.cpp.o: CMakeFiles/info.dir/flags.make
CMakeFiles/info.dir/src/info.cpp.o: src/info.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mkhuthir/openCV/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/info.dir/src/info.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/info.dir/src/info.cpp.o -c /home/mkhuthir/openCV/src/info.cpp

CMakeFiles/info.dir/src/info.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/info.dir/src/info.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mkhuthir/openCV/src/info.cpp > CMakeFiles/info.dir/src/info.cpp.i

CMakeFiles/info.dir/src/info.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/info.dir/src/info.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mkhuthir/openCV/src/info.cpp -o CMakeFiles/info.dir/src/info.cpp.s

CMakeFiles/info.dir/src/info.cpp.o.requires:

.PHONY : CMakeFiles/info.dir/src/info.cpp.o.requires

CMakeFiles/info.dir/src/info.cpp.o.provides: CMakeFiles/info.dir/src/info.cpp.o.requires
	$(MAKE) -f CMakeFiles/info.dir/build.make CMakeFiles/info.dir/src/info.cpp.o.provides.build
.PHONY : CMakeFiles/info.dir/src/info.cpp.o.provides

CMakeFiles/info.dir/src/info.cpp.o.provides.build: CMakeFiles/info.dir/src/info.cpp.o


# Object files for target info
info_OBJECTS = \
"CMakeFiles/info.dir/src/info.cpp.o"

# External object files for target info
info_EXTERNAL_OBJECTS =

bin/info: CMakeFiles/info.dir/src/info.cpp.o
bin/info: CMakeFiles/info.dir/build.make
bin/info: /usr/lib/x86_64-linux-gnu/libopencv_videostab.so.2.4.9
bin/info: /usr/lib/x86_64-linux-gnu/libopencv_ts.so.2.4.9
bin/info: /usr/lib/x86_64-linux-gnu/libopencv_superres.so.2.4.9
bin/info: /usr/lib/x86_64-linux-gnu/libopencv_stitching.so.2.4.9
bin/info: /usr/lib/x86_64-linux-gnu/libopencv_ocl.so.2.4.9
bin/info: /usr/lib/x86_64-linux-gnu/libopencv_gpu.so.2.4.9
bin/info: /usr/lib/x86_64-linux-gnu/libopencv_contrib.so.2.4.9
bin/info: /usr/lib/x86_64-linux-gnu/libopencv_photo.so.2.4.9
bin/info: /usr/lib/x86_64-linux-gnu/libopencv_legacy.so.2.4.9
bin/info: /usr/lib/x86_64-linux-gnu/libopencv_video.so.2.4.9
bin/info: /usr/lib/x86_64-linux-gnu/libopencv_objdetect.so.2.4.9
bin/info: /usr/lib/x86_64-linux-gnu/libopencv_ml.so.2.4.9
bin/info: /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so.2.4.9
bin/info: /usr/lib/x86_64-linux-gnu/libopencv_features2d.so.2.4.9
bin/info: /usr/lib/x86_64-linux-gnu/libopencv_highgui.so.2.4.9
bin/info: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.2.4.9
bin/info: /usr/lib/x86_64-linux-gnu/libopencv_flann.so.2.4.9
bin/info: /usr/lib/x86_64-linux-gnu/libopencv_core.so.2.4.9
bin/info: CMakeFiles/info.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mkhuthir/openCV/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin/info"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/info.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/info.dir/build: bin/info

.PHONY : CMakeFiles/info.dir/build

CMakeFiles/info.dir/requires: CMakeFiles/info.dir/src/info.cpp.o.requires

.PHONY : CMakeFiles/info.dir/requires

CMakeFiles/info.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/info.dir/cmake_clean.cmake
.PHONY : CMakeFiles/info.dir/clean

CMakeFiles/info.dir/depend:
	cd /home/mkhuthir/openCV && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mkhuthir/openCV /home/mkhuthir/openCV /home/mkhuthir/openCV /home/mkhuthir/openCV /home/mkhuthir/openCV/CMakeFiles/info.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/info.dir/depend

