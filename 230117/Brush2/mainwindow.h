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

private slots:
    void on_actionImageload_triggered();

    void on_actionColor_triggered();

    void on_ZoomIntoolButton_clicked();

    void on_ZoomOuttoolButton_clicked();

    void on_LeftrotatetoolButton_clicked();

    void on_RightrotatetoolButton_clicked();

private:

    Scene * scene;
    QGraphicsView *view;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
