#include "entityitem.h"

EntityItem::EntityItem(QObject *parent)
    : QQuickItem()
{

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
