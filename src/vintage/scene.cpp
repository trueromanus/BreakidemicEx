#include <QRandomGenerator>
#include "scene.h"

Scene::Scene()
{
    auto value1 = QRandomGenerator::global()->generate64();
    auto value2 = QRandomGenerator::global()->generate64();
    auto value3 = QRandomGenerator::global()->generate64();
    auto value4 = QRandomGenerator::global()->generate64();
    m_sceneId = QString::number(value1) + QString::number(value2) + QString::number(value3) + QString::number(value4);
    m_entityManager = new EntityManager(this);
}

void Scene::setSceneName(const QString &sceneName) noexcept
{
    if (m_sceneName == sceneName) return;

    m_sceneName = sceneName;
    emit sceneNameChanged();
}

void Scene::setActivated(bool activated) noexcept
{
    if (m_activated == activated) return;

    m_activated = activated;
    emit activatedChanged();

    if (activated) {
        startSceneTimer();
    }else {
        stopSceneTimer();
    }
}

void Scene::setPhysicsWorld(const Box2DWorld *physicsWorld) noexcept
{
    if (m_physicsWorld == physicsWorld) return;

    m_physicsWorld = const_cast<Box2DWorld *>(physicsWorld);
    emit physicsWorldChanged();
}

void Scene::timerEvent(QTimerEvent *event)
{
    if (m_physicsWorld != nullptr) m_physicsWorld->step(); // handle physics

    //update and freeze input controller

    m_entityManager->updateAllEntities(); // update logic, visual and calculations
}

void Scene::startSceneTimer()
{
    m_currentSceneTimer = startTimer(10, Qt::PreciseTimer);
}

void Scene::stopSceneTimer()
{
    if (m_currentSceneTimer == -1) return;

    killTimer(m_currentSceneTimer);
}
