import QtQuick 2.0

// This is available in all editors.
Rectangle{
    width: 200
    height: 200
    color: "red"
    Text {
        id: name
        anchors.centerIn: parent//将锚点设置为 父节点
        text: qsTr("Hello World")
    }
}
