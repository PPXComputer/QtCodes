import QtQuick 2.0

Item {
    Text {
        id: nameText
       x:0
       y:0
        text: qsTr("测试 x:" + nameText.x + " y:" + nameText.y)
        MouseArea {
            property real lastX: 0
            property real lastY: 0
            anchors.fill: parent
            onPressed: {
                lastX = mouseX
                lastY = mouseY
            }
            onPositionChanged: {
                if (pressed) {
                    nameText.x += mouseX - lastX
                    nameText.y += mouseY - lastY
                }
            }
        }
    }
}
