import QtQuick
import Box2D

Body {
    target: parent
    world: physicsWorld

    property bool isDynamic: false
    property bool isKinematic: false
    property bool isStatic: false

    onIsDynamicChanged: {
        if (isDynamic) bodyType = Body.Dynamic;
    }
    onIsKinematicChanged: {
        if (isKinematic) bodyType = Body.Kinematic;
    }
    onIsStaticChanged: {
        if (isStatic) bodyType = Body.Static;
    }
}
