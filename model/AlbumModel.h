#pragma once

#include <QAbstractListModel>
#include <QObject>
#include <QList>

#include "MediaList.h"

class AlbumModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum AlbumRoles {
        TitleRole = Qt::UserRole + 1,
        ArtistRole,
        YearRole,
        CoverRole
    };

    explicit AlbumModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;
    void addAlbum(const Album &album);
    void addAlbum(const QString &title, const QString &artist, int year, const QString &cover);
    void removeAlbum(const QString &title);
    QString getAlbumCover(const QString &title) const;

private:
    QList<Album> m_albums;
};