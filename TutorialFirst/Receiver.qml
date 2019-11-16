import QtQuick 2.0

Circle {
    id: receiver
    function useSlots(value) {
        circle_textText = value
        colorChanged.running = true
    }
    SequentialAnimation on cricleColor {
        id: colorChanged
        running: false

        ColorAnimation {
            from: "red"
            to: "blue"
            duration: 200
        }
        ColorAnimation {
            from: "blue"
            to: "red"
            duration: 200
        }
    }
}
