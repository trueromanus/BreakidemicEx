#include "playerinputcontroller.h"

PlayerInputController::PlayerInputController(QObject *parent)
    : QObject{parent}
{
    m_keysMapping.insert(0, Qt::Key_0);
    m_keysMapping.insert(1, Qt::Key_1);
    m_keysMapping.insert(2, Qt::Key_2);
    m_keysMapping.insert(3, Qt::Key_3);
    m_keysMapping.insert(4, Qt::Key_4);
    m_keysMapping.insert(5, Qt::Key_5);
    m_keysMapping.insert(6, Qt::Key_6);
    m_keysMapping.insert(7, Qt::Key_7);
    m_keysMapping.insert(8, Qt::Key_8);
    m_keysMapping.insert(9, Qt::Key_9);
}

void PlayerInputController::keyPressedHandler(int key, int nativeCode, bool control, bool shift, bool alt)
{
    if (!m_keysState.contains(key)) return;

    if (m_keysMapping.contains(key)) {
        m_keysState[key] = true;
        emit inputStateChanged();
    }

    //TODO: check native codes
}

void PlayerInputController::keyReleasedHandler(int key, int nativeCode, bool control, bool shift, bool alt)
{
    if (!m_keysState.contains(key)) return;

    if (m_keysMapping.contains(key)) {
        m_keysState[key] = false;
        emit inputStateChanged();
    }

    //TODO: check native codes
}
