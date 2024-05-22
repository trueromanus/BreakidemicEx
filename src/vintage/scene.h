#ifndef SCENE_H
#define SCENE_H

#include "qml-box2d/box2dworld.h"
#include "entitymanager.h"

class Scene : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QString sceneName READ sceneName WRITE setSceneName NOTIFY sceneNameChanged FINAL)
    Q_PROPERTY(QString sceneId READ sceneId NOTIFY sceneIdChanged FINAL)
    Q_PROPERTY(bool activated READ activated WRITE setActivated NOTIFY activatedChanged FINAL)
    Q_PROPERTY(Box2DWorld* physicsWorld READ physicsWorld WRITE setPhysicsWorld NOTIFY physicsWorldChanged FINAL)

private:
    QString m_sceneName { "" };
    QString m_sceneId { "" };
    EntityManager* m_entityManager { nullptr };
    bool m_activated { false };
    Box2DWorld* m_physicsWorld { nullptr };
    int m_currentSceneTimer { -1 };

public:
    Scene();

    QString sceneName() const noexcept { return m_sceneName; }
    void setSceneName(const QString& sceneName) noexcept;

    QString sceneId() const noexcept { return m_sceneId; }

    EntityManager* entityManager() const noexcept { return m_entityManager; }

    bool activated() const noexcept { return m_activated; }
    void setActivated(bool activated) noexcept;

    Box2DWorld* physicsWorld() const noexcept { return m_physicsWorld; }
    void setPhysicsWorld(const Box2DWorld* physicsWorld) noexcept;

protected:
    void timerEvent(QTimerEvent *event) override;

private:
    void startSceneTimer();
    void stopSceneTimer();

signals:
    void sceneNameChanged();
    void sceneIdChanged();
    void activatedChanged();
    void physicsWorldChanged();

};

#endif // SCENE_H
