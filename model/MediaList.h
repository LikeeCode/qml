#pragma once

#include <QString>
#include <QHash>
#include <QList>
#include <QMetaType> // Required for Q_DECLARE_METATYPE

// A lightweight struct for Album data.
// Q_GADGET allows it to have Q_PROPERTY without the overhead of QObject.
struct Album
{
    Q_GADGET

    // Expose members to the meta-object system (and thus QML)
    Q_PROPERTY(QString title MEMBER title CONSTANT)
    Q_PROPERTY(QString artist MEMBER artist CONSTANT)
    Q_PROPERTY(int year MEMBER year CONSTANT)
    Q_PROPERTY(QString cover MEMBER cover CONSTANT)

public:
    QString title;
    QString artist;
    int year;
    QString cover;
};

// A lightweight struct for Song data.
struct Song {
    Q_GADGET

    Q_PROPERTY(QString title MEMBER title CONSTANT)
    Q_PROPERTY(QString artist MEMBER artist CONSTANT)
    Q_PROPERTY(int duration MEMBER duration CONSTANT)
    Q_PROPERTY(QString album MEMBER album CONSTANT)

public:
    QString title;
    QString artist;
    int duration; // in seconds
    QString album;
};

// The global lists remain as value-based containers.
extern QHash<QString, Album> albumsList;
extern QHash<QString, QList<Song>> songsList;

// Declare the types to Qt's meta-type system so they can be used in signals/slots
// and wrapped in QVariant.
Q_DECLARE_METATYPE(Album)
Q_DECLARE_METATYPE(Song)
Q_DECLARE_METATYPE(QList<Song>)
