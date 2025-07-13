import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Item {
    anchors.fill: parent

    Column {
        spacing: 20
        anchors.centerIn: parent

        RowLayout {
            spacing: 40

            ColumnLayout {
                spacing: 8
                Label {
                    text: "Hight"
                    font.pointSize: 11
                    font.bold: true
                }
                Label {
                    text: calculatorModel.hight.toString()
                }
                Slider {
                    from: 0
                    to: 100
                    value: calculatorModel.hight
                    onValueChanged: calculatorModel.hight = value
                }
            }

            ColumnLayout {
                spacing: 8
                Label {
                    text: "Width"
                    font.pointSize: 11
                    font.bold: true
                }
                Label {
                    text: calculatorModel.width.toString()
                }
                Slider {
                    from: 0
                    to: 100
                    value: calculatorModel.width
                    onValueChanged: calculatorModel.width = value
                }
            }
        }

        RowLayout {
            spacing: 10
            Switch {
                checked: calculatorModel.continuousCalculate
                onToggled: calculatorModel.continuousCalculate = checked
            }
            Label {
                text: "Continuous calculate"
                font.bold: true
            }
        }

        Button {
            text: "Calculate"
            width: 120
            hoverEnabled: true
            onClicked: calculatorModel.calculateArea()
        }

        ColumnLayout {
            spacing: 8
            Label {
                text: "Area"
                font.bold: true
            }
            Label {
                text: calculatorModel.area.toString()
            }
            Slider {
                from: 0
                to: 10000
                value: calculatorModel.area
                enabled: false
            }
        }
    }
}
