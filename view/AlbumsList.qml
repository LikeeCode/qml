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

        // --- Correct ScrollBar Styling ---
        ScrollBar.vertical: ScrollBar {
            id: vbar
            width: 14
            // Use AsNeeded in production, but AlwaysOn is good for testing
            policy: ScrollBar.AlwaysOn

            // The track (background of the scrollbar)
            background: Rectangle {
                color: "#2E2D3C"
            }

            // The thumb (the draggable part)
            contentItem: Rectangle {
                id: thumb
                width: 8
                anchors.horizontalCenter: parent.horizontalCenter
                radius: 0
                z: 100

                // 1. Set the default appearance
                color: "#7777a8"

                // 2. Define the different visual states
                states: [
                    State {
                        name: "HOVERED"
                        // This state is active when hovered but NOT pressed
                        when: vbar.hovered && !vbar.pressed
                        PropertyChanges {
                            target: thumb
                            color: "#8888b9" // A color between normal and pressed
                        }
                    },
                    State {
                        name: "PRESSED"
                        when: vbar.pressed
                        PropertyChanges {
                            target: thumb
                            color: "#9999c0" // Brightest color for pressed
                        }
                    }
                ]
            }
        }
    }
}