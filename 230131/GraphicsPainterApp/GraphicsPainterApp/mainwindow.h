#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPoint>
#include <QHash>

class QGraphicsRectItem;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class SceneWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void wheelEvent(QWheelEvent* event) override;
    bool eventFilter(QObject* dest, QEvent* event) override;

private:    
    void addWidgetToScene(QPoint initPos);

    Ui::MainWindow *ui;
    QHash<QWidget*, QGraphicsRectItem*> widgetHash;
    SceneWidget* m_scene;

protected slots:
    void rotateItem();

private slots:
    void on_actionCursor_triggered();
    void on_actionLine_triggered();
    void on_actionEllipse_triggered();
    void on_actionImage_triggered();
    void on_actionStar_triggered();
    void on_actionPath_triggered();
    void on_actionColor_triggered();
    void setSelectItemColor(QColor color);
    void on_actionDelete_triggered();
    void on_actionRect_triggered();
    void on_actionLeft_triggered();
    void on_actionRight_triggered();
    void on_actionCapture_triggered();
};
#endif // MAINWINDOW_H
