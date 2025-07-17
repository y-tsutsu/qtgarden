import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.15

ApplicationWindow {
    width: 600
    height: 480
    visible: true
    title: qsTr("qtgarden 🌱")

    font.family: "Segoe UI"
    font.pointSize: 12

    Material.theme: Material.Light
    Material.accent: Material.Pink

    SwipeView {
        id: view
        anchors.fill: parent
        interactive: true

        Loader {
            source: "Calculator.qml"
        }
        Loader {
            source: "TodoList.qml"
        }
    }

    PageIndicator {
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        currentIndex: view.currentIndex
        count: view.count
    }
}
