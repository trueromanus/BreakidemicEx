#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <QObject>
#include <QMap>
#include <QQuickItem>

class EntityManager : public QObject
{
    Q_OBJECT

private:
    QMap<QString, QQuickItem*> m_entities { QMap<QString, QQuickItem*>() };

public:
    explicit EntityManager(QObject *parent = nullptr);

    QQuickItem* getEntity(const QString& id) const noexcept;
    Q_INVOKABLE void registerEntity(const QQuickItem* entity) noexcept;
    Q_INVOKABLE void unregisterEntity(const QQuickItem* entity) noexcept;

signals:

};

#endif // ENTITYMANAGER_H
