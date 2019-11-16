import QtQuick 2.13
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtMultimedia 5.13
import MyPackge 1.0
Window {
    id: root
    visible: true
    maximumWidth: 1000
    maximumHeight: 800
    minimumWidth: 640
    minimumHeight: 500
    height: 600
    title: qsTr("Hello World")
    // 应该是 一个列表视图中包含 一个 list项
    // 应该有一部的配置表信息
    property int fontSize: 12 //默认字体大小为12
    property var fontFamily: "SimSun"
    width: 1000
    MySql{
        id:mySql
        Component.onCompleted: {
            console.log("数据对象创建完毕")
        }
    }

    ListView {
        id: listView
        visible: true
        anchors.bottom: progressRow.top
        anchors.bottomMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        // 默认将第一个作为 目标
        currentIndex: -1
        focus: true
        boundsBehavior: Flickable.StopAtBounds
        // boundsBehavior:Flickable.StopAtBounds
        // delegate是显示
        // 显示为 一个单独的列表项 才行
        property real lastClassIndex: -1
        property real lastItemIndex: 0
        //property var myComponet:delegate
        width: parent.width / 7
        delegate: DelegateComponet {
            id: myComponet
            function heightData() {
                console.log("heightData")
            }
        }
        // model是数据
        model: GuideModel {
            id: guideModel
        }
        ScrollBar.vertical: ScrollBar {
            width: 15
            anchors.verticalCenter: parent.verticalCenter
            anchors.right: parent.right
            anchors.rightMargin: 0
        }

        Rectangle {
            id: rectangle
            x: 0
            y: 390
            height: 100
            color: "#ffffff"
            anchors.right: listView.right
            anchors.rightMargin: 0
            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0

            Flow {
                id: element
                anchors.fill: parent

                Image {
                    id: image
                    width: 100
                    height: 100
                    fillMode: Image.PreserveAspectFit
                    source: "qrc:/qtquickplugin/images/template_image.png"
                }

                Text {
                    id: element1
                    text: qsTr("Text")
                    font.pixelSize: 12
                }

                Text {
                    id: element2
                    text: qsTr("Text")
                    anchors.topMargin: element1.height
                    anchors.top: element1.bottom
                    anchors.right: element1.right
                    anchors.rightMargin: 0
                    font.pixelSize: 12
                }
            }
        }
    }
    TableView{
        id:tableView
        width: 400
        height: 200
        anchors.bottom: progressRow.top
        anchors.bottomMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: 0
        model: mySql.listModel()
    }

    Button {
        id: add
        text: "add"
        anchors.centerIn: parent
        width: 20
        height: 20
        property int count: 0
        onClicked: {
            listView.model.addItem(++count, "我的音乐")
        }
    }

    MediaPlayer {
        id: mediaPlayer
        property int isPlay: 0 // 0停止 1 暂停 2 开始
        source: playlist.currentItemSource // 初始化列表为 空 当添加的时候 就是在 list中添加和使用
        onSourceChanged: {
            // 包括了很多的 音乐信息
            console.log("当前播放的歌为" + metaData.author + metaData.date)
        }
        //MediaPlayer.duration 这里是以毫秒计数的
        onPlaying: {
            isPlay = 2
        }
        onStopped: {
            isPlay = 0
        }
        onPaused: {
            isPlay = 1
        }
        playlist: Playlist {
            id: playlist
            PlaylistItem {
                source: "qrc:/music/Thomas Greenberg - The Right Path_copy.mp3"
            }
            PlaylistItem{
                source: "qrc:/music/平井真美子 - 孤灯.mp3"
            }
            PlaylistItem{
                source: "qrc:/music/松本文紀 - 空気力学少女と少年の詩 -Oegel Ver.-.mp3"
            }

        }
        Component.onCompleted: {
            for(var i=0;i<playlist.itemCount;i++){

            }
        }
    }

    Row {
        id: progressRow
        y: 720
        width: 700
        visible: true
        height: parent.height / 10
        spacing: 0
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        leftPadding: 50

        Row {
            id: startRow
            visible: true
            width: listView.width
            antialiasing: false
            spacing: (width - preButton.width * 3) / 4

            leftPadding: (width - preButton.width * 3) / 4
            rightPadding: (width - preButton.width * 3) / 4
            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.top: parent.top
            anchors.topMargin: 0
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0

            Button {
                id: preButton
                width: 30
                text: qsTr("")
                flat: false
                highlighted: false
                anchors.verticalCenter: parent.verticalCenter
                icon.source: "Iamges/icon_udbw6jfgr79/round-arrow-left.png"
                onClicked: {
                    mediaPlayer.playlist.previous()
                }
            }

            Button {
                id: startButton
                property bool isPlay: false
                width: 30
                text: isPlay ? "1" : "0"
                anchors.verticalCenter: parent.verticalCenter
                onClicked: {

                    if (mediaPlayer.playbackState !== Audio.PlayingState) {
                        mediaPlayer.play();
                    } else {
                        mediaPlayer.pause();
                    }
                }
                icon.source: "qrc:/new/Iamges/round-arrow-down.png"
                //icon.source:":/new/Iamges/icon_udbw6jfgr79/message.png"
            }

            Button {
                id: nextButoon
                width: 30
                text: qsTr("")
                antialiasing: true
                anchors.verticalCenter: parent.verticalCenter
                icon.source: "qrc:/new/Iamges/round-arrow-down.png"
                onClicked: {
                    mediaPlayer.playlist.next()
                }
            }
        }

        Row {
            id: durationRow
            width: parent.width * 0.5
            anchors.top: parent.top
            anchors.topMargin: 0
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0
            anchors.left: startRow.right
            anchors.leftMargin: 0
            spacing: 5
            Text {
                id: durationTime
                text: {
                    var minute = (mediaPlayer.position / 1000).toFixed(0)
                    var m = (minute / 60).toFixed(0)
                    var s = (minute % 60).toFixed(0)
                    console.log(mediaPlayer.position)
                    return m + ":" + s
                }
                anchors.verticalCenter: parent.verticalCenter
                font.pixelSize: root.fontSize
                font.family: root.fontFamily
            }

            Slider {
                id: durationTimeSlider
                width: parent.width * 0.9
                anchors.verticalCenter: parent.verticalCenter
                value: mediaPlayer.position / mediaPlayer.duration
                handle: Rectangle {
                    x: durationTimeSlider.leftPadding + durationTimeSlider.visualPosition
                       * (durationTimeSlider.availableWidth - width)
                    y: durationTimeSlider.topPadding
                       + durationTimeSlider.availableHeight / 2 - height / 2
                    implicitWidth: 26
                    implicitHeight: 26
                    radius: 13
                    color: durationTimeSlider.pressed ? "#f0f0f0" : "#f6f6f6"
                    border.color: "#bdbebf"
                }
                property real index: 0
                property bool changed: false
                onMoved: {
                    if (pressed) {
                        index = position
                    }
                }
                onPressedChanged: {
                    if (pressed === true) {
                        changed = true
                    } else if (changed === true) {
                        mediaPlayer.seek(index * mediaPlayer.duration)
                        changed = false
                    }
                }
            }

            Text {
                id: endTime
                text: {
                    var minute = (mediaPlayer.duration.valueOf(
                                      ) / 1000).toFixed(0)
                    var m = (minute / 60).toFixed(0)
                    var s = (minute % 60).toFixed(0)
                    console.log(mediaPlayer.position)
                    return m + ":" + s
                }

                font.pixelSize: root.fontSize
                font.family: root.fontFamily
                anchors.verticalCenter: parent.verticalCenter
                // font.pixelSize: 12
            }
        }

        Row {
            id: voiceRow
            width: voiceSlider.width + 30
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0
            anchors.top: parent.top
            anchors.topMargin: 0
            anchors.left: durationRow.right
            anchors.leftMargin: 0
            leftPadding: 10
            Button {
                id: trumpetButton
                width: 20
                height: 20
                text: qsTr("unClok")
                property bool isMute: mediaPlayer.muted
                onClicked: {
                    mediaPlayer.muted=!mediaPlayer.muted
                }
                onIsMuteChanged: {
                    if (isMute) {
                        text = "Mute"
                    } else {
                        text = "unclok"
                    }
                }
                anchors.verticalCenter: parent.verticalCenter
            }

            Slider {
                id: voiceSlider
                anchors.verticalCenter: parent.verticalCenter
                value: 0.2
                onValueChanged: {
                    mediaPlayer.volume = value
                }
            }

            Button {
                id: palyModelButton
                width: 40
                height: 40
                text: qsTr("Button")
                anchors.verticalCenter: parent.verticalCenter
                ToolTip.visible: down
                ToolTip.text: qsTr("列表循环")
                Component.onCompleted: {
                    // 自动为列表播放
                    mediaPlayer.playlist.playbackMode=Playlist.Sequential
                }

                onClicked: {
                    if(mediaPlayer.playlist.playbackMode===Playlist.Sequential){
                        ToolTip.text= qsTr("单曲循环")
                        mediaPlayer.playlist.playbackMode=Playlist.Loop
                    }
                    else if(mediaPlayer.playlist.playbackMode===Playlist.Loop){
                        ToolTip.text= qsTr("随机播放")
                        mediaPlayer.playlist.playbackMode=Playlist.Random
                    }
                    else if(mediaPlayer.playlist.playbackMode===Playlist.Random){
                        ToolTip.text= qsTr("列表播放")
                        mediaPlayer.playlist.playbackMode=Playlist.Sequential
                    }
                }
            }


            Button {
                id: wordButton
                width: 40
                height: 40
                text: qsTr("Button")
                anchors.verticalCenter: parent.verticalCenter
            }

            Button {
                id: playListButton
                width: 40
                height: 40
                onClicked: {
                    tableView.visible=!tableView.visible;
                }

                text: qsTr("Button")
                anchors.verticalCenter: parent.verticalCenter
            }
        }
    }

}

/*##^##
Designer {
    D{i:1;anchors_height:720}D{i:7;anchors_height:400;anchors_width:400}D{i:6;anchors_width:200}
}
##^##*/

