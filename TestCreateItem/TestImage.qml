
import QtQuick 2.0
import "Create.js" as Code
Item {
    id:test_image
    width: 40
    height: 40
    Image {
        id: image
        anchors.fill: parent
        source: "qrc:/D:/MyDownloads/picute/icon_0b9kqwgrs3g5/smile.png"
        fillMode: Image.PreserveAspectFit
    }
    MouseArea{
        anchors.fill: parent
        onPressed: Code.createImage(mouse);
        onPositionChanged: Code.continueImage(mouse)
        onReleased: Code.endDrag(mouse);
    }
}

/*##^## Designer {
    D{i:1;anchors_height:100;anchors_width:100;anchors_x:43;anchors_y:65}
}
 ##^##*/
