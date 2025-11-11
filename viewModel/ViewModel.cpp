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

void ViewModel::createAlbumsList()
{
    if (!albumModel) {
        albumModel = new AlbumModel(this);
    }

    albumModel->addAlbum("Abbey Road", "The Beatles", 1969, "covers/abbey_road.jpg");
    albumModel->addAlbum("The Dark Side of the Moon", "Pink Floyd", 1973, "covers/dark_side_moon.jpg");
    albumModel->addAlbum("Thriller", "Michael Jackson", 1982, "covers/thriller.jpg");
    albumModel->addAlbum("Back in Black", "AC/DC", 1980, "covers/back_in_black.jpg");
}

void ViewModel::createSongsList()
{
    if (!songModel) {
        songModel = new SongModel(this);
    }

    songModel->addSong("Come Together", "The Beatles", 259, "Abbey Road");
    songModel->addSong("Money", "Pink Floyd", 382, "The Dark Side of the Moon");
    songModel->addSong("Billie Jean", "Michael Jackson", 294, "Thriller");
    songModel->addSong("Hells Bells", "AC/DC", 312, "Back in Black");
}
