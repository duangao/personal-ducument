/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *showLabel;
    QPushButton *pushButton0;
    QPushButton *clear;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton7;
    QPushButton *pushButton8;
    QPushButton *pushButton9;
    QPushButton *pushButtonA;
    QPushButton *pushButtonD;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton4;
    QPushButton *pushButton5;
    QPushButton *pushButton6;
    QPushButton *pushButtonB;
    QPushButton *pushButtonE;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton1;
    QPushButton *pushButton2;
    QPushButton *pushButton3;
    QPushButton *pushButtonC;
    QPushButton *pushButtonF;
    QWidget *widget1;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(635, 354);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QStringLiteral("Consolas"));
        font.setPointSize(10);
        font.setStyleStrategy(QFont::PreferAntialias);
        MainWindow->setFont(font);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        showLabel = new QLabel(centralWidget);
        showLabel->setObjectName(QStringLiteral("showLabel"));
        showLabel->setGeometry(QRect(20, 20, 591, 41));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(showLabel->sizePolicy().hasHeightForWidth());
        showLabel->setSizePolicy(sizePolicy1);
        showLabel->setFrameShape(QFrame::StyledPanel);
        showLabel->setFrameShadow(QFrame::Sunken);
        showLabel->setLineWidth(18);
        showLabel->setMidLineWidth(4);
        showLabel->setScaledContents(false);
        showLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pushButton0 = new QPushButton(centralWidget);
        pushButton0->setObjectName(QStringLiteral("pushButton0"));
        pushButton0->setGeometry(QRect(10, 260, 71, 21));
        sizePolicy1.setHeightForWidth(pushButton0->sizePolicy().hasHeightForWidth());
        pushButton0->setSizePolicy(sizePolicy1);
        clear = new QPushButton(centralWidget);
        clear->setObjectName(QStringLiteral("clear"));
        clear->setGeometry(QRect(550, 70, 71, 51));
        sizePolicy1.setHeightForWidth(clear->sizePolicy().hasHeightForWidth());
        clear->setSizePolicy(sizePolicy1);
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 70, 405, 181));
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton7 = new QPushButton(widget);
        pushButton7->setObjectName(QStringLiteral("pushButton7"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton7->sizePolicy().hasHeightForWidth());
        pushButton7->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(pushButton7);

        pushButton8 = new QPushButton(widget);
        pushButton8->setObjectName(QStringLiteral("pushButton8"));
        sizePolicy.setHeightForWidth(pushButton8->sizePolicy().hasHeightForWidth());
        pushButton8->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(pushButton8);

        pushButton9 = new QPushButton(widget);
        pushButton9->setObjectName(QStringLiteral("pushButton9"));
        sizePolicy.setHeightForWidth(pushButton9->sizePolicy().hasHeightForWidth());
        pushButton9->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(pushButton9);

        pushButtonA = new QPushButton(widget);
        pushButtonA->setObjectName(QStringLiteral("pushButtonA"));
        sizePolicy.setHeightForWidth(pushButtonA->sizePolicy().hasHeightForWidth());
        pushButtonA->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(pushButtonA);

        pushButtonD = new QPushButton(widget);
        pushButtonD->setObjectName(QStringLiteral("pushButtonD"));
        sizePolicy.setHeightForWidth(pushButtonD->sizePolicy().hasHeightForWidth());
        pushButtonD->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(pushButtonD);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton4 = new QPushButton(widget);
        pushButton4->setObjectName(QStringLiteral("pushButton4"));
        sizePolicy.setHeightForWidth(pushButton4->sizePolicy().hasHeightForWidth());
        pushButton4->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(pushButton4);

        pushButton5 = new QPushButton(widget);
        pushButton5->setObjectName(QStringLiteral("pushButton5"));
        sizePolicy.setHeightForWidth(pushButton5->sizePolicy().hasHeightForWidth());
        pushButton5->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(pushButton5);

        pushButton6 = new QPushButton(widget);
        pushButton6->setObjectName(QStringLiteral("pushButton6"));
        sizePolicy.setHeightForWidth(pushButton6->sizePolicy().hasHeightForWidth());
        pushButton6->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(pushButton6);

        pushButtonB = new QPushButton(widget);
        pushButtonB->setObjectName(QStringLiteral("pushButtonB"));
        sizePolicy.setHeightForWidth(pushButtonB->sizePolicy().hasHeightForWidth());
        pushButtonB->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(pushButtonB);

        pushButtonE = new QPushButton(widget);
        pushButtonE->setObjectName(QStringLiteral("pushButtonE"));
        sizePolicy.setHeightForWidth(pushButtonE->sizePolicy().hasHeightForWidth());
        pushButtonE->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(pushButtonE);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButton1 = new QPushButton(widget);
        pushButton1->setObjectName(QStringLiteral("pushButton1"));

        horizontalLayout_3->addWidget(pushButton1);

        pushButton2 = new QPushButton(widget);
        pushButton2->setObjectName(QStringLiteral("pushButton2"));

        horizontalLayout_3->addWidget(pushButton2);

        pushButton3 = new QPushButton(widget);
        pushButton3->setObjectName(QStringLiteral("pushButton3"));

        horizontalLayout_3->addWidget(pushButton3);

        pushButtonC = new QPushButton(widget);
        pushButtonC->setObjectName(QStringLiteral("pushButtonC"));

        horizontalLayout_3->addWidget(pushButtonC);


        horizontalLayout_4->addLayout(horizontalLayout_3);

        pushButtonF = new QPushButton(widget);
        pushButtonF->setObjectName(QStringLiteral("pushButtonF"));

        horizontalLayout_4->addWidget(pushButtonF);


        verticalLayout_2->addLayout(horizontalLayout_4);

        widget1 = new QWidget(centralWidget);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(440, 70, 98, 181));
        sizePolicy1.setHeightForWidth(widget1->sizePolicy().hasHeightForWidth());
        widget1->setSizePolicy(sizePolicy1);
        verticalLayout = new QVBoxLayout(widget1);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_1 = new QPushButton(widget1);
        pushButton_1->setObjectName(QStringLiteral("pushButton_1"));

        verticalLayout->addWidget(pushButton_1);

        pushButton_2 = new QPushButton(widget1);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(widget1);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(widget1);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        verticalLayout->addWidget(pushButton_4);

        MainWindow->setCentralWidget(centralWidget);
        showLabel->raise();
        pushButton7->raise();
        pushButton8->raise();
        pushButton9->raise();
        pushButton4->raise();
        pushButton5->raise();
        pushButton6->raise();
        pushButton1->raise();
        pushButton2->raise();
        pushButton3->raise();
        pushButtonA->raise();
        pushButtonB->raise();
        pushButtonC->raise();
        pushButtonD->raise();
        pushButtonE->raise();
        pushButtonF->raise();
        pushButton_1->raise();
        pushButton_2->raise();
        pushButton_3->raise();
        pushButton_4->raise();
        pushButton0->raise();
        clear->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 635, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        showLabel->setText(QApplication::translate("MainWindow", "0", 0));
        pushButton0->setText(QApplication::translate("MainWindow", "0", 0));
        clear->setText(QApplication::translate("MainWindow", "Clear", 0));
        pushButton7->setText(QApplication::translate("MainWindow", "7", 0));
        pushButton8->setText(QApplication::translate("MainWindow", "8", 0));
        pushButton9->setText(QApplication::translate("MainWindow", "9", 0));
        pushButtonA->setText(QApplication::translate("MainWindow", "A", 0));
        pushButtonD->setText(QApplication::translate("MainWindow", "D", 0));
        pushButton4->setText(QApplication::translate("MainWindow", "4", 0));
        pushButton5->setText(QApplication::translate("MainWindow", "5", 0));
        pushButton6->setText(QApplication::translate("MainWindow", "6", 0));
        pushButtonB->setText(QApplication::translate("MainWindow", "B", 0));
        pushButtonE->setText(QApplication::translate("MainWindow", "E", 0));
        pushButton1->setText(QApplication::translate("MainWindow", "1", 0));
        pushButton2->setText(QApplication::translate("MainWindow", "2", 0));
        pushButton3->setText(QApplication::translate("MainWindow", "3", 0));
        pushButtonC->setText(QApplication::translate("MainWindow", "C", 0));
        pushButtonF->setText(QApplication::translate("MainWindow", "F", 0));
        pushButton_1->setText(QApplication::translate("MainWindow", "Binary", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Decimal", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "Octal", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "Hexadecimal", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
