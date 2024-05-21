#include <QApplication>
#include "Player.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // create a scene
    QGraphicsScene * scene = new QGraphicsScene();

    int player_w = 100, player_h = 100;
    Player * player = new Player(scene, player_w, player_h);

    // add the item to the scene
    scene->addItem(player);

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    QGraphicsView * view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->show();
    view->setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);

    player->setPos(view->width()/2,view->height() - player->h);

    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);

    return a.exec();
}
