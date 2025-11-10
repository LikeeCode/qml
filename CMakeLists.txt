cmake_minimum_required(VERSION 3.16)

project(MinimalQML VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)

qt_add_executable(appMinimalQML
    main.cpp
)

qt_add_qml_module(appMinimalQML
    URI Hamilton
    VERSION 1.0
    QML_FILES main.qml
)

target_link_libraries(appMinimalQML
    PRIVATE Qt6::Quick)