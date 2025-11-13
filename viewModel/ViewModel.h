#pragma once

#include <QObject>

#include "model/AlbumModel.h"
#include "model/SongModel.h"

class ViewModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(AlbumModel* albumModel READ getAlbumModel WRITE setAlbumModel)
    Q_PROPERTY(SongModel* songModel READ getSongModel WRITE setSongModel NOTIFY songModelChanged)

    AlbumModel *albumModel{nullptr};
    SongModel *songModel{nullptr};

public:
    explicit ViewModel(QObject *parent = nullptr);
    ~ViewModel();

signals:
    void albumChanged(const Album& album);
    void songChanged(const Song& song);
    void songModelChanged();

public slots:
    AlbumModel* getAlbumModel() const { return albumModel; }
    void setAlbumModel(AlbumModel* model);

    SongModel* getSongModel() const { return songModel; }
    void setSongModel(SongModel* model);

    void setAlbum(const QString& albumTitle);
    void playTrack(const QString& trackTitle);
    void pauseTrack();
    void nextTrack();
    void previousTrack();

private:
    QString currentAlbum;
    QString currentAlbumCover;
    QList<Song> currentAlbumSongs;
    QString currentTrack;
    int currentPosition{0};
};
