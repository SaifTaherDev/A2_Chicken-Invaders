#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QObject>
#include "Player.h"

class Bullet: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Bullet(Player* player);
    int w = 10;
    int h = 50;
    Player* player;
public slots:
    void move();
};

#endif // BULLET_H
