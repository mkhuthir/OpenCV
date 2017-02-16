
# By: Muthanna A. Attyah 2017
#

cmake_minimum_required(VERSION 3.5.0)

project(OpenCV)

find_package( OpenCV REQUIRED )

# OpenCV Examples:
add_executable(displayAVI 	src/displayAVI.cpp)
add_executable(sliderAVI 	src/sliderAVI.cpp)
add_executable(smoothImage 	src/smoothImage.cpp)
add_executable(pyrdownImage src/pyrdownImage.cpp)
add_executable(canny     	src/canny.cpp)
add_executable(cannypyr     src/cannypyr.cpp)
add_executable(showImage    src/showImage.cpp)
add_executable(showImage2   src/showImage2.cpp)


target_link_libraries(sliderAVI 	${OpenCV_LIBS})
target_link_libraries(displayAVI 	${OpenCV_LIBS})
target_link_libraries(smoothImage 	${OpenCV_LIBS})
target_link_libraries(pyrdownImage 	${OpenCV_LIBS})
target_link_libraries(canny      	${OpenCV_LIBS})
target_link_libraries(cannypyr      ${OpenCV_LIBS})
target_link_libraries(showImage     ${OpenCV_LIBS})
target_link_libraries(showImage2    ${OpenCV_LIBS})
