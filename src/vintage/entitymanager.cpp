#include "entitymanager.h"
#include "entityitem.h"
#include <QDebug>

EntityManager::EntityManager(QObject *parent)
    : QObject{parent}
{

}

EntityItem *EntityManager::getEntity(const QString &id) const noexcept
{
    if (!m_entities.contains(id)) return nullptr;

    return m_entities.value(id);
}

void EntityManager::registerEntity(const EntityItem* entity) noexcept
{
    if (entity == nullptr) return;

    auto key = entity->identifier();
    if (m_entities.contains(key)) {
        qDebug() << "Entity with id " << key << " already registered in EntityManager";
    }

    m_entities.insert(key, const_cast<EntityItem*>(entity));
}

void EntityManager::unregisterEntity(const EntityItem *entity) noexcept
{
    if (entity == nullptr) return;

    auto key = entity->identifier();
    if (!m_entities.contains(key)) return;

    m_entities.remove(key);
}
