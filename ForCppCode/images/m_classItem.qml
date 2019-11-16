import QtQuick 2.12

BasicDropItem {
    id: element
    width: 150
    height: 200
//    containerHeight: height
//    containerWidth: width
    Column {
        id: column
        spacing: 15
        anchors.fill: parent

        TextInput {
            id: m_className
            width: column.width
            height: 20
            color: "#1a10cd"
            text: qsTr("Text Input")
            renderType: Text.NativeRendering
            font.pixelSize: 12
            onEditingFinished:{
               // getText()
            }
        }

        TextInput {
            id: textInput
            width: column.width
            height: 20
            text: qsTr("Text Input")
            font.pixelSize: 12
        }
    }
}






/*##^## Designer {
    D{i:2;anchors_height:400;anchors_width:200;anchors_x:31;anchors_y:72}D{i:1;anchors_height:200;anchors_width:200;anchors_x:142;anchors_y:120}
}
 ##^##*/
