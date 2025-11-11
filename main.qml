import QtQuick
import QtQuick.Window
import QtQuick.Controls

Window {
    width: 1280
    height: 720
    visible: true
    title: "Hamilton QML Player"
    color: '#363636'
    // Set an application/window icon. When resources are embedded via
    // `qt_add_qml_module(... RESOURCES ...)` you can reference them as
    // relative paths from QML (recommended) or with an explicit qrc:/ path.
    // This sets the window icon for the running application. Note: for a
    // system-level app icon (taskbar/explorer) you should also provide a
    // proper .ico and set it at link time (RC file) for Windows.
    // icon: "images/hamilton-logo.svg"
    // windowIcon: "images/hamilton-logo.svg"

    Image{
        id: logo
        source: "images/hamilton-logo.ico"
        anchors.centerIn: parent
        width: 400
        fillMode: Image.PreserveAspectFit
    }
}