import QtQuick 2.12
import QtQuick.Window 2.12
import QtMultimedia 5.12
import QtQuick.Dialogs 1.2
Window {
    id:root
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    Audio {
        id: player
        source: "E:/CloudMusic/久石譲 - The Rain.mp3"
    }
    Dialog{
        visible: false
        id:dialog
        title: qsTr("这是一个对话框")
    }

    Flickable {
        width: parent.width
        height:parent.height
        contentHeight: parent.height*4
        contentWidth: parent.width
        interactive: true
        MouseArea {
            anchors.fill: parent
            onPressed:dialog.open()

        }
        Text {
            id: artistName
            text: "Artist \t"+player.metaData.albumArtist
            font.family: "Courier"
        }
    }
}
