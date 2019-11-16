import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    Canvas{
        // 使用js的操作进行绘画
        id :canvas
        width: 586
        height: 448
        anchors.fill:  parent
        onPaint: {
            var ctx=getContext("2d")
            ctx.linewidth=4
            ctx.strokeStyle="blue"
            ctx.fillStyle="steelblue"
            ctx.beginPath()
            ctx.moveTo(50,50)
            ctx.lineTo(250,20)
            ctx.stroke()
        }
    }
    Loader{
        id: useTransform

    }
}
