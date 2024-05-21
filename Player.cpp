#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QMessageBox>
#include "Bullet.h"
#include "Enemy.h"

#include <QDebug>

Player::Player(QGraphicsScene *scene, int w, int h)
{
    this->w = w;
    this->h = h;
    this->scene = scene;
    setPixmap(QPixmap(":/images/ship.png").scaled(w, h));

    healthText = new QGraphicsTextItem();
    healthText->setPlainText(QString("Health: ") + QString::number(health));
    healthText->setDefaultTextColor(Qt::red);
    healthText->setFont(QFont("cambria", 16));
    scene->addItem(healthText);
    healthText->setPos(0, 0);

    scoreText = new QGraphicsTextItem();
    scoreText->setPlainText(QString("Score: ") + QString::number(score));
    scoreText->setDefaultTextColor(Qt::blue);
    scoreText->setFont(QFont("cambria", 16));
    scene->addItem(scoreText);
    scoreText->setPos(700, 0);
}
void Player::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0)
            setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 800)
            setPos(x()+10,y());
    }
    else if (event->key() == Qt::Key_Space){
        // create a bullet
        Bullet * bullet = new Bullet(this);
        bullet->setPos(x() + w / 2 - bullet->w / 2,y());
        scene->addItem(bullet);
    }
}

void Player::spawn(){
    // create an enemy
    Enemy * enemy = new Enemy();
    scene->addItem(enemy);
}

void Player::decrease() {
    health--;
    healthText->setPlainText(QString("Health: ") + QString::number(health));
    if (health < 1) {
        QMessageBox::information(nullptr, "Game Over!", "Final score: " + QString::number(score));
        scene->clear();
        QCoreApplication::quit();
        exit(EXIT_FAILURE);
    }
}

void Player::increase() {
    score++;
    scoreText->setPlainText(QString("Score: ") + QString::number(score));
}
