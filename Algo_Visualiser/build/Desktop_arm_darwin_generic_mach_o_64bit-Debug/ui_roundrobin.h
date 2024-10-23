/********************************************************************************
** Form generated from reading UI file 'roundrobin.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROUNDROBIN_H
#define UI_ROUNDROBIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Roundrobin
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *explain;
    QPushButton *visualise;
    QPushButton *closebtn;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QLineEdit *line3;
    QPushButton *insert;
    QLineEdit *line1;
    QPushButton *start;
    QPushButton *reset;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *fcfsbtn;
    QPushButton *leakybtn;
    QPushButton *tokenbtn;
    QPushButton *robinbtn;
    QPushButton *wrrobinbtn;

    void setupUi(QMainWindow *Roundrobin)
    {
        if (Roundrobin->objectName().isEmpty())
            Roundrobin->setObjectName("Roundrobin");
        Roundrobin->resize(1358, 862);
        Roundrobin->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        centralwidget = new QWidget(Roundrobin);
        centralwidget->setObjectName("centralwidget");
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 20, 431, 51));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        explain = new QPushButton(layoutWidget);
        explain->setObjectName("explain");
        explain->setMinimumSize(QSize(0, 2));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        explain->setFont(font);
        explain->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 123, 255);"));

        horizontalLayout->addWidget(explain);

        visualise = new QPushButton(layoutWidget);
        visualise->setObjectName("visualise");
        visualise->setFont(font);
        visualise->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 123, 255);"));

        horizontalLayout->addWidget(visualise);

        closebtn = new QPushButton(layoutWidget);
        closebtn->setObjectName("closebtn");
        closebtn->setFont(font);
        closebtn->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 123, 255);"));

        horizontalLayout->addWidget(closebtn);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(950, 80, 181, 221));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        line3 = new QLineEdit(layoutWidget1);
        line3->setObjectName("line3");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(line3->sizePolicy().hasHeightForWidth());
        line3->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(17);
        font1.setBold(false);
        line3->setFont(font1);
        line3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(205, 208, 208);"));

        verticalLayout->addWidget(line3);

        insert = new QPushButton(layoutWidget1);
        insert->setObjectName("insert");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(insert->sizePolicy().hasHeightForWidth());
        insert->setSizePolicy(sizePolicy1);
        insert->setMinimumSize(QSize(0, 0));
        QFont font2;
        font2.setPointSize(22);
        font2.setBold(true);
        insert->setFont(font2);
        insert->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 123, 255);"));

        verticalLayout->addWidget(insert);

        line1 = new QLineEdit(layoutWidget1);
        line1->setObjectName("line1");
        sizePolicy.setHeightForWidth(line1->sizePolicy().hasHeightForWidth());
        line1->setSizePolicy(sizePolicy);
        line1->setFont(font1);
        line1->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(205, 208, 208);"));

        verticalLayout->addWidget(line1);

        start = new QPushButton(layoutWidget1);
        start->setObjectName("start");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(start->sizePolicy().hasHeightForWidth());
        start->setSizePolicy(sizePolicy2);
        start->setMinimumSize(QSize(0, 0));
        start->setFont(font2);
        start->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 123, 255);"));

        verticalLayout->addWidget(start);

        reset = new QPushButton(layoutWidget1);
        reset->setObjectName("reset");
        sizePolicy2.setHeightForWidth(reset->sizePolicy().hasHeightForWidth());
        reset->setSizePolicy(sizePolicy2);
        reset->setMinimumSize(QSize(0, 0));
        reset->setBaseSize(QSize(0, 0));
        reset->setFont(font2);
        reset->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 123, 255);"));

        verticalLayout->addWidget(reset);

        layoutWidget_2 = new QWidget(centralwidget);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(1270, 480, 168, 181));
        verticalLayout_2 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        fcfsbtn = new QPushButton(layoutWidget_2);
        fcfsbtn->setObjectName("fcfsbtn");
        sizePolicy1.setHeightForWidth(fcfsbtn->sizePolicy().hasHeightForWidth());
        fcfsbtn->setSizePolicy(sizePolicy1);
        fcfsbtn->setMinimumSize(QSize(0, 6));
        QFont font3;
        font3.setPointSize(16);
        font3.setBold(true);
        fcfsbtn->setFont(font3);
        fcfsbtn->setStyleSheet(QString::fromUtf8("color: rgb(97, 131, 255);\n"
"background-color: rgb(177, 179, 179);"));

        verticalLayout_2->addWidget(fcfsbtn);

        leakybtn = new QPushButton(layoutWidget_2);
        leakybtn->setObjectName("leakybtn");
        sizePolicy1.setHeightForWidth(leakybtn->sizePolicy().hasHeightForWidth());
        leakybtn->setSizePolicy(sizePolicy1);
        leakybtn->setMinimumSize(QSize(0, 6));
        leakybtn->setFont(font3);
        leakybtn->setStyleSheet(QString::fromUtf8("color: rgb(97, 131, 255);\n"
"background-color: rgb(177, 179, 179);"));

        verticalLayout_2->addWidget(leakybtn);

        tokenbtn = new QPushButton(layoutWidget_2);
        tokenbtn->setObjectName("tokenbtn");
        sizePolicy1.setHeightForWidth(tokenbtn->sizePolicy().hasHeightForWidth());
        tokenbtn->setSizePolicy(sizePolicy1);
        tokenbtn->setMinimumSize(QSize(0, 6));
        tokenbtn->setFont(font3);
        tokenbtn->setStyleSheet(QString::fromUtf8("color: rgb(97, 131, 255);\n"
"background-color: rgb(177, 179, 179);"));

        verticalLayout_2->addWidget(tokenbtn);

        robinbtn = new QPushButton(layoutWidget_2);
        robinbtn->setObjectName("robinbtn");
        sizePolicy1.setHeightForWidth(robinbtn->sizePolicy().hasHeightForWidth());
        robinbtn->setSizePolicy(sizePolicy1);
        robinbtn->setMinimumSize(QSize(0, 6));
        robinbtn->setFont(font3);
        robinbtn->setStyleSheet(QString::fromUtf8("color: rgb(97, 131, 255);\n"
"background-color: rgb(0, 249, 0);"));

        verticalLayout_2->addWidget(robinbtn);

        wrrobinbtn = new QPushButton(layoutWidget_2);
        wrrobinbtn->setObjectName("wrrobinbtn");
        sizePolicy1.setHeightForWidth(wrrobinbtn->sizePolicy().hasHeightForWidth());
        wrrobinbtn->setSizePolicy(sizePolicy1);
        wrrobinbtn->setMinimumSize(QSize(0, 6));
        wrrobinbtn->setFont(font3);
        wrrobinbtn->setStyleSheet(QString::fromUtf8("color: rgb(97, 131, 255);\n"
"background-color: rgb(177, 179, 179);"));

        verticalLayout_2->addWidget(wrrobinbtn);

        Roundrobin->setCentralWidget(centralwidget);

        retranslateUi(Roundrobin);
        QObject::connect(closebtn, &QPushButton::clicked, Roundrobin, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(Roundrobin);
    } // setupUi

    void retranslateUi(QMainWindow *Roundrobin)
    {
        Roundrobin->setWindowTitle(QCoreApplication::translate("Roundrobin", "MainWindow", nullptr));
        explain->setText(QCoreApplication::translate("Roundrobin", "Explaination", nullptr));
        visualise->setText(QCoreApplication::translate("Roundrobin", "Visualisation", nullptr));
        closebtn->setText(QCoreApplication::translate("Roundrobin", "Close", nullptr));
        line3->setPlaceholderText(QCoreApplication::translate("Roundrobin", "No. of packets", nullptr));
        insert->setText(QCoreApplication::translate("Roundrobin", "Insert Packets", nullptr));
        line1->setPlaceholderText(QCoreApplication::translate("Roundrobin", "Packet Quanta", nullptr));
        start->setText(QCoreApplication::translate("Roundrobin", "First Time Seq.", nullptr));
        reset->setText(QCoreApplication::translate("Roundrobin", "Reset", nullptr));
        fcfsbtn->setText(QCoreApplication::translate("Roundrobin", "FCFS", nullptr));
        leakybtn->setText(QCoreApplication::translate("Roundrobin", "Leaky Buket", nullptr));
        tokenbtn->setText(QCoreApplication::translate("Roundrobin", "Token Bucket", nullptr));
        robinbtn->setText(QCoreApplication::translate("Roundrobin", "Round Robin", nullptr));
        wrrobinbtn->setText(QCoreApplication::translate("Roundrobin", "Weighted R. Robin", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Roundrobin: public Ui_Roundrobin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROUNDROBIN_H
