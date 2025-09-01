project(IContainer)
file(GLOB_RECURSE SOURCE_FILES
        ${CMAKE_SOURCE_DIR}/Libs/Vector/Include/*.h ${CMAKE_SOURCE_DIR}/Libs/List/Include/*.h)

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES}
        ../Vector/Test/vectorTest.cpp)
target_include_directories(IContainer INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/Include/*.h  )

