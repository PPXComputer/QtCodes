var startedPos = null
var posInWindow = null
var component = null
var sprite = null
function start(mouse) {
    posInWindow = dropItem.mapFromItem(myWindow, 0, 0)
    startedPos = {
        "x": mouse.x,
        "y": mouse.y
    }
    loadComponent(mouse)
}
function loadComponent(mouse) {
    if (component !== null) {
        // component has been previously loaded
        createItem(mouse)
        return
    }

    // 使用 qt.createComponent的使用
    component = Qt.createComponent(dropItem.componentFile)
    if (component.status === Component.Loading)
        //Depending on the content, it can be ready or error immediately
        component.statusChanged.connect(createItem)
    else
        createItem(mouse)
}

function createItem(mouse) {
    if (component.status === Component.Ready && sprite === null) {
        sprite = component.createObject(window, {
                                            "x":posInWindow.x,
                                            "y":posInWindow.y
                                        })
        // make sure created item is above the ground layer
    } else if (component.status === Component.Error) {
        sprite = null
        console.log("error creating component")
        console.log(component.errorString())
    }
}
function continueDrop(mouse) {
    if (sprite === null) {
        return
    }
    sprite.x = mouse.x + startedPos.x - posInWindow.x - dropItem.width * 0.5
    sprite.y = mouse.y + startedPos.y - posInWindow.y - dropItem.height * 0.5
}

function finished(mouse) {
    if (sprite === null)
        return
    sprite.created = true
    console.log("拖动目标的 created属性进行改动")
    sprite = null
}
