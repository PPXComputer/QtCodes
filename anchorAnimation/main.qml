import QtQuick 2.0
import QtQuick.Window 2.12

Window {

    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    Rectangle{
        anchors.fill: parent
        width: 640
        height: 480
        id:root
    Rectangle{
        id :myItem
        width: 640/2
        height: 480/2
        color: "blue"
    states: [
        State {
            name: "CLICKED"
            AnchorChanges{
                target: myItem
                anchors.bottom:root.bottom
                anchors.horizontalCenter: root.horizontalCenter
            }

            PropertyChanges {
                target: myItem
                color:"green"
                rotation:360
            }
        }
    ]
    transitions: [
        Transition {
            ParallelAnimation{
            AnchorAnimation{
                duration: 1200;
                easing.type: Easing.OutBounce
            }
            RotationAnimation{
                duration: 1200;
                easing.type: Easing.OutCirc
            }
            ColorAnimation{
                duration: 1200
            }
            }
        }
    ]
    MouseArea{
        anchors.fill: parent
        onClicked: {myItem.state="CLICKED"}
    }
    }
    }
}
