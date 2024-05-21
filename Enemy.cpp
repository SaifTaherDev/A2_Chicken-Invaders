#include "Enemy.h"
#include "Player.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand() -> really large int

#include <QDebug>
Enemy::Enemy(): QObject(), QGraphicsPixmapItem(){
    //set random position
    int random_number = rand() % 700;
    setPos(random_number, 0);
    setPixmap(QPixmap(":/images/chicken.png").scaled(w, h));

    // connect
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Enemy::move(){
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0; i < colliding_items.size(); i++) {
        if (typeid(*(colliding_items[i])) == typeid(Player)) {
            scene()->removeItem(this);
            delete this;
            Player *player = dynamic_cast<Player*>(colliding_items[i]);
            player->decrease();
            return;
        }
    }

    setPos(x(), y() + 5);

    if (y() + h > scene()->height()) {
        scene()->removeItem(this);
        delete this;
    }
}
