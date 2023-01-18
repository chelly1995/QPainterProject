#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>


class Scene: public QGraphicsScene
{
    Q_OBJECT
public:
    Scene(QObject *parent = nullptr);

    void setPaintColor();
//    void setPaintSize(qreal);
    QColor paintColor;
//    qreal paintSize;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
 //   void paintEvent(QPainter *event);


private:
    void drawLineTo(const QPointF &endPoint);

    void drawLine(QPointF &scenepos);

    bool drawing;
    //QGraphicsItemGroup * lineGroup;
    QGraphicsLineItem* m_lineItem;

    QPointF startingPoint;
    QPointF lastPenPoint;
   // qreal paintSize;

public slots:
      //  void setPaintSize(qreal);

};

#endif // SCENE_H
