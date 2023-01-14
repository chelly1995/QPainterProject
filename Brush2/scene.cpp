#include "scene.h"
#include "resizeablepixmapitem.h"

#include <QGraphicsSceneMouseEvent>

Scene::Scene(QObject *parent) : QGraphicsScene(parent),drawing(false)
{

}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){

        startingPoint = event->scenePos();
        drawing = true;
    }
}

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if((event->buttons() & Qt::LeftButton) && drawing){
        drawLineTo(event->scenePos());
    }
}

void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if((event->button() == Qt::LeftButton) && drawing){

        lineGroup = nullptr;
        drawing = false;

    }

}
void Scene::drawLineTo(const QPointF &endPoint)
{
    if(!lineGroup){
        lineGroup = new QGraphicsItemGroup();
        lineGroup->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
        addItem(lineGroup);
        lastPenPoint = startingPoint;
    }

    QGraphicsLineItem  *localLine = new QGraphicsLineItem(QLineF(lastPenPoint,endPoint));
    QPen mPen;
    mPen.setWidth(3);
    mPen.setColor(Qt::green);
    localLine->setPen(mPen);
    lineGroup->addToGroup(localLine);

    lastPenPoint = endPoint;
}
