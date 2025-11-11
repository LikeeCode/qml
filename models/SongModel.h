#pragma once

#include <QAbstractListModel>
#include <QObject>
#include <QList>

class SongModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum SongRoles {
        TitleRole = Qt::UserRole + 1,
        ArtistRole,
        DurationRole,
        AlbumRole
    };

    explicit SongModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;
    void addSong(const QString &title, const QString &artist, int duration, const QString &album);
private:
    struct Song {
        QString title;
        QString artist;
        int duration; // in seconds
        QString album;
    };
    QList<Song> m_songs;
};
