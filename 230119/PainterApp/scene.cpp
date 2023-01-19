#include "scene.h"

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsPathItem>
#include <QPainterPath>

Scene::Scene(QObject *parent)
    : QGraphicsScene{parent}, drawing(false), m_currentColor(Qt::red)
{

    m_currentItem = nullptr;

}


void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)    // 마우스 클릭 시
{
    QPen pen(Qt::red, 3);
    //if(items(event->scenePos()).isEmpty()){
    if(m_currentShape == Path){
        drawing = true;

        QPainterPath path;
        QGraphicsPathItem* item = addPath(path);
        item->setPen(pen);
        item->setBrush(Qt::transparent);

        path = item->path();
        path.moveTo(event->scenePos());
        //path.lineTo(event->scenePos());
        item->setPath(path);

        pathList.append(item);
    } else{

        m_startPos = event->scenePos();

    }

    QGraphicsScene::mousePressEvent(event);

}

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(m_currentShape == Path){
        if(drawing){
            QGraphicsPathItem* item = pathList.last();

            if(item){

                QPainterPath path = item->path();
                path.lineTo(event->scenePos());
                item->setPath(path);
            }
        }
    } else if(m_currentShape == Line){
        if(m_currentItem != nullptr)
            delete m_currentItem;

        QLineF line(m_startPos, event->scenePos());
        QGraphicsLineItem *item = new QGraphicsLineItem(line);
        item->setPen(QPen(QColor(Qt::red),1));
        addItem(item);
        m_currentItem = item;

    }else{

        if(m_currentItem != nullptr)
            delete m_currentItem;

        QRectF rect(m_startPos, event->scenePos());
        QGraphicsRectItem *item = new QGraphicsRectItem(rect);
        item->setPen(QPen(QColor(Qt::red),1));
        addItem(item);
        m_currentItem = item;

    }

    //m_startPos = event->scenePos();
    QGraphicsScene::mouseMoveEvent(event);
}


void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);

//        if(m_currentItem != nullptr)
//        delete m_currentItem;

    switch(m_currentShape){
    case Line:
        addLineItem(m_startPos, event->scenePos());
        break;

    case Rect:
        addRectItem(m_startPos, event->scenePos());
        break;

    case Ellipse:
        addEllipseItem(m_startPos, event->scenePos());
        break;

    case Path:
        if(drawing){
            QGraphicsPathItem* item = pathList.last();

            if(item){
                QPainterPath path = item->path();
                path.lineTo(event->scenePos());
                item->setPath(path);
                item->setFlag(QGraphicsItem::ItemIsMovable,true);
                item->setFlag(QGraphicsItem::ItemIsSelectable,true);
            }
            drawing = false;
        }
        break;

    case Image:
        addImageItem(m_startPos, event->scenePos());
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

void Scene::addLineItem(QPointF stPos, QPointF edPos)
{
    QLineF line(stPos,edPos);
    QGraphicsLineItem *lineItem = new QGraphicsLineItem(line);
    lineItem->setPen(QPen(m_currentColor, 3));

    lineItem->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
    //    QGraphicsRectItem *boundRectItem = new QGraphicsRectItem();
    //    boundRectItem->setRect(lineItem->boundingRect().adjusted(-2,-2,2,2));
    //    boundRectItem->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);

    //    boundRectItem->setPen(QPen(boundRectItem->isSelected()?Qt::red:Qt::transparent,1));
    //    lineItem->setParentItem(boundRectItem);

    addItem(lineItem);
    //addItem(boundRectItem);

}

void Scene::addRectItem(QPointF stPos, QPointF edPos)
{
    QRectF rect(stPos, edPos);
    QGraphicsRectItem *rectItem = new QGraphicsRectItem(rect);
    rectItem->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
    rectItem->setPen(QPen(rectItem->isSelected()?Qt::red:m_currentColor, rectItem->isSelected()?3:1));
    addItem(rectItem);
}

void Scene::addEllipseItem(QPointF stPos, QPointF edPos)
{
    QRectF rect(stPos, edPos);
    QGraphicsEllipseItem *ellipseItem = new QGraphicsEllipseItem(rect);
    //ellipseItem->setBrush(m_currentColor);    // 채우기 색
    ellipseItem->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
    ellipseItem->setPen(QPen(ellipseItem->isSelected()?Qt::red:m_currentColor, ellipseItem->isSelected()?3:1));
    addItem(ellipseItem);

}

void Scene::addImageItem(QPointF stPos, QPointF edPos)
{
    QRectF rect(stPos, edPos);
    QPixmap pixmap("Implant3.png");
    QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem(pixmap.scaled(rect.size().toSize(), Qt::KeepAspectRatio));

    QGraphicsRectItem * boundRectItem = new QGraphicsRectItem();
    boundRectItem->setRect(pixmapItem->boundingRect().adjusted(-5,-5,5,5));
    boundRectItem->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
    boundRectItem->setPen(QPen(boundRectItem->isSelected()?Qt::red:Qt::transparent, 1));

    pixmapItem->setParentItem(boundRectItem);
    boundRectItem->setPos(stPos);
    addItem(boundRectItem);
}

