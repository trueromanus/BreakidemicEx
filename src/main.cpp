#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "../qml-box2d/box2dplugin.h"

#include "../Brekidemic/ballcomponent.h"
#include "../Brekidemic/paddlecomponent.h"
#include "../Brekidemic/wallcomponent.h"
#include "../Brekidemic/localstorage.h"

#include "../vintage/entitymanager.h"
#include "../vintage/entityitem.h"
#include "../vintage/scene.h"

void registerVintageTypes();
void registerBrekidemicTypes();

int main(int argc, char *argv[])
{
    qputenv("QML_DISABLE_DISK_CACHE", "1");

    QGuiApplication app(argc, argv);

    Box2DPlugin plugin;
    plugin.registerTypes("Box2D");
    qmlProtectModule("Box2D", 2);

    registerVintageTypes();
    registerBrekidemicTypes();

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}

void registerVintageTypes() {
    qmlRegisterType<EntityItem>("Vintage", 1, 0, "EntityItem");
    qmlRegisterType<EntityManager>("Vintage", 1, 0, "EntityManager");
    qmlRegisterType<Scene>("Vintage", 1, 0, "Scene");
}

void registerBrekidemicTypes() {
    qmlRegisterType<BallComponent>("Brekidemic", 1, 0, "BallComponent");
    qmlRegisterType<WallComponent>("Brekidemic", 1, 0, "WallComponent");
    qmlRegisterType<PaddleComponent>("Brekidemic", 1, 0, "PaddleComponent");
    qmlRegisterType<LocalStorage>("Brekidemic", 1, 0, "LocalStorage");
}
