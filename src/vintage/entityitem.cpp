#include "entityitem.h"

EntityItem::EntityItem(QObject *parent)
    : QQuickItem()
{
    connect(this, &EntityItem::parentChanged, this, &EntityItem::innerParentChanged);
}

void EntityItem::setKind(const QString &kind) noexcept
{
    if (m_kind == kind) return;

    m_kind = kind;
    emit kindChanged();
}

void EntityItem::setTag(const QString &tag) noexcept
{
    if (m_tag == tag) return;

    m_tag = tag;
    emit tagChanged();
}

void EntityItem::setName(const QString& name) noexcept
{
    if (m_name == name) return;

    m_name = name;
    emit nameChanged();
}

void EntityItem::setComponent(const QObject *component) noexcept
{
    if (m_component == component) return;

    m_component = const_cast<QObject *>(component);
    emit componentChanged();
}

void EntityItem::componentComplete()
{
    QQuickItem::componentComplete();

    tryFillParentScene();

    if (m_scene != nullptr) m_scene->entityManager()->registerEntity(this);
}

void EntityItem::updateEntity()
{

}

void EntityItem::tryFillParentScene()
{
    QQuickItem* current = parentItem();

    while (current != nullptr) {
        auto value = static_cast<Scene*>(current);
        if (value != nullptr) {
            m_scene = value;
            break;
        } else {
            current = parentItem();
            if (current == nullptr) break;
        }
    }

    if (m_scene == nullptr) qDebug() << "Can't founded scene for entity " << m_name << " (" << m_kind << "):" << m_tag;
}

void EntityItem::innerParentChanged(QQuickItem *item)
{
    if (item == nullptr && m_scene != nullptr) m_scene->entityManager()->unregisterEntity(this);
}
