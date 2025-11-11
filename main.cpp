#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QIcon>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    // Use the QML module URI prefix (Hamilton) to access embedded resources.
    // Resources added via qt_add_qml_module(... RESOURCES ...) are prefixed with qrc:/<URI>/
    app.setWindowIcon(QIcon("qrc:/Hamilton/images/hamilton-logo.ico"));

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []()
        { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    
    const QUrl url("qrc:/Hamilton/main.qml");
    engine.load(url);

    return app.exec();
}
