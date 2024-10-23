/********************************************************************************
** Form generated from reading UI file 'fcfs.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FCFS_H
#define UI_FCFS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Fcfs
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *explain;
    QPushButton *visualise;
    QPushButton *closebtn;
    QPushButton *timeseq;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *packetsv;
    QPushButton *insert;
    QPushButton *reset;
    QWidget *layoutWidget_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *buffertime;
    QLineEdit *numoftimesq;
    QPushButton *rateset;
    QWidget *layoutWidget_4;
    QVBoxLayout *verticalLayout_3;
    QPushButton *fcfsbtn;
    QPushButton *leakybtn;
    QPushButton *tokenbtn;
    QPushButton *robinbtn;
    QPushButton *wrrobinbtn1;

    void setupUi(QMainWindow *Fcfs)
    {
        if (Fcfs->objectName().isEmpty())
            Fcfs->setObjectName("Fcfs");
        Fcfs->resize(1356, 866);
        Fcfs->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        centralwidget = new QWidget(Fcfs);
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

        timeseq = new QPushButton(centralwidget);
        timeseq->setObjectName("timeseq");
        timeseq->setGeometry(QRect(900, 270, 301, 38));
        timeseq->setFont(font);
        timeseq->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 123, 255);"));
        layoutWidget_2 = new QWidget(centralwidget);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(970, 170, 161, 81));
        verticalLayout_2 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        packetsv = new QLineEdit(layoutWidget_2);
        packetsv->setObjectName("packetsv");
        packetsv->setMinimumSize(QSize(0, 8));
        QFont font1;
        font1.setPointSize(18);
        font1.setBold(false);
        packetsv->setFont(font1);
        packetsv->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(205, 208, 208);"));

        verticalLayout_2->addWidget(packetsv);

        insert = new QPushButton(layoutWidget_2);
        insert->setObjectName("insert");
        insert->setFont(font);
        insert->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 123, 255);"));

        verticalLayout_2->addWidget(insert);

        reset = new QPushButton(centralwidget);
        reset->setObjectName("reset");
        reset->setGeometry(QRect(970, 330, 161, 38));
        reset->setFont(font);
        reset->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 123, 255);"));
        layoutWidget_3 = new QWidget(centralwidget);
        layoutWidget_3->setObjectName("layoutWidget_3");
        layoutWidget_3->setGeometry(QRect(900, 70, 291, 76));
        verticalLayout = new QVBoxLayout(layoutWidget_3);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        buffertime = new QLineEdit(layoutWidget_3);
        buffertime->setObjectName("buffertime");
        buffertime->setMinimumSize(QSize(0, 10));
        buffertime->setFont(font1);
        buffertime->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(205, 208, 208);"));

        horizontalLayout_2->addWidget(buffertime);

        numoftimesq = new QLineEdit(layoutWidget_3);
        numoftimesq->setObjectName("numoftimesq");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(numoftimesq->sizePolicy().hasHeightForWidth());
        numoftimesq->setSizePolicy(sizePolicy);
        numoftimesq->setMinimumSize(QSize(0, 10));
        numoftimesq->setBaseSize(QSize(0, 0));
        numoftimesq->setFont(font1);
        numoftimesq->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(205, 208, 208);"));

        horizontalLayout_2->addWidget(numoftimesq);


        verticalLayout->addLayout(horizontalLayout_2);

        rateset = new QPushButton(layoutWidget_3);
        rateset->setObjectName("rateset");
        rateset->setFont(font);
        rateset->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 123, 255);"));

        verticalLayout->addWidget(rateset);

        layoutWidget_4 = new QWidget(centralwidget);
        layoutWidget_4->setObjectName("layoutWidget_4");
        layoutWidget_4->setGeometry(QRect(1270, 440, 168, 181));
        verticalLayout_3 = new QVBoxLayout(layoutWidget_4);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        fcfsbtn = new QPushButton(layoutWidget_4);
        fcfsbtn->setObjectName("fcfsbtn");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(fcfsbtn->sizePolicy().hasHeightForWidth());
        fcfsbtn->setSizePolicy(sizePolicy1);
        fcfsbtn->setMinimumSize(QSize(0, 6));
        QFont font2;
        font2.setPointSize(16);
        font2.setBold(true);
        fcfsbtn->setFont(font2);
        fcfsbtn->setStyleSheet(QString::fromUtf8("color: rgb(97, 131, 255);\n"
"background-color: rgb(0, 249, 0);"));

        verticalLayout_3->addWidget(fcfsbtn);

        leakybtn = new QPushButton(layoutWidget_4);
        leakybtn->setObjectName("leakybtn");
        sizePolicy1.setHeightForWidth(leakybtn->sizePolicy().hasHeightForWidth());
        leakybtn->setSizePolicy(sizePolicy1);
        leakybtn->setMinimumSize(QSize(0, 6));
        leakybtn->setFont(font2);
        leakybtn->setStyleSheet(QString::fromUtf8("color: rgb(97, 131, 255);\n"
"background-color: rgb(177, 179, 179);"));

        verticalLayout_3->addWidget(leakybtn);

        tokenbtn = new QPushButton(layoutWidget_4);
        tokenbtn->setObjectName("tokenbtn");
        sizePolicy1.setHeightForWidth(tokenbtn->sizePolicy().hasHeightForWidth());
        tokenbtn->setSizePolicy(sizePolicy1);
        tokenbtn->setMinimumSize(QSize(0, 6));
        tokenbtn->setFont(font2);
        tokenbtn->setStyleSheet(QString::fromUtf8("color: rgb(97, 131, 255);\n"
"background-color: rgb(177, 179, 179);"));

        verticalLayout_3->addWidget(tokenbtn);

        robinbtn = new QPushButton(layoutWidget_4);
        robinbtn->setObjectName("robinbtn");
        sizePolicy1.setHeightForWidth(robinbtn->sizePolicy().hasHeightForWidth());
        robinbtn->setSizePolicy(sizePolicy1);
        robinbtn->setMinimumSize(QSize(0, 6));
        robinbtn->setFont(font2);
        robinbtn->setStyleSheet(QString::fromUtf8("color: rgb(97, 131, 255);\n"
"background-color: rgb(177, 179, 179);"));

        verticalLayout_3->addWidget(robinbtn);

        wrrobinbtn1 = new QPushButton(layoutWidget_4);
        wrrobinbtn1->setObjectName("wrrobinbtn1");
        sizePolicy1.setHeightForWidth(wrrobinbtn1->sizePolicy().hasHeightForWidth());
        wrrobinbtn1->setSizePolicy(sizePolicy1);
        wrrobinbtn1->setMinimumSize(QSize(0, 6));
        wrrobinbtn1->setFont(font2);
        wrrobinbtn1->setStyleSheet(QString::fromUtf8("color: rgb(97, 131, 255);\n"
"background-color: rgb(177, 179, 179);"));

        verticalLayout_3->addWidget(wrrobinbtn1);

        Fcfs->setCentralWidget(centralwidget);

        retranslateUi(Fcfs);
        QObject::connect(closebtn, &QPushButton::clicked, Fcfs, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(Fcfs);
    } // setupUi

    void retranslateUi(QMainWindow *Fcfs)
    {
        Fcfs->setWindowTitle(QCoreApplication::translate("Fcfs", "MainWindow", nullptr));
        explain->setText(QCoreApplication::translate("Fcfs", "Explaination", nullptr));
        visualise->setText(QCoreApplication::translate("Fcfs", "Visualisation", nullptr));
        closebtn->setText(QCoreApplication::translate("Fcfs", "Close", nullptr));
        timeseq->setText(QCoreApplication::translate("Fcfs", "First Time Sequence", nullptr));
        packetsv->setText(QString());
        packetsv->setPlaceholderText(QCoreApplication::translate("Fcfs", "no. of packets", nullptr));
        insert->setText(QCoreApplication::translate("Fcfs", "Insert", nullptr));
        reset->setText(QCoreApplication::translate("Fcfs", "Reset", nullptr));
        buffertime->setText(QString());
        buffertime->setPlaceholderText(QCoreApplication::translate("Fcfs", "Buffer time", nullptr));
        numoftimesq->setText(QString());
        numoftimesq->setPlaceholderText(QCoreApplication::translate("Fcfs", "No. of Time Seq.", nullptr));
        rateset->setText(QCoreApplication::translate("Fcfs", "Set", nullptr));
        fcfsbtn->setText(QCoreApplication::translate("Fcfs", "FCFS", nullptr));
        leakybtn->setText(QCoreApplication::translate("Fcfs", "Leaky Buket", nullptr));
        tokenbtn->setText(QCoreApplication::translate("Fcfs", "Token Bucket", nullptr));
        robinbtn->setText(QCoreApplication::translate("Fcfs", "Round Robin", nullptr));
        wrrobinbtn1->setText(QCoreApplication::translate("Fcfs", "Weighted R. Robin", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Fcfs: public Ui_Fcfs {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FCFS_H
