#ifndef VIEW_H
#define VIEW_H

#include <QGraphicsView>

class View : QGraphicsView
{
    Q_OBJECT
public:
    explicit View(QWidget *parent = nullptr);
};

#endif // VIEW_H
