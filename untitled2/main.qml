import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
// javascipt
    Rectangle {
        id: rectangle // int (i)
        x: 50
        y: 54
        width: 200
        height: 200
        color: "gray"
        MouseArea{
            anchors.fill: parent
            onClicked: {
                rectangle.color="blue"
            }
        }

    }
}
