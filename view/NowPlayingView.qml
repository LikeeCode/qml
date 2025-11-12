import QtQuick
import QtQuick.Controls
import Hamilton.Models 1.0

Item{
    id: root

    function updateAlbum(title, artist, year, cover){
        albumCover.source = "qrc:/Hamilton/" + cover
    }

    function updateSong(song, artist, duration){
        nowPlayingTitle.text = "Now Playing: " + song
    }

    Rectangle{
        id: header
        anchors.fill: parent
        // width: parent.width
        // height: parent.height
        color: '#373647'
        border.color: '#4a4a64'
        border.width: 1

        Text{
            id: nowPlayingTitle
            anchors.top: parent.top
            width: parent.width
            height: 50

            text: "Now Playing: "
            color: 'white'
            font.pixelSize: 24
        }

        Image{
            id: albumCover
            anchors.horizontalCenter: parent.horizontalCenter
            source: "qrc:/Hamilton/images/album-cover-default.png"
            // source: viewModel.activeAlbumCover ? "qrc:/Hamilton/" + viewModel.activeAlbumCover : ""
            width: 300
            fillMode: Image.PreserveAspectFit

            Connections {
                target: viewModel
                onAlbumChanged: function(title, artist, year, cover) {
                    updateAlbum(title, artist, year, cover)
                }
                onSongChanged: function(song, artist, duration, album) {
                    isActive = (title === song)
                    updateSong(song, artist, duration)
                }
            }
        }

        Item{
            id: playerControls
            anchors.bottom: parent.bottom
            width: parent.width
            height: 150

            Row{
                anchors.fill: parent
                spacing: 20

                Button{
                    text: "⏮️"
                    font.pixelSize: 32
                    width: 80
                    height: 80
                }

                Button{
                    text: "▶️"
                    font.pixelSize: 32
                    width: 80
                    height: 80
                }

                Button{
                    text: "⏭️"
                    font.pixelSize: 32
                    width: 80
                    height: 80
                }
            }
        }
    }
}
