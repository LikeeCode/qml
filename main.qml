import QtQuick
import QtQuick.Window
import QtQuick.Controls
// import ViewModel 1.0

Window {
    width: 1280
    height: 720
    visible: true
    title: "Hamilton QML Player"
    color: '#363636'

    Image{
        id: logo
        source: "images/hamilton-logo.ico"
        anchors.centerIn: parent
        width: 400
        fillMode: Image.PreserveAspectFit
    }

    Row{
        anchors.fill: parent

        AlbumsList{
            id: albumsList
            width: parent.width * 0.3
            height: parent.height
        }

        NowPlayingView{
            id: nowPlayingView
            width: parent.width * 0.4
            height: parent.height
        }

        SongsList{
            id: songsList
            width: parent.width * 0.3
            height: parent.height
        }
    }
}