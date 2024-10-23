#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "leaky.h"
#include "token.h"
#include "roundrobin.h"
#include "wroundrobin.h"
#include "fcfs.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // this->showFullScreen();

    seqani = new QSequentialAnimationGroup(this);
    parani = new QParallelAnimationGroup(this);

    text1 = new QTextEdit(this);
    text1->setGeometry(20,40,1300,50);
    text1->setText("Network Scheduling Algorithm Visualiser");
    text1->setStyleSheet("font:28px; color:black; border: 0px");
    text1->setFontWeight(QFont::Bold);
    text1->setAlignment(Qt::AlignCenter);
    text1->setReadOnly(true);
    text1->show();

    text2 = new QTextEdit(this);
    text2->setGeometry(20,100,1300,90);
    text2->setText("Network scheduling algorithms manage how data packets are selected and transmitted over the network. Given multiple data streams from different sources, the algorithms decide which streams should be sent in which order to ensure that every data stream gets fair shares of the total capacity within the network so that no congestion occurs.");
    text2->setStyleSheet("font:18px; color:black; border: 0px");
    text2->setReadOnly(true);
    text2->show();

    text3 = new QTextEdit(this);
    text3->setGeometry(20,200,1300,90);
    text3->setText("Now imagine several people trying to talk to you all at once. Without a system, it is totally chaotic. Network scheduling is like taking turns: each person (or device) gets a chance to speak (send data) for a short time before moving on to the next, so everyone gets a turn and no packet is delayed too long.");
    text3->setStyleSheet("font:18px; color:black; border: 0px");
    text3->setReadOnly(true);
    text3->show();

    img = new QLabel(this);
    QPixmap mainp("/Users/lakshaygarg/Desktop/Project sem5/images/main.png");
    QPixmap mainscaled = mainp.scaled(650,450);
    img->setPixmap(mainscaled);
    img->setGeometry(20,300,650,450);
    img->show();

    packet1 = new QLabel(this);
    QPixmap mainpix("/Users/lakshaygarg/Desktop/Project sem5/images//packet.jpg");
    QPixmap mainscale = mainpix.scaled(30,30);
    packet1->setPixmap(mainscale);
    packet1->setGeometry(20,300,30,30);
    packet1->show();

    ani1 = new QPropertyAnimation(packet1,"geometry");
    ani1->setDuration(3000);
    ani1->setStartValue(QRect(packet1->geometry()));
    ani1->setKeyValueAt(0.5,QRect(200,470,30,30));
    ani1->setEndValue(QRect(380,470,30,30));
    parani->addAnimation(ani1);

    packet2 = new QLabel(this);
    packet2->setPixmap(mainscale);
    packet2->setGeometry(20,450,30,30);
    packet2->show();

    ani2 = new QPropertyAnimation(packet2,"geometry");
    ani2->setDuration(3000);
    ani2->setStartValue(QRect(packet2->geometry()));
    ani2->setKeyValueAt(0.5,QRect(200,500,30,30));
    ani2->setEndValue(QRect(380,500,30,30));
    parani->addAnimation(ani2);

    packet3 = new QLabel(this);
    packet3->setPixmap(mainscale);
    packet3->setGeometry(20,600,30,30);
    packet3->show();

    ani3 = new QPropertyAnimation(packet3,"geometry");
    ani3->setDuration(3000);
    ani3->setStartValue(QRect(packet3->geometry()));
    ani3->setKeyValueAt(0.5,QRect(200,530,30,30));
    ani3->setEndValue(QRect(380,530,30,30));
    parani->addAnimation(ani3);
    seqani->addAnimation(parani);

    question = new QLabel(this);
    QPixmap qpix("/Users/lakshaygarg/Desktop/Project sem5/images/question-mark.png");
    QPixmap qpixscaled = qpix.scaled(60,60);
    question->setPixmap(qpixscaled);
    question->setGeometry(QRect(430,500,5,5));
    question->show();

    ani4 = new QPropertyAnimation(question, "geometry");
    ani4->setDuration(1000);
    ani4->setStartValue(QRect(430, 420, 30, 30));
    ani4->setKeyValueAt(0.5, QRect(430, 420, 60, 60));
    ani4->setEndValue(QRect(430, 420, 70, 70));
    seqani->addAnimation(ani4);

    seqani->start();
    seqani->setLoopCount(-1);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_fcfsbtn_clicked()
{
    closewindow();
    fcfs1 = new Fcfs(this);
    fcfs1->show();
}


void MainWindow::on_leakybtn_clicked()
{
    closewindow();
    leaky1 = new Leaky(this);
    leaky1->show();
}


void MainWindow::on_tokenbtn_clicked()
{
    closewindow();
    token1 = new Token(this);
    token1->show();
}


void MainWindow::on_robinbtn_clicked()
{
    closewindow();
    rrobin1 = new Roundrobin(this);
    rrobin1->show();
}


void MainWindow::on_wrrobinbtn_clicked()
{
    closewindow();
    wrrobin1 = new Wroundrobin(this);
    wrrobin1->show();
}

void MainWindow::closewindow()
{
    if (leaky1 != nullptr) {
        leaky1->close();
        delete leaky1;
        leaky1 = nullptr;
    }
    if (token1 != nullptr) {
        token1->close();
        delete token1;
        token1 = nullptr;
    }
    if (fcfs1 != nullptr) {
        fcfs1->close();
        delete fcfs1;
        fcfs1 = nullptr;
    }
    if (rrobin1 != nullptr) {
        rrobin1->close();
        delete rrobin1;
        rrobin1 = nullptr;
    }
    if (wrrobin1 != nullptr) {
        wrrobin1->close();
        delete wrrobin1;
        wrrobin1 = nullptr;
    }
}
