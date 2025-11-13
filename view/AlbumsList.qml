import QtQuick
import QtQuick.Controls
import Hamilton.Models 1.0

Item {
    id: root

    // The main background
    Rectangle {
        anchors.fill: parent
        color: '#373647'
        border.color: '#4a4a64'
        border.width: 1
    }

    // The delegate for each album item in the list
    Component {
        id: albumDelegate
        Rectangle {
            property bool isActive: false

            width: parent.width
            height: 100
            color: {
                if (isActive) {
                    '#7777a8'
                } else {
                    index % 2 === 0 ? '#444466' : '#3b3b5b'
                }
            }
            border.color: '#4a4a64'
            border.width: 1

            function updateColor() {
                color = isActive ? '#7777a8' : (index % 2 === 0 ? '#444466' : '#3b3b5b')
            }

            Connections {
                target: viewModel
                function onAlbumChanged(album) {
                    // Assuming album.title is what you need to compare
                    isActive = (title === album.title)
                    updateColor()
                }
            }

            Row {
                anchors.fill: parent
                anchors.margins: 10
                spacing: 10

                Image {
                    source: "qrc:/Hamilton/" + cover
                    width: 80
                    height: 80
                    fillMode: Image.PreserveAspectFit
                }

                Column {
                    spacing: 5
                    Text { text: title; font.bold: true; color: '#ffffff' }
                    Text { text: artist + " (" + year + ")"; color: '#cccccc' }
                }
            }

            MouseArea {
                anchors.fill: parent
                hoverEnabled: true
                onClicked: { viewModel.setAlbum(title) }
                onEntered: { if (!isActive) color = '#666688' }
                onExited: { updateColor() }
                onPressed: { if (!isActive) color = '#222244' }
                onReleased: { if (!isActive) color = '#666688' }
            }
        }
    }

    // The ListView is the top-level scrolling element.
    // The ScrollView has been removed.
    ListView {
        id: albumsListView
        anchors.fill: parent
        clip: true

        model: viewModel.getAlbumModel()
        delegate: albumDelegate

        // --- Final ScrollBar with Separate Increase/Decrease Areas ---
        ScrollBar.vertical: ScrollBar {
            id: vbar
            width: 14
            policy: ScrollBar.AsNeeded
            hoverEnabled: true

            // The thumb is the draggable part. Its styling is self-contained.
            // The ScrollBar itself handles the dragging logic for its contentItem.
            contentItem: Rectangle {
                id: thumb
                width: 8
                anchors.horizontalCenter: parent.horizontalCenter
                z: 2 // Ensure thumb is visually on top of the track background

                color: "#7777a8"

                states: [
                    State {
                        name: "HOVERED"
                        when: vbar.hovered && !vbar.pressed
                        PropertyChanges { target: thumb; color: "#8888b9" }
                    },
                    State {
                        name: "PRESSED"
                        when: vbar.pressed
                        PropertyChanges { target: thumb; color: "#9999c0" }
                    }
                ]

                transitions: [
                    Transition {
                        ColorAnimation { duration: 150; easing.type: Easing.InOutQuad }
                    }
                ]
            }

            // The background is now a container for the track and the click handlers.
            background: Item {
                id: backgroundContainer
                z: 1 // Ensure background is below the thumb

                // 1. The visible track rectangle that sits behind everything.
                Rectangle {
                    anchors.fill: parent
                    color: "#2E2D3C"
                }

                // The 'increase' (page down) click area.
                Rectangle {
                    id: increaseArea
                    anchors.left: parent.left
                    anchors.right: parent.right
                    anchors.bottom: parent.bottom
                    height: width
                    color: "#4a4a64"
                    z:1

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            vbar.increase()
                        }
                    }
                }

                // The 'decrease' (page up) click area.
                Rectangle {
                    id: decreaseArea
                    anchors.left: parent.left
                    anchors.right: parent.right
                    anchors.top: parent.top
                    height: width
                    color: "#4a4a64"
                    z:1

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            vbar.decrease()
                        }
                    }
                }
            }
        }
    }
}