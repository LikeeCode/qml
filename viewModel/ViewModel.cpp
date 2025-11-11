#include "ViewModel.h"
#include "MediaList.h"

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

    albumModel->addAlbum(albumsList["Abbey Road"]);
    albumModel->addAlbum(albumsList["The Dark Side of the Moon"]);
    albumModel->addAlbum(albumsList["Thriller"]);
    albumModel->addAlbum(albumsList["Back in Black"]);
}

void ViewModel::createSongsList()
{
    if (!songModel) {
        songModel = new SongModel(this);
    }
}
