import QtQuick 2.12
Repeater {
    id: repeater

    // 当前选择的目标 列表的坐标 相当于 对应什么类别
    property int currentIndex: delegateForTour.classIndex
    property int currentItemIndex: 0
    model: datas


    Rectangle {
        // 返回 所给索引的项
        width: classItem.width
        height: classItem.height
        // 当前 repater的坐标 对应某一项
        property int itemIndex: index
        property int classIndex: repeater.currentIndex
        MouseArea {
            anchors.fill: parent

            //                    propagateComposedEvents: true // 将当前事件传递给 父节点
            function getItem(classINdex, itemIndex) {
                var rep = listView.itemAtIndex(
                            classINdex).children[1].children[itemIndex + 1]
                console.log("找到的是" + rep.toString() + '\n')
                return rep
            }

            onClicked: {
                if (listView.lastClassIndex !== -1) {
                    var sd = getItem(listView.lastClassIndex,
                                     listView.lastItemIndex)
                    sd.color = "white"
                    console.log("之前项 设置成白色 " + sd.classIndex + " "
                                + sd.itemIndex + sd.toString() + '\n')
                }
                console.log("之前的索引为" + listView.lastClassIndex + "  "
                            + listView.lastItemIndex)
                listView.currentIndex = parent.classIndex
                listView.lastClassIndex = parent.classIndex
                listView.lastItemIndex = parent.itemIndex
                var ref = getItem(parent.classIndex, parent.itemIndex)
                ref.color = "gray"
                console.log("现在点击的索引为" + parent.classIndex + " " + parent.itemIndex + '\n')
                console.log("设置完成" + ref.classIndex + " " + ref.itemIndex + ref.toString(
                                ))
                mouse.accpected = false // 传递事件
            }
            hoverEnabled: true
            onEntered: {
                itemText.font.pixelSize = 13
                parent.border.width = 1
            }
            onExited: {
                itemText.font.pixelSize = 12
                parent.border.width = 0
            }
        }

        color: "white"
        // 自定义的数据
        Flow {
            spacing: 5
            anchors {
                verticalCenter: parent.verticalCenter
                leftMargin: 5
            }
            Image {
                id: icon
                width: 20
                height: classItem.height
                source: imageResource
            }
            Text {
                id: itemText
                font.family: root.fontFamily
                font.pixelSize: 12
                text: qsTr(datas[index])
            }
        }
    }

}
