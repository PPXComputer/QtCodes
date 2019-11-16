import QtQuick 2.0
import QtQuick.Window 2.12
Item {
 width: Screen.width/2
 height: Screen.height/5
 Rectangle{
     id:backGro
     anchors.fill: parent
     color: c
     states: [
         State {
             name: "Enter"
             PropertyChanges {
                 target:backGro
                 color:"orange"
             }
         }
         ,State {
             name: "Exit"
             PropertyChanges {
                 target: backGro
                 color:"transparent"
             }
         }
     ]
     transitions: [
         Transition {
             from: "Enter"
             to: "Exit"

             ColorAnimation {
                target: backGro
                 duration: 200
             }

         },
         Transition {
             from: "Exit"
             to: "Enter"

             ColorAnimation {
                 target: backGro
                 duration: 200
             }
         }
     ]

     Text{
         text:name
         anchors.centerIn: parent
         font.pixelSize: 10
     }
     Text{
         text:price
         anchors.right: parent.right
         font.pixelSize: 10
     }
     MouseArea{
         anchors.fill: parent
         hoverEnabled: true
         onEntered: {
             backGro.state="Enter"
             console.log("进入")
         }
         onExited: {
             backGro.state="Exit"
             console.log("离开")
         }
         onClicked: {
             scaleAnimation.start()
             opacityAnimation.start()
             console.log("进行了点击")
         }

         PropertyAnimation{
             id:scaleAnimation
             target: backGro
             property: "scale"
             from:0
             to:1
             duration: 1400
         }

         NumberAnimation {
             id:opacityAnimation
             target: backGro
             property: "opacity"
             from: 0
             to:1
             duration: 1400
             easing.type: Easing.InOutQuad
         }
     }
 }
}
