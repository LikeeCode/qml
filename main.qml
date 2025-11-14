import QtQuick
import QtQuick.Window
import QtQuick.Controls
import "theme"

Window {
    width: 1280
    height: 720
    visible: true
    title: "Hamilton QML Player"
    color: Theme.backgroundColor

    FontLoader {
        id: orbitronRegular
        source: "qrc:/Hamilton/fonts/Orbitron-Regular.ttf"
    }

    // Theme toggle button (top-right corner)
    Button {
        text: Theme.isDarkMode ? "☀️ Light" : "🌙 Dark"
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.margins: 10
        onClicked: Theme.toggleTheme()
    }

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