import QtQuick
import QtQuick.Window
import QtQuick.Controls

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
}