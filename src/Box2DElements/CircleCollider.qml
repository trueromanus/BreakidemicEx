import QtQuick
import Box2D

Circle {
    signal beginContactObject(var object)
    signal endContactObject(var object)

    onBeginContact: function (other) {
        beginContactObject(other.getBody().target);
    }
    onEndContact: function (other) {
        endContactObject(other.getBody().target);
    }
}
