#pragma once

#include <QObject>

#include "model/AlbumModel.h"
#include "model/PlayerModel.h"
#include "model/SongModel.h"

class ViewModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(AlbumModel *albumModel READ getAlbumModel WRITE setAlbumModel NOTIFY albumModelChanged)
    Q_PROPERTY(PlayerModel *playerModel READ getPlayerModel WRITE setPlayerModel NOTIFY playerModelChanged)
    Q_PROPERTY(SongModel *songModel READ getSongModel WRITE setSongModel NOTIFY songModelChanged)

    AlbumModel *albumModel{nullptr};
    PlayerModel *playerModel{nullptr};
    SongModel *songModel{nullptr};

public:
    explicit ViewModel(QObject *parent = nullptr);

signals:
    void albumModelChanged();
    void playerModelChanged();
    void songModelChanged();
    void activeAlbumChanged(const QString& albumTitle);
    void trackChanged(const QString& trackTitle);

public slots:
    AlbumModel* getAlbumModel() const { return albumModel; }
    void setAlbumModel(AlbumModel* model);

    PlayerModel* getPlayerModel() const { return playerModel; }
    void setPlayerModel(PlayerModel* model);

    SongModel* getSongModel() const { return songModel; }
    void setSongModel(SongModel* model);

    // qml invokable methods
    void setActiveAlbum(const QString& albumTitle);
    QString getActiveAlbum() const { return currentAlbum; }
    void playTrack(const QString& trackTitle);
    void pauseTrack();
    void nextTrack();
    void previousTrack();

private:
    QString currentAlbum;
    QString currentTrack;
    int currentPosition{0};
};
