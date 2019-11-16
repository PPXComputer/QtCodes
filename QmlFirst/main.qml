import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

ApplicationWindow {
    //只有根级元素 才能被其他元素进行访问
    id: mainWindow
    visible: true
    title: qsTr("Hello World")
    function textClicked() {
        //QtObject.objectName
        hello.rotation = hello.rotation + 10
    }
    Item {
        id: testItem
        anchors.bottom: parent.top
        width: 100

        Text {
            id: testItemTextn
            width: 139
            height: 39
            text: qsTr("这是一个可视化的项")
        }
    }
    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("&Open") //设置O为快捷键
                onTriggered: console.log("open file ")
            }
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit()
            }
        }
    }
    Button {
        id: hello
        text: qsTr("Hello")
        // anchors.left: parent.left
        anchors.centerIn: parent
        anchors.verticalCenter: parent.verticalCenter //居中
        // {color: "black"}
        onClicked: {
            mainWindow.title = "ppx"
            textClicked()
        }
    }
    Button {
        //响应式编程
        opacity: 0.5 //透明度
        anchors.left: hello.right
        anchors.leftMargin: 12
        anchors.verticalCenter: parent.verticalCenter

        anchors.verticalCenterOffset: 0
        // anchors.verticalCenterOffset: 0
        id: world
        Text {
            id: worldText
            anchors.centerIn: parent
            font.bold: false
            //使用其他人的属性使用
            font.pixelSize: hello.font.pixelSize
            text: qsTr("World")
        }
    }
    //可视化画布
    Rectangle {
        x: 0
        y: 391
        width: 154
        height: 89
        anchors.bottomMargin: 0
        anchors.bottom: parent.bottom
        color: "blue"
        Rectangle {
            radius: 50
            width: 50
            height: 50
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
        }
    }
    Canvas {
        //使用画布
        id: myCanvas
        anchors.right: parent.right
        width: 100
        height: 100
        onPaint: {

            var ctx = getContext("2d")
            ctx.fillStyle = Qt.rgba(1, 1, 0, 1)
            ctx.fillRect(0, 0, myCanvas.width, myCanvas.height)
        }
    }
    //在qml中使用 信号槽
    Button {
        background: Rectangle {
            color: "blue"
            width: parent.width
            height: parent.height
        }
        width: hello.width
        height: hello.height
        id: signalButton
        anchors.bottom: hello.top
        Text {
            anchors.centerIn: parent
            id: signalText
            text: qsTr("text")
        }
        anchors.verticalCenter: parent.verticalCenter
        //使用信号处理的 语柄的程序
        onClicked: {
            console.log("singal")
        }

        //使用Connection类型
        Button {
            id: connection

            ColorAnimation {
                from: "white"
                to: "black"
                duration: 200
            }
            anchors.left: signalButton.right
            width: signalButton.width
            height: signalButton.height
            Text {
                anchors.centerIn: parent
                id: onnectionText
                text: qsTr("text")
            }
            Connections {
                target: connection //填上接收者的名字
                onClicked: {

                    //使用槽函数
                }
            }
        }

        Item {

            //使用一个 Component完成的使用
            id: useItem
            //闭包中不需要 使用 类型声明
            function sendToPost(msg) {
                console.log(msg)
            }

            signal messagereceived(string msg, string text)
            // 发射信号方法一
            // onTopChanged: useItem.messagereceived("msg", "text")
            //信号的语柄中处理 参数将可以直接使用
            onMessagereceived: console.log(msg + text)

            // 信号连接信号 或者方法
            function foo1(msg) {
                console.log(msg)
            }
            signal tapped
            Component.onCompleted: {
                console.log("在对象创建的时候 就会触发这个槽函数")
                //发射信号方法二
                useItem.messagereceived("msg", "text")
                //连接方法
                useItem.messagereceived.connect(foo1)
                // 信号连接信号
                useItem.messagereceived.connect(tapped)
            }
            // 使用 Connection进行使用
            //    Connections {
            //        target: slider
            //        onMoved: {
            //            mainWindow.state = ""
            //        }
            //    }使用 Connec
        }

        Rectangle {
            id: useMouse
            width: 100
            height: 100
            color: "blue"
            anchors.centerIn: parent
            MouseArea {
                width: parent.width
                height: parent.height
                onClicked: console.log("使用鼠标区域点击")
            }
        }
    }

    Slider {

        id: slider
        x: 360
        y: 345
        value: {
            from: 0
            to: 200
        }

        width: 200
        height: 20
        anchors.right: parent.right
        visible: true
        onMoved: {
            world.scale = value
        }
    }
    Image {
        id: useAnimation
        x: 220
        y: 8
        anchors.rightMargin: 220
        source: "Microphone-.png"

        NumberAnimation on x {
            to: 340
            duration: 1000
            loops: Animation.Infinite
        }
    }
}




/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
