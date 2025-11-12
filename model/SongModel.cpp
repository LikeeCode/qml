#include "SongModel.h"

SongModel::SongModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

int SongModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return m_songs.count();
}

QVariant SongModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() < 0 || index.row() >= m_songs.count())
        return QVariant();

    const Song &song = m_songs.at(index.row());
    switch (role) {
    case TitleRole:
        return song.title;
    case ArtistRole:
        return song.artist;
    case DurationRole:
        return song.duration;
    case AlbumRole:
        return song.album;
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> SongModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[TitleRole] = "title";
    roles[ArtistRole] = "artist";
    roles[DurationRole] = "duration";
    roles[AlbumRole] = "album";
    return roles;
}

void SongModel::addSong(const QString &title, const QString &artist, int duration, const QString &album)
{
    beginInsertRows(QModelIndex(), m_songs.count(), m_songs.count());
    m_songs.append({title, artist, duration, album});
    endInsertRows();
}

void SongModel::setAlbum(const QString& albumTitle)
{
    if (songsList.contains(albumTitle))
    {
        clearSongs();
        beginInsertRows(QModelIndex(), 0, songsList[albumTitle].count() - 1);
        for(auto& song : songsList[albumTitle]){
            m_songs = songsList[albumTitle];
        }
        endInsertRows();
        emit albumChanged(albumTitle);
    }
}

void SongModel::clearSongs()
{
    beginResetModel();
    m_songs.clear();
    endResetModel();
}
