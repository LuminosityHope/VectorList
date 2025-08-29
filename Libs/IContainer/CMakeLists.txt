project(IContainer)
file(GLOB_RECURSE SOURCE_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/Include/*.h ${CMAKE_SOURCE_DIR}/Libs/List/Source/*.cpp {CMAKE_SOURCE_DIR}/Libs/Vector/Source/*.cpp)

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})
target_include_directories(IContainer INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/Include/*.h)

