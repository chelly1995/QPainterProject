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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSave;
    QAction *actionRedo;
    QAction *actionUndo;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QSplitter *splitter4;
    QSplitter *splitter3;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_13;
    QSpacerItem *horizontalSpacer_8;
    QLineEdit *doctorNameLineEdit;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *verticalSpacer_3;
    QTabWidget *tabWidget;
    QWidget *painterTab;
    QVBoxLayout *verticalLayout;
    QGroupBox *brushGroupBox;
    QHBoxLayout *horizontalLayout_6;
    QToolButton *cursorToolButton;
    QToolButton *brushToolButton;
    QGroupBox *figureGroupBox;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *circleToolButton;
    QToolButton *triangleToolButton;
    QToolButton *rectangleToolButton;
    QToolButton *arrowToolButton;
    QToolButton *linetoolButton;
    QGroupBox *colorGroupBox;
    QHBoxLayout *horizontalLayout_4;
    QToolButton *colorToolButton;
    QSpinBox *spinBox;
    QPushButton *drawClearPushButton;
    QWidget *processingTab;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *imageGroupBox;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_7;
    QToolButton *brightToolButton;
    QToolButton *brightnessToolButton;
    QToolButton *sharpenToolButton;
    QHBoxLayout *horizontalLayout_9;
    QToolButton *contrastToolButton;
    QToolButton *verticalFlipToolButton;
    QToolButton *horizontalFlipToolButton;
    QHBoxLayout *horizontalLayout_10;
    QToolButton *zoomInToolButton;
    QToolButton *zoomOutToolButton;
    QToolButton *panningToolButton;
    QHBoxLayout *horizontalLayout_12;
    QToolButton *leftRotateToolButton;
    QToolButton *rightRotateToolButton;
    QPushButton *imageSizeClearPushButton;
    QWidget *measueTab;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *measureGroupBox;
    QHBoxLayout *horizontalLayout_5;
    QToolButton *rulerToolButton;
    QToolButton *measureToolButton;
    QToolButton *protractorToolButton;
    QGroupBox *implantGroupBox;
    QHBoxLayout *horizontalLayout_11;
    QToolButton *implantToolButton;
    QToolButton *implantToolButton_2;
    QVBoxLayout *verticalLayout_7;
    QSpacerItem *verticalSpacer_4;
    QGroupBox *initializationGroupBox;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *layoutClearPushButton;
    QSpacerItem *verticalSpacer_2;
    QTableView *patientTableView;
    QSplitter *splitter2;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_11;
    QMdiArea *mdiArea;
    QFrame *line;
    QSpacerItem *verticalSpacer;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_14;
    QSpacerItem *horizontalSpacer_9;
    QListWidget *listWidget;
    QSpacerItem *horizontalSpacer_10;
    QFrame *frame;
    QMenuBar *menubar;
    QMenu *menuMenu;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1248, 681);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow {background-color: rgb(32, 56, 100)};\n"
