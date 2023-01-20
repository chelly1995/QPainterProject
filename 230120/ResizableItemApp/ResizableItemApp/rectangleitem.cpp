#include "rectangleitem.h"

#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

RectangleItem::RectangleItem(QGraphicsItem *parent)
    : QGraphicsItem(parent), m_isResizing(false), m_mousePressed(false)
{
    m_boundingRect = QRectF(0, 0, 200, 100);
    m_resizeHandles.fill(QRect(0, 0, 0, 0), 8);

    setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemSendsGeometryChanges);
    setAcceptHoverEvents(true);

    setPos(100, 150);
}

RectangleItem::~RectangleItem()
{

}

QRectF RectangleItem::boundingRect() const
{
    return m_boundingRect;
}

void RectangleItem::paint(QPainter *painter,
                          const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->fillRect(boundingRect(), QBrush(QColor(128, 128, 255, 128)));

    // resize handles
    double scale = this->scene()->views().at(0)->transform().m11();
    float rectSize = 6 / scale;
    QRectF handles(0, 0, rectSize, rectSize);
    QRectF m_CornerRect = m_boundingRect.adjusted(2, 2, -2, -2);

    handles.moveCenter(m_CornerRect.topLeft());             // TopLeft
    m_resizeHandles.replace(0, handles);

    handles.moveCenter(m_CornerRect.topRight());            // TopRight
    m_resizeHandles.replace(2, handles);

    handles.moveCenter(m_CornerRect.bottomRight());         // BottomRight
    m_resizeHandles.replace(4, handles);

    handles.moveCenter(m_CornerRect.bottomLeft());          // BottomLeft
    m_resizeHandles.replace(6, handles);

    QPointF center(m_CornerRect.center().x(), m_CornerRect.top());      // Top
    handles.moveCenter(center);
    m_resizeHandles.replace(1, handles);

    center = QPointF(m_CornerRect.right(), m_CornerRect.center().y());  // Right
    handles.moveCenter(center);
    m_resizeHandles.replace(3, handles);

    center = QPointF(m_CornerRect.center().x(), m_CornerRect.bottom()); // Bottom
    handles.moveCenter(center);
    m_resizeHandles.replace(5, handles);

    center = QPointF(m_CornerRect.left(), m_CornerRect.center().y());   // Left
    handles.moveCenter(center);
    m_resizeHandles.replace(7, handles);

    // arrow line
    float size = m_CornerRect.width();
    m_rotateLine.setP1(m_resizeHandles.at(7).center());
    m_rotateLine.setP2(QPointF(m_resizeHandles.at(7).center().x() + (size / 4),
                               m_resizeHandles.at(7).center().y()));

    // angle handle
    qreal arrowSize = 6.0 / scale;
    QPointF point = m_rotateLine.p2();
    double angle = qAcos(m_rotateLine.dx() / m_rotateLine.length());
    if (m_rotateLine.dy() >= 0)
        angle = (2.0 * M_PI) - angle;

    QPointF destArrowP1 = point + QPointF(sin(angle-M_PI/3.0) * arrowSize,
                                          cos(angle-M_PI/3.0) * arrowSize);
    QPointF destArrowP2 = point + QPointF(sin(angle-M_PI+M_PI/3.0) * arrowSize ,
                                          cos(angle-M_PI+M_PI/3.0) * arrowSize);

    m_angleHandle = QPolygonF() << m_rotateLine.p2() << destArrowP1 << destArrowP2;

    if(isUnderMouse()) {
        QPen pens(Qt::black, 2, Qt::DotLine, Qt::RoundCap, Qt::RoundJoin);
        pens.setCosmetic(true);

        // draw rect
        painter->setPen(pens);
        painter->drawRect(m_CornerRect);

        // draw arrow handle
        QPen arrowPen;
        arrowPen.setWidth(2);
        arrowPen.setCosmetic(true);
        arrowPen.setColor(Qt::yellow);
        painter->setBrush(Qt::black);
        painter->setPen(arrowPen);
        painter->drawLine(m_rotateLine);
        painter->drawPolygon(m_angleHandle);

        // draw resize handles
        pens.setColor(QColor(255, 255, 255));
        painter->setBrush(Qt::black);
        painter->setPen(pens);
        foreach(auto rect, m_resizeHandles)
            painter->drawEllipse(rect);
    }
}

void RectangleItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    m_mousePressed = true;
    m_isResizing = mousePosOnHandles(event->scenePos());
    if (m_isResizing) {
        m_actualRect = m_boundingRect;
    }
    setCursor(Qt::ClosedHandCursor);
    QGraphicsItem::mousePressEvent(event);
}

void RectangleItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (m_isResizing) {
        QPointF ptMouseMoveInItemsCoord = mapFromScene(event->scenePos());
        switch (m_resizeCorner) {
        case TOP_LEFT:
            if (this->scene()->sceneRect().contains(event->scenePos())) {
                m_boundingRect.setTopLeft(ptMouseMoveInItemsCoord);
                m_boundingRect = m_boundingRect.normalized();
            }
            break;
        case TOP:
            if (this->scene()->sceneRect().contains(event->scenePos())) {
                m_boundingRect.setTop(ptMouseMoveInItemsCoord.y());
                m_boundingRect = m_boundingRect.normalized();
            }
            break;
        case TOP_RIGHT:
            if (this->scene()->sceneRect().contains(event->scenePos())) {
                m_boundingRect.setTopRight(ptMouseMoveInItemsCoord);
                m_boundingRect = m_boundingRect.normalized();
            }
            break;
        case RIGHT:
            if (this->scene()->sceneRect().contains(event->scenePos())) {
                m_boundingRect.setRight(ptMouseMoveInItemsCoord.x());
                m_boundingRect = m_boundingRect.normalized();
            }
            break;
        case BOTTOM_RIGHT:
            if (this->scene()->sceneRect().contains(event->scenePos()))
            {
                m_boundingRect.setBottomRight(ptMouseMoveInItemsCoord);
                m_boundingRect = m_boundingRect.normalized();
            }
            break;
        case BOTTOM:
            if (this->scene()->sceneRect().contains(event->scenePos())) {
                m_boundingRect.setBottom(ptMouseMoveInItemsCoord.y());
                m_boundingRect = m_boundingRect.normalized();
            }
            break;
        case BOTTOM_LEFT:
            if (this->scene()->sceneRect().contains(event->scenePos())) {
                m_boundingRect.setBottomLeft(ptMouseMoveInItemsCoord);
                m_boundingRect = m_boundingRect.normalized();
            }
            break;
        case LEFT:
            if (this->scene()->sceneRect().contains(event->scenePos())) {
                m_boundingRect.setLeft(ptMouseMoveInItemsCoord.x());
                m_boundingRect = m_boundingRect.normalized();
            }
            break;
        case ROTATE:
            if (this->scene()->sceneRect().contains(event->scenePos())) {
                QLineF line(m_boundingRect.center(), ptMouseMoveInItemsCoord);

                double rotations = line.angle();
                if (line.dy() <= 0) {
                    rotations = 180.0 - rotations;
                } else {
                    rotations = rotations - 180.0;
                }
                m_angle = rotations;
                m_boundingRect = m_boundingRect.normalized();
                setTransformOriginPoint(m_boundingRect.center());
                setRotation(rotation() + m_angle);
            }
            break;
        }
        prepareGeometryChange();
        update();
    } else {
        prepareGeometryChange();
        update();
        QGraphicsItem::mouseMoveEvent(event);
    }
}

void RectangleItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if(m_mousePressed)
        setCursor(Qt::OpenHandCursor);
    m_mousePressed = false;
    m_isResizing = false;
    if (m_actualRect != m_boundingRect) {
        auto oldScenePos = scenePos();
        setTransformOriginPoint(m_boundingRect.center());
        auto newScenePos = scenePos();
        auto oldPos = pos();
        setPos(oldPos.x() + (oldScenePos.x() - newScenePos.x()),
               oldPos.y() + (oldScenePos.y() - newScenePos.y()));
    }
    prepareGeometryChange();
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}

void RectangleItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    m_isResizing = mousePosOnHandles(event->scenePos());
    setCursor(Qt::OpenHandCursor);
    if (m_isResizing) {
        switch (m_resizeCorner) {
        case TOP: case BOTTOM:
            setCursor(Qt::SizeVerCursor);
            break;
        case LEFT: case RIGHT:
            setCursor(Qt::SizeHorCursor);
            break;
        case TOP_LEFT: case BOTTOM_RIGHT:
            setCursor(Qt::SizeFDiagCursor);
            break;
        case TOP_RIGHT: case BOTTOM_LEFT:
            setCursor(Qt::SizeBDiagCursor);
            break;
        case ROTATE:
            setCursor(Qt::UpArrowCursor);
            break;
        default:
            setCursor(Qt::OpenHandCursor);
            break;
        }
    }
    update();
}

void RectangleItem::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
{
    m_isResizing = mousePosOnHandles(event->scenePos());
    setCursor(Qt::OpenHandCursor);
    if (m_isResizing) {
        switch (m_resizeCorner) {
        case TOP: case BOTTOM:
            setCursor(Qt::SizeVerCursor);
            break;
        case LEFT: case RIGHT:
            setCursor(Qt::SizeHorCursor);
            break;
        case TOP_LEFT: case BOTTOM_RIGHT:
            setCursor(Qt::SizeFDiagCursor);
            break;
        case TOP_RIGHT: case BOTTOM_LEFT:
            setCursor(Qt::SizeBDiagCursor);
            break;
        case ROTATE:
            setCursor(Qt::UpArrowCursor);
            break;
        default:
            setCursor(Qt::OpenHandCursor);
            break;
        }
    }
    update();
}

void RectangleItem::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    Q_UNUSED(event)
    setCursor(Qt::ArrowCursor);
    update();
}

bool RectangleItem::mousePosOnHandles(QPointF pos)
{
    bool resizable = false;
    int var4Index = 8;
    if (mapToScene(m_resizeHandles[(0+var4Index)%8]).containsPoint(pos, Qt::WindingFill)) {
        m_resizeCorner = TOP_LEFT;
        resizable = true;
    } else if (mapToScene(m_resizeHandles[(1+var4Index)%8]).containsPoint(pos, Qt::WindingFill)) {
        m_resizeCorner = TOP;
        resizable = true;
    } else if (mapToScene(m_resizeHandles[(2+var4Index)%8]).containsPoint(pos, Qt::WindingFill)) {
        m_resizeCorner = TOP_RIGHT;
        resizable = true;
    } else if (mapToScene(m_resizeHandles[(3+var4Index)%8]).containsPoint(pos, Qt::WindingFill)) {
        m_resizeCorner = RIGHT;
        resizable = true;
    } else if (mapToScene(m_resizeHandles[(4+var4Index)%8]).containsPoint(pos, Qt::WindingFill)) {
        m_resizeCorner = BOTTOM_RIGHT;
        resizable = true;
    } else if (mapToScene(m_resizeHandles[(5+var4Index)%8]).containsPoint(pos, Qt::WindingFill)) {
        m_resizeCorner = BOTTOM;
        resizable = true;
    } else if (mapToScene(m_resizeHandles[(6+var4Index)%8]).containsPoint(pos, Qt::WindingFill)) {
        m_resizeCorner = BOTTOM_LEFT;
        resizable = true;
    } else if (mapToScene(m_resizeHandles[(7+var4Index)%8]).containsPoint(pos, Qt::WindingFill)) {
        m_resizeCorner = LEFT;
        resizable = true;
    } else if (mapToScene(m_angleHandle).containsPoint(pos, Qt::WindingFill)) {
        m_resizeCorner = ROTATE;
        resizable = true;
    }
    return resizable;
}
