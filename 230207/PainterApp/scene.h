#ifndef SCENE_H
#define SCENE_H

//#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsSceneResizeEvent>
#include <QList>

//class QGraphicsPathItem;

class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Scene(QObject *parent = nullptr);

    enum Shape {Cursor, Line, Rect, Ellipse, Path, Arrow, Triangle, Image, Text};

    Shape getCurrentShape() const;
    void setCurrentShape(const Shape &value);

    QColor getCurrentColor() const;
    void setCurrentColor(const QColor& color);

    qreal rotation() const;
    void setRotation(qreal angle);



    void setText(QString string);

signals:

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override; 
    void resizeEvent(QGraphicsSceneResizeEvent *event);


    void keyPressEvent(QKeyEvent *event) override;

    void addLineItem(QPointF stPos, QPointF edPos);
    void addRectItem(QPointF stPos, QPointF edPos);
    void addEllipseItem(QPointF stPos, QPointF edPos);
    void addImageItem(QPointF stPos, QPointF edPos);
    void addTriangleItem(QPointF stPos, QPointF midPos, QPointF edPos);
    void addArrowItem(QPointF stPos, QPointF edPos);
    void addTextItem(QPointF stPos);


private:
    bool drawing;
    bool m_isClicked;

    int m_triClicked;

    // List
    QList<QGraphicsPathItem*> m_pathList;
    QList<QGraphicsItem*> m_allitems;

    //PathItem
    QGraphicsPathItem* m_pathItem;
    QGraphicsItem* m_currentItem;

    QColor m_currentColor;
    Shape m_currentShape;
    QPointF m_startPos;

    QPointF m_prevPos;  // 이전 좌표값
    QPointF m_midPos;
    QPointF m_latePos;  // 이후 좌표값

    qreal paintSize;        // 선의 크기를 기억하는 변수
    qreal rotateAngle;

    QString text;


public slots:

    void setPaintSize(qreal);
    void clearItems();
    void deleteItems();
    void rotate();
    void size();

};

#endif // SCENE_H
