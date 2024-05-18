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
