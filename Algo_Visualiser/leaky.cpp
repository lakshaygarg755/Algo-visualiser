#include "leaky.h"
#include "ui_leaky.h"

Leaky::Leaky(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Leaky)
{
    ui->setupUi(this);
    ui->rateset->hide();
    ui->insert->hide();
    ui->timeseq->hide();
    ui->outputrate->hide();
    ui->numoftimesq->hide();
    ui->packetsv->hide();
    ui->reset->hide();

}

Leaky::~Leaky()
{
    delete ui;
    // delete text;
    // qDeleteAll(labelvec);
    // labelvec.clear();
    // qDeleteAll(textvec);
    // textvec.clear();
}

void Leaky::on_explain_clicked()
{
    clearmainwindow();
    text = new QTextEdit(this);
    text->setGeometry(20,100,1200,700);
    text->setText("Imagine a bucket with a small hole at the bottom, and water being poured in at irregular intervals."
    " If too much water is poured in at once, some of it will spill over because the bucket has a fixed capacity. "
    "However, the water drips out of the hole at a constant rate."
    " Similarly, in the Leaky Bucket Algorithm, data packets enter the system at varying speeds, "
    "but they leave at a steady, regulated pace, preventing overflow (congestion).\n\n"
    "Steps Involved in the Algorithm\n"
    "1.Incoming Packets: Data packets arrive at different rates and are added to the bucket.\n"
    "2.Outflow Control: The bucket leaks packets at a fixed, constant rate.\n"
    "3.Overflow Condition: If the bucket becomes full, any extra incoming packets are discarded until there is room again.\n"
    "4.Constant Data Rate: Even though data arrives irregularly, the outflow remains steady.\n\n"
    "Advantages\n"
    "1. Simple to implement.\n"
    "2.Can regulate bursty traffic effectively.\n\n"
    "Disadvantages\n"
    "1.The leaky bucket algorithm can discard data when the bucket is full, which may lead to packet loss.\n"
    "It doesn't distinguish between high-priority and low-priority traffic.\n");
    text->setStyleSheet("border:0px;color:black;font:18px");
    text->setReadOnly(true);
    text->show();
    textvec.append(text);
    ui->rateset->hide();
    ui->insert->hide();
    ui->timeseq->hide();
    ui->outputrate->hide();
    ui->numoftimesq->hide();
    ui->packetsv->hide();
    ui->reset->hide();

}


void Leaky::on_visualise_clicked()
{
    clearmainwindow();

    label = new QLabel(this);
    QPixmap mainpix1("/Users/lakshaygarg/Desktop/Project sem5/images/leaky.png");
    label->setPixmap(mainpix1);
    label->setGeometry(20,60,681,731);
    label->show();
    labelvec.append(label);
    label = new QLabel(this);
    QPixmap mainpix2("/Users/lakshaygarg/Desktop/Project sem5/images/bucket.png");
    label->setPixmap(mainpix2);
    label->setGeometry(278,539,103,253);
    label->show();
    labelvec.append(label);
    ui->rateset->show();
    ui->insert->show();
    ui->timeseq->show();
    ui->outputrate->show();
    ui->numoftimesq->show();
    ui->packetsv->show();
    ui->insert->setEnabled(false);
    ui->timeseq->setEnabled(false);
    ui->reset->show();
}

void Leaky::clearmainwindow()
{
    if(!textvec.empty())
    {
        qDeleteAll(textvec);
        textvec.clear();
    }
    if(!labelvec.empty())
    {
        qDeleteAll(labelvec);
        labelvec.clear();
    }
}

