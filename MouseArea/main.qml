import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

Window {
    id: window
    visible: true

    title: qsTr("Hello World")
    width: 800
    height: 500


    Row {
        id: row
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        anchors.fill: parent

        Rectangle {
            id: rectangle
            width: 200
            height: 200
            color: activeFocus ? "#ee1a1a" : "grey"
            focus: true
            KeyNavigation.down: rectangle1
            KeyNavigation.up: rectangle2
        }

        Rectangle {
            id: rectangle1
            width: 200
            height: 200
            color: activeFocus ? "#1d64d5" : "grey"
            KeyNavigation.down: rectangle2
            KeyNavigation.up: rectangle
        }

        Rectangle {
            id: rectangle2
            width: 200
            height: 200
            color: activeFocus ? "#eebc3a" : "grey"
            KeyNavigation.down: rectangle
            KeyNavigation.up: rectangle1
        }
    }

    //    Button {
    //        id: button
    //        x: 261
    //        y: 259
    //        text: qsTr("Button")
    //        anchors.horizontalCenter: parent.horizontalCenter
    //        anchors.verticalCenter: parent.verticalCenter
    //    }
    //    Flickable{
    //        width: Screen.width
    //        height: Screen.height
    //        contentHeight: Screen.height*4
    //        contentWidth: Screen.width
    //        interactive: true
    //        boundsBehavior: Flickable.StopAtBounds
    //    }
}






/*##^## Designer {
    D{i:1;anchors_x:57;anchors_y:72}
}
 ##^##*/
