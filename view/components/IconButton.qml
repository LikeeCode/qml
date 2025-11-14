import QtQuick
import Qt5Compat.GraphicalEffects

Item {
    id: root
    width: sourceImage.width
    height: sourceImage.height

    property alias source: sourceImage.source
    property color color: "white"
    property color hoverColor: "lightgrey"
    property color pressedColor: "grey"

    signal clicked()

    Image {
        id: sourceImage
        anchors.fill: parent
        visible: false
        fillMode: Image.PreserveAspectFit
    }

    ColorOverlay {
        id: colorizedImage
        anchors.fill: sourceImage
        source: sourceImage
        color: root.color
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        hoverEnabled: true
        onClicked: root.clicked()
    }

    Behavior on color {
        ColorAnimation { duration: 150 }
    }

    states: [
        State {
            name: "pressed"
            when: mouseArea.pressed
            PropertyChanges { target: root; color: root.pressedColor }
        },
        State {
            name: "hovered"
            when: mouseArea.containsMouse && !mouseArea.pressed
            PropertyChanges { target: root; color: root.hoverColor }
        }
    ]
}
