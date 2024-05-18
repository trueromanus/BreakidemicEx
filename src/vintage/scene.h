#ifndef SCENE_H
#define SCENE_H

#include "entitymanager.h"

class Scene : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QString sceneName READ sceneName WRITE setSceneName NOTIFY sceneNameChanged FINAL)
    Q_PROPERTY(QString sceneId READ sceneId NOTIFY sceneIdChanged FINAL)

private:
    QString m_sceneName { "" };
    QString m_sceneId { "" };
    EntityManager* m_entityManager { nullptr };

public:
    Scene();

    QString sceneName() const noexcept { return m_sceneName; }
    void setSceneName(const QString& sceneName) noexcept;

    QString sceneId() const noexcept { return m_sceneId; }

    EntityManager* entityManager() const noexcept { return m_entityManager; }

signals:
    void sceneNameChanged();
    void sceneIdChanged();

};

#endif // SCENE_H
