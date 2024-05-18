#include "entitymanager.h"
#include <QDebug>

EntityManager::EntityManager(QObject *parent)
    : QObject{parent}
{

}

QQuickItem *EntityManager::getEntity(const QString &id) const noexcept
{
    if (!m_entities.contains(id)) return nullptr;

    return m_entities.value(id);
}

void EntityManager::registerEntity(const QQuickItem* entity) noexcept
{
    if (entity == nullptr) return;

    auto keyVariant = entity->property("identifier");
    auto key = keyVariant.toString();
    if (m_entities.contains(key)) {
        qDebug() << "Entity with id " << key << " already registered in EntityManager";
    }

    m_entities.insert(key, const_cast<QQuickItem*>(entity));
}

void EntityManager::unregisterEntity(const QQuickItem *entity) noexcept
{
    if (entity == nullptr) return;

    auto keyVariant = entity->property("identifier");
    auto key = keyVariant.toString();
    if (!m_entities.contains(key)) return;

    m_entities.remove(key);
}
