#ifndef BALLVIEWMODEL_H
#define BALLVIEWMODEL_H

#include <QObject>

class BallComponent : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool isHotPotato READ isHotPotato WRITE setIsHotPotato NOTIFY isHotPotatoChanged)
    Q_PROPERTY(int damage READ damage WRITE setDamage NOTIFY damageChanged)
    Q_PROPERTY(bool isOwnPossesion READ isOwnPossesion WRITE setIsOwnPossesion NOTIFY isOwnPossesionChanged)
    Q_PROPERTY(bool isDoubleDamage READ isDoubleDamage WRITE setIsDoubleDamage NOTIFY isDoubleDamageChanged)
    Q_PROPERTY(bool isHealer READ isHealer WRITE setIsHealer NOTIFY isHealerChanged)
    Q_PROPERTY(bool isHealerReverse READ isHealerReverse WRITE setIsHealerReverse NOTIFY isHealerReverseChanged)
    Q_PROPERTY(bool isDamager READ isDamager WRITE setIsDamager NOTIFY isDamagerChanged)

private:
    bool m_isHotPotato { false };
    int m_damage { 0 };
    bool m_isOwnPossesion { true };
    bool m_isDoubleDamage { false };
    bool m_isHealer { false };
    bool m_isHealerReverse { false };
    bool m_isDamager { false };

public:
    explicit BallComponent(QObject *parent = nullptr);

    bool isHotPotato() const noexcept { return m_isHotPotato; }
    void setIsHotPotato(const bool& isHotPotato) noexcept;

    int damage() const noexcept { return m_damage; }
    void setDamage(int damage) noexcept;

    bool isOwnPossesion() const noexcept { return m_isOwnPossesion; }
    void setIsOwnPossesion(const bool& isOwnPossesion) noexcept;

    bool isDoubleDamage() const noexcept { return m_isDoubleDamage; }
    void setIsDoubleDamage(const bool& isDoubleDamage) noexcept;

    bool isHealer() const noexcept { return m_isHealer; }
    void setIsHealer(const bool& isHealer) noexcept;

    bool isHealerReverse() const noexcept { return m_isHealerReverse; }
    void setIsHealerReverse(const bool& isHealerReverse) noexcept;

    bool isDamager() const noexcept { return m_isDamager; }
    void setIsDamager(const bool& isDamager) noexcept;

    Q_INVOKABLE float randomAngle();

signals:
    void isHotPotatoChanged();
    void damageChanged();
    void isOwnPossesionChanged();
    void isDoubleDamageChanged();
    void isHealerChanged();
    void isHealerReverseChanged();
    void isDamagerChanged();

};

#endif // BALLVIEWMODEL_H
