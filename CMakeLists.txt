cmake_minimum_required(VERSION 3.10)

project(Lab3)
set(LAB3_SRC_LIST src/*.cpp)

include(CTest)
set(MemoryCheckCommand valgrind)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++23 -Wall -g")

add_executable(arraySequenceTestExec src/arraySequenceTest.cpp)
add_executable(listSequenceTestExec  src/listSequenceTest.cpp)
add_executable(argParserTestExec     src/argParserTest.cpp)
add_executable(userInterface         src/userInterface.cpp)
add_executable(queueTestExec         src/queueTest.cpp)

target_include_directories(argParserTestExec PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(userInterface PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_subdirectory(PATypes)
target_link_libraries(arraySequenceTestExec PATypes)
target_link_libraries(listSequenceTestExec  PATypes)
target_link_libraries(argParserTestExec     PATypes)
target_link_libraries(userInterface         PATypes)
target_link_libraries(queueTestExec         PATypes)

enable_testing()

add_test(success_arraySequenceTest arraySequenceTestExec)
add_test(success_listSequenceTest  listSequenceTestExec)
add_test(success_argParserTest     argParserTestExec)
add_test(success_queueTest         queueTestExec)
