cmake_minimum_required(VERSION 3.5.0)

project(OpenCV)

find_package( OpenCV REQUIRED )

add_executable		(displayImage 	src/displayImage.cpp)
target_link_libraries	(displayImage 	${OpenCV_LIBS})

add_executable          (displayAVI 	src/displayAVI.cpp)
target_link_libraries   (displayAVI 	${OpenCV_LIBS})

add_executable          (sliderAVI 	src/sliderAVI.cpp)
target_link_libraries   (sliderAVI 	${OpenCV_LIBS})

