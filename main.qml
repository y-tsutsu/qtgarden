import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    width: 600
    height: 480
    visible: true
    title: qsTr("Hello World")

    Column {
        spacing: 20
        anchors.centerIn: parent

        Row {
            spacing: 40

            Column {
                spacing: 10
                Label { text: calculatorModel.hight.toString() }
                Slider {
                    from: 0; to: 100; value: calculatorModel.hight
                    onValueChanged: calculatorModel.hight = value
                }
                Label { text: "Hight" }
            }

            Column {
                spacing: 10
                Label { text: calculatorModel.width.toString() }
                Slider {
                    from: 0; to: 100; value: calculatorModel.width
                    onValueChanged: calculatorModel.width = value
                }
                Label { text: "Width" }
            }
        }

        Row {
            spacing: 10
            Switch {
                checked: calculatorModel.continuousCalculate
                onToggled: calculatorModel.continuousCalculate = checked
            }
            Label { text: "Continuous calculate" }
        }

        Button {
            text: "Calculate"
            onClicked: calculatorModel.calculateArea()
        }

        Column {
            spacing: 10
            Label { text: calculatorModel.area.toString() }
            Slider {
                from: 0; to: 10000
                value: calculatorModel.area
                enabled: false
            }
            Label { text: "Area" }
        }
    }
}
