import QtQuick
import QtQuick.Controls
import Hamilton.Models 1.0

Item{
    id: root

    Rectangle{
        id: header
        width: parent.width
        height: parent.height
        color: '#373647'
        border.color: '#4a4a64'
        border.width: 1
    }

    Component{
        id: albumDelegate
        Rectangle{
            property bool isActive: false

            function updateColor() {
                if(isActive) {
                    color = '#7777a8'
                } else {
                    color = index % 2 === 0 ? '#444466' : '#3b3b5b'
                }
            }

            Connections {
                target: viewModel
                function onAlbumChanged(newAlbum) {
                    isActive = (title === newAlbum)
                    updateColor()
                }
            }

            width: parent.width
            height: 100
            color: {
                updateColor()
            }
            border.color: '#4a4a64'
            border.width: 1

            Row{
                anchors.fill: parent
                anchors.margins: 10
                spacing: 10

                Image{
                    source: "qrc:/Hamilton/" + cover
                    width: 80
                    height: 80
                    fillMode: Image.PreserveAspectFit
                }

                Column{
                    spacing: 5

                    Text{
                        text: title
                        font.bold: true
                        color: '#ffffff'
                    }

                    Text{
                        text: artist + " (" + year + ")"
                        color: '#cccccc'
                    }
                }
            }

            MouseArea{
                anchors.fill: parent
                hoverEnabled: true

                onClicked: {
                    viewModel.setAlbum(title)
                }
                onEntered: { 
                    color = '#666688'
                }
                onExited: {
                    updateColor()
                }
                onPressed: {
                    color = '#222244'
                }
                onReleased: {
                    updateColor()
                }
            }
        }
    }

    ScrollView{
        id: albumScrollView
        anchors.fill: parent
        contentWidth: parent.width

        ListView{
            id: albumsListView
            width: parent.width
            height: parent.height
            model: viewModel.getAlbumModel()
            delegate: albumDelegate
        }
    }
}
