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
            width: parent.width
            height: 100
            color: index % 2 === 0 ? '#444466' : '#3b3b5b'
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
            model: AlbumModel{
                id: albumModel
            }
            delegate: albumDelegate
        }
    }
}
