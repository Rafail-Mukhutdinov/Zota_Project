cmake_minimum_required(VERSION 3.27)
project(MyTests LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Network)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Network)


file(GLOB TEST_SOURCES "*.cpp")
file(GLOB SRC_SOURCES "../lib/stringprocessor.cpp")



add_executable(MyTests ${TEST_SOURCES} ${SRC_SOURCES})
target_link_libraries(MyTests Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Network gtest_main gtest)

include(GNUInstallDirs)
install(TARGETS MyTests
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Включите Google Test
include(GoogleTest)
gtest_discover_tests(MyTests)
