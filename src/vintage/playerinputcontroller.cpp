#include "playerinputcontroller.h"

PlayerInputController::PlayerInputController(QObject *parent)
    : QObject{parent}
{
    m_keyNames.insert(Qt::Key_0, "0");
    m_keyNames.insert(Qt::Key_1, "1");
    m_keyNames.insert(Qt::Key_2, "2");
    m_keyNames.insert(Qt::Key_3, "3");
    m_keyNames.insert(Qt::Key_4, "4");
    m_keyNames.insert(Qt::Key_5, "5");
    m_keyNames.insert(Qt::Key_6, "6");
    m_keyNames.insert(Qt::Key_7, "7");
    m_keyNames.insert(Qt::Key_8, "8");
    m_keyNames.insert(Qt::Key_9, "9");
    m_keyNames.insert(Qt::Key_F1, "F1");
    m_keyNames.insert(Qt::Key_F2, "F2");
    m_keyNames.insert(Qt::Key_F3, "F3");
    m_keyNames.insert(Qt::Key_F4, "F4");
    m_keyNames.insert(Qt::Key_F5, "F5");
    m_keyNames.insert(Qt::Key_F6, "F7");
    m_keyNames.insert(Qt::Key_F8, "F8");
    m_keyNames.insert(Qt::Key_F9, "F9");
    m_keyNames.insert(Qt::Key_F10, "F10");
    m_keyNames.insert(Qt::Key_F11, "F11");
    m_keyNames.insert(Qt::Key_F12, "F12");
    m_keyNames.insert(Qt::Key_Up, "Up");
    m_keyNames.insert(Qt::Key_Down, "Down");
    m_keyNames.insert(Qt::Key_Left, "Left");
    m_keyNames.insert(Qt::Key_Right, "Right");
    m_keyNames.insert(Qt::Key_Control, "Control");
    m_keyNames.insert(Qt::Key_Shift, "Shift");
    m_keyNames.insert(Qt::Key_Alt, "Alt");
    m_keyNames.insert(Qt::Key_Home, "Home");
    m_keyNames.insert(Qt::Key_End, "End");
    m_keyNames.insert(Qt::Key_Insert, "Insert");
    m_keyNames.insert(Qt::Key_Delete, "Delete");
    m_keyNames.insert(Qt::Key_PageUp, "PageUp");
    m_keyNames.insert(Qt::Key_PageDown, "PageDown");
    m_keyNames.insert(Qt::Key_Asterisk, "Asteriks");
    m_keyNames.insert(Qt::Key_Backspace, "Backspace");
    m_keyNames.insert(Qt::Key_Enter, "Enter");
    m_keyNames.insert(Qt::Key_Plus, "Plus");
    m_keyNames.insert(Qt::Key_Minus, "Minus");
    m_keyNames.insert(Qt::Key_Backslash, "Backslash");
    m_keyNames.insert(Qt::Key_Space, "Space");
    m_keyNames.insert(Qt::Key_Slash, "Slash");
    m_keyNames.insert(Qt::Key_Equal, "Equal");
    m_keyNames.insert(Qt::Key_Return, "Enter");
}

void PlayerInputController::keyPressedHandler(int key, int nativeCode, bool control, bool shift, bool alt)
{
    if (m_nativeKeyNames.contains(key)) {
        auto keyName = m_nativeKeyNames.value(key);
        if (!m_currentKeys.contains(keyName)) m_currentKeys.append(keyName);
        emit currentKeysChanged();
    }

    if (m_keyNames.contains(key)) {
        auto keyName = m_keyNames.value(key);
        if (!m_currentKeys.contains(keyName)) m_currentKeys.append(keyName);
        emit currentKeysChanged();
    }
}

void PlayerInputController::keyReleasedHandler(int key, int nativeCode, bool control, bool shift, bool alt)
{
    if (m_nativeKeyNames.contains(key)) {
        auto keyName = m_nativeKeyNames.value(key);
        if (m_currentKeys.contains(keyName)) m_currentKeys.removeOne(keyName);
        emit currentKeysChanged();
    }

    if (m_keyNames.contains(key)) {
        auto keyName = m_keyNames.value(key);
        if (m_currentKeys.contains(keyName)) m_currentKeys.removeOne(keyName);
        emit currentKeysChanged();
    }
}
