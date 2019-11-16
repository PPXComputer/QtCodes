import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id: root
    visible: true
    width: 640
    minimumWidth: 640
    minimumHeight: 500
    height: 480
    Item {
        width: 600
        height: 480

        //Model
        ListModel {
            id: objModel
            Component.onCompleted: {
                objModel.append({
                                    "name": "Zero",
                                    "level": 0,
                                    "subNode": []
                                })
                objModel.append({
                                    "name": "One",
                                    "level": 0,
                                    "subNode": []
                                })
                objModel.append({
                                    "name": "Two",
                                    "level": 0,
                                    "subNode": []
                                })
                objModel.get(1).subNode.append({
                                                   "name": "Three",
                                                   "level": 1,
                                                   "subNode": []
                                               })
                objModel.get(1).subNode.append({
                                                   "name": "Four",
                                                   "level": 1,
                                                   "subNode": []
                                               })
                objModel.get(1).subNode.get(0).subNode.append({
                                                                  "name": "Five",
                                                                  "level": 2,
                                                                  "subNode": []
                                                              })
            }
        }

        //Delegate
        Component {
            id: objRecursiveDelegate
            Column {
                id: objRecursiveColumn
                MouseArea {
                    width: objRow.implicitWidth
                    height: objRow.implicitHeight
                    onDoubleClicked: {
                        for (var i = 1; i < parent.children.length - 1; ++i) {
                            parent.children[i].visible = !parent.children[i].visible
                        }
                    }
                    Row {
                        id: objRow
                        Item {
                            height: 1
                            width: model.level * 20
                        }
                        Text {
                            text: (objRecursiveColumn.children.length
                                   > 2 ? objRecursiveColumn.children[1].visible ? qsTr("-  ") : qsTr("+ ") : qsTr("   ")) + model.name
                            /*objRecursiveColumn.children.length > 2 ? */
                            color: ListView.isCurrentItem ? "blue" : "green"
                        }
                    }
                }
                Repeater {
                    model: subNode
                    delegate: objRecursiveDelegate
                }
            }
        }

        //View
        ListView {
            anchors.fill: parent
            model: 1===0?objModel:objModel
            delegate: objRecursiveDelegate
        }
    }
}
