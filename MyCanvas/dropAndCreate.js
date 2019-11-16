var itemComponent = null
var draggedItem = null
var startingMouse
var posnInWindow

function startDrag(mouse) {
    posnInWindow = cppItem.mapFromItem(myWindow, 0, 0) // 返回在window下的坐标
    startingMouse = {
        "x": mouse.x,
        "y": mouse.y
    }
    loadComponent()
    console.log("加载组件")
}

//Creation is split into two functions due to an asynchronous wait while
//possible external files are loaded.
function loadComponent() {
    if (itemComponent !== null) {
        // component has been previously loaded
        createItem()
        return
    }

    // 使用 qt.createComponent的使用
    itemComponent = Qt.createComponent(cppItem.componentFile)
    if (itemComponent.status === Component.Loading)
        //Depending on the content, it can be ready or error immediately
        component.statusChanged.connect(createItem)
    else
        createItem()
}

function createItem() {
    if (itemComponent.status === Component.Ready && draggedItem === null) {
        draggedItem = itemComponent.createObject(myWindow, {
                                                     "image": cppItem.image,
                                                     "x": posnInWindow.x,
                                                     "y": posnInWindow.y
                                                 })
        console.log("x:"+posnInWindow.x+"y:"+posnInWindow.y)
        console.log(cppItem.image)
        // make sure created item is above the ground layer
        console.log("创建成功")
    } else if (itemComponent.status === Component.Error) {
        draggedItem = null
        console.log("error creating component")
        console.log(itemComponent.errorString())
    }
}

function continueDrag(mouse) {
    if (draggedItem === null)
        return
   // console.log("当前鼠标在拖动")
    draggedItem.x = mouse.x + posnInWindow.x - startingMouse.x
    draggedItem.y = mouse.y + posnInWindow.y - startingMouse.y
}

function endDrag(mouse) {
    if (draggedItem === null)
        return
    console.log("将created属性设置为 true" + draggedItem.objectName)
    draggedItem.created = true
    draggedItem = null
}
