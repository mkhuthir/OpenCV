
# By: Muthanna A. Attyah 2017
#

cmake_minimum_required(VERSION 3.5.0)

project(OpenCV)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package( OpenCV REQUIRED )

# OpenCV Examples:
add_executable(displayAVI 	src/displayAVI.cpp)
add_executable(sliderAVI 	src/sliderAVI.cpp)
add_executable(smoothImage 	src/smoothImage.cpp)
add_executable(pyrdownImage src/pyrdownImage.cpp)
add_executable(canny     	src/canny.cpp)
add_executable(pipe         src/pipe.cpp)
add_executable(pipe2        src/pipe2.cpp)
add_executable(showImage    src/showImage.cpp)
add_executable(showImage2   src/showImage2.cpp)
add_executable(camera       src/camera.cpp)
add_executable(grayVideo    src/grayVideo.cpp)
add_executable(inimat       src/inimat.cpp)
add_executable(cvmat        src/cvmat.cpp)
add_executable(info         src/info.cpp)


target_link_libraries(sliderAVI 	${OpenCV_LIBS})
target_link_libraries(displayAVI 	${OpenCV_LIBS})
target_link_libraries(smoothImage 	${OpenCV_LIBS})
target_link_libraries(pyrdownImage 	${OpenCV_LIBS})
target_link_libraries(canny      	${OpenCV_LIBS})
target_link_libraries(pipe          ${OpenCV_LIBS})
target_link_libraries(pipe2         ${OpenCV_LIBS})
target_link_libraries(showImage     ${OpenCV_LIBS})
target_link_libraries(showImage2    ${OpenCV_LIBS})
target_link_libraries(camera        ${OpenCV_LIBS})
target_link_libraries(grayVideo     ${OpenCV_LIBS})
target_link_libraries(inimat        ${OpenCV_LIBS})
target_link_libraries(cvmat         ${OpenCV_LIBS})
target_link_libraries(info          ${OpenCV_LIBS})
