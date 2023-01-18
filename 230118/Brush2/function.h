#ifndef FUNCTION_H
#define FUNCTION_H

#include <QWidget>

class Function : public QWidget
{
    Q_OBJECT
public:
    explicit Function(QWidget *parent = nullptr);

signals:


public slots:
    void zoomIn();
    void zoomOut();
    void leftRotate();
    void rightRotate();


};

#endif // FUNCTION_H
