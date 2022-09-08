#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <QObject>
#include <QMap>
#include "entityitem.h"

class EntityManager : public QObject
{
    Q_OBJECT

private:
    QMap<QString, EntityItem*> m_entities { QMap<QString, EntityItem*>() };

public:
    explicit EntityManager(QObject *parent = nullptr);

    EntityItem* getEntity(const QString& id) const noexcept;
    Q_INVOKABLE void registerEntity(const EntityItem* entity) noexcept;
    Q_INVOKABLE void unregisterEntity(const EntityItem* entity) noexcept;

signals:

};

#endif // ENTITYMANAGER_H
