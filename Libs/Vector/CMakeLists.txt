##add_library(Vector ${CMAKE_CURRENT_SOURCE_DIR}/Source/vector.cpp)
##target_include_directories(Vector ${CMAKE_CURRENT_SOURCE_DIR}/Include
        ##${CMAKE_SOURCE_DIR}/Libs/IContainer/Include)
##target_link_libraries(List IContainer)##
add_library(Vector ${CMAKE_SOURCE_DIR}/Libs/Vector/Include/vector.h ${CMAKE_SOURCE_DIR}/Libs/Vector/Source/vector.cpp)
target_include_directories(Vector INTERFACE Libs/Vector/Include)
target_link_libraries(Vector PUBLIC IContainer)