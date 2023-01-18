#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "scene.h"
#include "view.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Scene *scene;
    View *view;

private slots:
    void on_actionImageLoad_triggered();

    void on_actionRectangle_triggered();

    void on_actionLine_triggered();

    void on_actionEllipse_triggered();

    void on_actionBrush_triggered();

private:
    Ui::MainWindow *ui;

//    Scene *scene;
//    View *view;
};
#endif // MAINWINDOW_H
