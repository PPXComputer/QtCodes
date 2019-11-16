import QtQuick 2.12
import QtQuick.Window 2.12
import Qt.labs.calendar 1.0
import QtQuick.Dialogs.qml 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Text {
        id: element
        x: 141
        y: 27
        width: 311
        height: 35
        text: qsTr("番茄时间的使用即开始为25分钟为 一个周期")
        opacity: 0.8
        anchors.verticalCenterOffset: -196

        font.pixelSize: 16
        anchors {
            horizontalCenterOffset: 0
            verticalCenterOffset: 10
        }
    }

    Rectangle {
        id: inCenter
        anchors.centerIn: parent
        radius: 100
        width: 200
        height: 200
        color: "#0a73f5"
    }

    Rectangle {
        id: rectangle1
        anchors.centerIn: parent
        radius: 100
        width: 210
        height: 210
        opacity: 0.1
        clip: false
        visible: true
    }
}
