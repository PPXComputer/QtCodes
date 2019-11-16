import QtQuick 2.0
import QtQuick.Window 2.12
// This is available in all editors.
Window{

    width: 100
    height: 100

    property url source: ""
    Image {
        id: name
        source: "   "
    }
}
