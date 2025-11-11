#pragma once

#include <QString>
#include <QHash>
#include <QList>

struct Album
{
    QString title;
    QString artist;
    int year;
    QString cover;
};

struct Song {
    QString title;
    QString artist;
    int duration; // in seconds
    QString album;
};

extern QHash<QString, Album> albumsList;
extern QHash<QString, QList<Song>> songsList;
