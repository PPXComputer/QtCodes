import QtQuick 2.12
import QtQuick.Controls 2.5

ApplicationWindow {
    function restart_qq(recta) {
        if (recta.x === 100)
            anim.restart()
        else {
            recta.x = 100
            recta.y = 100
        }
    }
    title: "ppx"
    visible: true
    // 使用动画分组
    Rectangle {
        id: useParnell
        visible: true
        property int duration: 2000
        x: 100
        y: 100
        width: useQQ.width
        height: useQQ.height
        Button {
            id: useQQ
            width: qq.width
            height: qq.height
            Image {
                id: qq
                visible: true
                source: "qq.png"
            }
            onClicked: {
                restart_qq(useParnell)
            }
        }
    }
    // 使用平行的动画效果
    ParallelAnimation {
        id: anim

        NumberAnimation {
            target: useParnell
            properties: "x,y"
            duration: useParnell.duration
            easing.type: Easing.InOutQuad
            to: 200
        }
        RotationAnimation {
            target: useParnell
            duration: useParnell.duration
            to: 360
        }
    }

    // 使用状态描述
    // 使用过渡进行动画的显示
    Rectangle {
        width: 100
        height: 100
        color: "lightsteelblue"
        id: useState
        states: [
            State {
                name:"extend"
                PropertyChanges {
                    target: useState
                    width:200
                    height:200
                }
            },
           State {
                name:"min"
                PropertyChanges {
                    target: useState
                    width:50
                    height:50
                }
            }
        ]
        MouseArea{
            anchors.fill: parent
            onClicked: {
                useState.shiftStates()
            }
        }
        transitions: [
        Transition {
            from: "extend"
            to: "min"

            ColorAnimation {
                target: useState
                properties: "color"
                from: "white"
                to: "black"
               // duration: 2000
            }
        }
        ]
        function shiftStates(){
            if(useState.width>=100)
            {
                useState.state="min"
            }
            else
            {
                useState.state="extend"
            }
        }
    }
}



/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
