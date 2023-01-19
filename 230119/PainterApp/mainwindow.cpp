#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "scene.h"

#include <QGraphicsView>
#include <QFileDialog>
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QGraphicsView *view = new QGraphicsView(this);

    scene = new Scene(this);

    view->setScene(scene);
    ui->verticalLayout->addWidget(view);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionImageLoad_triggered()
{
    QFileDialog dlg;
    QString filePath = dlg.getOpenFileName(this, "Load Image", "", "Image Files (*.png *.jpg *.bmp)");

    QImage *imgSize = new QImage(filePath);
    QPixmap buf = QPixmap::fromImage(*imgSize);
    buf = buf.scaled(imgSize->width(), imgSize->height());

    //scene = new Scene;
    scene->addPixmap(buf);
    scene->update();

}


void MainWindow::on_actionBrush_triggered()
{
   scene->setCurrentShape(Scene::Path);
}


void MainWindow::on_actionRect_triggered()
{
 scene->setCurrentShape(Scene::Rect);
}


void MainWindow::on_actionEllipse_triggered()
{
    scene->setCurrentShape(Scene::Ellipse);
}


void MainWindow::on_actionLine_triggered()
{
    scene->setCurrentShape(Scene::Line);
}


void MainWindow::on_actionColor_triggered()
{
    QColor color = QColorDialog::getColor();
    if(color.isValid()){
        scene->setCurrentColor(color);
    }
}


void MainWindow::on_actionImplantImage_triggered()
{
    scene->setCurrentShape(Scene::Image);
}


void MainWindow::on_actionClear_triggered()
{
    scene->clear();
}

