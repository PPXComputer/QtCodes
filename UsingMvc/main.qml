import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: Screen.width/2
    height: Screen.height/2
    title: qsTr("Hello World")
    ListView{
        anchors.fill: parent
        model: Model{}
        delegate: MyDel{}
    }
}
