#include "widget.h"
#include "rectangleitem.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QGraphicsScene* scene = new QGraphicsScene;
    scene->addItem(new RectangleItem());
    scene->setSceneRect(0, 0, 400, 400);

    QGraphicsView* view = new QGraphicsView(scene, this);
    view->resize(420, 420);
}

Widget::~Widget()
{
}