void Leaky::on_rateset_clicked()
{
    outputFlowRate = ui->outputrate->text().toInt();
    numoftime = ui->numoftimesq->text().toInt();
    if(outputFlowRate < 1 || outputFlowRate > 10 )
    {
        QMessageBox msg;
        msg.setText("The value of output rate is out of bounds!");
        msg.setStyleSheet("QLabel { color: black; }"
                          "QPushButton { color: black; }"
                          "QMessageBox { background-color: white; }");
        msg.exec();
        return;
    }
    if(numoftime < 1 || numoftime > 10 )
    {
        QMessageBox msg;
        msg.setText("The number of time sequences is out of bounds!");
        msg.setStyleSheet("QLabel { color: black; }"
                          "QPushButton { color: black; }"
                          "QMessageBox { background-color: white; }");
        msg.exec();
        return;
    }
    ui->rateset->setEnabled(false);
    ui->insert->setEnabled(true);
}


void Leaky::on_insert_clicked() {
    QString input = ui->packetsv->text();
    if (input.isEmpty()) {
        qDebug() << "Input is empty!" << Qt::endl;
        return;
    }

    QStringList stringList = input.split(",");
    for (QString str : stringList) {
        bool ok;
        int packet = str.trimmed().toInt(&ok);
        if (ok) {
            packetsvec.append(packet);
        } else {
            qDebug() << "Invalid packet value: " << str << Qt::endl;
        }
    }
    if(packetsvec.size() != numoftime){
        QMessageBox msg;
        msg.setText("Entered values in array is invalid!");
        msg.setStyleSheet("QLabel { color: black; }"
                          "QPushButton { color: black; }"
                          "QMessageBox { background-color: white; }");
        msg.exec();
        input.clear();
        stringList.clear();
        packetsvec.clear();
        return;
    }

    ui->insert->setEnabled(false);
    ui->timeseq->setEnabled(true);
}



void Leaky::on_timeseq_clicked()
{

    animationgp = new QSequentialAnimationGroup(this);
    if(j>=packetsvec.size())
    {
        if(packetv.empty())
        {
            QMessageBox msg;
            msg.setText("Bucket is already empty");
            msg.setStyleSheet("QLabel { color: black; }"
                              "QPushButton { color: black; }"
                              "QMessageBox { background-color: white; }");
            msg.exec();
            return;
        }
        for(int i=0;i<(outputFlowRate<packetv.size()?outputFlowRate:packetv.size());i++)
        {
            animation1 = new QPropertyAnimation(packetv.front(),"geometry");
            animation1->setDuration(1000);
            animation1->setKeyValueAt(0.4,QRect(280,765,100,25));
            animation1->setEndValue(QRect(610,766,100,25));
            animationgp->addAnimation(animation1);
            packetv.pop_front();
            packetsinbucket--;
            bkttop+=25;
            newpackets = 0;
            packetsdropped = 0;
        }
        animationgp->start();
        text = new QTextEdit(this);
        text->setGeometry(602,247,30,160);
        text->setText(QString("10\n%1\n%2\n%3\n%4\n%5")
                          .arg(j++)
                          .arg(packetsinbucket)
                          .arg(packetssent)
                          .arg(newpackets)
                          .arg(packetsdropped));
        text->setStyleSheet("border:0px;color:black;font:18px");
        text->setReadOnly(true);
        text->show();
        return;
    }
    newpackets = packetsvec.at(j);
    j++;
    packetsdropped = 0;
    ui->timeseq->setText("Next Time Seq.");

    for(int i=packetsinbucket;i<newpackets+packetsinbucket;i++)
    {
        QLabel *label1 = new QLabel(this);
        QPixmap pktpix("/Users/lakshaygarg/Desktop/Project sem5/images/packet.png");
        QPixmap pktscl = pktpix.scaled(100,25);
        label1->setPixmap(pktscl);
        label1->setGeometry(QRect(280,342,100,25));
        label1->show();
        labelvec.append(label1);

        packetv.append(label1);
        animation1 = new QPropertyAnimation(packetv.at(i),"geometry");
        animation1->setDuration(1500-100*i);
        animation1->setEndValue(QRect(280,bkttop-=25,100,25));
        animationgp->addAnimation(animation1);
    }
    packetsinbucket+=newpackets;


    packetssent = packetsinbucket>outputFlowRate?outputFlowRate:packetsinbucket;
    for(int i=0;i<packetssent;i++)
    {
        animation1 = new QPropertyAnimation(packetv.front(),"geometry");
        animation1->setDuration(700);
        animation1->setKeyValueAt(0.2,QRect(280,766,100,25));
        animation1->setEndValue(QRect(610,766,100,25));
        animationgp->addAnimation(animation1);
        packetv.pop_front();
    }
    packetsinbucket-=packetssent;
    bkttop+=25*packetssent;

    int downtop = 791;
    for(int i=0;i<packetsinbucket;i++)
    {
        animation1 = new QPropertyAnimation(packetv.at(i),"geometry");
        animation1->setDuration(500);
        animation1->setEndValue(QRect(280,downtop-=25,100,25));
        animationgp->addAnimation(animation1);

    }

    if(packetsinbucket>10)
    {
        while(packetsinbucket>10)
        {
            animation1 = new QPropertyAnimation(packetv.at(10),"geometry");
            animation1->setDuration(1300);
            animation1->setKeyValueAt(0.3,QRect(280,516,100,25));
            animation1->setKeyValueAt(0.7,QRect(450,516,100,25));
            animation1->setEndValue(QRect(450,660,68,24));
            animation1->setEasingCurve(QEasingCurve::Type::OutBounce);
            animationgp->addAnimation(animation1);
            packetsinbucket-=1;
            packetv.removeAt(10);
            packetsdropped++;
        }
        bkttop = 541;
    }
    animationgp->start();


    text = new QTextEdit(this);
    text->setGeometry(602,247,30,160);
    text->setText(QString("10\n%1\n%2\n%3\n%4\n%5")
                      .arg(j)
                      .arg(packetsinbucket)
                      .arg(packetssent)
                      .arg(newpackets)
                      .arg(packetsdropped));
    text->setStyleSheet("border:0px;color:black;font:18px");
    text->setReadOnly(true);
    text->show();
    textvec.append(text);
}


