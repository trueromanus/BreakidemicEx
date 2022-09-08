#ifndef PLAYERINPUTCONTROLLER_H
#define PLAYERINPUTCONTROLLER_H

#include <QObject>
#include <QMap>

class PlayerInputController : public QObject
{
    Q_OBJECT
private:
    QMap<uint32_t, uint32_t> m_keysMapping { QMap<uint32_t, uint32_t>() };
    QMap<uint32_t, bool> m_keysState { QMap<uint32_t, bool>() };

public:
    explicit PlayerInputController(QObject *parent = nullptr);

    Q_INVOKABLE void keyPressedHandler(int key, int nativeCode, bool control, bool shift, bool alt);
    Q_INVOKABLE void keyReleasedHandler(int key, int nativeCode, bool control, bool shift, bool alt);

signals:
    void inputStateChanged();

};

#endif // PLAYERINPUTCONTROLLER_H
