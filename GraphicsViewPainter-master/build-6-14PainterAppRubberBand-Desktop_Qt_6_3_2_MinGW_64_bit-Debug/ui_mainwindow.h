/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAdd_Image;
    QAction *actionQuit;
    QAction *actionPen;
    QAction *actionEraser;
    QAction *actionEllipse;
    QAction *actionRectangle;
    QAction *actionStar;
    QAction *actionAbout;
    QAction *actionCursor;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *listLayout;
    QVBoxLayout *viewLayout;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuTools;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(825, 600);
        actionAdd_Image = new QAction(MainWindow);
        actionAdd_Image->setObjectName(QString::fromUtf8("actionAdd_Image"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd_Image->setIcon(icon);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuit->setIcon(icon1);
        actionPen = new QAction(MainWindow);
        actionPen->setObjectName(QString::fromUtf8("actionPen"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/pen.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPen->setIcon(icon2);
        actionEraser = new QAction(MainWindow);
        actionEraser->setObjectName(QString::fromUtf8("actionEraser"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/eraser.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEraser->setIcon(icon3);
        actionEllipse = new QAction(MainWindow);
        actionEllipse->setObjectName(QString::fromUtf8("actionEllipse"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/ellipse.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEllipse->setIcon(icon4);
        actionRectangle = new QAction(MainWindow);
        actionRectangle->setObjectName(QString::fromUtf8("actionRectangle"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/rectangle.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRectangle->setIcon(icon5);
        actionStar = new QAction(MainWindow);
        actionStar->setObjectName(QString::fromUtf8("actionStar"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/star.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStar->setIcon(icon6);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/about.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon7);
        actionCursor = new QAction(MainWindow);
        actionCursor->setObjectName(QString::fromUtf8("actionCursor"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/cursor.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCursor->setIcon(icon8);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        listLayout = new QVBoxLayout();
        listLayout->setSpacing(6);
        listLayout->setObjectName(QString::fromUtf8("listLayout"));

        horizontalLayout->addLayout(listLayout);

        viewLayout = new QVBoxLayout();
        viewLayout->setSpacing(6);
        viewLayout->setObjectName(QString::fromUtf8("viewLayout"));

        horizontalLayout->addLayout(viewLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 825, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QString::fromUtf8("menuTools"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionAdd_Image);
        menuFile->addAction(actionQuit);
        menuTools->addAction(actionCursor);
        menuTools->addAction(actionPen);
        menuTools->addAction(actionEraser);
        menuTools->addAction(actionEllipse);
        menuTools->addAction(actionRectangle);
        menuTools->addAction(actionStar);
        menuHelp->addAction(actionAbout);
        mainToolBar->addAction(actionCursor);
        mainToolBar->addAction(actionPen);
        mainToolBar->addAction(actionEraser);
        mainToolBar->addAction(actionEllipse);
        mainToolBar->addAction(actionStar);
        mainToolBar->addAction(actionRectangle);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionAdd_Image->setText(QCoreApplication::translate("MainWindow", "Add Image", nullptr));
        actionQuit->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        actionPen->setText(QCoreApplication::translate("MainWindow", "Pen", nullptr));
        actionEraser->setText(QCoreApplication::translate("MainWindow", "Eraser", nullptr));
        actionEllipse->setText(QCoreApplication::translate("MainWindow", "Ellipse", nullptr));
        actionRectangle->setText(QCoreApplication::translate("MainWindow", "Rectangle", nullptr));
        actionStar->setText(QCoreApplication::translate("MainWindow", "Star", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        actionCursor->setText(QCoreApplication::translate("MainWindow", "Cursor", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        menuTools->setTitle(QCoreApplication::translate("MainWindow", "Tools", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
