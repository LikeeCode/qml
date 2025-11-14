import QtQuick
import QtGraphicalEffects

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
        visible: false // The original image is not visible
    }

    Colorize {
        id: colorizedImage
        anchors.fill: sourceImage
        source: sourceImage
        color: root.color
        hue: 1.0
        saturation: 0.0
        lightness: 0.0
    }

    MouseArea {
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
            when: parent.MouseArea.pressed
            PropertyChanges { target: root; color: root.pressedColor }
        },
        State {
            name: "hovered"
            when: parent.MouseArea.containsMouse
            PropertyChanges { target: root; color: root.hoverColor }
        }
    ]
}
