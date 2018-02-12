import QtQuick 2.9
import QtQuick.Window 2.2
import CppPlugin 1.0

Window {
    id: mainWindow
    visible: true
    width: 640
    height: 480

    signal qmlSignal(string msg)

    CppPlugin {
        id: plugin
        stringHello: "Hello World!"
    }

    Text {
        anchors {
            top: parent.top
            left: parent.left
        }

        text: plugin.stringHello
    }

    MouseArea {
        anchors.fill: parent
        onClicked: mainWindow.qmlSignal("Hello from QML");
    }

    function qmlFunction(msg) {
        console.log("Got message: ", msg)
        return "some return value"
    }
}
