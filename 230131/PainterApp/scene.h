#ifndef SCENE_H
#define SCENE_H

//#include <QObject>
#include <QGraphicsScene>
#include <QList>

//class QGraphicsPathItem;

class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Scene(QObject *parent = nullptr);

    enum Shape {Cursor, Line, Rect, Ellipse, Path, Image, Arrow, Triangle};

    Shape getCurrentShape() const;
    void setCurrentShape(const Shape &value);

    QColor getCurrentColor() const;
    void setCurrentColor(const QColor& color);

    qreal rotation() const;
    void setRotation(qreal angle);


signals:

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

   // void removeItem(QGraphicsItem*item);

    void keyPressEvent(QKeyEvent *event) override;

    void addLineItem(QPointF stPos, QPointF edPos);
    void addRectItem(QPointF stPos, QPointF edPos);
    void addEllipseItem(QPointF stPos, QPointF edPos);
    void addImageItem(QPointF stPos, QPointF edPos);
    void addTriangleItem(QPointF stPos, QPointF edPos);
    void addArrowItem(QPointF stPos, QPointF edPos);


private:
    bool drawing;
    // List
    QList<QGraphicsPathItem*> m_pathList;
    QList<QGraphicsItem*> m_allitems;

    //PathItem
    QGraphicsPathItem* m_pathItem;
    QGraphicsItem* m_currentItem;

    QColor m_currentColor;
    Shape m_currentShape;
    QPointF m_startPos;

    qreal paintSize;        // 선의 크기를 기억하는 변수
    qreal rotateAngle;


public slots:

    void setPaintSize(qreal);
    void clearItems();

};

#endif // SCENE_H
