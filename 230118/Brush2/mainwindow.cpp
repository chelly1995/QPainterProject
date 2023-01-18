#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "scene.h"
#include "function.h"
#include "view.h"


//#include <QGraphicsScene>
#include <QGraphicsView>
#include <QFileDialog>
#include <QDoubleSpinBox>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //    view = new View;
    //    view->setScene(scene);
    //    ui->verticalLayout->addWidget(view);

    view = new View;

    scene = new Scene;
    view->setScene(scene);
    ui->verticalLayout->addWidget(view);
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

    // scene = new Scene;
    scene->addPixmap(buf);

    scene->update();
    // view = new View;
    //    view->setScene(scene);
    //    ui->verticalLayout->addWidget(view);


}


void MainWindow::on_actionColor_triggered()
{
    scene->setPaintColor();
}




void MainWindow::on_ZoomIntoolButton_clicked()
{
    view->scale(1.25,1.25);
}


void MainWindow::on_ZoomOuttoolButton_clicked()
{
    view->scale(0.8, 0.8);
}


void MainWindow::on_LeftrotatetoolButton_clicked()
{
    view->rotate(90);
}


void MainWindow::on_RightrotatetoolButton_clicked()
{
    view->rotate(-90);
}

