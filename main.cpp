#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlEngine>
#include <QIcon>

#include "model/AlbumModel.h"
#include "model/PlayerModel.h"
#include "model/SongModel.h"

#include "viewModel/ViewModel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    app.setWindowIcon(QIcon("qrc:/Hamilton/images/hamilton-logo.ico"));

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []()
        { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    // Register C++ model types for use from QML if needed (optional).
    // Use a module name for grouping
    qmlRegisterType<AlbumModel>("Hamilton.Models", 1, 0, "AlbumModel");
    qmlRegisterType<PlayerModel>("Hamilton.Models", 1, 0, "PlayerModel");
    qmlRegisterType<SongModel>("Hamilton.Models", 1, 0, "SongModel");

    // Create the ViewModel on the heap and give it the application as parent so
    // its lifetime is managed by Qt's parent/child system. Expose it to QML
    // as a context property named "viewModel" (lowercase) for easy access.
    ViewModel *viewModel = new ViewModel(&app);
    QQmlEngine::setObjectOwnership(viewModel, QQmlEngine::CppOwnership);
    engine.rootContext()->setContextProperty("viewModel", viewModel);

    const QUrl url("qrc:/Hamilton/main.qml");
    engine.load(url);

    return app.exec();
}
