/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLine;
    QAction *actionEllipse;
    QAction *actionImage;
    QAction *actionStar;
    QAction *actionPath;
    QAction *actionColor;
    QAction *actionCursor;
    QAction *actionDelete;
    QAction *actionRect;
    QAction *actionRotate_Right;
    QAction *actionLeft;
    QAction *actionRight;
    QAction *actionCapture;
    QGraphicsView *graphicsView;
    QMenuBar *menubar;
    QMenu *menuShape;
    QMenu *menuFormat;
    QMenu *menuRotate;
    QMenu *menuEdit;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionLine = new QAction(MainWindow);
        actionLine->setObjectName("actionLine");
        actionEllipse = new QAction(MainWindow);
        actionEllipse->setObjectName("actionEllipse");
        actionImage = new QAction(MainWindow);
        actionImage->setObjectName("actionImage");
        actionStar = new QAction(MainWindow);
        actionStar->setObjectName("actionStar");
        actionPath = new QAction(MainWindow);
        actionPath->setObjectName("actionPath");
        actionColor = new QAction(MainWindow);
        actionColor->setObjectName("actionColor");
        actionCursor = new QAction(MainWindow);
        actionCursor->setObjectName("actionCursor");
        actionDelete = new QAction(MainWindow);
        actionDelete->setObjectName("actionDelete");
        actionRect = new QAction(MainWindow);
        actionRect->setObjectName("actionRect");
        actionRotate_Right = new QAction(MainWindow);
        actionRotate_Right->setObjectName("actionRotate_Right");
        actionLeft = new QAction(MainWindow);
        actionLeft->setObjectName("actionLeft");
        actionRight = new QAction(MainWindow);
        actionRight->setObjectName("actionRight");
        actionCapture = new QAction(MainWindow);
        actionCapture->setObjectName("actionCapture");
        graphicsView = new QGraphicsView(MainWindow);
        graphicsView->setObjectName("graphicsView");
        MainWindow->setCentralWidget(graphicsView);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        menuShape = new QMenu(menubar);
        menuShape->setObjectName("menuShape");
        menuFormat = new QMenu(menubar);
        menuFormat->setObjectName("menuFormat");
        menuRotate = new QMenu(menuFormat);
        menuRotate->setObjectName("menuRotate");
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName("menuEdit");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuShape->menuAction());
        menubar->addAction(menuFormat->menuAction());
        menuShape->addAction(actionCursor);
        menuShape->addAction(actionLine);
        menuShape->addAction(actionRect);
        menuShape->addAction(actionEllipse);
        menuShape->addAction(actionImage);
        menuShape->addAction(actionStar);
        menuShape->addAction(actionPath);
        menuShape->addSeparator();
        menuFormat->addAction(actionColor);
        menuFormat->addAction(menuRotate->menuAction());
        menuRotate->addAction(actionLeft);
        menuRotate->addAction(actionRight);
        menuEdit->addAction(actionDelete);
        menuEdit->addSeparator();
        menuEdit->addAction(actionCapture);
        toolBar->addAction(actionDelete);
        toolBar->addAction(actionCapture);
        toolBar->addSeparator();
        toolBar->addAction(actionCursor);
        toolBar->addAction(actionLine);
        toolBar->addAction(actionRect);
        toolBar->addAction(actionEllipse);
        toolBar->addAction(actionImage);
        toolBar->addAction(actionStar);
        toolBar->addAction(actionPath);
        toolBar->addSeparator();
        toolBar->addAction(actionColor);
        toolBar->addAction(actionLeft);
        toolBar->addAction(actionRight);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionLine->setText(QCoreApplication::translate("MainWindow", "Line", nullptr));
        actionEllipse->setText(QCoreApplication::translate("MainWindow", "Ellipse", nullptr));
        actionImage->setText(QCoreApplication::translate("MainWindow", "Image", nullptr));
        actionStar->setText(QCoreApplication::translate("MainWindow", "Star", nullptr));
        actionPath->setText(QCoreApplication::translate("MainWindow", "Path", nullptr));
        actionColor->setText(QCoreApplication::translate("MainWindow", "Color", nullptr));
        actionCursor->setText(QCoreApplication::translate("MainWindow", "Cursor", nullptr));
        actionDelete->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        actionRect->setText(QCoreApplication::translate("MainWindow", "Rect", nullptr));
        actionRotate_Right->setText(QCoreApplication::translate("MainWindow", "Rotate Right", nullptr));
        actionLeft->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        actionRight->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        actionCapture->setText(QCoreApplication::translate("MainWindow", "Capture", nullptr));
        menuShape->setTitle(QCoreApplication::translate("MainWindow", "Shape", nullptr));
        menuFormat->setTitle(QCoreApplication::translate("MainWindow", "Format", nullptr));
        menuRotate->setTitle(QCoreApplication::translate("MainWindow", "Rotate", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
