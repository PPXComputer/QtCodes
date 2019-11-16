var pos = null
var component = null
var sprite = null
var posInWindow=null
var startMouse=null
function createSpriteObjects() {

    component = Qt.createComponent("Test.qml")
    sprite = component.createObject(appWindow, {
                                        "x": 100,
                                        "y": 100
                                    })
    var obj=element.mapFromItem(button,0,0)
    console.log("x:"+obj.x+"y:"+obj.y)
    if (sprite === null) {
        // Error Handling
        console.log("Error creating object")
    }
}

function createImage(mouse)
{
    // 获得 当前位置与窗口的偏移量
    posInWindow=test_image.mapFromItem(element,0,0)
    startMouse={x:mouse.x,y:mouse.y}
    component=Qt.createComponent("TestImage.qml",appWindow)
    sprite=component.createObject(appWindow,{"x":mouse.x,"y":mouse.y})
    if(sprite!==null)
    {
        continueImage(mouse)
    }
    else{
        console.log("不能创建 组件")
    }
}
function continueImage(mouse)
{
    sprite.x=mouse.x+startMouse.x-posInWindow.x-test_image.width
    sprite.y=mouse.y+startMouse.y-posInWindow.y-test_image.height
}

function endDrag(mouse)
{
    if(sprite ===null)
        return ;
//    if(mouse.x<0||mouse.y<0){
//        console.log(x+"   "+y)
//        sprite.destroy()
//    }else{

//    }
}
