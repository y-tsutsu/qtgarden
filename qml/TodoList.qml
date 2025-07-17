import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Item {
    anchors.fill: parent

    ColumnLayout {
        anchors.centerIn: parent
        spacing: 20

        RowLayout {
            spacing: 10
            TextField {
                id: inputField
                placeholderText: "Add new item"
                Layout.preferredWidth: 300
            }
            Button {
                text: "Add"
                onClicked: {
                    if (inputField.text.length > 0) {
                        todoModel.addItem(inputField.text);
                        inputField.text = "";
                    }
                }
            }
        }

        CheckBox {
            text: "Show only incomplete"
            onToggled: todoModel.setShowOnlyUndone(checked)
        }

        ListView {
            Layout.preferredWidth: 400
            Layout.preferredHeight: 300
            model: todoModel

            delegate: Rectangle {
                width: parent ? parent.width : 0
                height: 40
                color: done ? "lavenderblush" : "ghostwhite"
                border.width: 1
                border.color: "gainsboro"

                RowLayout {
                    spacing: 10
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.fill: parent
                    anchors.topMargin: -5

                    CheckBox {
                        id: checkbox
                        checked: done
                        onToggled: todoModel.toggleDone(index)
                    }
                    Label {
                        text: contents
                        font.strikeout: done
                        font.pixelSize: 18
                        Layout.fillWidth: true
                    }
                    Button {
                        text: "❌"
                        onClicked: todoModel.removeItem(index)
                        background.visible: false
                    }
                }
            }
        }
    }
}
