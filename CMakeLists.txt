cmake_minimum_required (VERSION 3.0)
project (text-editor)
set (CMAKE_C_COMPILER gcc)
file (GLOB SOURCES "*.c" "*.h")
add_executable (${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} libtermbox.a)
