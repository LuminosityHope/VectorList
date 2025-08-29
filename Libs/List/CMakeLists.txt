add_library(List ${CMAKE_CURRENT_SOURCE_DIR}/Include/list.h  ${CMAKE_CURRENT_SOURCE_DIR}/Source/list.cpp)
target_include_directories(List PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Include)
target_link_libraries(List INTERFACE IContainer)