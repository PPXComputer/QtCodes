import QtQuick 2.0

Item {
    property Circle target: null //只有父级属性 才能被其他文件访问
    Rectangle {
        id: rectangle

        focus: true //启动键盘事件
        Keys.onPressed: {
            if (event.key === Qt.Key_Plus) {
                target.width += 10
            } else if (event.key === Qt.Key_Minus) {
                target.width -= 10
            }
        }

        gradient: Gradient {
            GradientStop {
                position: 0
                color: "#75bef8"
            }

            GradientStop {
                position: 1
                color: "#000000"
            }
        }
        anchors.fill: parent
    }
}

/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:1;anchors_height:200;anchors_width:200;anchors_x:195;anchors_y:106}
}
 ##^##*/

