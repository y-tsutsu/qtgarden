import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 400
    height: 300
    title: qsTr("Hello from QML")

    Button {
        text: "Click Me"
        anchors.centerIn: parent
        onClicked: console.log("Button clicked!")
    }
}
