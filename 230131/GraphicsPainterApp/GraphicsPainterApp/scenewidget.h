#ifndef SCENEWIDGET_H
#define SCENEWIDGET_H

#include <QGraphicsScene>
#include <QList>

class QGraphicsEllipseItem;
class QGraphicsPathItem;
class MovableItem;

class SceneWidget : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit SceneWidget(QObject *parent = nullptr);

    enum Shape { Cursor, Line, Rect, Ellipse, Path, Image, Star };

    Shape getCurrentShape() const;
    void setCurrentShape(const Shape &value);

    QColor getCurrentColor() const;
    void setCurrentColor(const QColor& color);

    void deleteCurrentItem();

    void setCapture(bool);

protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) override;

    void addLineItem(QPointF stPos, QPointF edPos);
    void addRectItem(QPointF stPos, QPointF edPos);
    void addEllipseItem(QPointF stPos, QPointF edPos);
    void addImageItem(QPointF stPos, QPointF edPos);
    void addStarItem(QPointF stPos, QPointF edPos);

private:
     bool m_isDrawable;
     QList<QGraphicsPathItem*> m_pathList;
     QList<MovableItem*> m_itemList;
     QGraphicsPathItem* m_pathItem;
     QColor m_currentColor;
     Shape m_currentShape;
     QPointF m_startPos;
     QGraphicsItem* m_currentItem;
     bool m_isCapture;

public slots:
     void updateScene();     
     void rotateLeftCurrentItem();
     void rotateRightCurrentItem();
};

#endif // SCENEWIDGET_H
