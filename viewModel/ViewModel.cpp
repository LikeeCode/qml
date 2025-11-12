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
    if (songModel) songModel->setParent(this);
}

void ViewModel::setAlbum(const QString& albumTitle) {
    auto info = albumModel->getAlbumInfo(albumTitle);
    currentAlbum = info.title;
    currentAlbumSongs = songsList[albumTitle];
    if (songModel) {
        songModel->setAlbum(currentAlbum);
    }
    emit albumChanged(info.title, info.artist, info.year, info.cover);
}

void ViewModel::playTrack(const QString& trackTitle) {
    currentTrack = trackTitle;
    for(const auto& song : currentAlbumSongs){
        if(currentTrack == song.title){
            emit songChanged(song.title, song.artist, song.duration, song.album);
            break;
        }
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
