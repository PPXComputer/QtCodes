import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtMultimedia 5.12
Window {
    id: root
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    color: palette.window
    SystemPalette {
        id: palette
    }
    Timer {
        interval: 500
        running: true
        repeat: true
        onTriggered: {
            //            time.text=Date().toString()
            time.text = Qt.formatDateTime(new Date(), "dd hh::mm:ss ap")
        }
    }
    Loader {
        id: loader
        //可以动态加载组件
        //source: Qt.resolvedUrl("xxx.qml")//获得当前目录
    }
    Component {
        id: redSquare

        Rectangle {
            color: "red"
            width: 10
            height: 10
        }
    }
    Button {
        anchors.centerIn: parent
        width: parent.width / 2
        height: parent.height / 2
        onClicked: {
            // Qt.darker( firstColor ,degree) 创建比firstColor 更黑的层度
            console.log(Qt.platform.os)
            loader.sourceComponent = redSquare
        }

        Text {
            id: time
            color: palette.windowText
        }
    }
}
