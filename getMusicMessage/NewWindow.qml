import QtQuick 2.0
import QtQuick.Window 2.12
// This is available in all editors.
Window{

    width: 100
    height: 100
    id:window
    property string source: ""
    onSourceChanged: {
        console.log(window.source)
        name.source=""
        name.source=window.source
    }

    Image {
        id: name
        cache: false
        source: ""
    }
}
