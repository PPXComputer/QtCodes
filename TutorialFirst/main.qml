import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Backgroud {
        id: backgroud
        anchors.fill: parent
        target: sender
        Sender {
            id: sender
            x: 29
            y: 140
            width: 200
            height: 200
            target: receiver //使用 qml控件进行赋值
            cricleColor: "#0000ff"
            circle_textText: "Sender"
            anchors.verticalCenter: parent.verticalCenter
        }

        Receiver {
            id: receiver
            x: 432
            y: 140
            width: sender.width //进行属性绑定
            cricleColor: "#ff0000"
            circle_textText: "Receiver"
            anchors.verticalCenter: parent.verticalCenter
        }
    }
}

/*##^## Designer {
    D{i:1;anchors_x:276;anchors_y:216}
}
 ##^##*/

