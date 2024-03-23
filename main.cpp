
#include <QApplication>
#include "myrect.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include "bullet.h"
#include <QCoreApplication>
#include <QObject>
#include <QDebug>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // create a scene
    QGraphicsScene * scene = new QGraphicsScene();

    // create an item to add to the scene
    MyRect * player = new MyRect();
    player->setPixmap(QPixmap(":/image/ship.png"));
    player->score = 0;
    player->scoreTextItem = new QGraphicsTextItem(QString("Score: 0"));
    player->scoreTextItem->setPos(10, 10); // Set position of the text item on the scene
    scene->addItem(player->scoreTextItem);
    player->health = 3;
    player->healthTextItem = new QGraphicsTextItem(QString("Health: 3"));
    player->healthTextItem->setPos(700, 10); // Set position of the text item on the scene
    scene->addItem(player->healthTextItem);

    // add the item to the scene
    scene->addItem(player);

    // make rect focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // create a view to visualize the scene
    QGraphicsView * view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // show the view
    view->show();
    view->setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);

    player->setPos(view->width()/2,view->height() - 100);

    // spawn enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);

    return a.exec();
}
