#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsRectItem>
#include <QObject>

class Enemy: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy();
    int w = 100;
    int h = 100;
public slots:
    void move();
};

#endif // ENEMY_H
