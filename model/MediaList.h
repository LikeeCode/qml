#pragma once

#include <QString>
#include <QHash>

#include "model/AlbumModel.h"
#include "model/SongModel.h"

QHash<QString, Album> albumsList{
    {"Abbey Road", {"Abbey Road", "The Beatles", 1969, "images/album-cover-default.png"}},
    {"The Dark Side of the Moon", {"The Dark Side of the Moon", "Pink Floyd", 1973, "images/album-cover-default.png"}},
    {"Thriller", {"Thriller", "Michael Jackson", 1982, "images/album-cover-default.png"}},
    {"Back in Black", {"Back in Black", "AC/DC", 1980, "images/album-cover-default.png"}}};

QHash<QString, QList<Song>> songsList{
    {"Abbey Road", {
        {"Come Together", "The Beatles", 259, "Abbey Road"},
        {"Something", "The Beatles", 182, "Abbey Road"},
        {"Octopus's Garden", "The Beatles", 171, "Abbey Road"},
        {"Here Comes the Sun", "The Beatles", 185, "Abbey Road"}
    }},
    {"The Dark Side of the Moon", {
        {"Speak to Me", "Pink Floyd", 90, "The Dark Side of the Moon"},
        {"Breathe", "Pink Floyd", 163, "The Dark Side of the Moon"},
        {"Time", "Pink Floyd", 412, "The Dark Side of the Moon"},
        {"Money", "Pink Floyd", 382, "The Dark Side of the Moon"}
    }},
    {"Thriller", {
        {"Wanna Be Startin' Somethin'", "Michael Jackson", 362, "Thriller"},
        {"Thriller", "Michael Jackson", 358, "Thriller"},
        {"Beat It", "Michael Jackson", 258, "Thriller"},
        {"Billie Jean", "Michael Jackson", 294, "Thriller"}
    }},
    {"Back in Black", {
        {"Hells Bells", "AC/DC", 312, "Back in Black"},
        {"Shoot to Thrill", "AC/DC", 315, "Back in Black"},
        {"Back in Black", "AC/DC", 255, "Back in Black"},
        {"You Shook Me All Night Long", "AC/DC", 210, "Back in Black"}
    }}};