"\n"
""));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName("actionSave");
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName("actionRedo");
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName("actionUndo");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        splitter4 = new QSplitter(centralwidget);
        splitter4->setObjectName("splitter4");
        splitter4->setOrientation(Qt::Horizontal);
        splitter3 = new QSplitter(splitter4);
        splitter3->setObjectName("splitter3");
        splitter3->setOrientation(Qt::Horizontal);
        splitter = new QSplitter(splitter3);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Vertical);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName("layoutWidget");
        verticalLayout_8 = new QVBoxLayout(layoutWidget);
        verticalLayout_8->setObjectName("verticalLayout_8");
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_8);

        doctorNameLineEdit = new QLineEdit(layoutWidget);
        doctorNameLineEdit->setObjectName("doctorNameLineEdit");
        doctorNameLineEdit->setReadOnly(true);

        horizontalLayout_13->addWidget(doctorNameLineEdit);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_7);


        verticalLayout_5->addLayout(horizontalLayout_13);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_3);


        verticalLayout_8->addLayout(verticalLayout_5);

        tabWidget = new QTabWidget(layoutWidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setTabPosition(QTabWidget::West);
        tabWidget->setTabShape(QTabWidget::Triangular);
        painterTab = new QWidget();
        painterTab->setObjectName("painterTab");
        verticalLayout = new QVBoxLayout(painterTab);
        verticalLayout->setObjectName("verticalLayout");
        brushGroupBox = new QGroupBox(painterTab);
        brushGroupBox->setObjectName("brushGroupBox");
        brushGroupBox->setStyleSheet(QString::fromUtf8("QGroupBox {color: rgb(255, 255, 255)};"));
        horizontalLayout_6 = new QHBoxLayout(brushGroupBox);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        cursorToolButton = new QToolButton(brushGroupBox);
        cursorToolButton->setObjectName("cursorToolButton");
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../../Image/cursor.png"), QSize(), QIcon::Normal, QIcon::Off);
        cursorToolButton->setIcon(icon);

        horizontalLayout_6->addWidget(cursorToolButton);

        brushToolButton = new QToolButton(brushGroupBox);
        brushToolButton->setObjectName("brushToolButton");
        brushToolButton->setStyleSheet(QString::fromUtf8("QToolButton {color: rgb(255, 255, 255)};\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("Image/draw.png"), QSize(), QIcon::Normal, QIcon::Off);
        brushToolButton->setIcon(icon1);

        horizontalLayout_6->addWidget(brushToolButton);


        verticalLayout->addWidget(brushGroupBox);

        figureGroupBox = new QGroupBox(painterTab);
        figureGroupBox->setObjectName("figureGroupBox");
        figureGroupBox->setStyleSheet(QString::fromUtf8("QGroupBox {color: rgb(255, 255, 255)};"));
        horizontalLayout_3 = new QHBoxLayout(figureGroupBox);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        circleToolButton = new QToolButton(figureGroupBox);
        circleToolButton->setObjectName("circleToolButton");
        circleToolButton->setMinimumSize(QSize(0, 0));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icon/Image/circle2.png"), QSize(), QIcon::Normal, QIcon::Off);
        circleToolButton->setIcon(icon2);
        circleToolButton->setIconSize(QSize(30, 30));

        horizontalLayout_3->addWidget(circleToolButton);

        triangleToolButton = new QToolButton(figureGroupBox);
        triangleToolButton->setObjectName("triangleToolButton");
        triangleToolButton->setMinimumSize(QSize(0, 0));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icon/Image/triangle2.png"), QSize(), QIcon::Normal, QIcon::Off);
        triangleToolButton->setIcon(icon3);
        triangleToolButton->setIconSize(QSize(30, 30));

        horizontalLayout_3->addWidget(triangleToolButton);

        rectangleToolButton = new QToolButton(figureGroupBox);
        rectangleToolButton->setObjectName("rectangleToolButton");
        rectangleToolButton->setMinimumSize(QSize(0, 0));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icon/Image/rectangle2.png"), QSize(), QIcon::Normal, QIcon::Off);
        rectangleToolButton->setIcon(icon4);
        rectangleToolButton->setIconSize(QSize(30, 30));

        horizontalLayout_3->addWidget(rectangleToolButton);

        arrowToolButton = new QToolButton(figureGroupBox);
        arrowToolButton->setObjectName("arrowToolButton");
        arrowToolButton->setMinimumSize(QSize(0, 0));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icon/Image/arrow3.png"), QSize(), QIcon::Normal, QIcon::Off);
        arrowToolButton->setIcon(icon5);
        arrowToolButton->setIconSize(QSize(30, 30));

        horizontalLayout_3->addWidget(arrowToolButton);

        linetoolButton = new QToolButton(figureGroupBox);
        linetoolButton->setObjectName("linetoolButton");

        horizontalLayout_3->addWidget(linetoolButton);


        verticalLayout->addWidget(figureGroupBox);

        colorGroupBox = new QGroupBox(painterTab);
        colorGroupBox->setObjectName("colorGroupBox");
        colorGroupBox->setStyleSheet(QString::fromUtf8("QGroupBox {color: rgb(255, 255, 255)};"));
        horizontalLayout_4 = new QHBoxLayout(colorGroupBox);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        colorToolButton = new QToolButton(colorGroupBox);
        colorToolButton->setObjectName("colorToolButton");
        colorToolButton->setLayoutDirection(Qt::LeftToRight);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icon/Image/color.png"), QSize(), QIcon::Normal, QIcon::Off);
        colorToolButton->setIcon(icon6);
        colorToolButton->setIconSize(QSize(150, 15));

        horizontalLayout_4->addWidget(colorToolButton);

        spinBox = new QSpinBox(colorGroupBox);
        spinBox->setObjectName("spinBox");

        horizontalLayout_4->addWidget(spinBox);


        verticalLayout->addWidget(colorGroupBox);

        drawClearPushButton = new QPushButton(painterTab);
        drawClearPushButton->setObjectName("drawClearPushButton");
        drawClearPushButton->setStyleSheet(QString::fromUtf8("QPushButton {background-color: rgb(217, 217, 217)};"));

        verticalLayout->addWidget(drawClearPushButton);

        tabWidget->addTab(painterTab, QString());
        processingTab = new QWidget();
        processingTab->setObjectName("processingTab");
        verticalLayout_4 = new QVBoxLayout(processingTab);
        verticalLayout_4->setObjectName("verticalLayout_4");
        imageGroupBox = new QGroupBox(processingTab);
        imageGroupBox->setObjectName("imageGroupBox");
        imageGroupBox->setStyleSheet(QString::fromUtf8("QGroupBox {color: rgb(255, 255, 255)};"));
        verticalLayout_3 = new QVBoxLayout(imageGroupBox);
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        brightToolButton = new QToolButton(imageGroupBox);
        brightToolButton->setObjectName("brightToolButton");
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icon/Image/bright.png"), QSize(), QIcon::Normal, QIcon::Off);
        brightToolButton->setIcon(icon7);
        brightToolButton->setIconSize(QSize(30, 30));

        horizontalLayout_7->addWidget(brightToolButton);

        brightnessToolButton = new QToolButton(imageGroupBox);
        brightnessToolButton->setObjectName("brightnessToolButton");
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/icon/Image/brightness.png"), QSize(), QIcon::Normal, QIcon::Off);
        brightnessToolButton->setIcon(icon8);
        brightnessToolButton->setIconSize(QSize(30, 30));

        horizontalLayout_7->addWidget(brightnessToolButton);

        sharpenToolButton = new QToolButton(imageGroupBox);
        sharpenToolButton->setObjectName("sharpenToolButton");
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/icon/Image/sharpen.png"), QSize(), QIcon::Normal, QIcon::Off);
        sharpenToolButton->setIcon(icon9);
        sharpenToolButton->setIconSize(QSize(30, 30));

        horizontalLayout_7->addWidget(sharpenToolButton);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        contrastToolButton = new QToolButton(imageGroupBox);
        contrastToolButton->setObjectName("contrastToolButton");
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/icon/Image/Contrast.png"), QSize(), QIcon::Normal, QIcon::Off);
        contrastToolButton->setIcon(icon10);
        contrastToolButton->setIconSize(QSize(30, 30));

        horizontalLayout_9->addWidget(contrastToolButton);

        verticalFlipToolButton = new QToolButton(imageGroupBox);
        verticalFlipToolButton->setObjectName("verticalFlipToolButton");
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/icon/Image/vertical flip.png"), QSize(), QIcon::Normal, QIcon::Off);
        verticalFlipToolButton->setIcon(icon11);
        verticalFlipToolButton->setIconSize(QSize(30, 30));

        horizontalLayout_9->addWidget(verticalFlipToolButton);

        horizontalFlipToolButton = new QToolButton(imageGroupBox);
        horizontalFlipToolButton->setObjectName("horizontalFlipToolButton");
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/icon/Image/horizontal flip.png"), QSize(), QIcon::Normal, QIcon::Off);
        horizontalFlipToolButton->setIcon(icon12);
        horizontalFlipToolButton->setIconSize(QSize(30, 30));

        horizontalLayout_9->addWidget(horizontalFlipToolButton);


        verticalLayout_3->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        zoomInToolButton = new QToolButton(imageGroupBox);
        zoomInToolButton->setObjectName("zoomInToolButton");
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/icon/Image/zoom.png"), QSize(), QIcon::Normal, QIcon::Off);
        zoomInToolButton->setIcon(icon13);
        zoomInToolButton->setIconSize(QSize(30, 30));

        horizontalLayout_10->addWidget(zoomInToolButton);

        zoomOutToolButton = new QToolButton(imageGroupBox);
        zoomOutToolButton->setObjectName("zoomOutToolButton");
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/icon/Image/zoomOut.png"), QSize(), QIcon::Normal, QIcon::Off);
        zoomOutToolButton->setIcon(icon14);
        zoomOutToolButton->setIconSize(QSize(30, 30));

        horizontalLayout_10->addWidget(zoomOutToolButton);

        panningToolButton = new QToolButton(imageGroupBox);
        panningToolButton->setObjectName("panningToolButton");
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/icon/Image/panning.png"), QSize(), QIcon::Normal, QIcon::Off);
        panningToolButton->setIcon(icon15);
        panningToolButton->setIconSize(QSize(30, 30));

        horizontalLayout_10->addWidget(panningToolButton);


        verticalLayout_3->addLayout(horizontalLayout_10);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        leftRotateToolButton = new QToolButton(imageGroupBox);
        leftRotateToolButton->setObjectName("leftRotateToolButton");
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/icon/Image/rotate_L.png"), QSize(), QIcon::Normal, QIcon::Off);
        leftRotateToolButton->setIcon(icon16);
        leftRotateToolButton->setIconSize(QSize(30, 30));

        horizontalLayout_12->addWidget(leftRotateToolButton);

        rightRotateToolButton = new QToolButton(imageGroupBox);
        rightRotateToolButton->setObjectName("rightRotateToolButton");
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/icon/Image/rotate_R.png"), QSize(), QIcon::Normal, QIcon::Off);
        rightRotateToolButton->setIcon(icon17);
        rightRotateToolButton->setIconSize(QSize(30, 30));

        horizontalLayout_12->addWidget(rightRotateToolButton);

        imageSizeClearPushButton = new QPushButton(imageGroupBox);
        imageSizeClearPushButton->setObjectName("imageSizeClearPushButton");
        imageSizeClearPushButton->setStyleSheet(QString::fromUtf8("QPushButton {background-color: rgb(217, 217, 217)};"));

        horizontalLayout_12->addWidget(imageSizeClearPushButton);


        verticalLayout_3->addLayout(horizontalLayout_12);


        verticalLayout_4->addWidget(imageGroupBox);

        tabWidget->addTab(processingTab, QString());
        measueTab = new QWidget();
        measueTab->setObjectName("measueTab");
        verticalLayout_6 = new QVBoxLayout(measueTab);
        verticalLayout_6->setObjectName("verticalLayout_6");
        measureGroupBox = new QGroupBox(measueTab);
        measureGroupBox->setObjectName("measureGroupBox");
        measureGroupBox->setStyleSheet(QString::fromUtf8("QGroupBox {color: rgb(255, 255, 255)};"));
        horizontalLayout_5 = new QHBoxLayout(measureGroupBox);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        rulerToolButton = new QToolButton(measureGroupBox);
        rulerToolButton->setObjectName("rulerToolButton");
        rulerToolButton->setMinimumSize(QSize(0, 0));
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/icon/Image/ruler.png"), QSize(), QIcon::Normal, QIcon::Off);
        rulerToolButton->setIcon(icon18);
        rulerToolButton->setIconSize(QSize(30, 30));

        horizontalLayout_5->addWidget(rulerToolButton);

        measureToolButton = new QToolButton(measureGroupBox);
        measureToolButton->setObjectName("measureToolButton");
        measureToolButton->setMinimumSize(QSize(0, 0));
        QIcon icon19;
        icon19.addFile(QString::fromUtf8(":/icon/Image/measure.png"), QSize(), QIcon::Normal, QIcon::Off);
        measureToolButton->setIcon(icon19);
        measureToolButton->setIconSize(QSize(30, 30));

        horizontalLayout_5->addWidget(measureToolButton);

        protractorToolButton = new QToolButton(measureGroupBox);
        protractorToolButton->setObjectName("protractorToolButton");
        protractorToolButton->setMinimumSize(QSize(0, 0));
        QIcon icon20;
        icon20.addFile(QString::fromUtf8(":/icon/Image/progtractor.png"), QSize(), QIcon::Normal, QIcon::Off);
        protractorToolButton->setIcon(icon20);
        protractorToolButton->setIconSize(QSize(30, 30));

        horizontalLayout_5->addWidget(protractorToolButton);


        verticalLayout_6->addWidget(measureGroupBox);

        implantGroupBox = new QGroupBox(measueTab);
        implantGroupBox->setObjectName("implantGroupBox");
        implantGroupBox->setStyleSheet(QString::fromUtf8("QGroupBox {color: rgb(255, 255, 255)};"));
        horizontalLayout_11 = new QHBoxLayout(implantGroupBox);
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        implantToolButton = new QToolButton(implantGroupBox);
        implantToolButton->setObjectName("implantToolButton");
        implantToolButton->setMinimumSize(QSize(100, 0));
        implantToolButton->setSizeIncrement(QSize(0, 0));
        QIcon icon21;
        icon21.addFile(QString::fromUtf8(":/icon/Image/implant.png"), QSize(), QIcon::Normal, QIcon::Off);
        implantToolButton->setIcon(icon21);
        implantToolButton->setIconSize(QSize(30, 30));

        horizontalLayout_11->addWidget(implantToolButton);

        implantToolButton_2 = new QToolButton(implantGroupBox);
        implantToolButton_2->setObjectName("implantToolButton_2");
        implantToolButton_2->setMinimumSize(QSize(100, 0));
        implantToolButton_2->setSizeIncrement(QSize(0, 0));
        implantToolButton_2->setIcon(icon21);
        implantToolButton_2->setIconSize(QSize(30, 30));

        horizontalLayout_11->addWidget(implantToolButton_2);


        verticalLayout_6->addWidget(implantGroupBox);

        tabWidget->addTab(measueTab, QString());

        verticalLayout_8->addWidget(tabWidget);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalSpacer_4 = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_4);

        initializationGroupBox = new QGroupBox(layoutWidget);
        initializationGroupBox->setObjectName("initializationGroupBox");
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush);
#endif
        initializationGroupBox->setPalette(palette);
        initializationGroupBox->setAutoFillBackground(false);
        initializationGroupBox->setStyleSheet(QString::fromUtf8("QGroupBox {color: rgb(255, 255, 255)};\n"
"\n"
"\n"
""));
        initializationGroupBox->setCheckable(false);
        horizontalLayout_8 = new QHBoxLayout(initializationGroupBox);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        layoutClearPushButton = new QPushButton(initializationGroupBox);
        layoutClearPushButton->setObjectName("layoutClearPushButton");
        layoutClearPushButton->setStyleSheet(QString::fromUtf8("QPushButton {background-color: rgb(217, 217, 217)};\n"
""));

        horizontalLayout_8->addWidget(layoutClearPushButton);


        verticalLayout_7->addWidget(initializationGroupBox);


        verticalLayout_8->addLayout(verticalLayout_7);

        verticalSpacer_2 = new QSpacerItem(256, 36, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_2);

        splitter->addWidget(layoutWidget);
        patientTableView = new QTableView(splitter);
        patientTableView->setObjectName("patientTableView");
        patientTableView->setAlternatingRowColors(true);
        patientTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        splitter->addWidget(patientTableView);
        patientTableView->verticalHeader()->setDefaultSectionSize(15);
        splitter3->addWidget(splitter);
        splitter2 = new QSplitter(splitter3);
        splitter2->setObjectName("splitter2");
        splitter2->setOrientation(Qt::Vertical);
        layoutWidget1 = new QWidget(splitter2);
        layoutWidget1->setObjectName("layoutWidget1");
        verticalLayout_11 = new QVBoxLayout(layoutWidget1);
        verticalLayout_11->setObjectName("verticalLayout_11");
        verticalLayout_11->setContentsMargins(0, 0, 0, 0);
        mdiArea = new QMdiArea(layoutWidget1);
        mdiArea->setObjectName("mdiArea");
        mdiArea->setStyleSheet(QString::fromUtf8("QMdiArea {background-color: rgb(32, 56, 100)};\n"
""));
        mdiArea->setViewMode(QMdiArea::TabbedView);

        verticalLayout_11->addWidget(mdiArea);

        line = new QFrame(layoutWidget1);
        line->setObjectName("line");
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_11->addWidget(line);

        verticalSpacer = new QSpacerItem(522, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_11->addItem(verticalSpacer);

        splitter2->addWidget(layoutWidget1);
        layoutWidget2 = new QWidget(splitter2);
        layoutWidget2->setObjectName("layoutWidget2");
        horizontalLayout_14 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_14->setObjectName("horizontalLayout_14");
        horizontalLayout_14->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_9);

        listWidget = new QListWidget(layoutWidget2);
        listWidget->setObjectName("listWidget");

        horizontalLayout_14->addWidget(listWidget);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_10);

        splitter2->addWidget(layoutWidget2);
        splitter3->addWidget(splitter2);
        splitter4->addWidget(splitter3);
        frame = new QFrame(splitter4);
        frame->setObjectName("frame");
        frame->setMaximumSize(QSize(16777215, 16777215));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        splitter4->addWidget(frame);

        verticalLayout_2->addWidget(splitter4);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1248, 17));
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName("menuMenu");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuMenu->menuAction());
        toolBar->addAction(actionSave);
        toolBar->addSeparator();
        toolBar->addAction(actionUndo);
        toolBar->addSeparator();
        toolBar->addAction(actionRedo);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "\354\240\200\354\236\245", nullptr));
        actionRedo->setText(QCoreApplication::translate("MainWindow", "Redo", nullptr));
        actionUndo->setText(QCoreApplication::translate("MainWindow", "Undo", nullptr));
        doctorNameLineEdit->setText(QCoreApplication::translate("MainWindow", "Doctor.", nullptr));
        brushGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Brush", nullptr));
        cursorToolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        brushToolButton->setText(QCoreApplication::translate("MainWindow", "Brush", nullptr));
        figureGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Figure", nullptr));
        circleToolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        triangleToolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        rectangleToolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        arrowToolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        linetoolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        colorGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Color & Size", nullptr));
        colorToolButton->setText(QCoreApplication::translate("MainWindow", "Color", nullptr));
        drawClearPushButton->setText(QCoreApplication::translate("MainWindow", "Draw Clear", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(painterTab), QCoreApplication::translate("MainWindow", "Painter", nullptr));
        imageGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Image", nullptr));
        brightToolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        brightnessToolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        sharpenToolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        contrastToolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        verticalFlipToolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        horizontalFlipToolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        zoomInToolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        zoomOutToolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        panningToolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        leftRotateToolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        rightRotateToolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        imageSizeClearPushButton->setText(QCoreApplication::translate("MainWindow", "Source\n"
"Size", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(processingTab), QCoreApplication::translate("MainWindow", "Processing", nullptr));
        measureGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Measure", nullptr));
        rulerToolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        measureToolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        protractorToolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        implantGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Implant", nullptr));
        implantToolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        implantToolButton_2->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(measueTab), QCoreApplication::translate("MainWindow", "Measure", nullptr));
        initializationGroupBox->setTitle(QCoreApplication::translate("MainWindow", "\354\264\210\352\270\260\355\231\224", nullptr));
        layoutClearPushButton->setText(QCoreApplication::translate("MainWindow", "Layout Clear", nullptr));
        menuMenu->setTitle(QCoreApplication::translate("MainWindow", "Menu", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
