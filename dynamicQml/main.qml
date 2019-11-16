import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

Window {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    property var component;
    function createComponent(){
        component=Qt.createComponent("qrc:/component.qml")
        if(component.status===Component.Error){
            console.log("输出错误"+component.errorString())
        }else{
            console.log(component.status)
        }
    }

    Button {
        id: button
        x: 280
        y: 236
        text: qsTr("Button")
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        onClicked: window.createComponent()
    }
}
