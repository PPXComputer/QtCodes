import QtQuick 2.0

BasicDropItem {
    id:imageTest
    width: 60
    height: 60
    property bool created: false
    Image {
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit
        source: "qrc:/D:/MyDownloads/picute/icon_2uh1hjsr0qm/Backward-Button.png"
    }

}
