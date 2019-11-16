import QtQuick 2.12
import QtQuick.Window 2.12
import TaoQuick 1.0
import "qrc:/Tao/Qml/"
Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    TTextBtn{
        width: parent.width
        height: parent.height
        onClicked: {
            console.log("Hello   world")
        }
    }
}
