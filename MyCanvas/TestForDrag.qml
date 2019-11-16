import QtQuick 2.0

Image {
    id:testFor
    property bool created: false
    width: 24
    height: 24
    visible: true

    anchors.fill: parent
    source: "qrc:/D:/MyDownloads/picute/icon_0b9kqwgrs3g5/smile.png"
    onCreatedChanged: {
        if(testFor.x< 1)
            testFor.deleteLater()
        else{
            console.log("创建成功 x:"+testFor.x)
        }
    }
}
