import QtQuick
import "../Box2DElements"

Item {
    id: wall

    PhysicsBody {
        BoxCollider {
            x: wall.x
            y: wall.y
            width: wall.width
            height: wall.height
        }
    }
}
