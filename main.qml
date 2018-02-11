import QtQuick 2.9
import QtQuick.Window 2.2
import CppPlugin 1.0

Window {
    visible: true
    width: 640
    height: 480

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
}
