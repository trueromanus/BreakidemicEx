#ifndef PADDLECOMPONENT_H
#define PADDLECOMPONENT_H

#include <QObject>
#include "ballcomponent.h"
#include "../vintage/entitymanager.h"

class PaddleComponent : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int health READ health NOTIFY healthChanged)
    Q_PROPERTY(bool isDied READ isDied NOTIFY isDiedChanged)
    Q_PROPERTY(EntityManager* entityManager READ entityManager WRITE setEntityManager NOTIFY entityManagerChanged)

private:
    int m_health { 0 };
    bool m_isDied { false };
    EntityManager* m_entityManager { nullptr };

public:
    explicit PaddleComponent(QObject *parent = nullptr);

    int health() const noexcept { return m_health; }
    void setHealth(const int& health) noexcept;

    bool isDied() const noexcept { return m_isDied; }
    void setIsDied(const bool& isDied) noexcept;

    EntityManager* entityManager() const noexcept { return m_entityManager; }
    void setEntityManager(const EntityManager* entityManager) noexcept;

    Q_INVOKABLE void beginCollideWith(const QObject* object);
    Q_INVOKABLE void endCollideWith(const QObject* object);
    void touchBallToBottomLine(const BallComponent* ball);
    void touchBallToPlayer(const QString& ball);
    void touchEnemyToPlayer();

signals:
    void healthChanged();
    void isDiedChanged();
    void entityManagerChanged();

};

#endif // PADDLECOMPONENT_H
