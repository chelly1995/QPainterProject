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

    void setPaintColor();
    QColor paintColor;
    qreal paintSize;

signals:
protected:

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
//    void drawLineTo(const QPointF &endPoint);
    QList<QGraphicsPathItem*> pathList;
    bool drawing;

    QPointF previousPoint;
};

#endif // SCENE_H
