cmake_minimum_required(VERSION 3.27)
project(MyTests)

find_package(Qt6 COMPONENTS Core REQUIRED)

file(GLOB TEST_SOURCES "*.cpp")
file(GLOB SRC_SOURCES "../lib/stringprocessor.cpp")
#file(GLOB LIB_SOURCES "../Server/*.cpp")


add_executable(MyTests ${TEST_SOURCES} ${SRC_SOURCES})# ${LIB_SOURCES})

# Свяжите ваш исполняемый файл с библиотеками Google Test и Qt6
target_link_libraries(MyTests gtest_main Qt6::Core)

# Включите Google Test
include(GoogleTest)
gtest_discover_tests(MyTests)
