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

    Scene {
        id: scene
        width: 1280
        height: 720
        focus: true
        /*transform: [
            Translate { y: 20 },
            Scale {
                origin.x: screen.width / 2
                origin.y: screen.height / 2
                xScale: window.width / 640
                yScale: window.height / 480
            }
        ]*/
        Keys.onPressed: function(event) {
            if (event.isAutoRepeat) return;

            playerInputController.keyPressedHandler(
                event.key,
                event.nativeKey,
                (event.modifiers & Qt.ControlModifier),
                (event.modifiers & Qt.ShiftModifier),
                (event.modifiers & Qt.AltModifier)
            );
            event.accepted = true;
        }
        Keys.onReleased: function(event) {
            if (event.isAutoRepeat) return;

            playerInputController.keyReleasedHandler(
                event.key,
                event.nativeKey,
                (event.modifiers & Qt.ControlModifier),
                (event.modifiers & Qt.ShiftModifier),
                (event.modifiers & Qt.AltModifier)
            );
            event.accepted = true;
        }

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

        Paddle {
            id: playerPaddle
            x: 1269
            y: 400
            name: "player"
        }
    }

    EntityManager {
        id: entityManager
    }

    LocalStorage {
        id: localStorage
    }

    PlayerInputController {
        id: playerInputController
        onCurrentKeysChanged: {
            console.log(playerInputController.currentKeys);
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
