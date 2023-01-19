#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "scene.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionImageLoad_triggered();

    void on_actionBrush_triggered();

    void on_actionRect_triggered();

    void on_actionEllipse_triggered();

    void on_actionLine_triggered();

    void on_actionColor_triggered();

    void on_actionImplantImage_triggered();

    void on_actionClear_triggered();

private:
    Ui::MainWindow *ui;

    Scene  * scene;


};
#endif // MAINWINDOW_H
