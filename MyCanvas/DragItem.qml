import QtQuick 2.0

Rectangle {
    id: classItem
    color: "#f7a3a3"
    visible: true
    property string image: "qrc:/D:/MyDownloads/picute/icon_0b9kqwgrs3g5/smile.png"
    property bool created: false
    width: 120
    height: 200
    onCreatedChanged: {
        console.log('创建成功'+"x:"+classItem.x)
    }

    Column {
        id: column
        anchors.fill: parent
        spacing: 10
        Image {
            source: image

        }
        Text {
            id: headData
            property string classHeader: ""
            text: qsTr("class " + classHeader)
            font.pixelSize: 12
        }

        Text {
            id: element1
            text: qsTr("Text")
            font.pixelSize: 12
        }

        Text {
            id: element2
            text: qsTr("Text")
            font.pixelSize: 12
        }
    }
}






/*##^## Designer {
    D{i:3;anchors_height:400;anchors_width:200;anchors_x:20;anchors_y:27}
}
 ##^##*/
