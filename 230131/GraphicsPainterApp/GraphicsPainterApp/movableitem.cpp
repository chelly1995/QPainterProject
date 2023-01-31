#include "movableitem.h"

#include <QGraphicsSceneMouseEvent>
#include <QBrush>

#define ItemWidth 16

MovableItem::MovableItem(QGraphicsItem *parent) : QGraphicsEllipseItem(parent), m_isMovable(false)
{
    QBrush brush(QColor(Qt::black), Qt::SolidPattern);
    setBrush(brush);
    setRect(0, 0, ItemWidth, ItemWidth);
    setTransformOriginPoint(ItemWidth/2, ItemWidth/2);
}

void MovableItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    m_isMovable = true;
    m_offset = event->pos();
    setPos(mapToScene(event->pos().rx(), event->pos().ry()));
    QGraphicsItem::mousePressEvent(event);
    event->accept();
}

void MovableItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(m_isMovable) {
        setPos(mapToScene(event->pos().rx(), event->pos().ry()));
    }
    QGraphicsItem::mouseMoveEvent(event);
    event->ignore();
}

void MovableItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton && m_isMovable) {
        setPos(mapToScene(event->pos().rx(), event->pos().ry()));
        m_isMovable = false;
        update();
    }
    QGraphicsItem::mouseReleaseEvent(event);
    event->ignore();
}

