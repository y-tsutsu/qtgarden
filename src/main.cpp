#include "CalculatorModel.h"
#include "TodoListModel.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickStyle>

int main(int argc, char *argv[])
{
    QQuickStyle::setStyle("Material");

    QGuiApplication app(argc, argv);

    CalculatorModel calculatorModel;
    TodoListModel todoModel;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("calculatorModel", &calculatorModel);
    engine.rootContext()->setContextProperty("todoModel", &todoModel);
    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    if (engine.rootObjects().isEmpty())
    {
        return -1;
    }

    return app.exec();
}
