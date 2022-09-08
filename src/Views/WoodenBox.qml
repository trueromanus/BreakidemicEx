import QtQuick
import "../Box2DElements"

Item {
    id: root
    width: 100
    height: 100

    Image {
        source: "woodenbox.png"
        mipmap: true
    }

    PhysicsBody {
        id: boxBody
        target: root
        isDynamic: true

        BoxCollider {
            density: 1
            friction: 0.3
            restitution: 0.5
            width: root.width
            height: root.height
        }
    }
}
