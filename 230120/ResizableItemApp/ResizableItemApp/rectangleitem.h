#ifndef RECTANGLEITEM_H
#define RECTANGLEITEM_H

#include <QGraphicsItem>

class RectangleItem : public QGraphicsItem
{
public:
    enum ResizeCorners { TOP_LEFT, TOP, TOP_RIGHT, RIGHT,
                         BOTTOM_RIGHT, BOTTOM, BOTTOM_LEFT, LEFT,
                         ROTATE };
    RectangleItem(QGraphicsItem *parent = nullptr);
    ~RectangleItem();

    QRectF boundingRect() const override;
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0) override;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent * event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent * event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent * event) override;

    /* hoverEvent 마우스를 올렸을 때 */

    void hoverEnterEvent(QGraphicsSceneHoverEvent * event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent * event) override;
    void hoverMoveEvent(QGraphicsSceneHoverEvent * event) override;
    bool mousePosOnHandles(QPointF pos);

private:
    QRectF m_boundingRect;
    QRectF m_actualRect;

    QVector<QRectF> m_resizeHandles;    //! Resizable handles around the shape
    QLineF m_rotateLine;                //! Arrow line used as rotation handle
    QPolygonF m_angleHandle;            //! Arrow head

    double m_angle;
    bool m_isResizing;
    bool m_mousePressed;
    ResizeCorners m_resizeCorner;
};

#endif // RECTANGLEITEM_H
