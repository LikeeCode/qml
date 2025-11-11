cmake_minimum_required(VERSION 3.16)

project(HamiltonQML VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.8 COMPONENTS Quick Core REQUIRED)

qt_add_executable(HamiltonQMLPlayer
    main.cpp
    model/MediaList.h
    model/MediaList.cpp
    model/AlbumModel.h
    model/AlbumModel.cpp
    model/SongModel.h
    model/SongModel.cpp
    model/PlayerModel.h
    model/PlayerModel.cpp
    viewModel/ViewModel.h
    viewModel/ViewModel.cpp
)

# Windows icon
if(WIN32)
    target_sources(HamiltonQMLPlayer PRIVATE "${CMAKE_CURRENT_LIST_DIR}/appicon.rc")
endif()

qt_add_qml_module(HamiltonQMLPlayer
    URI Hamilton
    VERSION 1.0
    QML_FILES main.qml
        view/AlbumsList.qml
        view/NowPlayingView.qml
        view/SongsList.qml
    RESOURCES
        images/hamilton-logo.svg
        images/hamilton-logo.ico
        images/album-cover-default.png
)

target_link_libraries(HamiltonQMLPlayer
    PRIVATE Qt6::Quick Qt6::Core)
