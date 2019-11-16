import QtQuick 2.0

Item {
    id: element1
    width: 300
    height: 300
    property alias circleColor: circle.color
    property alias elementText: element.text

    Rectangle {
        id: circle
        y: 100
        height: 200
        color: "#f28d8d"
        radius: width*0.5
        anchors.verticalCenter: parent.verticalCenter
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.left: parent.left

        Text {
            id: element
            x: 138
            y: 132
            width: 50
            height: 36
            text: qsTr("ppx")
            anchors.horizontalCenterOffset: 25
            anchors.horizontalCenter: parent.horizontalCenter
            font.family: "Tahoma"
            font.pixelSize: 12
        }
    }

}







/*##^## Designer {
    D{i:1;anchors_height:200;anchors_width:200;anchors_x:92;anchors_y:100}
}
 ##^##*/
