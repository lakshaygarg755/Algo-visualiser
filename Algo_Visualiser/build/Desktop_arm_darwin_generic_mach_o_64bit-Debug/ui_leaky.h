/********************************************************************************
** Form generated from reading UI file 'leaky.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEAKY_H
#define UI_LEAKY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Leaky
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *explain;
    QPushButton *visualise;
    QPushButton *closebtn;
    QPushButton *timeseq;
    QPushButton *reset;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *outputrate;
    QLineEdit *numoftimesq;
    QPushButton *rateset;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *packetsv;
    QPushButton *insert;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QPushButton *fcfsbtn;
    QPushButton *leakybtn;
    QPushButton *tokenbtn;
    QPushButton *robinbtn;
    QPushButton *wrrobinbtn;

    void setupUi(QMainWindow *Leaky)
    {
        if (Leaky->objectName().isEmpty())
            Leaky->setObjectName("Leaky");
        Leaky->resize(1358, 864);
        Leaky->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        centralwidget = new QWidget(Leaky);
        centralwidget->setObjectName("centralwidget");
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 10, 431, 51));
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
        timeseq->setGeometry(QRect(880, 270, 301, 38));
        timeseq->setFont(font);
        timeseq->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 123, 255);"));
        reset = new QPushButton(centralwidget);
        reset->setObjectName("reset");
        reset->setGeometry(QRect(950, 330, 161, 38));
        reset->setFont(font);
        reset->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 123, 255);"));
        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(880, 70, 291, 76));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        outputrate = new QLineEdit(layoutWidget1);
        outputrate->setObjectName("outputrate");
        outputrate->setMinimumSize(QSize(0, 10));
        QFont font1;
        font1.setPointSize(18);
        font1.setBold(false);
        outputrate->setFont(font1);
        outputrate->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(205, 208, 208);"));

        horizontalLayout_2->addWidget(outputrate);

        numoftimesq = new QLineEdit(layoutWidget1);
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

        rateset = new QPushButton(layoutWidget1);
        rateset->setObjectName("rateset");
        rateset->setFont(font);
        rateset->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 123, 255);"));

        verticalLayout->addWidget(rateset);

        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(950, 170, 161, 81));
        verticalLayout_2 = new QVBoxLayout(layoutWidget2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        packetsv = new QLineEdit(layoutWidget2);
        packetsv->setObjectName("packetsv");
        packetsv->setMinimumSize(QSize(0, 8));
        packetsv->setFont(font1);
        packetsv->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(205, 208, 208);"));

        verticalLayout_2->addWidget(packetsv);

        insert = new QPushButton(layoutWidget2);
        insert->setObjectName("insert");
        insert->setFont(font);
        insert->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 123, 255);"));

        verticalLayout_2->addWidget(insert);

        layoutWidget_2 = new QWidget(centralwidget);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(1270, 470, 168, 181));
        verticalLayout_3 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        fcfsbtn = new QPushButton(layoutWidget_2);
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
"background-color: rgb(177, 179, 179);"));

        verticalLayout_3->addWidget(fcfsbtn);

        leakybtn = new QPushButton(layoutWidget_2);
        leakybtn->setObjectName("leakybtn");
        sizePolicy1.setHeightForWidth(leakybtn->sizePolicy().hasHeightForWidth());
        leakybtn->setSizePolicy(sizePolicy1);
        leakybtn->setMinimumSize(QSize(0, 6));
        leakybtn->setFont(font2);
        leakybtn->setStyleSheet(QString::fromUtf8("color: rgb(97, 131, 255);\n"
"background-color: rgb(0, 249, 0);"));

        verticalLayout_3->addWidget(leakybtn);

        tokenbtn = new QPushButton(layoutWidget_2);
        tokenbtn->setObjectName("tokenbtn");
        sizePolicy1.setHeightForWidth(tokenbtn->sizePolicy().hasHeightForWidth());
        tokenbtn->setSizePolicy(sizePolicy1);
        tokenbtn->setMinimumSize(QSize(0, 6));
        tokenbtn->setFont(font2);
        tokenbtn->setStyleSheet(QString::fromUtf8("color: rgb(97, 131, 255);\n"
"background-color: rgb(177, 179, 179);"));

        verticalLayout_3->addWidget(tokenbtn);

        robinbtn = new QPushButton(layoutWidget_2);
        robinbtn->setObjectName("robinbtn");
        sizePolicy1.setHeightForWidth(robinbtn->sizePolicy().hasHeightForWidth());
        robinbtn->setSizePolicy(sizePolicy1);
        robinbtn->setMinimumSize(QSize(0, 6));
        robinbtn->setFont(font2);
        robinbtn->setStyleSheet(QString::fromUtf8("color: rgb(97, 131, 255);\n"
"background-color: rgb(177, 179, 179);"));

        verticalLayout_3->addWidget(robinbtn);

        wrrobinbtn = new QPushButton(layoutWidget_2);
        wrrobinbtn->setObjectName("wrrobinbtn");
        sizePolicy1.setHeightForWidth(wrrobinbtn->sizePolicy().hasHeightForWidth());
        wrrobinbtn->setSizePolicy(sizePolicy1);
        wrrobinbtn->setMinimumSize(QSize(0, 6));
        wrrobinbtn->setFont(font2);
        wrrobinbtn->setStyleSheet(QString::fromUtf8("color: rgb(97, 131, 255);\n"
"background-color: rgb(177, 179, 179);"));

        verticalLayout_3->addWidget(wrrobinbtn);

        Leaky->setCentralWidget(centralwidget);

        retranslateUi(Leaky);
        QObject::connect(closebtn, &QPushButton::clicked, Leaky, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(Leaky);
    } // setupUi

    void retranslateUi(QMainWindow *Leaky)
    {
        Leaky->setWindowTitle(QCoreApplication::translate("Leaky", "MainWindow", nullptr));
        explain->setText(QCoreApplication::translate("Leaky", "Explaination", nullptr));
        visualise->setText(QCoreApplication::translate("Leaky", "Visualisation", nullptr));
        closebtn->setText(QCoreApplication::translate("Leaky", "Close", nullptr));
        timeseq->setText(QCoreApplication::translate("Leaky", "First Time Sequence", nullptr));
        reset->setText(QCoreApplication::translate("Leaky", "Reset", nullptr));
        outputrate->setText(QString());
        outputrate->setPlaceholderText(QCoreApplication::translate("Leaky", "Output Rate", nullptr));
        numoftimesq->setText(QString());
        numoftimesq->setPlaceholderText(QCoreApplication::translate("Leaky", "No. of Time Seq.", nullptr));
        rateset->setText(QCoreApplication::translate("Leaky", "Set", nullptr));
        packetsv->setText(QString());
        packetsv->setPlaceholderText(QCoreApplication::translate("Leaky", "no. of packets", nullptr));
        insert->setText(QCoreApplication::translate("Leaky", "Insert", nullptr));
        fcfsbtn->setText(QCoreApplication::translate("Leaky", "FCFS", nullptr));
        leakybtn->setText(QCoreApplication::translate("Leaky", "Leaky Buket", nullptr));
        tokenbtn->setText(QCoreApplication::translate("Leaky", "Token Bucket", nullptr));
        robinbtn->setText(QCoreApplication::translate("Leaky", "Round Robin", nullptr));
        wrrobinbtn->setText(QCoreApplication::translate("Leaky", "Weighted R. Robin", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Leaky: public Ui_Leaky {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEAKY_H
