cmake_minimum_required(VERSION 3.27)

project(Server LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Network Qml)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Network Qml)

add_executable(Server
    server.cpp
    ../lib/networkconnector.h
    ../lib/networkconnector.cpp
    ../lib/stringprocessor.h
    ../lib/stringprocessor.cpp
    ../lib/filelogger.h
    ../lib/filelogger.cpp
)
target_link_libraries(Server Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Network Qt${QT_VERSION_MAJOR}::Qml)

include(GNUInstallDirs)
install(TARGETS Server
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
