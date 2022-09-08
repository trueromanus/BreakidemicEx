import QtQuick
import "../Box2DElements"

Image {
    id: screen
    width: 640
    height: 480
    /*transform: [
        Translate { y: 20 },
        Scale {
            origin.x: screen.width / 2
            origin.y: screen.height / 2
            xScale: window.width / 640
            yScale: window.height / 480
        }
    ]*/

    source: "Views/background.png"

    PhysicsWorld {
        id: physicsWorld
        //gravity: Qt.point(8,0)
    }

    Repeater {
        model: 3
        delegate: WoodenBox {
            x: Math.random() * (screen.width - 100)
            y: Math.random() * (screen.height / 3)
            rotation: Math.random() * 90
        }
    }

    Wall {
        id: ground
        height: 20
        anchors { left: parent.left; right: parent.right; top: parent.bottom }
    }
    Wall {
        id: ceiling
        height: 20
        anchors { left: parent.left; right: parent.right; bottom: parent.top }
    }
    Wall {
        id: leftWall
        width: 20
        anchors { right: parent.left; bottom: ground.top; top: ceiling.bottom }
    }
    Wall {
        id: rightWall
        width: 20
        anchors { left: parent.right; bottom: ground.top; top: ceiling.bottom }
    }

    PhysicsDebugDraw {
        id: debugDraw
        world: physicsWorld
    }

    MouseArea {
        id: debugMouseArea
        anchors.fill: parent
        onPressed: debugDraw.visible = !debugDraw.visible
    }
}
