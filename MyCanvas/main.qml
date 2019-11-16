import QtQuick 2.12
import QtQuick.Window 2.12

Window{
    visible: true
    width: 640
    height: 480
    Item {
        anchors.fill: parent
        id: myWindow
        //    title: qsTr("Hello World")
        Grid {
            id: grid
            x: 398
            width: myWindow.width / 5
            rows: 3
            columns: 2
            spacing: 10
            anchors.top: parent.top
            anchors.topMargin: 0
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0
            anchors.right: parent.right
            anchors.rightMargin: 0
            CppItem {
                image: "qrc:/D:/MyDownloads/picute/icon_0b9kqwgrs3g5/smile.png"
                componentFile: "DragItem.qml"
                itemText: "class"
            }
            CppItem {
                image:"qrc:/D:/MyDownloads/picute/icon_0b9kqwgrs3g5/smile.png"
                componentFile: "TestForDrag.qml"
                itemText: "test"
            }

            Text {
                id: propertyName
                text: "property"
            }
            Text {
                id: memberName
                text: "memberName"
            }
            Text {
                id: privateName
                text: "private"
            }
            Text {
                id: publicName
                text: "publicName"
            }
        }

        Rectangle {
            id: rectangle
           anchors.left: parent.left
           anchors.right: grid.left
           anchors.top: parent.top
           anchors.bottom: parent.bottom
            color: "#ffffff"
            MouseArea {
                anchors.fill: parent
                onClicked: rectangle.focus = false;
            }
        }
    }
}



/*##^## Designer {
    D{i:9;anchors_x:91;anchors_y:77}
}
 ##^##*/
