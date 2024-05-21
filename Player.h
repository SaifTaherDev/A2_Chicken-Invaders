#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QObject>

class Player:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player(QGraphicsScene *scene, int w = 100, int h = 100);
    void keyPressEvent(QKeyEvent * event);
    void decrease();
    void increase();

    int w;
    int h;
    QGraphicsScene *scene;
    int health = 3;
    int score = 0;
    QGraphicsTextItem *healthText;
    QGraphicsTextItem *scoreText;
public slots:
    void spawn();
};

#endif // PLAYER_H
