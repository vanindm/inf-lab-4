cmake_minimum_required(VERSION 3.10)

project(Lab4)
set(LAB3_SRC_LIST src/*.cpp)

include(CTest)
set(MemoryCheckCommand valgrind)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++23 -Wall -g")

add_executable(userInterface         src/userInterface.cpp)
add_executable(binaryTreeTestExec    src/binaryTreeTest.cpp)
add_executable(setTestExec           src/setTest.cpp)
add_executable(largeDataTestExec     src/largeDataTest.cpp)

target_include_directories(userInterface          PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(binaryTreeTestExec     PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(setTestExec            PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(largeDataTestExec      PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_subdirectory(PATypes)
target_link_libraries(userInterface              PATypes)
target_link_libraries(binaryTreeTestExec         PATypes)
target_link_libraries(setTestExec                PATypes)
target_link_libraries(largeDataTestExec          PATypes)

enable_testing()

add_test(success_binaryTreeTest binaryTreeTestExec)
add_test(success_setTest        setTestExec)