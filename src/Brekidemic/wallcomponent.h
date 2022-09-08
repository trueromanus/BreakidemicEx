#ifndef WALLCOMPONENT_H
#define WALLCOMPONENT_H

#include <QObject>

class WallComponent : public QObject
{
    Q_OBJECT
public:
    explicit WallComponent(QObject *parent = nullptr);

signals:

};

#endif // WALLCOMPONENT_H
