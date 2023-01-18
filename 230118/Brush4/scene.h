#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QList>


class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Scene(QObject *parent = nullptr);

    enum Shape { Cursor, Line, Rect, Ellipse, Path };

    Shape getCurrentShape() const;
    void setCurrentShape(const Shape &value);

    QColor getCurrentColor() const;
    void setCurrentColor(const QColor& color);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) override;


    void addLineItem(QPointF stPos, QPointF edPos);
    void addRectItem(QPointF stPos, QPointF edPos);
    void addEllipseItem(QPointF stPos, QPointF edPos);

private:
    bool drawing;
    QList<QGraphicsPathItem*> m_pathList;
    QGraphicsPathItem* m_pathItem;

    QColor m_currentColor;
    Shape m_currentShape;
    QPointF m_startPos;
    QGraphicsItem* m_currentItem;

public slots:
    void updateScene();

};

#endif // SCENE_H
