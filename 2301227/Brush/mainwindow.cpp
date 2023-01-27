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


void MainWindow::on_ColortoolButton_clicked()
{
    QColor color = QColorDialog::getColor();
    if(color.isValid()){
        scene->setCurrentColor(color);
    }
}


void MainWindow::on_RecttoolButton_clicked()
{
scene->setCurrentShape(Scene::Rect);
}


void MainWindow::on_EllipsetoolButton_clicked()
{
    scene->setCurrentShape(Scene::Ellipse);
}


void MainWindow::on_LinetoolButton_clicked()
{
    scene->setCurrentShape(Scene::Line);
}


void MainWindow::on_BrushtoolButton_clicked()
{
    scene->setCurrentShape(Scene::Path);
}


void MainWindow::on_actionCursor_triggered()
{
    scene->setCurrentShape(Scene::Cursor);
}

