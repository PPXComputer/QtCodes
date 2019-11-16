import QtQuick 2.12
import QtQuick.Controls 2.12


Rectangle {
    id: delegateForTour
    property var datas:  dataArray.split(",")
    function freshHeight(){
        //repeater.itemAdded() add item s
        delegateForTour.height=(datas.length + 1) * (root.fontSize + 8) + 50
        parent.forceLayout()
      // this.height=(this.datas.length+1)*(root.fontSize+8)+50
    }

    width: listView.width
    anchors.leftMargin: 10
    height:100 //设置50的间距
    onDatasChanged:{

        delegateForTour.height=(datas.length)*30+50
        console.log("height :"+height)
    }


    onHeightChanged: {
        console.log("data length :"+datas.length)
        console.log("height changed :"+height)
    }

    property int classIndex: index
    MouseArea {
        anchors.fill: parent
        //设置当前目标为 选中项
        propagateComposedEvents: true
        onDoubleClicked: {}
        onClicked: {
            listView.currentIndex = index
            mouse.accepted = false //传递事件
            //            console.log("当前的类别索引为" + index)
            //            console.log("当前类为"+parent.classIndex)
        }
    }

    Column {
        id: column
        spacing: 5
        Flow {
            spacing: listView.width - classItem.width - 25
            Text {
                id: classItem
                width: listView.width
                text: name
                font.bold: true
                font.pointSize: 12
                property bool isEmpty: false
            }
            Button {
                width: 15
                height: classItem.height
                Image {
                    id: fold
                    anchors.fill: parent
                    property bool unfold: false
                }
                onClicked: {
                    fold.unfold = !fold.unfold
                    repeater.visible = !repeater.visible
                }
            }
        }

        DelegateRepater {
            id: repeater
        }
    }
}

