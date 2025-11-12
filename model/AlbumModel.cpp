#include "AlbumModel.h"

AlbumModel::AlbumModel(QObject *parent)
    : QAbstractListModel(parent)
{
    for (auto album: albumsList)
    {
        addAlbum(album);
    }
}

int AlbumModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return m_albums.count();
}

QVariant AlbumModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() < 0 || index.row() >= m_albums.count())
        return QVariant();

    const Album &album = m_albums[index.row()];
    switch (role) {
    case TitleRole:
        return album.title;
    case ArtistRole:
        return album.artist;
    case YearRole:
        return album.year;
    case CoverRole:
        return album.cover;
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> AlbumModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[TitleRole] = "title";
    roles[ArtistRole] = "artist";
    roles[YearRole] = "year";
    roles[CoverRole] = "cover";
    return roles;
}

void AlbumModel::addAlbum(const Album &album)
{
    beginInsertRows(QModelIndex(), m_albums.count(), m_albums.count());
    m_albums.append(album);
    endInsertRows();
}

void AlbumModel::addAlbum(const QString &title, const QString &artist, int year, const QString &cover)
{
    beginInsertRows(QModelIndex(), m_albums.count(), m_albums.count());
    m_albums.append({title, artist, year, cover});
    endInsertRows();
}

void AlbumModel::removeAlbum(const QString &title)
{
    for (int i = 0; i < m_albums.count(); ++i) {
        if (m_albums[i].title == title) {
            beginRemoveRows(QModelIndex(), i, i);
            m_albums.removeAt(i);
            endRemoveRows();
            return;
        }
    }
}

Album AlbumModel::getAlbumInfo(const QString &title) const
{
    if(m_albums.isEmpty()) return {};

    for (const Album &album : m_albums) {
        if (album.title == title) {
            return album;
        }
    }

    return {};
}
