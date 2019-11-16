import QtQuick 2.0

Item {
    Rectangle {
        id: rectangle
        color: "#ffffff"
        anchors.fill: parent

        Text {
            id: element
           anchors.centerIn: parent
            text: qsTr("这是一个组件")
            font.pixelSize: 12
        }
    }

}

/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:1;anchors_height:200;anchors_width:200;anchors_x:71;anchors_y:94}
}
 ##^##*/
