import QtQuick 2.12
import QtQuick.Window 2.12
import QtCanvas3D 1.1
import QtQuick.Controls 2.12
Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    signal useButton()
    Button{
        id: myButton
        anchors.centerIn: parent
        onClicked: useButton()
    }
}
