#include "scene.h"

#include <QGraphicsView>
//#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsPathItem>
#include <QPainterPath>


Scene::Scene(QObject *parent)
    : QGraphicsScene{parent}, drawing(false), m_currentColor(Qt::red),paintSize(3.0f)
{

    m_currentItem = nullptr;

}


void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QPen pen(m_currentColor, paintSize);

    if(m_currentShape == Path){

        drawing = true;

        QPainterPath path;
        QGraphicsPathItem* item = addPath(path);
        item->setPen(pen);
        item->setBrush(Qt::transparent);

        path = item->path();
        path.moveTo(event->scenePos());
        item->setPath(path);

        m_pathList.append(item);

    }else{

        m_startPos = event->scenePos();

    }

    QGraphicsScene::mousePressEvent(event);

}


void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

    if(m_currentShape == Path){
        if(drawing){
            QGraphicsPathItem* item = m_pathList.last();

            if(item){

                QPainterPath path = item->path();
                path.lineTo(event->scenePos());
                item->setPath(path);
                item->setFlag(QGraphicsItem::ItemIsSelectable);

            }

        }



    }

    if(m_currentShape == Cursor){

        if(m_currentItem != nullptr)
            delete m_currentItem;

        foreach(auto item, m_pathList) {
            m_startPos = event->scenePos();
            if(item->isSelected()){
                                item->setFlags(QGraphicsItem::ItemIsSelectable);
                                item->setFlags(QGraphicsItem::ItemIsMovable);
                //    item->setPos(maptoScene(event->scenePos()));
                item->setCursor(Qt::ClosedHandCursor);
            }
        }

    }
}

void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{

    Q_UNUSED(event);

    if(m_currentItem != nullptr)
        delete m_currentItem;

    switch(m_currentShape){
    case Cursor:
        break;
    case Line:
        //  addLineItem(m_startPos, event->scenePos());
        break;

    case Rect:
        //   addRectItem(m_startPos, event->scenePos());
        break;

    case Ellipse:
        //  addEllipseItem(m_startPos, event->scenePos());
        break;

    case Path:
        if(drawing){
            QGraphicsPathItem* item = m_pathList.last();

            if(item){
                QPainterPath path = item->path();
                path.lineTo(event->scenePos());
                item->setPath(path);
                // item->setFlag(QGraphicsItem::ItemIsMovable,true);
                //  item->setFlag(QGraphicsItem::ItemIsSelectable,true);

            }
            drawing = false;
        }
        break;

    case Image:
        //addImageItem(m_startPos, event->scenePos());
        break;
    }
    m_currentItem = nullptr;
    QGraphicsScene::mouseReleaseEvent(event);
}

Scene::Shape Scene::getCurrentShape() const
{
    return m_currentShape;

}

void Scene::setCurrentShape(const Shape &value)
{
    m_currentShape = value;

}

QColor Scene::getCurrentColor() const
{
    return m_currentColor;
}

void Scene::setCurrentColor(const QColor& color)
{

    m_currentColor = color;
}

void Scene::setPaintSize(qreal size){

    paintSize=size;
}

