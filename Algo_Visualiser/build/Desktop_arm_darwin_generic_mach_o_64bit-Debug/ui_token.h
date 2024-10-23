/********************************************************************************
** Form generated from reading UI file 'token.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOKEN_H
#define UI_TOKEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Token
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *explain;
    QPushButton *visualise;
    QPushButton *closebtn;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *packetsv;
    QPushButton *insert;
    QPushButton *reset;
    QWidget *layoutWidget_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *tokenrate;
    QLineEdit *numoftimesq;
    QPushButton *rateset;
    QPushButton *timeseq;
    QWidget *layoutWidget_4;
    QVBoxLayout *verticalLayout_3;
    QPushButton *fcfsbtn;
    QPushButton *leakybtn;
    QPushButton *tokenbtn;
    QPushButton *robinbtn;
    QPushButton *wrrobinbtn;

    void setupUi(QMainWindow *Token)
    {
        if (Token->objectName().isEmpty())
            Token->setObjectName("Token");
        Token->resize(1357, 867);
        Token->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        centralwidget = new QWidget(Token);
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

        layoutWidget_2 = new QWidget(centralwidget);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(950, 150, 161, 81));
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
        reset->setGeometry(QRect(950, 330, 161, 38));
        reset->setFont(font);
        reset->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 123, 255);"));
        layoutWidget_3 = new QWidget(centralwidget);
        layoutWidget_3->setObjectName("layoutWidget_3");
        layoutWidget_3->setGeometry(QRect(860, 40, 291, 76));
        verticalLayout = new QVBoxLayout(layoutWidget_3);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        tokenrate = new QLineEdit(layoutWidget_3);
        tokenrate->setObjectName("tokenrate");
        tokenrate->setMinimumSize(QSize(0, 10));
        tokenrate->setFont(font1);
        tokenrate->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(205, 208, 208);"));

        horizontalLayout_2->addWidget(tokenrate);

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

        timeseq = new QPushButton(centralwidget);
        timeseq->setObjectName("timeseq");
        timeseq->setGeometry(QRect(890, 260, 301, 38));
        timeseq->setFont(font);
        timeseq->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 123, 255);"));
        layoutWidget_4 = new QWidget(centralwidget);
        layoutWidget_4->setObjectName("layoutWidget_4");
        layoutWidget_4->setGeometry(QRect(1270, 460, 168, 181));
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
"background-color: rgb(177, 179, 179);"));

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
"background-color: rgb(0, 249, 0);"));

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

        wrrobinbtn = new QPushButton(layoutWidget_4);
        wrrobinbtn->setObjectName("wrrobinbtn");
        sizePolicy1.setHeightForWidth(wrrobinbtn->sizePolicy().hasHeightForWidth());
        wrrobinbtn->setSizePolicy(sizePolicy1);
        wrrobinbtn->setMinimumSize(QSize(0, 6));
        wrrobinbtn->setFont(font2);
        wrrobinbtn->setStyleSheet(QString::fromUtf8("color: rgb(97, 131, 255);\n"
"background-color: rgb(177, 179, 179);"));

        verticalLayout_3->addWidget(wrrobinbtn);

        Token->setCentralWidget(centralwidget);

        retranslateUi(Token);
        QObject::connect(closebtn, &QPushButton::clicked, Token, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(Token);
    } // setupUi

    void retranslateUi(QMainWindow *Token)
    {
        Token->setWindowTitle(QCoreApplication::translate("Token", "MainWindow", nullptr));
        explain->setText(QCoreApplication::translate("Token", "Explaination", nullptr));
        visualise->setText(QCoreApplication::translate("Token", "Visualisation", nullptr));
        closebtn->setText(QCoreApplication::translate("Token", "Close", nullptr));
        packetsv->setText(QString());
        packetsv->setPlaceholderText(QCoreApplication::translate("Token", "no. of packets", nullptr));
        insert->setText(QCoreApplication::translate("Token", "Insert", nullptr));
        reset->setText(QCoreApplication::translate("Token", "Reset", nullptr));
        tokenrate->setText(QString());
        tokenrate->setPlaceholderText(QCoreApplication::translate("Token", "Token rate", nullptr));
        numoftimesq->setText(QString());
        numoftimesq->setPlaceholderText(QCoreApplication::translate("Token", "No. of Time Seq.", nullptr));
        rateset->setText(QCoreApplication::translate("Token", "Set", nullptr));
        timeseq->setText(QCoreApplication::translate("Token", "First Time Sequence", nullptr));
        fcfsbtn->setText(QCoreApplication::translate("Token", "FCFS", nullptr));
        leakybtn->setText(QCoreApplication::translate("Token", "Leaky Buket", nullptr));
        tokenbtn->setText(QCoreApplication::translate("Token", "Token Bucket", nullptr));
        robinbtn->setText(QCoreApplication::translate("Token", "Round Robin", nullptr));
        wrrobinbtn->setText(QCoreApplication::translate("Token", "Weighted R. Robin", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Token: public Ui_Token {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOKEN_H
