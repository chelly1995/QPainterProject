#include "scenewidget.h"
#include "movableitem.h"
#include "resizablerectitem.h"
#include "resizablepixmapitem.h"
#include "resizablestaritem.h"

#include <QPainterPath>
#include <QGraphicsPathItem>
#include <QGraphicsSceneMouseEvent>

#define ItemWidth   16

SceneWidget::SceneWidget(QObject *parent)
    : QGraphicsScene(parent), m_isDrawable(false), m_currentColor(Qt::black), m_isCapture(false)
{
    QPainterPath path;
    m_pathItem = addPath(path);
    m_pathItem->setZValue(10);

    QBrush brush(QColor(Qt::black), Qt::SolidPattern);
    MovableItem* item1 = new MovableItem();
    item1->setZValue(11);
    item1->setPos(-100, 100);
    MovableItem* item2 = new MovableItem();
    item2->setZValue(11);
    item2->setPos(-100, -100);
    MovableItem* item3 = new MovableItem();
    item3->setZValue(11);
    item3->setPos(100, -100);
    MovableItem* item4 = new MovableItem();
    item4->setZValue(11);
    item4->setPos(100, 100);

    addItem(item1);
    addItem(item2);
    addItem(item3);
    addItem(item4);

    m_itemList.append(item1);
    m_itemList.append(item2);
    m_itemList.append(item3);
    m_itemList.append(item4);

    m_currentItem = nullptr;

    update();
}

void SceneWidget::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{    
    QPen pen(QColor(Qt::red), 3);

    if(items(mouseEvent->scenePos()).isEmpty()) {
        if(m_currentShape == Path) {
            m_isDrawable = true;

            QPainterPath path;
            QGraphicsPathItem* item = addPath(path);
            item->setPen(pen);
            item->setBrush(Qt::transparent);

            path = item->path();
            path.moveTo(mouseEvent->scenePos());
            item->setPath(path);

            m_pathList.append(item);
        } else if(m_currentShape != Cursor) {
            m_startPos = mouseEvent->scenePos();
        }
    }
    QGraphicsScene::mousePressEvent(mouseEvent);
}

void SceneWidget::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{    
    if(m_currentItem != nullptr)
        delete m_currentItem;

    if(m_currentShape == Path) {
        if(m_isDrawable) {
            QGraphicsPathItem* item = m_pathList.last();
            if(item) {
                QPainterPath path = item->path();
                path.lineTo(mouseEvent->scenePos());
                item->setPath(path);
            }
        }
    } else if(m_currentShape == Line) {
        QLineF line(m_startPos, mouseEvent->scenePos());
        QGraphicsLineItem *item = new QGraphicsLineItem(line);
        item->setPen(QPen(QColor(Qt::red), 1));
        addItem(item);
        m_currentItem = item;
    } else if(m_currentShape != Cursor) {
        QRectF rect(m_startPos, mouseEvent->scenePos());
        QGraphicsRectItem *item = new QGraphicsRectItem(rect);
        item->setPen(QPen(QColor(Qt::red), 1));
        addItem(item);
        m_currentItem = item;
    }
    QGraphicsScene::mouseMoveEvent(mouseEvent);
}

void SceneWidget::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    Q_UNUSED(mouseEvent);

    if(m_currentItem != nullptr)
        delete m_currentItem;

    switch (m_currentShape) {
    case Cursor:
        break;
    case Line:
        addLineItem(m_startPos, mouseEvent->scenePos());
        break;
    case Rect:
#if 0
        addRectItem(m_startPos, mouseEvent->scenePos());
#else
    {
        ResizableRectItem * rectItem = new ResizableRectItem();
        rectItem->setRect(QRectF(m_startPos, mouseEvent->scenePos()).normalized());
        rectItem->setBrush(QBrush(Qt::green));
        rectItem->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);
        addItem(rectItem);
    }
#endif
        break;
    case Ellipse: {
        QRectF rect = QRectF(m_startPos, mouseEvent->scenePos()).normalized();
        addEllipseItem(rect.topLeft(), rect.bottomRight());
    }
        break;
    case Path:
        if(m_isDrawable) {
            QGraphicsPathItem* item = m_pathList.last();
            if(item) {
                QPainterPath path = item->path();
                path.lineTo(mouseEvent->scenePos());
                item->setPath(path);
                item->setFlag(QGraphicsItem::ItemIsMovable, true);
                item->setFlag(QGraphicsItem::ItemIsSelectable, true);
            }
            m_isDrawable = false;
        }
        break;
    case Image:{
        QRectF rect = QRectF(m_startPos, mouseEvent->scenePos()).normalized();
        addImageItem(rect.topLeft(), rect.bottomRight());
    }
        break;
    case Star:{
        QRectF rect = QRectF(m_startPos, mouseEvent->scenePos()).normalized();
        addStarItem(rect.topLeft(), rect.bottomRight());
    }
        break;
    }

    m_currentItem = nullptr;

    QGraphicsScene::mouseReleaseEvent(mouseEvent);
}

