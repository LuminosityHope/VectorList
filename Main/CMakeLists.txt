include_directories(List)
include_directories(Vector)
add_executable(Main main.cpp)
target_link_libraries(Main List Vector)
