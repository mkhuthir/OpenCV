cmake_minimum_required(VERSION 3.5.0)

project(OpenCV)

find_package( OpenCV REQUIRED )

add_executable(displayImage src/displayImage.cpp)
add_executable(displayAVI 	src/displayAVI.cpp)
add_executable(sliderAVI 	src/sliderAVI.cpp)
add_executable(smoothImage 	src/smoothImage.cpp)

target_link_libraries(sliderAVI 	${OpenCV_LIBS})
target_link_libraries(displayImage 	${OpenCV_LIBS})
target_link_libraries(displayAVI 	${OpenCV_LIBS})
target_link_libraries(smoothImage 	${OpenCV_LIBS})

