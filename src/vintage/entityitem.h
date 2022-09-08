#ifndef ENTITYITEM_H
#define ENTITYITEM_H

#include <QQuickItem>

class EntityItem : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QString kind READ kind WRITE setKind NOTIFY kindChanged)
    Q_PROPERTY(QString tag READ tag WRITE setTag NOTIFY tagChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QObject* component READ component WRITE setComponent NOTIFY componentChanged)

private:
    QString m_kind { "" };
    QString m_tag { "" };
    QString m_name { "" };
    QObject* m_component { nullptr };

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


signals:
    void kindChanged();
    void tagChanged();
    void nameChanged();
    void componentChanged();

};

#endif // ENTITYITEM_H
