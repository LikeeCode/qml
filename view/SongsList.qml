import QtQuick
import QtQuick.Controls

Item{
    id: root

    Rectangle{
        id: header
        width: parent.width
        height: parent.height
        color: '#373647'
        border.color: '#4a4a64'
        border.width: 1

        Component{
            id: songDelegate
            Rectangle{
                property bool isActive: false

                function updateColor() {
                    if(isActive) {
                        color = '#7777a8'
                    } else {
                        color = index % 2 === 0 ? '#444466' : '#3b3b5b'
                    }
                }

                function formatTime(duration) {
                    var minutes = Math.floor(duration / 60)
                    var seconds = duration % 60

                    var secondsString = (seconds < 10 ? "0" : "") + seconds
                    return minutes + ":" + secondsString
                }

                Connections {
                    target: viewModel
                    function onSongChanged(song) {
                        isActive = (title === song.title)
                        updateColor()
                    }
                }

                width: header.width
                height: 60
                color: {
                    updateColor()
                }
                border.color: '#4a4a64'
                border.width: 1

                Row{
                    anchors.fill: parent
                    anchors.margins: 10
                    spacing: 10

                    Column{
                        spacing: 5
                        width: parent.width

                        Row{
                            width: parent.width
                            spacing: 5

                            Text{
                                text: title
                                font.bold: true
                                font.family: "Orbitron"
                                font.pixelSize: 14
                                color: '#ffffff'
                                width: 3 * parent.width / 4
                            }
                            Text{
                                text: formatTime(duration)
                                font.bold: true
                                font.family: "Orbitron"
                                font.pixelSize: 14
                                color: '#bebebe'
                                width: parent.width / 4
                            }
                        }

                        Text{
                            text: artist
                            color: '#cccccc'
                        }
                    }
                }

                MouseArea{
                    anchors.fill: parent
                    hoverEnabled: true

                    onClicked: {
                        viewModel.playTrack(title)
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
                id: songsListView
                width: parent.width
                height: parent.height
                model: viewModel.songModel
                delegate: songDelegate
            }
        }
    }
}
