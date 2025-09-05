project(List)

file(GLOB_RECURSE SOURCE_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/Source/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Include/${PROJECT_NAME}/*.h )

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES}
        test/main.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE  ${CMAKE_CURRENT_SOURCE_DIR}/Include/${PROJECT_NAME})
target_include_directories(${PROJECT_NAME} PUBLIC  ${CMAKE_CURRENT_SOURCE_DIR}/Include/)

#target_link_libraries(${PROJECT_NAME} PUBLIC IContainer)

include("unittest.cmake")