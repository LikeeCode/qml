#include "ViewModel.h"

ViewModel::ViewModel(QObject *parent) : QObject(parent)
{
}

void ViewModel::setAlbumModel(AlbumModel* model) {
    if (albumModel == model) return;
    if (albumModel) albumModel->deleteLater(); // or allow ownership transfer
    albumModel = model;
    if (albumModel) albumModel->setParent(this);
}

void ViewModel::setPlayerModel(PlayerModel* model) {
    if (playerModel == model) return;
    if (playerModel) playerModel->deleteLater(); // or allow ownership transfer
    playerModel = model;
    if (playerModel) playerModel->setParent(this);
}

void ViewModel::setSongModel(SongModel* model) {
    if (songModel == model) return;
    if (songModel) songModel->deleteLater(); // or allow ownership transfer
    songModel = model;
    if (songModel){
        songModel->setParent(this);
        connect(songModel, &SongModel::albumChanged, this, [this](const QString &album){
            currentAlbum = album;
            emit albumChanged(currentAlbum); });

        connect(songModel, &SongModel::songChanged, this, [this](const Song &song){
            currentTrack = song.title;
            emit songChanged(currentTrack); });
    }
}

void ViewModel::setAlbum(const QString& albumTitle) {
    currentAlbum = albumTitle;
    if (songModel) {
        songModel->setAlbum(currentAlbum);
        emit songModelChanged();
    }
}

void ViewModel::playTrack(const QString& trackTitle) {
    currentTrack = trackTitle;
    if (songModel)
    {
        songModel->setSong(currentTrack);
    }
}

void ViewModel::pauseTrack() {
    // Logic to pause the track
}

void ViewModel::nextTrack() {
    // Logic to go to the next track
}

void ViewModel::previousTrack() {
    // Logic to go to the previous track
}
