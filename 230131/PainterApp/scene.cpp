#include "scene.h"

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsPathItem>
#include <QPainterPath>
#include <QKeyEvent>
#include <QTransform>
#include <QCursor>
#include <QDebug>


Scene::Scene(QObject *parent)
    : QGraphicsScene{parent}, drawing(false), m_currentColor(Qt::red),paintSize(3.0f),rotateAngle(0.0)
{

    m_currentItem = nullptr;
    m_currentShape = Cursor;


}


void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)    // 마우스 클릭 시
{
    QPen pen(m_currentColor, paintSize);
    //    if(items(event->scenePos()).isEmpty()){
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

        // item->setFlag(QGraphicsItem::ItemIsSelectable,true);

        m_pathList.append(item);
    }else if(m_currentShape != Cursor){

        m_startPos = event->scenePos();

    }

    QGraphicsScene::mousePressEvent(event);

}

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(m_currentShape == Path){
        if(drawing){
            QGraphicsPathItem* item = m_pathList.last();
            item->setFlag(QGraphicsItem::ItemIsSelectable,true);
            if(item){

                QPainterPath path = item->path();
                path.lineTo(event->scenePos());
                item->setPath(path);

            }
        }
    } else if(m_currentShape == Line){
        if(m_currentItem != nullptr)
            delete m_currentItem;

        /* 드래그 시 Line을 graphicsview에 보여줌 */

        QLineF line(m_startPos, event->scenePos());
        QGraphicsLineItem *item = new QGraphicsLineItem(line);
        item->setPen(QPen(QColor(Qt::red),1));
        item->setFlag(QGraphicsItem::ItemIsSelectable);
        addItem(item);
        m_currentItem = item;

    }else if(m_currentShape == Cursor){

        /* 선택된 아이템 이동 */

        foreach(auto item, selectedItems())
            item->setFlags(QGraphicsItem::ItemIsMovable| QGraphicsItem::ItemIsSelectable);
        update();


    }

    else if(m_currentShape != Cursor){

        if(m_currentItem != nullptr)
            delete m_currentItem;

        /* 드래그 시 사각형을 graphicsview에 보여줌 */

        QRectF rect(m_startPos, event->scenePos());
        //   qDebug()<<"("<<m_startPos<<","<<event->scenePos()<<")";
        QGraphicsRectItem *item = new QGraphicsRectItem(rect);
        item->setPen(QPen(QColor(Qt::red),1));
        item->rotation();
        //item->setCursor(QCursor(Qt::ArrowCursor));
        addItem(item);
        m_currentItem = item;

    }

    // m_startPos = event->scenePos();
    QGraphicsScene::mouseMoveEvent(event);
}


void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);

    // 드래그 시 영역을 표시하는 부분
    if(m_currentItem != nullptr)
        delete m_currentItem;

    switch(m_currentShape){
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

    case Path:
        if(drawing){
            QGraphicsPathItem* item = m_pathList.last();

            if(item){
                QPainterPath path = item->path();
                path.lineTo(event->scenePos());
                item->setPath(path);

            }
            drawing = false;
        }
        break;

    case Image:
        addImageItem(m_startPos, event->scenePos());
        break;

    case Arrow:
        addArrowItem(m_startPos, event->scenePos());
        break;

    case Triangle:
        addTriangleItem(m_startPos, event->scenePos());
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
    lineItem->setPen(QPen(m_currentColor, paintSize));

    lineItem->setFlags(QGraphicsItem::ItemIsSelectable);


    /* 선 회전 */
    QTransform transform = lineItem->transform();
    transform.rotate(rotateAngle, Qt::ZAxis);
    lineItem->setTransform(transform);

    addItem(lineItem);

    m_allitems.append(lineItem);
}

void Scene::addRectItem(QPointF stPos, QPointF edPos)
{
    QRectF rect(stPos, edPos);
    QGraphicsRectItem *rectItem = new QGraphicsRectItem(rect);
    rectItem->setFlags(QGraphicsItem::ItemIsSelectable);
    // rectItem->setBrush(m_currentColor);
    rectItem->setPen(QPen(rectItem->isSelected()?Qt::red:m_currentColor, rectItem->isSelected()?1:paintSize));

    /* 사각형 회전 */
    QTransform transform = rectItem->transform();
    transform.rotate(rotateAngle, Qt::ZAxis);
    rectItem->setTransform(transform);

    addItem(rectItem);

    m_allitems.append(rectItem);
}

