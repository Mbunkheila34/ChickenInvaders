#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsRectItem>
#include <QObject>

class MyRect:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:

    void keyPressEvent(QKeyEvent * event);
    int score;
    int health;
    QGraphicsTextItem *scoreTextItem;
    QGraphicsTextItem *healthTextItem;

public slots:
    void spawn();
    void decrease();
    void increase();
signals:
    void gameOver(int score);

};

#endif // MYRECT_H
