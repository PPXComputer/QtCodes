import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3
import sql.model 1.1
Window {
    id: window
    visible: true
    width: 800
    height: 700
    property alias myWindow: myWindow
    title: qsTr("Hello World")

    Rectangle {
        id: containerBar
        x: 416
        width: parent.width/7
        height: parent.height-menuBar.height
        color: "#cecbd9"
        anchors.topMargin: menuBar.height
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.rightMargin: 0

        Column {
            id: column
            antialiasing: true
            spacing: 33
            anchors.fill: parent

          DropItem {
                id: m_class
                width: parent.width
                height: parent.spacing
                text: qsTr("Class")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pointSize: 11
                renderType: Text.QtRendering
                wrapMode: Text.WordWrap
                elide: Text.ElideNone
                componentFile: "image_test.qml"
            }

           DropItem {
                id: m_fun
                width: parent.width
                height: parent.spacing
                text: qsTr("Function")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                wrapMode: Text.WordWrap
                font.pixelSize: 12
                componentFile: "m_classItem.qml"
               // property url sd: wdaadasd
            }

            Text {
                id: m_property
                width: parent.width
                height: parent.spacing
                text: qsTr("Property")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 12
            }
        }

    }
    MySql{
        id:mySql
    }

    Item {
        id: myWindow
        anchors.fill: parent
        focus:false
        Rectangle {
            id: menuBar
            height: parent.height/12
            gradient: Gradient {
                GradientStop {
                    position: 0
                    color: "#dedfd2"
                }

                GradientStop {
                    position: 0.194
                    color: "#c2c798"
                }
            }
            anchors.right: parent.right
            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.top: parent.top
            anchors.topMargin: 0

            Text {
                id: element
                text: qsTr("这是菜单栏")
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                font.pixelSize: 12
            }
        }

        Rectangle {
            id: canvaItem
            gradient: Gradient {
                GradientStop {
                    position: 0
                    color: "#9c94e2"
                }

                GradientStop {
                    position: 1
                    color: "#000000"
                }
            }
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0
            anchors.rightMargin: containerBar.width
            anchors.right: parent.right
            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.topMargin: menuBar.height
            anchors.top: parent.top
        }

        Button {
            id: button
            x: 692
            y: 249
            text: qsTr("delete")
        }

        Button {
            id: button1
            x: 692
            y: 324
            text: qsTr("add")
        }
    }
}








/*##^## Designer {
    D{i:3;anchors_height:33;anchors_width:129}D{i:2;anchors_height:400;anchors_width:200}
D{i:1;anchors_height:200;anchors_y:75}D{i:7;anchors_width:200;anchors_x:19;anchors_y:8}
D{i:12;anchors_height:200;anchors_width:200;anchors_x:8;anchors_y:46}D{i:6;anchors_height:200;anchors_width:200;anchors_x:142;anchors_y:115}
}
 ##^##*/
