#include "myrect.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "bullet.h"
#include "enemy.h"
#include <QMessageBox>

#include <QDebug>
void MyRect::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0)
            setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 800)
            setPos(x()+10,y());
    }
    else if (event->key() == Qt::Key_Space){
        if(health > 0)
        {
            // create a bullet
            Bullet * bullet = new Bullet();
            bullet->setPixmap(QPixmap(":/image/red_laser.png").scaled(10,50));
            bullet->setPos(x()+45,y());
            scene()->addItem(bullet);
            connect(bullet, SIGNAL(hit()), this, SLOT(increase()));
        }
    }
}

void MyRect::spawn(){
    // create an enemy
    Enemy * enemy = new Enemy();
    enemy->setPixmap(QPixmap(":/image/chicken.jpg").scaled(100,100));
    scene()->addItem(enemy);
    connect(enemy, SIGNAL(escaped()),this, SLOT(decrease()));
}

void MyRect::decrease(){
    if(health > 0)
    {
        this->health--;
        healthTextItem->setPlainText(QString("Health: %1").arg(health));
        if (health == 0) {
            QMessageBox::information(nullptr, "Game Over", QString("You lose! Your score: %1").arg(score));
        }
    }
}

void MyRect::increase(){
    if(health > 0)
    {
        this->score++;
        scoreTextItem->setPlainText(QString("Score: %1").arg(score));
    }
}
