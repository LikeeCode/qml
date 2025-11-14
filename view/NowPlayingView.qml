import QtQuick
import QtQuick.Controls
import Hamilton.Models 1.0
import "components" // Import the IconButton component

Item{
    id: root

    function updateAlbum(title, artist, year, cover){
        albumCover.source = "qrc:/Hamilton/" + cover
    }

    function updateSong(song, artist, duration){
        nowPlayingTitle.text = song
    }

    Connections {
        target: viewModel
        function onAlbumChanged(album) {
            updateAlbum(album.title, album.artist, album.year, album.cover)
        }
        function onSongChanged(song) {
            updateSong(song.title, song.artist, song.duration)
        }
    }

    Rectangle{
        id: header
        anchors.fill: parent
        color: '#373647'
        border.color: '#4a4a64'
        border.width: 1

        Column{
            id: content
            anchors.fill: parent

            Text{
                id: nowPlayingTitle
                anchors.top: parent.top
                width: parent.width
                height: parent.height * 0.12     // flexible height (12% of column)
                color: 'white'
                font.pixelSize: Math.max(14, parent.height * 0.04) // scale font with height
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                text: "No song selected"
            }

            Image{
                id: albumCover
                anchors.top: nowPlayingTitle.bottom
                anchors.bottom: controls.top        // stretch between title and controls
                anchors.left: parent.left
                anchors.right: parent.right
                source: "qrc:/Hamilton/images/album-cover-default.png"
                fillMode: Image.PreserveAspectFit
                smooth: true
                anchors.bottomMargin: 20
            }

            Row{
                id: controls
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 10
                width: parent.width
                height: Math.max(48, parent.height * 0.1)  // flexible controls height
                spacing: 0

                IconButton {
                    source: "qrc:/Hamilton/images/controls/rewind.png"
                    width: parent.width / 3
                    height: parent.height - 20
                    color: "#cccccc"
                    hoverColor: "#ffffff"
                    pressedColor: "#aaaaaa"
                    onClicked: {
                        viewModel.previousTrack()
                    }
                }

                IconButton {
                    source: "qrc:/Hamilton/images/controls/play.png"
                    width: parent.width / 3
                    height: parent.height - 20
                    color: "#cccccc"
                    hoverColor: "#ffffff"
                    pressedColor: "#aaaaaa"
                    onClicked: {
                        viewModel.playTrack() // or pause/play toggle logic
                    }
                }

                IconButton {
                    source: "qrc:/Hamilton/images/controls/fast-forward.png"
                    width: parent.width / 3
                    height: parent.height - 20
                    color: "#cccccc"
                    hoverColor: "#ffffff"
                    pressedColor: "#aaaaaa"
                    onClicked: {
                        viewModel.nextTrack()
                    }
                }
            }
        }
    }
}
