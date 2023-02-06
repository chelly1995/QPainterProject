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
    : QGraphicsScene{parent}, drawing(false), m_currentColor(Qt::red), paintSize(3.0f), rotateAngle(0.0)
{
    m_currentItem = nullptr;
    m_currentShape = Cursor;
    m_isClicked = false;
    m_triClicked = 1;
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


    }else if(m_currentShape == Line){
        if(!m_isClicked){
            m_prevPos = event->scenePos();
            m_isClicked = true;
        }
        else{
            m_latePos = event->scenePos();
            addLineItem(m_prevPos, m_latePos);
            m_isClicked = false;
        }

    }else if(m_currentShape == Rect){
        if(!m_isClicked){
            m_prevPos = event->scenePos();
            m_isClicked = true;
        }
        else{
            m_latePos = event->scenePos();
            addRectItem(m_prevPos, m_latePos);
            m_isClicked = false;
        }
    }else if(m_currentShape == Ellipse){
        //        if(!m_isClicked){
        //            m_prevPos =event->scenePos();
        //            m_isClicked = true;

        //        }else{
        //            m_latePos = event->scenePos();
        //            addEllipseItem(m_prevPos, m_latePos);
        //            m_isClicked = false;
        //        }

        m_startPos = event->scenePos();

    }else if(m_currentShape == Arrow){
        if(!m_isClicked){
            m_prevPos =event->scenePos();
            m_isClicked = true;

        }else{
            m_latePos = event->scenePos();
            addArrowItem(m_prevPos, m_latePos);
            m_isClicked = false;
        }
    }else if(m_currentShape == Triangle){
        if(m_triClicked == 1){
            qDebug()<<m_triClicked;
            m_prevPos =event->scenePos();
            m_triClicked++;
            // qDebug()<<m_triClicked;

        }else if(m_triClicked == 2){
            qDebug()<<m_triClicked;
            m_midPos = event->scenePos();
            m_triClicked++;
        }else if(m_triClicked == 3){
            qDebug()<<m_triClicked;
            m_latePos = event->scenePos();
            addTriangleItem(m_prevPos, m_midPos, m_latePos);
            m_triClicked = 1;
        }
        else if(m_currentShape == Image){
            if(!m_isClicked){
                m_prevPos = event->scenePos();
                m_isClicked = true;
            }
            else{
                m_latePos = event->scenePos();
                addImageItem(m_prevPos, m_latePos);
                m_isClicked = false;
            }
        }

    }else if(m_currentShape == Text){
        m_prevPos = event->scenePos();
        addTextItem(m_prevPos);

    }
    else if(m_currentShape != Cursor){

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
    }

    else if(m_currentShape == Cursor){

        /* 선택된 아이템 이동 */

        foreach(auto item, selectedItems())
            item->setFlags(QGraphicsItem::ItemIsMovable| QGraphicsItem::ItemIsSelectable);
        update();


    }


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
        break;
    case Rect:
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
        // addImageItem(m_startPos, event->scenePos());
        break;

    case Arrow:
        break;

    case Triangle:
        break;

    case Text:
        break;
    }
    m_currentItem = nullptr;
    QGraphicsScene::mouseReleaseEvent(event);
}

void Scene::resizeEvent(QGraphicsSceneResizeEvent *event)
{
    //  QSize itemSize1 = viewport()->size();

    qDebug()<<"1";

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

    addItem(ellipseItem);

    m_allitems.append(ellipseItem);


}


void Scene::addTriangleItem(QPointF stPos,QPointF mdPos, QPointF edPos)
{
    QVector<QPoint> v;
    v<<QPoint(stPos.x(),stPos.y())<<QPoint(mdPos.x(),mdPos.y())<<QPoint(edPos.x(),edPos.y());

    QGraphicsPolygonItem *polygonItem = new QGraphicsPolygonItem(QPolygonF(v));
    polygonItem->setFlags(QGraphicsItem::ItemIsSelectable);
    polygonItem->setPen(QPen(polygonItem->isSelected()?Qt::red:m_currentColor, polygonItem->isSelected()?1:paintSize));


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


void Scene::addImageItem(QPointF stPos, QPointF edPos)
{
    QRectF rect(stPos, edPos);
    QPixmap pixmap("Implant4_1.png");
    QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem(pixmap.scaled(rect.size().toSize(), Qt::KeepAspectRatio));

    pixmapItem->setFlags(QGraphicsItem::ItemIsSelectable);
    pixmapItem->setPos(stPos);

    addItem(pixmapItem);

    m_allitems.append(pixmapItem);
    qDebug()<< m_allitems.size();
}


void Scene::addTextItem(QPointF stPos)
{
    QGraphicsTextItem *textItem = new QGraphicsTextItem(text);

    textItem->setFlags(QGraphicsItem::ItemIsSelectable);
   // textItem->setFont("Helvetica");
   //textItem->setRotation(rotateAngle);
   textItem->setScale(paintSize);
   textItem->setDefaultTextColor(m_currentColor);

    textItem->setPos(stPos);


    addItem(textItem);

    m_allitems.append(textItem);


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

    /* 모든 도형 지우기 */

    foreach(auto items, m_allitems)
        removeItem(items);

    /* 브러쉬 지우기 */

    foreach(auto items, m_pathList)
        removeItem(items);

}



void Scene::deleteItems()
{
    if(selectedItems().count()>0){

        foreach(auto item, selectedItems())
            removeItem(item);
        update();

    }
}


void Scene::rotate(){

    foreach(auto item, selectedItems()){
        item->setTransformOriginPoint(QPoint((m_latePos.x()+m_prevPos.x())/2,(m_latePos.y()+m_prevPos.y())/2));
        item->setRotation(rotateAngle);
    }
    update();

}

void Scene::size(){
//    foreach(auto item, selectedItems())
//             item->setScale(paintSize);

//    update();

}


void Scene::setPaintSize(qreal size){

    paintSize=size;
}


void Scene::setRotation(qreal angle){

    rotateAngle=angle;
}


void Scene::setText(QString string){

    text = string;

}
