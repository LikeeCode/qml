#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QIcon>
#include <QQmlContext>

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

    qmlRegisterType<AlbumModel>("AlbumModel", 1, 0, "AlbumModel");
    qmlRegisterType<SongModel>("PlayerModel", 1, 0, "PlayerModel");
    qmlRegisterType<SongModel>("SongModel", 1, 0, "SongModel");

    ViewModel viewModel;
    engine.rootContext()->setContextProperty("ViewModel", &viewModel);

    const QUrl url("qrc:/Hamilton/main.qml");
    engine.load(url);

    return app.exec();
}
