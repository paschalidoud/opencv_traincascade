cmake_minimum_required (VERSION 2.6) 

FIND_PACKAGE( OpenCV REQUIRED )

PROJECT(rectangle) 
SET(SRC
    src/rectangle.cpp      
)
ADD_EXECUTABLE( ${PROJECT_NAME} ${SRC} )
TARGET_LINK_LIBRARIES( ${PROJECT_NAME}  ${OpenCV_LIBS} )
