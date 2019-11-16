import QtQuick 2.0
import QtQuick.Controls 2.12

// 起始的目标 属性 有
//holdedPosition 坐标映射在画布上的坐标
// 可拖拽
// 目标是否在被创建  created
// 和 inArea() 判断是否在画布中 否则删除 并记录坐标
Rectangle {
    id: basicDropItem
    // 一个 var 类型的qml对象  属性的 position
    property var holdedPosition: {
        "x": 0,
        "y": 0
    }
    property bool created: false
    color: "#ffffff"
    property real lastX
    property real lastY

    // 判断 是否在 指定区域 否则删除
    function inArea() {
        // mapFromItem()
        //将参数item(A)的坐标系统的区域(x,y,width,height)映射到调用该方法的对象(B)的坐标系统中
        //mapToItem()
        //将调用该方法的对象(C)的坐标点(x,y)，
        //映射到参数item(D)的坐标系统中，并返回一个映射之后的坐标(point)
        var position = basicDropItem.mapToItem(canvaItem, 0, 0)
        if ((0 < position.x && position.x < canvaItem.width)
                && (0 < position.y && position.y < canvaItem.height)) {
            // 设置起始位置
            holdedPosition.x = position.x
            holdedPosition = position.y
            // console.log('创建成功 坐标为' +
            //  holdedPosition.x.toString() + "  " + holdedPosition.y.toString())
        } else {
            basicDropItem.destroy()
            console.log("未在画板上删除此组件")
        }
    }
    onCreatedChanged: {

        // 不能落在 菜单栏 和 项目栏中
        inArea()
    }
    border.color: '#00000000'
    // 父节点的 鼠标事件的设计
    MouseArea {
        id: basicMouseArea
        anchors.fill: parent
        enabled: true
        Menu {
            id: contextMenu
            title: "Edit"

            MenuItem {
                text: "Cut"
                onTriggered: {

                }
            }
            MenuItem {
                text: "Copy"
                onTriggered: {

                }
            }

            MenuItem {
                text: "Paste"
                onTriggered: {

                }
            }
        }
        onEntered: {
            // This is available in all editors.
            parent.border.color = "#deb887"
            parent.border.width = 5
        }
        onExited: {
            border.color = '#00000000'
            parent.border.width = 0
        }

        onPressed: {
            lastY = mouseY
            lastX = mouseX
        }
        onClicked: {
            if (mouse.button === Qt.RightButton)
                contextMenu.popup()
        }
        onPositionChanged: {
            if (pressed) {
                basicDropItem.x += mouse.x - lastX
                basicDropItem.y += mouse.y - lastY
                inArea()
            }
        }
        onReleased: {
            // 在最后一个记录 当前在 画布下的坐标
            inArea()
        }
    }
}

/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:1;anchors_height:200;anchors_width:200;anchors_x:100;anchors_y:71}
}
 ##^##*/

