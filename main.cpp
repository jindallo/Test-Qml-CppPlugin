#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>

#include "cppplugin.h"
#include "myclass.h"

int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    qmlRegisterType<CppPlugin>("CppPlugin", 1, 0, "CppPlugin");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    MyClass myClass;
    QObject::connect(engine.rootObjects().first(), SIGNAL(qmlSignal(QString)),
                     &myClass, SLOT(cppSlot(QString)));

    QVariant returnedValue;
    QVariant msg = "Hello from C++";
    QMetaObject::invokeMethod(engine.rootObjects().first(), "qmlFunction",
                              Q_RETURN_ARG(QVariant, returnedValue),
                              Q_ARG(QVariant, msg));
    qDebug() << "QML function returned: " << returnedValue.toString();

    return app.exec();
}
