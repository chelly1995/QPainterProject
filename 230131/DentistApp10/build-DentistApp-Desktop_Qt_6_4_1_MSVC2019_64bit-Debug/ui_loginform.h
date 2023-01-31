/********************************************************************************
** Form generated from reading UI file 'loginform.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINFORM_H
#define UI_LOGINFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginForm
{
public:
    QVBoxLayout *verticalLayout_5;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *page1;
    QVBoxLayout *verticalLayout_4;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *topVerticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *leftHorizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLineEdit *idLineEdit;
    QLineEdit *passwordLineEdit;
    QToolButton *loginToolButton;
    QSpacerItem *rightHorizontalSpacer;
    QSpacerItem *buttonVerticalSpacer;
    QVBoxLayout *verticalLayout_3;

    void setupUi(QWidget *LoginForm)
    {
        if (LoginForm->objectName().isEmpty())
            LoginForm->setObjectName("LoginForm");
        LoginForm->resize(1248, 681);
        verticalLayout_5 = new QVBoxLayout(LoginForm);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(LoginForm);
        stackedWidget->setObjectName("stackedWidget");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy);
        stackedWidget->setAutoFillBackground(true);
        page = new QWidget();
        page->setObjectName("page");
        stackedWidget->addWidget(page);
        page1 = new QWidget();
        page1->setObjectName("page1");
        page1->setAutoFillBackground(false);
        verticalLayout_4 = new QVBoxLayout(page1);
        verticalLayout_4->setObjectName("verticalLayout_4");
        splitter = new QSplitter(page1);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName("layoutWidget");
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(108, 14, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        label = new QLabel(layoutWidget);
        label->setObjectName("label");
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(2);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(200, 200));
        label->setSizeIncrement(QSize(0, 0));
        label->setBaseSize(QSize(8, 0));
        label->setMidLineWidth(-5);

        horizontalLayout_3->addWidget(label);

        splitter->addWidget(layoutWidget);
        layoutWidget1 = new QWidget(splitter);
        layoutWidget1->setObjectName("layoutWidget1");
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        topVerticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(topVerticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        leftHorizontalSpacer = new QSpacerItem(96, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(leftHorizontalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        idLineEdit = new QLineEdit(layoutWidget1);
        idLineEdit->setObjectName("idLineEdit");

        verticalLayout->addWidget(idLineEdit);

        passwordLineEdit = new QLineEdit(layoutWidget1);
        passwordLineEdit->setObjectName("passwordLineEdit");
        passwordLineEdit->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(passwordLineEdit);


        horizontalLayout->addLayout(verticalLayout);

        loginToolButton = new QToolButton(layoutWidget1);
        loginToolButton->setObjectName("loginToolButton");

        horizontalLayout->addWidget(loginToolButton);


        horizontalLayout_2->addLayout(horizontalLayout);

        rightHorizontalSpacer = new QSpacerItem(68, 118, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(rightHorizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_2);

        buttonVerticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(buttonVerticalSpacer);

        splitter->addWidget(layoutWidget1);

        verticalLayout_4->addWidget(splitter);

        stackedWidget->addWidget(page1);

        verticalLayout_5->addWidget(stackedWidget);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");

        verticalLayout_5->addLayout(verticalLayout_3);


        retranslateUi(LoginForm);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(LoginForm);
    } // setupUi

    void retranslateUi(QWidget *LoginForm)
    {
        LoginForm->setWindowTitle(QCoreApplication::translate("LoginForm", "Form", nullptr));
        label->setText(QCoreApplication::translate("LoginForm", "\354\230\244\354\212\244\355\205\234 \353\241\234\352\263\240", nullptr));
        loginToolButton->setText(QCoreApplication::translate("LoginForm", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginForm: public Ui_LoginForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINFORM_H
