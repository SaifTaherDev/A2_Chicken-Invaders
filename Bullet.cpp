#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Enemy.h"

#include <QDebug>
Bullet::Bullet(Player* player): QObject(), QGraphicsPixmapItem(){
    // drew the rect
    setPixmap(QPixmap(":/images/red_laser.png").scaled(w, h));
    this->player = player;
    // connect
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Bullet::move(){
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0; i < colliding_items.size(); i++) {
        if (typeid(*colliding_items[i]) == typeid(Enemy)) {
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            player->increase();
            delete this;
            delete colliding_items[i];
            return;
        }
    }

    setPos(x(), y() -  10);
    if (pos().y() + h < 0) {
        scene()->removeItem(this);
        delete this;
    }
}
