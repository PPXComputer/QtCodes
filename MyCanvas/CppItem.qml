import QtQuick 2.0
import "dropAndCreate.js" as Code
Text {
    property string image: ""
    property string itemText: ""
    property string componentFile: ""
    property int count: 0

    id: cppItem
    text: itemText
    font.pixelSize: 20
    MouseArea {
        anchors.fill: parent
        onEntered: parent.font.bold = true
        onExited: parent.font.bold = false
        onPressed: {
            font.pixelSize=25
            Code.startDrag(mouse)
        }
        onPositionChanged: Code.continueDrag(mouse)
        onReleased: Code.endDrag(mouse)
    }
}
