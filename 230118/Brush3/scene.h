#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QtWidgets>
#include <QList>

class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Scene(QObject *parent = nullptr);

    enum Shape {Cursor, Line, Rect, Ellipse, Brush, Star};

    Shape getCurrentShape() const;
    void setCurrentShape(const Shape &value);

    QColor getCurrentcolor() const;
    void setCurrentcolor(const QColor& color);

    void setPaintColor();
    QColor paintColor;
    qreal paintSize;

signals:

protected:

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    void addLineItem(QPointF stPos, QPointF edPos);
    void addRectItem(QPointF stPos, QPointF edPos);
    void addEllipseItem(QPointF stPos, QPointF edPos);
    void addImageItem(QPointF stPos, QPointF edPos);
   // void addStarItem(QPointF stPos, QPointF edPos);


private:

    bool drawing;
    QList<QGraphicsPathItem*> pathList;
    QList<QGraphicsEllipseItem*> m_itemList;
    QGraphicsPathItem* pathItem;
    QColor m_currentColor;
    Shape m_currentShape;
    QPointF m_startPos;
    QGraphicsItem* m_currentItem;

public slots:
    void updateScene();
};

#endif // SCENE_H
