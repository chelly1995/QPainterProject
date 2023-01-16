#include "scene.h"


#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QColorDialog>
#include <QDebug>


Scene::Scene(QObject *parent) : QGraphicsScene(parent),drawing(false)
{
    paintColor = Qt::green;
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){

        startingPoint = event->scenePos();
        // qDebug()<<startingPoint;

        //  lineGroup != nullptr;

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
        // drawLineTo(event->scenePos());
        // lineGroup = nullptr;
        drawing = false;


    }

}


void Scene::drawLineTo(const QPointF &endPoint)
{
    // lastPenPoint = startingPoint;

    if(lineGroup != nullptr){                   // 드로잉하고 있을 때
        lineGroup = new QGraphicsItemGroup();
        lineGroup->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
        addItem(lineGroup);
        //     lastPenPoint = endPoint;
    }


    QGraphicsLineItem *localLine = new QGraphicsLineItem(QLineF(lastPenPoint,endPoint));

    QPen mPen;
    //QPen mPen(paintColor,paintSize);
    // mPen.setStyle(Qt::SolidLine);
    mPen.setWidth(3);
    //mPen.setCapStyle(Qt::RoundCap);
    //mPen.setJoinStyle(Qt::RoundJoin);
    mPen.setColor(paintColor);
    localLine->setPen(mPen);
    lineGroup->addToGroup(localLine);
    qDebug() << lastPenPoint << "/" << endPoint;
    lastPenPoint = endPoint;
    qDebug() << lastPenPoint << "/" << endPoint;

    //    int x1, x2, y1, y2;

    //    if(lastPenPoint.x()<endPoint.x()){
    //        x1 = lastPenPoint.x(); x2=endPoint.x();

    //    }else{
    //        x1=endPoint.x(); x2 = lastPenPoint.x();

    //    }

    //    if(lastPenPoint.y()<endPoint.y()){
    //        y1 = lastPenPoint.y(); y2=endPoint.y();

    //    }else{
    //        y1=endPoint.y(); y2 = lastPenPoint.y();

    //    }


    //    QRectF rect(x1,x2,y1,y2);
    //  //  update(rect.toRect().adjusted(-5,-,5,+5,+5));
    //    lastPenPoint = endPoint;

}

void Scene::setPaintColor(){

    paintColor = QColorDialog::getColor(paintColor);

}
