#ifndef PLAYERINPUTCONTROLLER_H
#define PLAYERINPUTCONTROLLER_H

#include <QObject>
#include <QMap>

class PlayerInputController : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QStringList currentKeys READ currentKeys NOTIFY currentKeysChanged)

private:
    QMap<uint32_t, QString> m_keyNames { QMap<uint32_t, QString>() };
    QMap<uint32_t, QString> m_nativeKeyNames { QMap<uint32_t, QString>() };
    QStringList m_currentKeys { QStringList() };

public:
    explicit PlayerInputController(QObject *parent = nullptr);

    QStringList currentKeys() const noexcept { return m_currentKeys; }

    Q_INVOKABLE void keyPressedHandler(int key, int nativeCode, bool control, bool shift, bool alt);
    Q_INVOKABLE void keyReleasedHandler(int key, int nativeCode, bool control, bool shift, bool alt);

signals:
    void currentKeysChanged();

};

#endif // PLAYERINPUTCONTROLLER_H
