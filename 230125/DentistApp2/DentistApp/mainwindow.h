#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include "scene.h"

class Layout;

class QListWidgetItem;
class QGraphicsView;
class QGraphicsScene;

class QSqlQuery;
class QSqlTableModel;
class QGraphicsPixmapItem;
class QStackedWidget;
class Maxlayout;


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void styleColor();                  // ui 색상 조절
    void customLayoutLocation();        // customLayout의 graphicsView 위치 좌표값
    void loadImages();                  // 이미지 로드

    bool d = false;
    bool r = false;
    bool y = false;


protected:
    void changeEvent(QEvent *event) override;                       // 윈도우 창 변경될 때


public slots:
    void selectItem(QListWidgetItem*);
    void previousScreen();              // 이전 화면 (layout클래스 화면으로 돌아감)


private slots:
    void on_imageClearPushButton_clicked();

    void layoutSizeChanged(QGraphicsView *grid);
    void DoubleWidget(QGraphicsView *grid);


    void on_circleToolButton_clicked();

    void on_rectangleToolButton_clicked();

    void on_brushToolButton_clicked();

    void on_doubleSpinBox_valueChanged(double arg1);

    void on_colorToolButton_clicked();

    void on_implantToolButton_clicked();

private:
    Ui::MainWindow *ui;

    /* 레이아웃 */
    Layout *customLayout;
    Maxlayout *myMaxlayout;

    /* 이중 창 */
    QStackedWidget *stackWidget;

    int cnt = 0;

    /* 환자 정보 DB */
    void patientLoad();

    QSqlQuery *patientQuery;
    QSqlTableModel *patientQueryModel;

    QHash<QGraphicsPixmapItem*, QString> itemHash;

Scene  * scene;
signals:
//    void sig_currentImage(int);
//    void sig_grid1(QGraphicsPixmapItem* pixItem);
//    void sig_test(QString);
};
#endif // MAINWINDOW_H
