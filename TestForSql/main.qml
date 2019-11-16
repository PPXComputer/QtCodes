import QtQuick 2.12
import QtQuick.Controls 1.4 as Q14
import QtQuick.Controls 2.12
import QtQuick.Window 2.12
import sql.MySql 1.1
import sql.MyModel 1.1

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    MySql {
        id: mySql
        onFileNeedToChanged: {
            name = "new file"
            mySql.startNewFile(name)
        }
    }

    Q14.TableView {
        selectionMode: 0
        anchors.centerIn: parent
        Q14.TableViewColumn {
            title: "Name"
            role: "Name"
            width: 100
        }
        Q14.TableViewColumn {
            title: "Value"
            role: "Value"
            width: 100
        }
        Q14.TableViewColumn {
            title: "Args"
            role: "Args"
            width: 100
        }

        //使用 qsqltableModel来使用
        model: MyModel {
            id: testModel
            tableName: "Function"
        }
    }
    TableView {
        id: testForTable
        width: 100
        height: 100
        anchors.left: parent.left
        anchors.verticalCenter: parent.verticalCenter
        clip: true
       // columns: 3

       delegate: Component {
            Rectangle {
                border.width: 5
                implicitWidth: 100
                implicitHeight: 50
                Column {
                    Text {
                        text: Args
                    }
                    Text {
                        text: Name
                    }
                    Text{
                        text: Values
                    }
                }
            }
        }
        model: MyModel {

            tableName: "Function"
        }
        Component.onCompleted: {
            testForTable.forceLayout()
        }
    }
}
