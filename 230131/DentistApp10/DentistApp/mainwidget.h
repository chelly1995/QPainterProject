#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QStackedWidget>
#include "mainwindow.h"
#include "loginform.h"

class MainWidget : public QStackedWidget
{
    Q_OBJECT
public:
    explicit MainWidget(QWidget *parent = nullptr);
    MainWindow *window;
    LoginForm *login;


public slots:
    void switchStack(int);


signals:

};

#endif // MAINWIDGET_H
