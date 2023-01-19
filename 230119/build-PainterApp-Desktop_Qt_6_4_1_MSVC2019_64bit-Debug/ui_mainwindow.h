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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionImageLoad;
    QAction *actionBrush;
    QAction *actionRect;
    QAction *actionColor;
    QAction *actionEllipse;
    QAction *actionLine;
    QAction *actionImplantImage;
    QAction *actionClear;
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionImageLoad = new QAction(MainWindow);
        actionImageLoad->setObjectName("actionImageLoad");
        actionBrush = new QAction(MainWindow);
        actionBrush->setObjectName("actionBrush");
        actionRect = new QAction(MainWindow);
        actionRect->setObjectName("actionRect");
        actionColor = new QAction(MainWindow);
        actionColor->setObjectName("actionColor");
        actionEllipse = new QAction(MainWindow);
        actionEllipse->setObjectName("actionEllipse");
        actionLine = new QAction(MainWindow);
        actionLine->setObjectName("actionLine");
        actionImplantImage = new QAction(MainWindow);
        actionImplantImage->setObjectName("actionImplantImage");
        actionClear = new QAction(MainWindow);
        actionClear->setObjectName("actionClear");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(10, 10, 781, 521));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actionImageLoad);
        toolBar->addSeparator();
        toolBar->addAction(actionBrush);
        toolBar->addSeparator();
        toolBar->addAction(actionLine);
        toolBar->addAction(actionRect);
        toolBar->addAction(actionEllipse);
        toolBar->addSeparator();
        toolBar->addAction(actionColor);
        toolBar->addAction(actionImplantImage);
        toolBar->addAction(actionClear);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionImageLoad->setText(QCoreApplication::translate("MainWindow", "ImageLoad", nullptr));
        actionBrush->setText(QCoreApplication::translate("MainWindow", "Brush", nullptr));
        actionRect->setText(QCoreApplication::translate("MainWindow", "Rect", nullptr));
        actionColor->setText(QCoreApplication::translate("MainWindow", "Color", nullptr));
        actionEllipse->setText(QCoreApplication::translate("MainWindow", "Ellipse", nullptr));
        actionLine->setText(QCoreApplication::translate("MainWindow", "Line", nullptr));
        actionImplantImage->setText(QCoreApplication::translate("MainWindow", "ImplantImage", nullptr));
        actionClear->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
