#pragma once

#include <QAbstractListModel>
#include <QObject>
#include <QList>

class PlayerModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum PlayerRoles {
        TrackRole = Qt::UserRole + 1,
        ArtistRole,
        DurationRole,
        IsPlayingRole
    };

    explicit PlayerModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;
};
