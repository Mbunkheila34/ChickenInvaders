#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "enemy.h"

#include <QDebug>
Bullet::Bullet(): QObject(), QGraphicsPixmapItem(){
    // drew the rect
    // setRect(0,0,10,50);

    // connect
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Bullet::move(){
    // if bullet collides with enemy, destroy both
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){
            // remove them both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            emit hit();
            // delete them both
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    // move bullet up
    setPos(x(),y()-10);
    if (pos().y() < 0){
        scene()->removeItem(this);
        delete this;
    }
}
