#pragma once

#include <QAbstractListModel>
#include <QObject>
#include <QList>

#include "MediaList.h"

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
    
    void setAlbum(const QString& album);

signals:
    void albumChanged(const QString& album);
    void songChanged(const Song& song);

private:
    QList<Song> m_songs;

    void clearSongs();
};