void Leaky::on_reset_clicked()
{

    ui->outputrate->clear();
    ui->numoftimesq->clear();
    ui->packetsv->clear();
    ui->timeseq->setText("First Time Seq.");

    outputFlowRate = 0;
    numoftime = 0;
    packetsinbucket = 0;
    packetsdropped = 0;
    packetssent = 0;
    newpackets = 0;
    bkttop = 791;
    j = 0;
    packetsvec.clear();
    while(!labelvec.empty())
    {
        labelvec.front()->hide();
        labelvec.pop_front();
    }
    label = new QLabel(this);
    QPixmap mainpix1("/Users/lakshaygarg/Desktop/Project sem5/images/leaky.png");
    label->setPixmap(mainpix1);
    label->setGeometry(20,60,681,731);
    label->show();
    labelvec.append(label);
    label = new QLabel(this);
    QPixmap mainpix2("/Users/lakshaygarg/Desktop/Project sem5/images/bucket.png");
    label->setPixmap(mainpix2);
    label->setGeometry(278,539,103,253);
    label->show();
    labelvec.append(label);

    if(animationgp != nullptr) animationgp->clear();
    ui->rateset->setEnabled(true);
    ui->insert->setEnabled(false);
    ui->timeseq->setEnabled(false);
    QMessageBox msg;
    msg.setText("Visualizer reset successfully!");
    msg.setStyleSheet("QLabel { color: black; }"
                      "QPushButton { color: black; }"
                      "QMessageBox { background-color: white; }");
    msg.exec();
}

void Leaky::on_fcfsbtn_clicked()
{
    fcfs1 = new Fcfs(this);
    fcfs1->show();
    this->close();
}


void Leaky::on_tokenbtn_clicked()
{
    token1 = new Token(this);
    token1->show();
    this->close();
}


void Leaky::on_robinbtn_clicked()
{
    rrobin1 = new Roundrobin(this);
    rrobin1->show();
    this->close();
}


void Leaky::on_wrrobinbtn_clicked()
{
    wrrobin1 = new Wroundrobin(this);
    wrrobin1->show();
    this->close();
}