void Scene::addEllipseItem(QPointF stPos, QPointF edPos)
{
    QRectF rect(stPos, edPos);
    QGraphicsEllipseItem *ellipseItem = new QGraphicsEllipseItem(rect);
    // ellipseItem->setBrush(m_currentColor);    // 채우기 색
    ellipseItem->setFlags(QGraphicsItem::ItemIsSelectable);
    ellipseItem->setPen(QPen(ellipseItem->isSelected()?Qt::red:m_currentColor, ellipseItem->isSelected()?1:paintSize));

    /* 원형 회전 */
    QTransform transform = ellipseItem->transform();
    transform.rotate(rotateAngle, Qt::ZAxis);
    ellipseItem->setTransform(transform);


    addItem(ellipseItem);

    m_allitems.append(ellipseItem);


}


void Scene::addTriangleItem(QPointF stPos, QPointF edPos)
{
    QVector<QPoint> v;
    v<<QPoint((edPos.x()+stPos.x())/2,stPos.y())<<QPoint(stPos.x(),edPos.y())<<QPoint(edPos.x(),edPos.y());

    QGraphicsPolygonItem *polygonItem = new QGraphicsPolygonItem(QPolygonF(v));
    polygonItem->setFlags(QGraphicsItem::ItemIsSelectable);
    polygonItem->setPen(QPen(polygonItem->isSelected()?Qt::red:m_currentColor, polygonItem->isSelected()?1:paintSize));

    // polygonItem->setPos(stPos);

    addItem(polygonItem);

    m_allitems.append(polygonItem);

}

void Scene::addArrowItem(QPointF stPos, QPointF edPos)
{
    QVector<QPoint> v;

    QPointF midPos;
    midPos = edPos-stPos;


    v<<QPoint(stPos.x()+(midPos.x()/2),stPos.y())<<QPoint(stPos.x(),stPos.y()+(midPos.y()/3))
    <<QPoint(stPos.x()+(midPos.x()*2/5),stPos.y()+(midPos.y()/3))<<QPoint(stPos.x()+(midPos.x()*2/5),edPos.y())
    <<QPoint(stPos.x()+(midPos.x()*3/5),edPos.y()) <<QPoint(stPos.x()+(midPos.x()*3/5),stPos.y()+(midPos.y()/3))
    <<QPoint(edPos.x(),stPos.y()+(midPos.y()/3));

    QGraphicsPolygonItem *polygonItem = new QGraphicsPolygonItem(QPolygonF(v));
    polygonItem->setFlags(QGraphicsItem::ItemIsSelectable);
    polygonItem->setPen(QPen(polygonItem->isSelected()?Qt::red:m_currentColor, polygonItem->isSelected()?1:paintSize));
    polygonItem->setBrush(m_currentColor);

    // polygonItem->setPos(stPos);

    addItem(polygonItem);

    m_allitems.append(polygonItem);
    qDebug()<< m_allitems.size();
}

void removeItem(QGraphicsItem*item)
{

    delete item;

}

void Scene::addImageItem(QPointF stPos, QPointF edPos)
{
    QRectF rect(stPos, edPos);
    QPixmap pixmap("Implant4_1.png");
    QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem(pixmap.scaled(rect.size().toSize(), Qt::KeepAspectRatio));

    pixmapItem->setFlags(QGraphicsItem::ItemIsSelectable);
    pixmapItem->setPos(stPos);

    /* 사진 회전 */
    QTransform transform = pixmapItem->transform();
    transform.rotate(rotateAngle, Qt::ZAxis);
    pixmapItem->setTransform(transform);

    addItem(pixmapItem);

    m_allitems.append(pixmapItem);
    qDebug()<< m_allitems.size();
}


void Scene::keyPressEvent(QKeyEvent *event) // delete Key 입력 시 아이템 삭제
{
    if(event->key() == Qt::Key_Delete){
        if(selectedItems().count()>0){

            foreach(auto item, selectedItems())
                removeItem(item);
            update();

        }
    }
}


void Scene::clearItems()
{

    //qDebug()<<m_allitems.size();

    /* 모든 도형 지우기 */

    for(int i=0; i<m_allitems.size();i++)
    {
        QGraphicsItem *graphicitem = m_allitems[i];
        removeItem(graphicitem);
        delete graphicitem;
    }

    //qDebug()<<m_pathList.size();

    /* 브러쉬 지우기 */

    for(int i=0; i<m_pathList.size();i++)
    {
        QGraphicsItem *graphicpathitem = m_pathList[i];
        removeItem(graphicpathitem);
        delete graphicpathitem;
    }
}

void Scene::setPaintSize(qreal size){

    paintSize=size;
}


void Scene::setRotation(qreal angle){

    rotateAngle=angle;
}
