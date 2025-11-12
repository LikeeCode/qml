#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlEngine>
#include <QIcon>
#include <QtQml> // For qmlRegisterUncreatableType

#include "model/AlbumModel.h"
#include "model/PlayerModel.h"
#include "model/SongModel.h"
#include "model/MediaList.h" // Include the header with our structs

#include "viewModel/ViewModel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    app.setWindowIcon(QIcon("qrc:/Hamilton/images/hamilton-logo.ico"));

    // Register our value types for signal/slot communication
    qRegisterMetaType<Album>("Album");
    qRegisterMetaType<Song>("Song");
    qRegisterMetaType<QList<Song>>("QList<Song>");

    // Make the type names known to QML. They are "uncreatable" from QML,
    // but this allows QML to understand them when they arrive from C++.
    qmlRegisterUncreatableType<Album>("Hamilton.Models", 1, 0, "Album", "Cannot create Album in QML");
    qmlRegisterUncreatableType<Song>("Hamilton.Models", 1, 0, "Song", "Cannot create Song in QML");

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
    
    // Create and attach models to the ViewModel
    AlbumModel *albumModel = new AlbumModel();
    PlayerModel *playerModel = new PlayerModel();
    SongModel *songModel = new SongModel();
    
    viewModel->setAlbumModel(albumModel);
    viewModel->setPlayerModel(playerModel);
    viewModel->setSongModel(songModel);
    
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("viewModel", viewModel);

    const QUrl url("qrc:/Hamilton/main.qml");
    engine.load(url);

    return app.exec();
}
