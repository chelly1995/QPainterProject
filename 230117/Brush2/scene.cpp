#include "scene.h"

#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QColorDialog>
#include <QDebug>

Scene::Scene(QObject *parent) : QGraphicsScene(parent),drawing(false),m_lineItem()
{
    paintColor = Qt::green;
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){

        startingPoint = event->scenePos();

        drawing = true;
        lastPenPoint = startingPoint;
    }
    QGraphicsScene::mousePressEvent(event);
}

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    // drawLineTo(event->scenePos());
    if((event->buttons() & Qt::LeftButton) && drawing){
        lastPenPoint = event->scenePos();

        QPen pen;
        pen.setStyle(Qt::DashLine);
        pen.setBrush(paintColor);
        pen.setWidth(5);

        m_lineItem = new QGraphicsLineItem(event->scenePos().x(), event->scenePos().y(),event->scenePos().x(), event->scenePos().y());

        m_lineItem->setPen(pen);

        addItem(m_lineItem);

    }

    m_lineItem->setLine(event->scenePos().x(), event->scenePos().y(),event->scenePos().x(), event->scenePos().y());
    update();

}

void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if((event->button() == Qt::LeftButton) && drawing){

        //lineGroup = nullptr;
        drawing = false;
        //  lastPenPoint = event->pos();

    }
    QGraphicsScene::mouseReleaseEvent(event);
}


void Scene::drawLineTo(const QPointF &endPoint)
{

    //if(lineGroup != nullptr){                   // lineGroup에 값이 존재할 경우
    //        lineGroup = new QGraphicsItemGroup();
    //        lineGroup->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
    //        addItem(lineGroup);
    // lastPenPoint = startingPoint;

    //  qDebug()<<lineGroup;
    //}


    QGraphicsLineItem *localLine = new QGraphicsLineItem(QLineF(lastPenPoint,endPoint));

    QPen mPen;
    mPen.setStyle(Qt::SolidLine);
    mPen.setWidth(3);
    //mPen.setCapStyle(Qt::RoundCap);
    //mPen.setJoinStyle(Qt::RoundJoin);
    mPen.setColor(paintColor);
    localLine->setPen(mPen);
    //lineGroup->addToGroup(localLine);
    //lastPenPoint = endPoint;
    qDebug() << lastPenPoint << "/" << endPoint;
    qDebug() << localLine;

}

void Scene::setPaintColor(){

    paintColor = QColorDialog::getColor(paintColor);

}
