import QtQuick 2.0

Circle {
    id: sender
    property int counter: 0
    signal sender_text(string value)
    property Receiver target: null
    onTargetChanged: {
        // 在 target的值在 改变的 时候  连接 发送
        //也就是有连接 者的时候 进行 绑定
        sender_text.connect(target.useSlots)
    }
    MouseArea {
        anchors.fill: parent
        onClicked: {
            counter++
            sender.sender_text(counter)
        }
        onPressed: sender.cricleColor = "blue"
        onReleased: sender.cricleColor = "red"
    }
}
