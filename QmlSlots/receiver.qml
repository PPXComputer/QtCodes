import QtQuick 2.0

Circle {
    id : myReceiver
    function receiver(value){
        contenText=value
        // This is available in all editors.
        colornotify.running=true
    }
    SequentialAnimation  on circleColor {
        id:colornotify
        running:  false
        ColorAnimation {
            from: "Red"
            to: "blue"
            duration: 200
        }

    }


    ColorAnimation {
        from: "white"
        to: "black"
        duration: 200
    }
}