void SceneWidget::updateScene()
{
    qDebug("updateScene");
    QPen pen(QColor(Qt::red), 1);
    m_pathItem->setPen(pen);
//    m_pathItem->setBrush(Qt::transparent);
    QPainterPath path = m_pathItem->path();

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

        (m_isCapture)?item->hide():item->show();
    }
    path.closeSubpath();

    if(!m_isCapture)
        m_pathItem->setPath(path);

    setSelectionArea(path);
}

void SceneWidget::setCapture(bool flag)
{
    m_isCapture = flag;
    updateScene();
}

void SceneWidget::deleteCurrentItem()
{
    foreach(auto item, selectedItems())
        removeItem(item);
    update();
}

void SceneWidget::rotateLeftCurrentItem()
{
    foreach(auto item, selectedItems())
        item->setRotation(item->rotation() - 1);
    update();
}

void SceneWidget::rotateRightCurrentItem()
{
    foreach(auto item, selectedItems())
        item->setRotation(item->rotation() + 1);
    update();
}

SceneWidget::Shape SceneWidget::getCurrentShape() const
{
    return m_currentShape;
}

void SceneWidget::setCurrentShape(const Shape &value)
{
    m_currentShape = value;
}

QColor SceneWidget::getCurrentColor() const
{
    return m_currentColor;
}

void SceneWidget::setCurrentColor(const QColor& color)
{
    m_currentColor = color;
    foreach(auto item, selectedItems()) {
        foreach (QGraphicsItem *childItem, item->childItems()) {
            //Is rect ?
            QGraphicsRectItem* rectItem = qgraphicsitem_cast<QGraphicsRectItem*>(childItem);
            if(rectItem) {
                rectItem->setPen(QPen(rectItem->isSelected()?Qt::red:m_currentColor, rectItem->isSelected()?3:1));
            }

            //Is path ?
            QGraphicsPathItem* pathItem = qgraphicsitem_cast<QGraphicsPathItem*>(childItem);
            if(pathItem) {
                pathItem->setPen(QPen(m_currentColor, 3));
            }

            //Is ellipse?
            QGraphicsEllipseItem* ellipseItem = qgraphicsitem_cast<QGraphicsEllipseItem*>(childItem);
            if(ellipseItem){
                ellipseItem->setPen(QPen(ellipseItem->isSelected()?Qt::red:m_currentColor, ellipseItem->isSelected()?3:1));
                ellipseItem->setBrush(QBrush(m_currentColor));
            }
        }
    }

    update();
}

void SceneWidget::addLineItem(QPointF stPos, QPointF edPos)
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

void SceneWidget::addRectItem(QPointF stPos, QPointF edPos)
{
    QRectF rect(stPos, edPos);
    QGraphicsRectItem *rectItem = new QGraphicsRectItem(rect);
    rectItem->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
    rectItem->setPen(QPen(rectItem->isSelected()?Qt::red:m_currentColor, rectItem->isSelected()?3:1));
    addItem(rectItem);
}

void SceneWidget::addEllipseItem(QPointF stPos, QPointF edPos)
{
    QRectF rect(stPos, edPos);
    QGraphicsEllipseItem *ellipseItem = new QGraphicsEllipseItem(rect);
    ellipseItem->setBrush(m_currentColor);
    ellipseItem->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
    ellipseItem->setPen(QPen(ellipseItem->isSelected()?Qt::red:m_currentColor, ellipseItem->isSelected()?3:1));
    addItem(ellipseItem);
}

#include <QGraphicsView>
void SceneWidget::addImageItem(QPointF stPos, QPointF edPos)
{
    QRectF rect(stPos, edPos);
    QPixmap pixmap(":/images/qt.png");
    QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem(pixmap.scaled(rect.size().toSize(), Qt::KeepAspectRatio));

    QGraphicsRectItem * boundRectItem = new QGraphicsRectItem();
    boundRectItem->setRect(pixmapItem->boundingRect().adjusted(-5,-5,5,5));
    boundRectItem->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
    boundRectItem->setPen(QPen(boundRectItem->isSelected()?Qt::red:Qt::transparent, 1));

    pixmapItem->setParentItem(boundRectItem);
    boundRectItem->setPos(stPos);
    addItem(boundRectItem);
}

void SceneWidget::addStarItem(QPointF stPos, QPointF edPos)
{
    QPolygon poly;
    poly << QPoint(0, 85) << QPoint(75, 75)
         << QPoint(100, 10) << QPoint(125, 75)
         << QPoint(200, 85) << QPoint(150, 125)
         << QPoint(160, 190) << QPoint(100, 150)
         << QPoint(40, 190) << QPoint(50, 125)
         << QPoint(0, 85);

    QPainterPath path;
    path.addPolygon(poly);

    QRectF rect(stPos, edPos);
    QGraphicsPathItem *starPath = new QGraphicsPathItem(path);
    starPath->setPen(QPen(starPath->isSelected()?Qt::red:m_currentColor, starPath->isSelected()?3:1));
    starPath->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
    starPath->setBrush(Qt::green);
    starPath->setScale(rect.size().width()/starPath->boundingRect().size().width());
    starPath->setPos(stPos);
    addItem(starPath);
}
