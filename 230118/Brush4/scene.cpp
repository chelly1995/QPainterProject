#include "scene.h"

#include <QPainterPath>
#include <QGraphicsPathItem>
#include <QGraphicsSceneMouseEvent>


Scene::Scene(QObject *parent)
    : QGraphicsScene(parent), drawing(false), m_currentColor(Qt::black)
{


}


void Scene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    QPen pen(QColor(Qt::red),3);

    if(m_currentShape == Path){

        drawing == true;

        QPainterPath path;
        QGraphicsPathItem* item = addPath(path);
        item->setPen(pen);
        item->setBrush(Qt::transparent);

        path = item->path();
        path.moveTo(mouseEvent->scenePos());
        item->setPath(path);

        m_pathList.append(item);
    } else if(m_currentShape != Cursor){
        m_startPos = mouseEvent->scenePos();

    }

     QGraphicsScene::mousePressEvent(mouseEvent);
}

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{

    if(m_currentShape == Path){
        if(drawing){
            QGraphicsPathItem* item = m_pathList.last();
            if(item){
                QPainterPath path = item->path();
                path.lineTo(mouseEvent->scenePos());
                item->setPath(path);

            }
        }


    }
}

void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
     Q_UNUSED(mouseEvent);

    if(m_currentItem != nullptr)
        delete m_currentItem;

    switch (m_currentShape) {
//    case Cursor:
//        break;
//    case Line:
//        addLineItem(m_startPos, mouseEvent->scenePos());
//        break;
//    case Rect:
//        addRectItem(m_startPos, mouseEvent->scenePos());
//        break;
//    case Ellipse:
//        addEllipseItem(m_startPos, mouseEvent->scenePos());
//        break;
    case Path:
        if(drawing) {
            QGraphicsPathItem* item = m_pathList.last();
            if(item) {
                QPainterPath path = item->path();
                path.lineTo(mouseEvent->scenePos());
                item->setPath(path);
                item->setFlag(QGraphicsItem::ItemIsMovable, true);
                item->setFlag(QGraphicsItem::ItemIsSelectable, true);
            }
            drawing = false;
        }
        break;
//    case Image:
//        addImageItem(m_startPos, mouseEvent->scenePos());
//        break;
//    case Star:
//        addStarItem(m_startPos, mouseEvent->scenePos());
//        break;
    }
    m_currentItem = nullptr;
    QGraphicsScene::mouseReleaseEvent(mouseEvent);

}
