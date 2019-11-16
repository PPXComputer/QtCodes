import QtQuick 2.0
import "CreateItem.js" as Code

Text {
    id: dropItem
    property string componentFile: ""
    property string image_source: "qrc:/D:/MyDownloads/picute/icon_2uh1hjsr0qm/Backward-Button.png"

    MouseArea {
        anchors.fill: parent
        onPressed: {
            Code.start(mouse)
            //            parent.border = 5
            parent.color = "steelblue"
        }
        onPositionChanged: Code.continueDrop(mouse)
        onReleased: {
            Code.finished(mouse)
            parent.color="#000000"
        }
    }
}

/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/

