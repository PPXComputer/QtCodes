import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id: window
    visible: true
    width: 640
    height: 480
    color: "#00000000"
    property alias windowColor: window.color
    title: qsTr("Hello World")

    Rectangle {
        id: rectangle
        gradient: Gradient {
            GradientStop {
                position: 0
                color: "#aff4ec"
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
    D{i:1;anchors_height:467;anchors_width:640;anchors_x:-8;anchors_y:26}
}
 ##^##*/
