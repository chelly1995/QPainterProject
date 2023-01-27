#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "scene.h"


#include <QMainWindow>
#include <QGraphicsScene>

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

    void on_ColortoolButton_clicked();

    void on_RecttoolButton_clicked();

    void on_EllipsetoolButton_clicked();

    void on_LinetoolButton_clicked();

    void on_BrushtoolButton_clicked();

    void on_actionCursor_triggered();

private:
    Ui::MainWindow *ui;

     Scene *scene;
};
#endif // MAINWINDOW_H
