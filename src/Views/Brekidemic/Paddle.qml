import QtQuick
import Vintage
import Brekidemic
import '../../Box2DElements'
import "../Vintage"

Entity {
    id: root
    width: 10
    height: 100
    kind: "paddle"
    component: PaddleComponent {
    }

    Image {
        source: localStorage.assetsPath + "paddle.png"
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit
    }

    PhysicsBody{
        id: paddleBody
        target: root
        isKinematic: true
        bullet: false
        fixedRotation: true

        BoxCollider {
            id: boxCollider
            x: root.x
            y: root.y
            width: root.width
            height: root.height
            onBeginContactObject: function (object) {
                root.component.beginCollideWith(object);
            }
        }
    }

    onYChanged: {
        if (y < 5) paddleBody.linearVelocity = Qt.point(0, 0);
        if (y + height >= scene.height) paddleBody.linearVelocity = Qt.point(0, 0);
    }

    /*
    Connections {
        target: controller
        onXAxisChanged: {
            if (x < 5 && controller.xAxis < 0 || x + width > scene.width && controller.xAxis > 0) return;
            boxCollider.linearVelocity = Qt.point(controller.xAxis * 750, 0);
        }
    }
*/

}
