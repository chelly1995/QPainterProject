#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "rectangle.h"


#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // QGraphicsScene*scene = new QGraphicsScene(this);
    scene = new QGraphicsScene(this);
    scene->setBackgroundBrush(QBrush(QColor(Qt::yellow)));
    scene->setSceneRect(-500,-500,600,600);

    ui->graphicsView->setScene(scene);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_toolButton1_clicked()
{

}


void MainWindow::on_toolButton_2_clicked()
{
    QPen mPen;
    mPen.setWidth(5);
    mPen.setColor(Qt::red);

    Rectangle *rectItem=new Rectangle();
    rectItem->setRect(-10,-10,200,200);
    rectItem->setFlag(QGraphicsItem::ItemIsFocusable);
    rectItem->setFlag(QGraphicsItem::ItemIsMovable);
    rectItem->setFlag(QGraphicsItem::ItemIsSelectable);
    rectItem->setFocus();

    rectItem->setPen(mPen);
    rectItem->setBrush(QBrush(Qt::NoBrush));


    scene->addItem(rectItem);

    //ui->graphicsView->setScene(scene);

}



void MainWindow::on_LoadButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,
                                                        tr("Load Image"),
                                                        mResourceDir,
                                                        tr("Images (*.png *.jpg)"));

        if (filename.isEmpty())  {
            return;
        }

        QPixmap p(filename);
        if (! ui->graphicsView->scene()) {
            qDebug() << "No Scene!";

            QGraphicsScene *scene = new QGraphicsScene(this);
            ui->graphicsView->setScene(scene);
        }
        ui->graphicsView->scene()->addPixmap(p);
}

