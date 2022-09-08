#include "paddlecomponent.h"

PaddleComponent::PaddleComponent(QObject *parent)
    : QObject{parent}
{

}

void PaddleComponent::setHealth(const int &health) noexcept
{
    if (m_health == health) return;

    m_health = health;
    emit healthChanged();
}

void PaddleComponent::setIsDied(const bool &isDied) noexcept
{
    if (m_isDied == isDied) return;

    m_isDied = isDied;
    emit isDiedChanged();
}

void PaddleComponent::setEntityManager(const EntityManager *entityManager) noexcept
{
    if (m_entityManager == entityManager) return;

    m_entityManager = const_cast<EntityManager *>(entityManager);
    emit entityManagerChanged();
}

void PaddleComponent::beginCollideWith(const QObject *object)
{
    auto ball = dynamic_cast<const BallComponent*>(object);
    if (ball != nullptr) {

    }
}

void PaddleComponent::endCollideWith(const QObject *object)
{

}

void PaddleComponent::touchBallToBottomLine(const BallComponent* ball)
{
    if (m_health == 0) return;

    int value = 0;
    auto damage = ball->damage();

    if (ball->isHealer() || ball->isHotPotato()) return;

    if (ball->isDamager() || ball->isOwnPossesion()) {
        value = m_health - damage;
        if (value < 0) value = 0;
    }

    setHealth(value);
    setIsDied(value == 0);
}

void PaddleComponent::touchBallToPlayer(const QString& ball)
{
    if (m_health == 0) return;

    /*int value = 0;
    auto damage = ball->damage();

    if (ball->isOwnPossesion()) return;
    if (ball->isHealer()) value = ball->isHealerReverse() ? m_health - damage : m_health + damage;
    if (ball->isHotPotato() || ball->isDamager()) value = m_health - damage;
    if (value < 0) value = 0;

    setHealth(value);
    setIsDied(value == 0);*/
}

void PaddleComponent::touchEnemyToPlayer()
{
    auto value = m_health - 2;
    if (value < 0) value = 0;

    setHealth(value);
    setIsDied(value == 0);
}
