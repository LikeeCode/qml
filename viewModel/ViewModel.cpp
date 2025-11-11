#include "ViewModel.h"

ViewModel::ViewModel(QObject *parent) : QObject(parent)
{
}

void ViewModel::setAlbumModel(AlbumModel* model) {
    if (albumModel == model) return;
    if (albumModel) albumModel->deleteLater(); // or allow ownership transfer
    albumModel = model;
    if (albumModel) albumModel->setParent(this);
    emit albumModelChanged();
}

void ViewModel::setPlayerModel(PlayerModel* model) {
    if (playerModel == model) return;
    if (playerModel) playerModel->deleteLater(); // or allow ownership transfer
    playerModel = model;
    if (playerModel) playerModel->setParent(this);
    emit playerModelChanged();
}

void ViewModel::setSongModel(SongModel* model) {
    if (songModel == model) return;
    if (songModel) songModel->deleteLater(); // or allow ownership transfer
    songModel = model;
    if (songModel) songModel->setParent(this);
    emit songModelChanged();
}

void ViewModel::setActiveAlbum(const QString& albumTitle) {
    currentAlbum = albumTitle;
    // Load songs for the selected album into the songModel
    if (songModel) {
        // Clear existing songs
        songModel->clearSongs();

        // Add songs from the selected album
        // if (songsList.contains(albumTitle)) {
        //     for (const Song& song : songsList[albumTitle]) {
        //         songModel->addSong(song.title, song.artist, song.duration, song.album);
        //     }
        // }
    }
}

void ViewModel::playTrack(const QString& trackTitle) {
    currentTrack = trackTitle;
    // Logic to play the track
    emit trackChanged(trackTitle);
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
