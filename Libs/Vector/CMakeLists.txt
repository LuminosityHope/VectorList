##add_library(Vector ${CMAKE_CURRENT_SOURCE_DIR}/Source/vector.cpp)
##target_include_directories(Vector ${CMAKE_CURRENT_SOURCE_DIR}/Include
        ##${CMAKE_SOURCE_DIR}/Libs/IContainer/Include)
##target_link_libraries(List IContainer)##
project(Vector)
file(GLOB_RECURSE SOURCE_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/Source/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Include/*.h )

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES}
        ${CMAKE_CURRENT_SOURCE_DIR}/Test/vectorTest.cpp)

#add_library(Vector ${CMAKE_CURRENT_SOURCE_DIR}/Source/vector.cpp  ${CMAKE_CURRENT_SOURCE_DIR}/Include/vector.h )
target_include_directories(${PROJECT_NAME} PRIVATE  ${CMAKE_CURRENT_SOURCE_DIR}/Include)
target_link_libraries(${PROJECT_NAME} INTERFACE IContainer)