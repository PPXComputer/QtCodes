import QtQuick 2.0

Circle {
    id :sender
    property int  counter: 0
    signal send(string value)
    property myReceiver target: null
    onTargetChanged: {
        send(target.receive)
    }
    MouseArea{
        onClicked: {
            sender.counter++
            sender.send(counter)
        }
        onPressed: {
            sender.circleColor="blue"
        }
        onReleased: {
            sender.circleColor="red"
        }
    }
}
