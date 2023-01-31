/********************************************************************************
** Form generated from reading UI file 'keyfeaturesform.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KEYFEATURESFORM_H
#define UI_KEYFEATURESFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_KeyFeaturesForm
{
public:
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *savePushButton;
    QSpacerItem *horizontalSpacer;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QCheckBox *zoomInCheckBox;
    QCheckBox *zoomOutCheckBox;
    QCheckBox *leftRotateCheckBox;
    QCheckBox *rightRotateCheckBox;
    QCheckBox *brushCheckBox;
    QCheckBox *rectangleCheckBox;
    QCheckBox *triangleCheckBox;
    QCheckBox *ellipseCheckBox;
    QCheckBox *moveShapeCheckBox;
    QCheckBox *blendingCheckBox;
    QCheckBox *lengthMeasurementCheckBox;
    QCheckBox *angleMeasurementCheckBox;
    QCheckBox *brightnessCheckBox;
    QCheckBox *darknessCheckBox;
    QCheckBox *sharpenCheckBox;
    QCheckBox *contrastCheckBox;
    QCheckBox *inversionCheckBox;
    QCheckBox *horizontalFlipCheckBox;
    QCheckBox *verticalFlipCheckBox;
    QCheckBox *implantCheckBox;
    QTableView *tableView;

    void setupUi(QWidget *KeyFeaturesForm)
    {
        if (KeyFeaturesForm->objectName().isEmpty())
            KeyFeaturesForm->setObjectName("KeyFeaturesForm");
        KeyFeaturesForm->resize(260, 523);
        verticalLayout_4 = new QVBoxLayout(KeyFeaturesForm);
        verticalLayout_4->setObjectName("verticalLayout_4");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalSpacer = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        label = new QLabel(KeyFeaturesForm);
        label->setObjectName("label");
        label->setMaximumSize(QSize(16777215, 50));
        QFont font;
        font.setFamilies({QString::fromUtf8("Tmon\353\252\254\354\206\214\353\246\254 Black")});
        font.setPointSize(20);
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("QLabel {color: rgb(180, 199, 231)};\n"
""));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        verticalSpacer_2 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        verticalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer_2 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        savePushButton = new QPushButton(KeyFeaturesForm);
        savePushButton->setObjectName("savePushButton");
        savePushButton->setStyleSheet(QString::fromUtf8("QPushButton {background-color: rgb(170, 255, 255)};\n"
"\n"
""));

        horizontalLayout->addWidget(savePushButton);

        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_3->addLayout(horizontalLayout);

        widget = new QWidget(KeyFeaturesForm);
        widget->setObjectName("widget");
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        zoomInCheckBox = new QCheckBox(widget);
        zoomInCheckBox->setObjectName("zoomInCheckBox");
        zoomInCheckBox->setStyleSheet(QString::fromUtf8("QCheckBox {color: rgb(255, 255, 255);}\n"
""));

        verticalLayout->addWidget(zoomInCheckBox);

        zoomOutCheckBox = new QCheckBox(widget);
        zoomOutCheckBox->setObjectName("zoomOutCheckBox");
        zoomOutCheckBox->setStyleSheet(QString::fromUtf8("QCheckBox {color: rgb(255, 255, 255);}"));

        verticalLayout->addWidget(zoomOutCheckBox);

        leftRotateCheckBox = new QCheckBox(widget);
        leftRotateCheckBox->setObjectName("leftRotateCheckBox");
        leftRotateCheckBox->setStyleSheet(QString::fromUtf8("QCheckBox {color: rgb(255, 255, 255);}"));

        verticalLayout->addWidget(leftRotateCheckBox);

        rightRotateCheckBox = new QCheckBox(widget);
        rightRotateCheckBox->setObjectName("rightRotateCheckBox");
        rightRotateCheckBox->setStyleSheet(QString::fromUtf8("QCheckBox {color: rgb(255, 255, 255);}"));

        verticalLayout->addWidget(rightRotateCheckBox);

        brushCheckBox = new QCheckBox(widget);
        brushCheckBox->setObjectName("brushCheckBox");
        brushCheckBox->setStyleSheet(QString::fromUtf8("QCheckBox {color: rgb(255, 255, 255);}"));

        verticalLayout->addWidget(brushCheckBox);

        rectangleCheckBox = new QCheckBox(widget);
        rectangleCheckBox->setObjectName("rectangleCheckBox");
        rectangleCheckBox->setStyleSheet(QString::fromUtf8("QCheckBox {color: rgb(255, 255, 255);}"));

        verticalLayout->addWidget(rectangleCheckBox);

        triangleCheckBox = new QCheckBox(widget);
        triangleCheckBox->setObjectName("triangleCheckBox");
        triangleCheckBox->setStyleSheet(QString::fromUtf8("QCheckBox {color: rgb(255, 255, 255);}"));

        verticalLayout->addWidget(triangleCheckBox);

        ellipseCheckBox = new QCheckBox(widget);
        ellipseCheckBox->setObjectName("ellipseCheckBox");
        ellipseCheckBox->setStyleSheet(QString::fromUtf8("QCheckBox {color: rgb(255, 255, 255);}"));

        verticalLayout->addWidget(ellipseCheckBox);

        moveShapeCheckBox = new QCheckBox(widget);
        moveShapeCheckBox->setObjectName("moveShapeCheckBox");
        moveShapeCheckBox->setStyleSheet(QString::fromUtf8("QCheckBox {color: rgb(255, 255, 255);}"));

        verticalLayout->addWidget(moveShapeCheckBox);

        blendingCheckBox = new QCheckBox(widget);
        blendingCheckBox->setObjectName("blendingCheckBox");
        blendingCheckBox->setStyleSheet(QString::fromUtf8("QCheckBox {color: rgb(255, 255, 255);}"));

        verticalLayout->addWidget(blendingCheckBox);

        lengthMeasurementCheckBox = new QCheckBox(widget);
        lengthMeasurementCheckBox->setObjectName("lengthMeasurementCheckBox");
        lengthMeasurementCheckBox->setStyleSheet(QString::fromUtf8("QCheckBox {color: rgb(255, 255, 255);}"));

        verticalLayout->addWidget(lengthMeasurementCheckBox);

        angleMeasurementCheckBox = new QCheckBox(widget);
        angleMeasurementCheckBox->setObjectName("angleMeasurementCheckBox");
        angleMeasurementCheckBox->setStyleSheet(QString::fromUtf8("QCheckBox {color: rgb(255, 255, 255);}"));

        verticalLayout->addWidget(angleMeasurementCheckBox);

        brightnessCheckBox = new QCheckBox(widget);
        brightnessCheckBox->setObjectName("brightnessCheckBox");
        brightnessCheckBox->setStyleSheet(QString::fromUtf8("QCheckBox {color: rgb(255, 255, 255);}"));

        verticalLayout->addWidget(brightnessCheckBox);

        darknessCheckBox = new QCheckBox(widget);
        darknessCheckBox->setObjectName("darknessCheckBox");
        darknessCheckBox->setStyleSheet(QString::fromUtf8("QCheckBox {color: rgb(255, 255, 255);}"));

        verticalLayout->addWidget(darknessCheckBox);

        sharpenCheckBox = new QCheckBox(widget);
        sharpenCheckBox->setObjectName("sharpenCheckBox");
        sharpenCheckBox->setStyleSheet(QString::fromUtf8("QCheckBox {color: rgb(255, 255, 255);}"));

        verticalLayout->addWidget(sharpenCheckBox);

        contrastCheckBox = new QCheckBox(widget);
        contrastCheckBox->setObjectName("contrastCheckBox");
        contrastCheckBox->setStyleSheet(QString::fromUtf8("QCheckBox {color: rgb(255, 255, 255);}"));

        verticalLayout->addWidget(contrastCheckBox);

        inversionCheckBox = new QCheckBox(widget);
        inversionCheckBox->setObjectName("inversionCheckBox");
        inversionCheckBox->setStyleSheet(QString::fromUtf8("QCheckBox {color: rgb(255, 255, 255);}"));

        verticalLayout->addWidget(inversionCheckBox);

        horizontalFlipCheckBox = new QCheckBox(widget);
        horizontalFlipCheckBox->setObjectName("horizontalFlipCheckBox");
        horizontalFlipCheckBox->setStyleSheet(QString::fromUtf8("QCheckBox {color: rgb(255, 255, 255);}"));

        verticalLayout->addWidget(horizontalFlipCheckBox);

        verticalFlipCheckBox = new QCheckBox(widget);
        verticalFlipCheckBox->setObjectName("verticalFlipCheckBox");
        verticalFlipCheckBox->setStyleSheet(QString::fromUtf8("QCheckBox {color: rgb(255, 255, 255);}"));

        verticalLayout->addWidget(verticalFlipCheckBox);

        implantCheckBox = new QCheckBox(widget);
        implantCheckBox->setObjectName("implantCheckBox");
        implantCheckBox->setStyleSheet(QString::fromUtf8("QCheckBox {color: rgb(255, 255, 255);}"));

        verticalLayout->addWidget(implantCheckBox);


        verticalLayout_3->addWidget(widget);


        horizontalLayout_2->addLayout(verticalLayout_3);

        tableView = new QTableView(KeyFeaturesForm);
        tableView->setObjectName("tableView");

        horizontalLayout_2->addWidget(tableView);


        verticalLayout_4->addLayout(horizontalLayout_2);


        retranslateUi(KeyFeaturesForm);

        QMetaObject::connectSlotsByName(KeyFeaturesForm);
    } // setupUi

    void retranslateUi(QWidget *KeyFeaturesForm)
    {
        KeyFeaturesForm->setWindowTitle(QCoreApplication::translate("KeyFeaturesForm", "Form", nullptr));
        label->setText(QCoreApplication::translate("KeyFeaturesForm", "Key Features", nullptr));
        savePushButton->setText(QCoreApplication::translate("KeyFeaturesForm", "Save", nullptr));
        zoomInCheckBox->setText(QCoreApplication::translate("KeyFeaturesForm", "Zoom In", nullptr));
        zoomOutCheckBox->setText(QCoreApplication::translate("KeyFeaturesForm", "Zoom Out", nullptr));
        leftRotateCheckBox->setText(QCoreApplication::translate("KeyFeaturesForm", "90\302\260 Rotate", nullptr));
        rightRotateCheckBox->setText(QCoreApplication::translate("KeyFeaturesForm", "-90\302\260 Rotate", nullptr));
        brushCheckBox->setText(QCoreApplication::translate("KeyFeaturesForm", "Brush", nullptr));
        rectangleCheckBox->setText(QCoreApplication::translate("KeyFeaturesForm", "Rectangle", nullptr));
        triangleCheckBox->setText(QCoreApplication::translate("KeyFeaturesForm", "Triangle", nullptr));
        ellipseCheckBox->setText(QCoreApplication::translate("KeyFeaturesForm", "Ellipse", nullptr));
        moveShapeCheckBox->setText(QCoreApplication::translate("KeyFeaturesForm", "Move Shape", nullptr));
        blendingCheckBox->setText(QCoreApplication::translate("KeyFeaturesForm", "Blending", nullptr));
        lengthMeasurementCheckBox->setText(QCoreApplication::translate("KeyFeaturesForm", "Length Measurement", nullptr));
        angleMeasurementCheckBox->setText(QCoreApplication::translate("KeyFeaturesForm", "Angle Measurement", nullptr));
        brightnessCheckBox->setText(QCoreApplication::translate("KeyFeaturesForm", "Brightness", nullptr));
        darknessCheckBox->setText(QCoreApplication::translate("KeyFeaturesForm", "Darkness", nullptr));
        sharpenCheckBox->setText(QCoreApplication::translate("KeyFeaturesForm", "Sharpen", nullptr));
        contrastCheckBox->setText(QCoreApplication::translate("KeyFeaturesForm", "Contrast", nullptr));
        inversionCheckBox->setText(QCoreApplication::translate("KeyFeaturesForm", "Inversion", nullptr));
        horizontalFlipCheckBox->setText(QCoreApplication::translate("KeyFeaturesForm", "Horizontal Flip", nullptr));
        verticalFlipCheckBox->setText(QCoreApplication::translate("KeyFeaturesForm", "Vertical Flip", nullptr));
        implantCheckBox->setText(QCoreApplication::translate("KeyFeaturesForm", "Implant", nullptr));
    } // retranslateUi

};

namespace Ui {
    class KeyFeaturesForm: public Ui_KeyFeaturesForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KEYFEATURESFORM_H
