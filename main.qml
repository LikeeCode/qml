import QtQuick
import QtQuick.Window

Window {
    width: 640
    height: 480
    visible: true
    title: "Hamilton"

    Image{
        id: logo
        source: "images/hamilton-logo.ico"
        anchors.centerIn: parent
        width: 400
        fillMode: Image.PreserveAspectFit
    }
}