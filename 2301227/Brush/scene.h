#ifndef SCENE_H
#define SCENE_H

#include <QObject>
#include <QGraphicsScene>
#include <QList>

class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Scene(QObject *parent = nullptr);

    enum Shape {Cursor, Line, Rect, Ellipse, Path, Image};

    Shape getCurrentShape() const;
    void setCurrentShape(const Shape &value);

    QColor getCurrentColor() const;
    void setCurrentColor(const QColor& color);



signals:

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;


private:
    bool drawing;

    // List
    QList<QGraphicsPathItem*> m_pathList;

    //pathitem

    QGraphicsPathItem* m_pathItem;
    QGraphicsItem* m_currentItem;

    QColor m_currentColor;
    Shape m_currentShape;
    QPointF m_startPos;

    qreal paintSize;


public slots:

    void setPaintSize(qreal);

};

#endif // SCENE_H
