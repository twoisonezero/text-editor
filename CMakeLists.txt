cmake_minimum_required(VERSION 3.5)
project(text-editor)
#set(CMAKE_C_COMPILER gcc)
set(PROJECT_EXECUTABLE_NAME "steelseditor")

macro(package_add_test TESTNAME)
	add_executable(${TESTNAME} ${ARGN})
	target_link_libraries(${TESTNAME} gtest gmock gtest_main ${PROJECT_NAME})
	add_test(NAME ${TESTNAME} COMMAND ${TESTNAME})
	set_target_properties(${TESTNAME} PROPERTIES FOLDER tests)
endmacro()

add_subdirectory(extern/googletest)
set_target_properties(gtest PROPERTIES FOLDER extern)
set_target_properties(gtest_main PROPERTIES FOLDER extern)
set_target_properties(gmock PROPERTIES FOLDER extern)
set_target_properties(gmock_main PROPERTIES FOLDER extern)
enable_testing()

file(GLOB SOURCES "*.c" "*.h")
list(REMOVE_ITEM SOURCES main.c)
add_library(${PROJECT_NAME} ${SOURCES})

add_executable(${PROJECT_EXECUTABLE_NAME} main.c)
target_link_libraries(${PROJECT_EXECUTABLE_NAME} libtermbox.a)
target_link_libraries(${PROJECT_EXECUTABLE_NAME} ${PROJECT_NAME})

package_add_test(sequence-test1 sequence-test1.cpp)
package_add_test(sequence-test2 sequence-test2.cpp)

