import QtQuick 2.12
import QtQuick.Window 2.12
import QtDataVisualization 1.3
import Qt.labs.qmlmodels 1.0
import QtQuick.Controls 2.3

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Column {
        id: column
        x: 535
        y: 0
        width: 105
        height: 301
        Repeater {
            //            model:3 // 使用model的个数来进行确定
            model: ["first", "seconde", "thrid"] //使用js的序列对象
            Rectangle {
                width: 100
                height: 100
                radius: 30
                color: "lightblue"
                Text {
                    id: msg
                    text: qsTr(index+modelData) // name+Data 是JavaScript中使用序列值的方法
                    anchors.centerIn: parent
                }
            }
        }
    }

    Rectangle {
        id: rectangle
        x: 0
        y: 0
        width: 247
        height: 480
        color: "#ffffff"
        ListView{
            anchors.fill: parent
            anchors.margins:20
            clip:true //启动裁剪的功能
            model:30
            delegate: myComponent
            spacing: 10
            //            orientation:  方向
            //高亮当前 项
            highlight: highlightItem
            highlightRangeMode: ListView.StrictlyEnforceRange
            focus: true
        }
        Component{
            id:myComponent
            Rectangle{
                width:30
                height: 30
                color:  ListView.isCurrentItem?"lightblue":"gray"
                Text {
                    anchors.centerIn: parent
                    id: com_text
                    text: index

                }
            }
        }
        Component{
            id :highlightItem
            Rectangle{
                width:30
                height: 30
                color: "red"
            }
        }

    }

    ListView {
        property int count: 4
        id: dynamicList
        x: 265
        y: 21
        width: 110
        height: 442
        model: ListModel {
            id:dynamicModel
            ListElement {
                name: "Grey"
                colorCode: "grey"
            }

            ListElement {
                name: "Red"
                colorCode: "red"
            }

            ListElement {
                name: "Blue"
                colorCode: "blue"
            }

            ListElement {
                name: "Green"
                colorCode: "green"
            }

        }
        delegate: Item {
            x: 5
            width: 80
            height: 40

            Row {
                id: row1
                Rectangle {
                    width: 40
                    height: 40
                    color: colorCode
                }

                Text {
                    text: "name"
                    anchors.verticalCenter: parent.verticalCenter
                    font.bold: true
                }
                spacing: 10
            }
        }
    }

    Button {

        id: button
        x: 401
        y: 36
        text: qsTr("添加")
        onClicked:dynamicModel.append({"number": ++dynamicList.count})
    }

    Button {
        id: button1
        x: 401
        y: 106
        text: qsTr("删除")
    }



}
