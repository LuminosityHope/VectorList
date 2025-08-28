add_library(List ${CMAKE_SOURCE_DIR}/Libs/List/Include/list.h ${CMAKE_SOURCE_DIR}/Libs/List/Source/list.cpp)
target_include_directories(List INTERFACE Libs/List/Include)
target_link_libraries(List PUBLIC IContainer)