#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>

class Scene: public QGraphicsScene
{
    Q_OBJECT
public:
    Scene(QObject *parent = nullptr);


protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;


private:
    void drawLineTo(const QPointF &endPoint);
    bool drawing;
    QGraphicsItemGroup * lineGroup;
    QPointF startingPoint;
    QPointF lastPenPoint;
};

#endif // SCENE_H
