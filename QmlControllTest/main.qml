import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    Action {
        id: actionNew
        text: "&New"
        shortcut: StandardKey.New
        onTriggered: {
            area.placeholderText = qsTr("新建")
        }
    }
    Action {
        id: actionOpen
        text: "&Open"
        shortcut: StandardKey.Open
        onTriggered: {
            area.placeholderText = qsTr("打开")
        }
    }
    Action {
        id: actionSave
        text: "&Save"
        shortcut: StandardKey.Save
        onTriggered: {
            area.placeholderText = qsTr("保存")
        }
    }

    menuBar: MenuBar {
        Menu {
            title: qsTr("打开文件")
            MenuItem {
                action: actionNew
            }
            MenuItem {
                action: actionOpen
            }
            MenuItem {
                action: actionSave
            }
        }
    }
    header: ToolBar {
        RowLayout {
            ToolButton {
                action: actionNew
            }
            ToolButton {
                action: actionOpen
            }
            ToolButton {
                action: actionSave
            }
        }
    }
    TextArea {
        id: area
        anchors.fill: parent
    }
}
