/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *closebtn;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *fcfsbtn;
    QPushButton *leakybtn;
    QPushButton *tokenbtn;
    QPushButton *robinbtn;
    QPushButton *wrrobinbtn;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1354, 862);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        closebtn = new QPushButton(centralwidget);
        closebtn->setObjectName("closebtn");
        closebtn->setGeometry(QRect(1270, 620, 151, 51));
        QFont font;
        font.setPointSize(17);
        font.setBold(true);
        closebtn->setFont(font);
        closebtn->setStyleSheet(QString::fromUtf8("color: rgb(97, 131, 255);\n"
"background-color: rgb(177, 179, 179);"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(1270, 440, 168, 181));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        fcfsbtn = new QPushButton(layoutWidget);
        fcfsbtn->setObjectName("fcfsbtn");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(fcfsbtn->sizePolicy().hasHeightForWidth());
        fcfsbtn->setSizePolicy(sizePolicy);
        fcfsbtn->setMinimumSize(QSize(0, 6));
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(true);
        fcfsbtn->setFont(font1);
        fcfsbtn->setStyleSheet(QString::fromUtf8("color: rgb(97, 131, 255);\n"
"background-color: rgb(177, 179, 179);"));

        verticalLayout->addWidget(fcfsbtn);

        leakybtn = new QPushButton(layoutWidget);
        leakybtn->setObjectName("leakybtn");
        sizePolicy.setHeightForWidth(leakybtn->sizePolicy().hasHeightForWidth());
        leakybtn->setSizePolicy(sizePolicy);
        leakybtn->setMinimumSize(QSize(0, 6));
        leakybtn->setFont(font1);
        leakybtn->setStyleSheet(QString::fromUtf8("color: rgb(97, 131, 255);\n"
"background-color: rgb(177, 179, 179);"));

        verticalLayout->addWidget(leakybtn);

        tokenbtn = new QPushButton(layoutWidget);
        tokenbtn->setObjectName("tokenbtn");
        sizePolicy.setHeightForWidth(tokenbtn->sizePolicy().hasHeightForWidth());
        tokenbtn->setSizePolicy(sizePolicy);
        tokenbtn->setMinimumSize(QSize(0, 6));
        tokenbtn->setFont(font1);
        tokenbtn->setStyleSheet(QString::fromUtf8("color: rgb(97, 131, 255);\n"
"background-color: rgb(177, 179, 179);"));

        verticalLayout->addWidget(tokenbtn);

        robinbtn = new QPushButton(layoutWidget);
        robinbtn->setObjectName("robinbtn");
        sizePolicy.setHeightForWidth(robinbtn->sizePolicy().hasHeightForWidth());
        robinbtn->setSizePolicy(sizePolicy);
        robinbtn->setMinimumSize(QSize(0, 6));
        robinbtn->setFont(font1);
        robinbtn->setStyleSheet(QString::fromUtf8("color: rgb(97, 131, 255);\n"
"background-color: rgb(177, 179, 179);"));

        verticalLayout->addWidget(robinbtn);

        wrrobinbtn = new QPushButton(layoutWidget);
        wrrobinbtn->setObjectName("wrrobinbtn");
        sizePolicy.setHeightForWidth(wrrobinbtn->sizePolicy().hasHeightForWidth());
        wrrobinbtn->setSizePolicy(sizePolicy);
        wrrobinbtn->setMinimumSize(QSize(0, 6));
        wrrobinbtn->setFont(font1);
        wrrobinbtn->setStyleSheet(QString::fromUtf8("color: rgb(97, 131, 255);\n"
"background-color: rgb(177, 179, 179);"));

        verticalLayout->addWidget(wrrobinbtn);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);
        QObject::connect(closebtn, &QPushButton::clicked, MainWindow, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        closebtn->setText(QCoreApplication::translate("MainWindow", "Close", nullptr));
        fcfsbtn->setText(QCoreApplication::translate("MainWindow", "FCFS", nullptr));
        leakybtn->setText(QCoreApplication::translate("MainWindow", "Leaky Buket", nullptr));
        tokenbtn->setText(QCoreApplication::translate("MainWindow", "Token Bucket", nullptr));
        robinbtn->setText(QCoreApplication::translate("MainWindow", "Round Robin", nullptr));
        wrrobinbtn->setText(QCoreApplication::translate("MainWindow", "Weighted R. Robin", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
