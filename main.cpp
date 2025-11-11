#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QIcon>

#include "models/AlbumModel.h"
#include "models/PlayerModel.h"
#include "models/SongModel.h"

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

    const QUrl url("qrc:/Hamilton/main.qml");
    engine.load(url);

    return app.exec();
}
