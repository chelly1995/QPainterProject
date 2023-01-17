#include "scene.h"

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
//#include <QGraphicsLineItem>
#include <QGraphicsPathItem>
#include <QPainterPath>
#include <QDebug>
#include <QColorDialog>


Scene::Scene(QObject *parent)
    : QGraphicsScene{parent},drawing(false)
{
    pathList.clear();
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){


//        drawing = true;
//        QPen pen(paintColor, 3);

//        QPainterPath path;
//        QGraphicsPathItem* item = addPath(path);

//        // path.moveTo(event->scenePos());
//        item->setPen(pen);
//        item->setBrush(Qt::transparent);

//        path = item->path();
//        path.moveTo(event->scenePos());
//        path.lineTo(event->scenePos());
//        item->setPath(path);

//        pathList.append(item);

        previousPoint = event->scenePos();

    }
}

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if((event->buttons() & Qt::LeftButton) && drawing){

//        QGraphicsPathItem* item = pathList.last();
//        if(item){
//            QPainterPath path = item->path();
//            path.lineTo(event->scenePos());
//            item->setPath(path);
//        }

        addLine(previousPoint.x(),previousPoint.y(),event->scenePos().x(),event->scenePos().y(),
                QPen(Qt::red,10,Qt::SolidLine,Qt::RoundCap));

        previousPoint = event->scenePos();
    }
}

void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if((event->button() == Qt::LeftButton) && drawing){
        drawing = false;
    }
}



void Scene::setPaintColor(){
    paintColor = QColorDialog::getColor(paintColor);
}

