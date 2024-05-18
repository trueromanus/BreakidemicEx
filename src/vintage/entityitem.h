#ifndef ENTITYITEM_H
#define ENTITYITEM_H

#include <QQuickItem>
#include "scene.h"

class EntityItem : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QString kind READ kind WRITE setKind NOTIFY kindChanged)
    Q_PROPERTY(QString tag READ tag WRITE setTag NOTIFY tagChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QObject* component READ component WRITE setComponent NOTIFY componentChanged)
    Q_PROPERTY(QString identifier READ identifier NOTIFY identifierChanged)

private:
    QString m_kind { "" };
    QString m_tag { "" };
    QString m_name { "" };
    QObject* m_component { nullptr };
    Scene* m_scene { nullptr };

public:
    explicit EntityItem(QObject *parent = nullptr);

    QString kind() const noexcept { return m_kind; }
    void setKind(const QString& kind) noexcept;

    QString tag() const noexcept { return m_tag; }
    void setTag(const QString& tag) noexcept;

    QString name() const noexcept { return m_name; }
    void setName(const QString& name) noexcept;

    QString identifier() const noexcept { return m_name + m_kind + m_tag; }

    QObject* component() const noexcept { return m_component; }
    void setComponent(const QObject* component) noexcept;

    void componentComplete() override;

    Q_INVOKABLE void updateEntity();

private:
    void tryFillParentScene();

private slots:
    void innerParentChanged(QQuickItem* item);

signals:
    void kindChanged();
    void tagChanged();
    void nameChanged();
    void componentChanged();
    void identifierChanged();

};

#endif // ENTITYITEM_H
