#ifndef LOCALSTORAGE_H
#define LOCALSTORAGE_H

#include <QObject>
#include <QCoreApplication>

class LocalStorage : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString assetsPath READ assetsPath NOTIFY assetsPathChanged)

public:
    explicit LocalStorage(QObject *parent = nullptr);
#ifdef Q_OS_WIN
    QString assetsPath() const noexcept { return "file:///" + QCoreApplication::applicationDirPath() + "/assets/"; }
#elif
    QString assetsPath() const noexcept { return "file://" + QCoreApplication::applicationDirPath() + "/assets/"; }
#endif

signals:
    void assetsPathChanged();

};

#endif // LOCALSTORAGE_H
