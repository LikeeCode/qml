import QtQuick
import QtQuick.Controls
import Hamilton.Models 1.0

Item{
    id: root

    function updateAlbum(title, artist, year, cover){
        albumCover.source = "qrc:/Hamilton/" + cover
    }

    function updateSong(song, artist, duration){
        nowPlayingTitle.text = song
    }

    Rectangle{
        id: header
        anchors.fill: parent
        color: '#373647'
        border.color: '#4a4a64'
        border.width: 1

        Text{
            id: nowPlayingTitle
            anchors.top: parent.top
            width: parent.width
            height: 50
            color: 'white'
            font.pixelSize: 24
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }

        Image{
            id: albumCover
            anchors.top: nowPlayingTitle.bottom
            source: "qrc:/Hamilton/images/album-cover-default.png"
            width: parent.width
            fillMode: Image.PreserveAspectFit

            Connections {
                target: viewModel
                function onAlbumChanged(title, artist, year, cover) {
                    updateAlbum(title, artist, year, cover)
                }
                function onSongChanged(song, artist, duration, album) {
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
