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
                width: 200
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

        ListView {
            width: 400
            height: 350
            model: todoModel
            delegate: Rectangle {
                width: parent.width
                height: 40
                color: done ? "lavenderblush" : "ghostwhite"
                border.width: 1
                border.color: "gainsboro"

                RowLayout {
                    spacing: 10
                    anchors.verticalCenter: parent.verticalCenter

                    CheckBox {
                        id: checkbox
                        checked: done
                        onToggled: todoModel.toggleDone(index)
                    }
                    Label {
                        text: contents
                        font.strikeout: done
                        font.pixelSize: 18
                    }
                }
            }
        }
    }
}
