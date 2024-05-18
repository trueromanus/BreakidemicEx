import QtQuick
import '../../Box2DElements'
import Vintage

EntityItem {
    id: root
    kind: `wall`

    PhysicsBody {
        BoxCollider {
            x: root.x
            y: root.y
            width: root.width
            height: root.height
        }
    }
}
