import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3
import "Create.js" as Code
Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    id:appWindow
    MouseArea{
        id:mouse
        anchors.fill: parent
        Text{
            text:"x:"+mouse.mouseX+"y:"+mouse.mouseY
        }
    }

    Item {
        id: element
        anchors.fill: parent

        Button {
            id: button
            y: 417
            text: qsTr("Button")
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0
            anchors.left: parent.left
            anchors.leftMargin: 0
            onClicked: {
                Code.createSpriteObjects()
            }
        }
        TestImage{
            anchors.right: parent.right
            anchors.top: parent.top
        }
    }
}





/*##^## Designer {
    D{i:2;anchors_x:8}D{i:1;anchors_height:200;anchors_width:200;anchors_x:184;anchors_y:151}
D{i:7;anchors_y:8}D{i:4;anchors_y:17}
}
 ##^##*/
