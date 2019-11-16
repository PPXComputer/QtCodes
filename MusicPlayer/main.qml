import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

Window {
    id: window
    visible: true
    width: 640
    height: 480
//    property alias delegateItem: delegateItem
    title: qsTr("Hello World")

    ListView {
        property bool isHeader: false
        id: listView
        width: 110
        height: 480
        snapMode: ListView.NoSnap
        anchors.top: parent.top
        anchors.topMargin: 10
        anchors.left: parent.left
        anchors.leftMargin: 0
        header:Item{
            Rectangle{
                width: listView.width
                height: 10
                anchors.verticalCenter: parent.verticalCenter
            Text{
                text:qsTr("歌单")
                anchors.verticalCenter: parent.verticalCenter
            }
        }
        }
        headerPositioning:
            ListView.OverlayHeader
        function changedDelegate(){
            
        }

        delegate:  Item {
            x: 5
            width: 80
            height: 40
            id:delegateItem
            Row {
                id: row1
                spacing: 10

                Rectangle {
                    width: 40
                    height: 40
                    color: colorCode
                }

                Text {
                    text: name
                    anchors.verticalCenter: parent.verticalCenter
                    font.bold: true
                }
            }
        }


        model: ListModel {
            ListElement {
                name: "Grey"
                colorCode: "grey"
            }

            ListElement {
                name: "Red"
                colorCode: "red"
            }

            ListElement {
                name: "Blue"
                colorCode: "blue"
            }

            ListElement {
                name: "Green"
                colorCode: "green"
            }
        }
    }
}
