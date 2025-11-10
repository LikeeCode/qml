import QtQuick
import QtQuick.Window

Window {
    width: 640
    height: 480
    visible: true
    title: "Hamilton"

    Image{
        id: img01
        source: "qrc:/Hamilton/images/img_01.png"
        anchors.centerIn: parent
    }
}