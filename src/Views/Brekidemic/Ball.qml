import QtQuick
import Vintage
import Brekidemic
import '../../Box2DElements'
import "../Vintage"

Entity {
    id: root
    name: "ball"
    kind: "interactiveelements"
    tag: "main"
    width: 10
    height: 10
    component: BallComponent {
        damage: 2
    }

    Image {
        source: localStorage.assetsPath + "ball.png"
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit
    }

    PhysicsBody{
        id: ballBody
        target: root
        isDynamic: true
        angularDamping: 1
        linearDamping: 0
        fixedRotation: false
        angularVelocity: 80

        CircleCollider {
            id: ballCollider
            friction: 1
            restitution: 0.7
            radius: root.width / 2
            density: 1
            onBeginContact: function (other) {
                const body = other.getBody();
                const randomAngle = root.component.randomAngle();

                const yNormal = ballCollider.y === other.y ? 0 : ballCollider.y < other.y ? -1 : 1;
                const xNormal = ballCollider.x === other.x ? 0 : ballCollider.x < other.x ? -1 : 1;

                if (yNormal > 0 || yNormal < 0) {
                    const impulse = ballBody.linearVelocity.x < 0 ? -1 + randomAngle : 1 - randomAngle;
                    ballBody.applyLinearImpulse(body.toWorldVector(Qt.point(impulse, yNormal < 0 ? -1 : 1)), body.getWorldCenter());
                }

                if (xNormal > 0 || xNormal < 0) {
                    const impulseX = ballBody.linearVelocity.y < 0 ? -2 + randomAngle : 2 - randomAngle;
                    ballBody.applyLinearImpulse(body.toWorldVector(Qt.point(xNormal > 0 ? -1 : 1, impulseX)), body.getWorldCenter());
                }
            }
        }
    }
}
