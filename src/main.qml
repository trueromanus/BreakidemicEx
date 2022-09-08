import QtQuick
import "Views"
import Vintage
import Brekidemic
import "Views/Brekidemic"
import "Box2DElements"

Window {
    id: window
    width: 1280
    height: 720
    visible: true
    title: "Breakidemic"

    EntityManager {
        id: entityManager
    }

    LocalStorage {
        id: localStorage
    }

    Scene {
        id: scene
        width: 1280
        height: 720

        Rectangle {
            anchors.fill: parent
            color: "lightgray"
        }

        WallBase {
            name: "left"
            width: 2
            height: 720
            x: 0
        }

        WallBase {
            name: "right"
            width: 2
            height: 720
            x: 1279
        }

        WallBase {
            name: "top"
            width: 1280
            height: 2
            x: 0
            y: -1
        }

        WallBase {
            name: "bottom"
            height: 10
            width: 1280
            x: 0
            y: 720
        }

        Ball {
            id: ball
            x: 610
            y: 100
        }

    }

    PhysicsWorld {
        id: physicsWorld
        gravity: Qt.point(0, 10)
    }

    PhysicsDebugDraw {
        id: debugDraw
        world: physicsWorld
    }
}
