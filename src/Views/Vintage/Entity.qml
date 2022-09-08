import QtQuick 2.0
import Vintage

EntityItem {
    id: root

    Component.onCompleted: {
        entityManager.registerEntity(root);
    }
    Component.onDestruction: {
        entityManager.unregisterEntity(root);
    }
}
