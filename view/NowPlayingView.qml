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

        Column{
            anchors.fill: parent

            Text{
                id: nowPlayingTitle
                anchors.top: parent.top
                width: parent.width
                height: 50
                color: 'white'
                font.pixelSize: 24
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                text: "No song selected"
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

            Row{
                id: controls
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 20
                width: parent.width
                spacing: 0

                Image{
                    source: "qrc:/Hamilton/images/controls/rewind.png"
                    width: parent.width / 3
                    height: 100
                    fillMode: Image.PreserveAspectFit
                }

                Image{
                    source: "qrc:/Hamilton/images/controls/play.png"
                    width: parent.width / 3
                    height: 100
                    fillMode: Image.PreserveAspectFit
                }

                Image{
                    source: "qrc:/Hamilton/images/controls/fast-forward.png"
                    width: parent.width / 3
                    height: 100
                    fillMode: Image.PreserveAspectFit
                }
            }
        }
    }
}
