#include "PlayerModel.h"

PlayerModel::PlayerModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

int PlayerModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return 0; // Placeholder: Replace with actual data count
}

QVariant PlayerModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // Placeholder: Replace with actual data retrieval logic
    switch (role) {
    case TrackRole:
        return QString("Track %1").arg(index.row() + 1);
    case ArtistRole:
        return QString("Artist %1").arg(index.row() + 1);
    case DurationRole:
        return QString("3:30");
    case IsPlayingRole:
        return false;
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> PlayerModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[TrackRole] = "track";
    roles[ArtistRole] = "artist";
    roles[DurationRole] = "duration";
    roles[IsPlayingRole] = "isPlaying";
    return roles;
}
