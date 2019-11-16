import QtQuick 2.0


ListModel {
    id: musicModel
    // 这是一个 项有一个
    ListElement {
        name: qsTr("推荐")
        url: ""
    }
    ListElement {
        name: qsTr("发现音乐")
        url: ""
    }

     ListElement {
        name: qsTr("我的音乐")
        url: ""
    }
    ListElement {
        name: qsTr("本地音乐")
        url: ""
    }

    ListElement {
        name: qsTr("下载管理")
        url: ""
    }
}
