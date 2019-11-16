import QtQuick 2.4

 Component {
    Rectangle{
        id: delegateItem
        width: musicList.width
        height: 15
//                color: musicList.currentIndex
        Image {
            width: parent.width
            height: parent.height
            source: url
            anchors.left: parent.left
        }
        Text {
            id:listText
            text: name
            anchors.left:parent.left
            anchors.leftMargin: url==="" ?0:10

        }
        MouseArea{
            anchors.fill: parent
            onClicked: {
                console.log("点击"+name)
            }
            hoverEnabled: true
            onEntered:listText.font.weight= Font.DemiBold
            onExited: listText.font.weight=Font.Normal
        }
    }
}

