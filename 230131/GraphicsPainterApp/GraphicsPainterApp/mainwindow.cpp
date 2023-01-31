#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "scenewidget.h"
#include "scenewidgetitem.h"

#include <QGraphicsView>
#include <QGraphicsProxyWidget>
#include <QGraphicsSceneMouseEvent>
#include <QWheelEvent>
#include <QScrollBar>
#include <QtMath>
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    setAutoFillBackground(true);
    setStyleSheet("background-color: white;");

    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setScene(new QGraphicsScene(this));
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);    
//    ui->graphicsView->setDragMode(QGraphicsView::RubberBandDrag);

    m_scene = new SceneWidget(this);
    m_scene->setCurrentShape(SceneWidget::Cursor);
    m_scene->setSceneRect(QRectF(-400, -400, 800, 800));
    m_scene->addLine(-400, 0, 400, 0);
    m_scene->addLine(0, -400, 0, 400);

    connect(m_scene, SIGNAL(changed(const QList<QRectF> &)), m_scene, SLOT(updateScene()));

    connect(m_scene, SIGNAL(changed(const QList<QRectF> &)),
            ui->graphicsView, SLOT(update()));

    ui->graphicsView->setScene(m_scene);
//    setDragMode(QGraphicsView::RubberBandDrag);

    // Add widget proxies + their parenting graphics items to scene
//    addWidgetToScene(QPoint(10, 10));
//    addWidgetToScene(QPoint(300, 100));
//    addWidgetToScene(QPoint(200, 200));
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject* dest, QEvent* event)
{
    if(event->type() == QEvent::MouseButtonPress)
    {
        qDebug("MouseButtonPress");
        QGraphicsProxyWidget* item = dynamic_cast<QGraphicsProxyWidget*>(dest);
        QGraphicsSceneMouseEvent *e = dynamic_cast<QGraphicsSceneMouseEvent*>(event);
        if(e->modifiers() == Qt::Key_Control && e->button() == Qt::LeftButton)
            item->setRotation(item->rotation()+1);
        else if(e->modifiers() == Qt::Key_Control && e->button() == Qt::RightButton)
            item->setRotation(item->rotation()-1);
    }

    return QObject::eventFilter(dest, event);
}

void MainWindow::addWidgetToScene(QPoint initPos)
{
    // Create a widget
    SceneWidgetItem *widget = new SceneWidgetItem();

    QGraphicsRectItem *proxyControl = ui->graphicsView->scene()->addRect(initPos.x(), initPos.y(), widget->width(), 20, QPen(Qt::black), QBrush(Qt::darkGreen));
    proxyControl->setFlag(QGraphicsItem::ItemIsMovable, true);
    proxyControl->setFlag(QGraphicsItem::ItemIsSelectable, true);

    // Create the proxy by adding the widget to the scene
    QGraphicsProxyWidget* const proxy = ui->graphicsView->scene()->addWidget(widget);

    proxy->setPos(initPos.x(), initPos.y()+proxyControl->rect().height());
    proxy->setParentItem(proxyControl);
    proxy->installEventFilter(this);

    widgetHash[widget] = proxyControl;
    connect(widget, SIGNAL(rotateItem()), this, SLOT(rotateItem()));
}

void MainWindow::wheelEvent(QWheelEvent *event)
{
    qreal deltaScale = 1;
    deltaScale += event->angleDelta().ry() > 0 ? 0.1 : -0.1;
    ui->graphicsView->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    ui->graphicsView->scale(deltaScale, deltaScale);
}

void MainWindow::rotateItem()
{
    SceneWidgetItem *widget = qobject_cast<SceneWidgetItem*>(sender());
    QGraphicsRectItem *item = widgetHash[widget];
    item->setRotation(item->rotation()+1);
}

void MainWindow::on_actionCursor_triggered()
{
    m_scene->setCurrentShape(SceneWidget::Cursor);
}

void MainWindow::on_actionLine_triggered()
{
    m_scene->setCurrentShape(SceneWidget::Line);
}

void MainWindow::on_actionRect_triggered()
{
    m_scene->setCurrentShape(SceneWidget::Rect);
}

void MainWindow::on_actionEllipse_triggered()
{
    m_scene->setCurrentShape(SceneWidget::Ellipse);
}

void MainWindow::on_actionImage_triggered()
{
    m_scene->setCurrentShape(SceneWidget::Image);
}

void MainWindow::on_actionStar_triggered()
{
    m_scene->setCurrentShape(SceneWidget::Star);
}

void MainWindow::on_actionPath_triggered()
{
    m_scene->setCurrentShape(SceneWidget::Path);
}

void MainWindow::on_actionDelete_triggered()
{
    m_scene->deleteCurrentItem();
}

void MainWindow::on_actionColor_triggered()
{
    QColor color = QColorDialog::getColor();
    if(color.isValid()) {
        m_scene->setCurrentColor(color);
    }
}

void MainWindow::setSelectItemColor(QColor color)
{
    if(m_scene->selectedItems().count()!= 0){
        //Loop through the selected items
        foreach (QGraphicsItem * item, m_scene->selectedItems()) {

            //Loop to find children
            foreach (QGraphicsItem * childItem, item->childItems()) {
                //Is rect ?
                QGraphicsRectItem* mItem = qgraphicsitem_cast<QGraphicsRectItem*>(childItem);
                if(mItem){
                    mItem->setBrush(QBrush(color));
                }

                //Is path ?
                QGraphicsPathItem* pathItem = qgraphicsitem_cast<QGraphicsPathItem*>(childItem);
                if(pathItem){
                    pathItem->setBrush(QBrush(color));
                }

                //Is ellipse?
                QGraphicsEllipseItem* ellipseItem = qgraphicsitem_cast<QGraphicsEllipseItem*>(childItem);
                if(ellipseItem){
                    ellipseItem->setBrush(QBrush(color));
                }
            }
        }
    }
}

void MainWindow::on_actionLeft_triggered()
{
    m_scene->rotateLeftCurrentItem();
}

void MainWindow::on_actionRight_triggered()
{
    m_scene->rotateRightCurrentItem();
}

void MainWindow::on_actionCapture_triggered()
{
    QRectF rect = m_scene->selectionArea().boundingRect().normalized();
    QPoint pos1 = ui->graphicsView->mapFromScene(rect.topLeft());
    QPoint pos2 = ui->graphicsView->mapFromScene(rect.bottomRight());
    m_scene->setCapture(true);
    QPixmap pix = ui->graphicsView->grab(QRect(pos1, pos2));
    m_scene->setCapture(false);
    pix.save("test.png");
}

