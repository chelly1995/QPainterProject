#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "scene.h"


#include <QGraphicsScene>
#include <QGraphicsView>
#include <QFileDialog>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new Scene(this);
    //QGraphicsView *view = new QGraphicsView(this);

    //ui->verticalLayout->addWidget(view);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionImageload_triggered()
{

    QFileDialog dlg;
    QString filePath = dlg.getOpenFileName(this, "Load Image", "", "Image Files (*.png *.jpg *.bmp)");

    QImage *imgSize = new QImage(filePath);
    QPixmap buf = QPixmap::fromImage(*imgSize);
    buf = buf.scaled(imgSize->width(), imgSize->height());

    scene = new Scene;
    scene->addPixmap(buf);

    QGraphicsView *view = new QGraphicsView(this);
    view->setScene(scene);
    ui->verticalLayout->addWidget(view);

}

