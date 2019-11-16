import QtQuick 2.0

Item {
    width: 200
    height: 200
    property alias cricleColor: cricle.color
    property alias circle_textText: circle_text.text
    Rectangle {
        id: cricle
        color: "#fe7474"
        radius: width * 0.5
        anchors.fill: parent

        Text {
            id: circle_text
            x: 97
            y: 74
            text: qsTr("Text")
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            font.pixelSize: 30
        }
    }
}




/*##^## Designer {
    D{i:1;anchors_height:200;anchors_width:200;anchors_x:-8;anchors_y:8}
}
 ##^##*/
