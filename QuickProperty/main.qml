import QtQuick 2.12
import QtQuick.Window 2.12

//qt qml有 可以使用一部分的 JavaScript语法进行导入
//id, property ,signal, signal handler ,method
//attached properties and attached signal handler attributes
//附加的 property 和 绑定的信号的属性 和
// 和 枚举的属性
Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    Column {
        width: 200
        height: 200

        TextInput {
            id: myTextInput
            text: qsTr("Hello World")
        }

        Text {
            property int a: 0
            property double b: 1.2
            property url baidu: "www.baidu.com"
            property bool isBaseCode: true
            property var object_var: Rectangle {
                Item {
                    id: var_ItemName
                }
            }

            text: myTextInput //指定这个文字为 TextInput的使用的text属性
        }
    }
    Rectangle {
        property alias Counter: Rectangle.ppx // 使用别名来进行命名的 内部属性的 引用
        // 属性别名和类型
        //属性别名不能具有显式的类型规范。属性别名的类型是它引用的属性或对象的声明类型。
        //因此，如果您为通过id引用的对象创建别名，并内联声明额外的属性，则无法通过别名访问这些额外的属性:
        Item {
            property alias inner: innerItem
            Item {
                id: innerItem
                property int counter: 0
            }
            inner.counter: 1 //可以使用  //注意在外部文件时不可以 进行使用 inner.counter进行初始化
        }
        Item {
            id: testItem2
            // 默认属性
            default property string text: "123" // 设置一个默认值 下次调用的时候自动为 123
        }
        property color previousColor
        property int ppx: 1

        //设置只读的属性
        readonly property int ReadCounter: 10 //ReadCounter :0 error:无法更改只读属性

        //默认属性 指那些 将为未定义的属性 将 其作为 使用的一方
        default property var DefaultProperty
        property string UseDefault: "hello" + DefaultProperty.text //动态语言的 使用

        //在其他的 内部使用 text
        UseDefault: "world"
        DefaultProperty: Text {
            text: "world"
        } //与之前使用 defalutproperty.text使用的

        property color nextColor
        onNextColorChanged: console.log(
                                "The next color will be: " + nextColor.toString(
                                    ))
        states: [
            State {
                name: "name"
                PropertyChanges {
                    target: object
                }
            }
        ]
        // 属性修饰符 将特殊属性 进行使用
        // 信号语柄 即方法属性的 使用
        Item {
            id: test_signal
            MouseArea {
                //只带的信号的属性
                anchors.fill: parent
                onClicked: {
                    console.log("按下则控制台打印")
                }
            }
        }
        signal mySignal
        // 没有圆括号表示没有参数的 信号
        signal hover
        // 这个圆括号是可选的
        signal action_move(string action, var postion)

        //信号处理程序
        Rectangle {
            id: useSignal
            signal actived(real postionX, real positiony)
            signal deactived
            MouseArea {
                onPressed: actived(mouseX, mouseY)
                onReleased: useSignal.deactived() //使用 信号处理程序
            }
        }

        property list<Rectangle> ListTest: [
            Rectangle {
                color: "red"
            },
            Rectangle {
                color: "blue"
            }
        ]
        Text {
            id: sdsd
            text: qsTr("text")
        }
        ListView {
            Text {
                id: myEnum

                //枚举必须为大写字母
                property int textType: myEnum.TextType.FirstType
                font.bold: textType === myEnum.TextType.FirstType //使用 三个等号进行判断
            }
            // ListView.currentItem.activeFocus:
            delegate: Item {
                id: delegateItem
                width: 100
                height: 50
                Rectangle {

                    //  color : ListView.isCurrentItem ? "red":"blue"
                    //错误 信号 只能在当前的 对象 和委托对象中使用 和 处理
                }
            }

            model: ListModel {
                id: test_model
                Component.onCompleted: {
                    for (; i < 10; i++)
                        listModel.append({
                                             "Name": "Item " + i
                                         })
                }
            }
            //              delegate:Text {不能同时进行绑定
            //                  id: name
            //                  text: qsTr("text")
            //              }
        }
    }
}
