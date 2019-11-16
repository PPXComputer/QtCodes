import QtQuick 2.12
import QtQuick.Window 2.12
import QtMultimedia 5.12
import QtQuick.Controls 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    MediaPlayer {
        id: play
        source: "qrc:/music/Thomas Greenberg - The Right Path.mp3"
        playlist: Playlist {
            PlaylistItem {
                source: "qrc:/music/Yulia - 여름날의 소풍.mp3"
            }
        }
        Component.onCompleted: {
            play.volume = 0.2
        }
    }
    Button {
        id: start
        anchors.centerIn: parent
        width: 50
        height: 50
        onClicked: {
            play.play()

            console.log("当前的资源为" + play.errorString)
            // 无法解析 歌曲的信息
            console.log("当前资源的信息" + play.metaData.author)
            console.log(play.metaData.videoCodec)
            console.log(play.metaData.duration)
        }
        onDoubleClicked: {
            play.playlist.next()
        }
    }
    NewWindow {
        id: newWindow
        visible: false
    }

    Button {
        anchors.right: start.left
        width: 50
        height: 50
        onClicked: {
            newWindow.visible = true
        }
    }

    Image {
        id: img
        cache: false // 动态刷新 清除缓存
        anchors.left: parent.left
        anchors.top: parent.top
        width: 30
        height: 20
        source: ""
        MouseArea {
            anchors.fill: parent
            onClicked: {
                console.log("点击了此图像")
            }
        }

        Connections {
            target: provider
            onIamgeResourceChanged: {
                console.log(CoveImage)
                img.source = ""
                img.source = CoveImage
                newWindow.source = ""
                newWindow.source = CoveImage
            }
        }
    }
}
