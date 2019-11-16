import QtQuick 2.12
import sql.model 1.1
// 指向一个类
// 类有 函数 成员 友元 属性 和  各个成员,属性的setter和 getter
// 还有 继承 实现 虚基类的设置
import QtQuick.Shapes 1.11
import QtQuick.Controls 2.12

BasicDropItem {
    id: element
    width: 250
    height: 300
    color: "#dccd9a"
    border.width: 1


    //    containerHeight: height
    //    containerWidth: width
    Column {
        id: column
        anchors.fill: parent
        spacing: 0
        //Name char(30) primary key,Return char (30) , Args char(50) ,Access int
        //        Name char(30) primary key,Type char (30)),Access int

        function fleshFunctionTable() {
            array = mySql.refleshFunction()
            if (array.lenght >= 4) {
                for (i = 0; i <= aaray.lenght; i += 4) {
                    name = array[i]
                    Return = array[i + 1]
                    Arg = array[i + 2]
                    Access = array[i + 3]
                    addFunColum(name, Return, Arg, Access)
                }
            }
        }

        function fleshMemberTable() {
            array = mySql.refleshFunction()
            if (array.lenght >= 3) {
                for (i = 0; i <= array.lenght; i += 3) {
                    name=array[i]
                    type=array[i+1]
                    access=array[i+2]
                    addMemColum(name,type,access)
                }
            }
        }

        function addMemColum(Name,Type,Access) {
            mySql.addMemColum(Name, Type, Access)
            fleshMemberTable()
        }

        function addFunColum(NameReturnArgsAccess) {
            mySql.addColum(Name, Return, Args, Access)
            fleshFunctionTable()
        }
        function deleteFunColum() {
            myFunctionView.currentIndex=-1
        }

        function deleteMemColum() {
            myMemberView.currentIndex=-1
        }

        TextInput {
            id: m_className
            width: column.width
            height: 20
            color: "#bf3030"
            text: qsTr("ClassName")
            cursorVisible: true
            selectByMouse: true
            mouseSelectionMode: TextInput.SelectWords
            horizontalAlignment: Text.AlignLeft
            font.bold: true
            font.family: "Arial"
            renderType: Text.NativeRendering
            font.pixelSize: 15
            onEditingFinished: {
                // getText()
                console.log(m_className.text.toString())
            }
        }

        Rectangle {
            id: rectangle
            height: parent.height / 6
            color: "#ffffff"
            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.right: parent.right
            anchors.rightMargin: 0

            Text {
                id: element1
                y: -30
                height: parent.height
                text: qsTr("函数( 返回值  函数名字 参数)")
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 0
                anchors.left: button.right
                anchors.leftMargin: 0
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 13
            }

            Button {
                id: button
                anchors.top: parent.top
                anchors.topMargin: 0
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 0
                anchors.right: parent.right
                anchors.rightMargin: 200
                icon.source: "qrc:/D:/MyDownloads/picute/icon_0b9kqwgrs3g5/fenlei.png"
                icon.height: button.height * 2
                icon.width: button.width * 2
                display: AbstractButton.IconOnly
                property bool flexible: true
                x: 0
                width: 50
                ToolTip.visible: hovered
                ToolTip.text: qsTr("open/close the active project")
                onClicked: {

                    // 点击时展开 函数列表
                    if (flexible) {
                        myMemberView.visible = true
                        element.height += myMemberView.height
                        flexible = !flexible
                    } else {
                        myMemberView.visible = false
                        element.height -= myMemberView.height
                        flexible = !flexible
                    }
                }
            }
        }

        ListView {
            id: myMemberView
            y: 0
            height: 160
            anchors.right: parent.right
            anchors.rightMargin: 0
            anchors.left: parent.left
            anchors.leftMargin: 0
            delegate: Item {
                x: 5
                width: 80
                height: 40
                Row {
                    id: row1
                    spacing: 10
                    Rectangle {
                        width: 40
                        height: 40
                        color: colorCode
                    }

                    Text {
                        text: name
                        anchors.verticalCenter: parent.verticalCenter
                        font.bold: true
                    }
                }
            }
            model: ListModel {
                ListElement {
                    name: "Grey"
                    colorCode: "grey"
                }

                ListElement {
                    name: "Red"
                    colorCode: "red"
                }

                ListElement {
                    name: "Blue"
                    colorCode: "blue"
                }

                ListElement {
                    name: "Green"
                    colorCode: "green"
                }
            }
        }

        ////       Q14.TableView {
        //            // 添加一行的 数据 并且 直接 可以进行编辑
        //            id: functionList
        //            x: 0
        //            y: 0
        //            visible: false
        //            width: parent.width
        //            height: 160
        //            clip: true //不会自动截取超过的部分

        //            Q14.TableViewColumn {
        //                role: "returnValue"
        //                title: qsTr("返回值")
        //                width: functionList.viewport.width / functionList.columnCount
        //            }
        //            Q14.TableViewColumn {
        //                role: "functionName"
        //                title: qsTr("函数名")
        //                width: functionList.viewport.width / functionList.columnCount
        //            }
        //            Q14.TableViewColumn {
        //                role: "parameters"
        //                title: qsTr("参数")
        //                width: functionList.viewport.width / functionList.columnCount
        //            }
        //            // 可以使用 c++模型来进行 添加数据
        //            function addData(index){
        //                functionListModel.append()
        //            }

        //            model: ListModel {
        //                id: functionListModel
        //                ListElement {
        //                    returnValue: "Grey"
        //                    functionName: qsTr("皮皮虾")
        //                    parameters: "int ,sd ,s"
        //                }
        //            }
        //        }

        // 函数 和 属性 成员 都应该是一个可扩展的列表
        // 函数有fickle界面演示  返回值  名字 参数 (参数如果包括 其他类型 进行划线相连接 )
    }
}
/*##^## Designer {
    D{i:2;anchors_height:400;anchors_width:200;anchors_x:31;anchors_y:72}D{i:4;anchors_x:0}
D{i:5;anchors_height:20;anchors_width:20;anchors_y:"-30"}D{i:3;anchors_width:200}
D{i:6;anchors_width:110;anchors_x:0;anchors_y:0}D{i:1;anchors_height:200;anchors_width:200;anchors_x:142;anchors_y:120}
}
 ##^##*/

