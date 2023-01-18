#include "scene.h"

//#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
//#include <QGraphicsLineItem>
#include <QGraphicsPathItem>
#include <QPainterPath>
#include <QDebug>
#include <QColorDialog>


#define ItemWidth   16


Scene::Scene(QObject *parent)
    : QGraphicsScene{parent},drawing(false)
{
    QPainterPath path;
    pathItem = addPath(path);

    update();

    // pathList.clear();
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){

        if(m_currentShape == Brush){
            drawing = true;
            QPen pen(paintColor, 3);

            QPainterPath path;
            QGraphicsPathItem* item = addPath(path);
            item->setPen(pen);
            item->setBrush(Qt::transparent);

            path = item->path();
            path.moveTo(event->scenePos());
            path.lineTo(event->scenePos());
            item->setPath(path);

            pathList.append(item);

        }else if(m_currentShape !=Cursor){

            m_startPos = event->scenePos();
        }
    }
    QGraphicsScene::mousePressEvent(event);
}

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

    if(m_currentShape == Brush){
        if(drawing) {

            QGraphicsPathItem* item = pathList.last();
            if(item) {
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
        item->setPen(QPen(QColor(Qt::red), 1));
        addItem(item);
        m_currentItem = item;

    } else if(m_currentShape != Cursor){

        if(m_currentItem != nullptr)
            delete m_currentItem;
        QRectF rect(m_startPos, event->scenePos());
        QGraphicsRectItem *item = new QGraphicsRectItem(rect);
        item->setPen(QPen(QColor(Qt::red), 1));
        addItem(item);
        m_currentItem = item;


    }
    QGraphicsScene::mouseMoveEvent(event);
}

void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{

    Q_UNUSED(event);

    if(m_currentItem != nullptr)
        delete m_currentItem;

    switch (m_currentShape) {
    case Cursor:
        break;
    case Line:
        addLineItem(m_startPos, event->scenePos());
        break;
    case Rect:
        addRectItem(m_startPos, event->scenePos());
        break;
    case Ellipse:
        addEllipseItem(m_startPos, event->scenePos());
        break;
    case Brush:
        if(drawing) {
            QGraphicsPathItem* item = pathList.last();
            if(item) {
                QPainterPath path = item->path();
                path.lineTo(event->scenePos());
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
//        addStarItem(m_startPos, event->scenePos());
//        break;
    }
    m_currentItem = nullptr;
    QGraphicsScene::mouseReleaseEvent(event);
}



void Scene::setPaintColor(){
    paintColor = QColorDialog::getColor(paintColor);
}

Scene::Shape Scene::getCurrentShape() const
{
    return m_currentShape;
}

void Scene::setCurrentShape(const Shape &value)
{
     m_currentShape = value;
}


void Scene::updateScene()
{
    qDebug("updateScene");
    QPen pen(QColor(Qt::red), 1);
    pathItem->setPen(pen);
//    m_pathItem->setBrush(Qt::transparent);
    QPainterPath path = pathItem->path();

    int cnt = 0;
    path.clear();
    foreach(auto item, m_itemList) {
//        qDebug() << item->scenePos();
        QPointF p = item->scenePos();
        if(cnt++ == 0) {
            path.moveTo(p.rx()+ItemWidth/2, p.ry()+ItemWidth/2);
        } else {
            path.lineTo(p.rx()+ItemWidth/2, p.ry()+ItemWidth/2);
        }

    }
    path.closeSubpath();
    pathItem->setPath(path);
}
void Scene::addLineItem(QPointF stPos, QPointF edPos)
{
    QLineF line(stPos, edPos);
    QGraphicsLineItem *lineItem = new QGraphicsLineItem(line);
    lineItem->setPen(QPen(m_currentColor, 3));

    QGraphicsRectItem *boundRectItem = new QGraphicsRectItem();
    boundRectItem->setRect(lineItem->boundingRect().adjusted(-2, -2, 2, 2));
    boundRectItem->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);

    boundRectItem->setPen(QPen(boundRectItem->isSelected()?Qt::red:Qt::transparent, 1));
    lineItem->setParentItem(boundRectItem);

    addItem(boundRectItem);
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
    ellipseItem->setBrush(m_currentColor);
    ellipseItem->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
    ellipseItem->setPen(QPen(ellipseItem->isSelected()?Qt::red:m_currentColor, ellipseItem->isSelected()?3:1));
    addItem(ellipseItem);
}
