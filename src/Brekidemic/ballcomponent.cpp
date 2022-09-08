#include <QRandomGenerator>
#include <QDebug>
#include "ballcomponent.h"

BallComponent::BallComponent(QObject *parent)
    : QObject{parent}
{

}

void BallComponent::setIsHotPotato(const bool& isHotPotato) noexcept
{
    if (m_isHotPotato == isHotPotato) return;

    m_isHotPotato = isHotPotato;
    emit isHotPotatoChanged();
}

void BallComponent::setDamage(int damage) noexcept
{
    if (m_damage == damage) return;

    m_damage = damage;
    emit damageChanged();
}

void BallComponent::setIsOwnPossesion(const bool& isOwnPossesion) noexcept
{
    if (m_isOwnPossesion == isOwnPossesion) return;

    m_isOwnPossesion = isOwnPossesion;
    emit isOwnPossesionChanged();
}

void BallComponent::setIsDoubleDamage(const bool &isDoubleDamage) noexcept
{
    if (m_isDoubleDamage == isDoubleDamage) return;

    m_isDoubleDamage = isDoubleDamage;
    emit isDoubleDamageChanged();
}

void BallComponent::setIsHealer(const bool& isHealer) noexcept
{
    if (m_isHealer == isHealer) return;

    m_isHealer = isHealer;
    emit isHealerChanged();
}

void BallComponent::setIsHealerReverse(const bool& isHealerReverse) noexcept
{
    if (m_isHealerReverse == isHealerReverse) return;

    m_isHealerReverse = isHealerReverse;
    emit isHealerReverseChanged();
}

void BallComponent::setIsDamager(const bool& isDamager) noexcept
{
    if (m_isDamager == isDamager) return;

    m_isDamager = isDamager;
    emit isDamagerChanged();
}

float BallComponent::randomAngle()
{
    auto value = QRandomGenerator::global()->bounded(0, 50);
    return static_cast<float>(value) / static_cast<float>(100);
}
