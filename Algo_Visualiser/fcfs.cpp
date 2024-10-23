#include "fcfs.h"
#include "ui_fcfs.h"

Fcfs::Fcfs(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Fcfs)
{
    ui->setupUi(this);

    ui->rateset->hide();
    ui->insert->hide();
    ui->timeseq->hide();
    ui->buffertime->hide();
    ui->numoftimesq->hide();
    ui->packetsv->hide();
    ui->reset->hide();
}

Fcfs::~Fcfs()
{
    delete ui;
}

void Fcfs::clearmainwindow()
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

void Fcfs::on_explain_clicked()
{
    clearmainwindow();
    text = new QTextEdit(this);
    text->setGeometry(20,100,1200,700);
    text->setText("The First In, First Out (FIFO) algorithm is a straightforward queuing method in which the first packet added to the queue is the first one to be processed. "
                  "Imagine a line at a ticket counter: the first person in line is the first to buy a ticket and leave, while newcomers join at the end of the line.\n\n"
                  "Steps Involved in the Algorithm\n"
                  "1. Packet Arrival: Data packets arrive at the system and are placed at the end of the queue.\n"
                  "2. Queue Processing: Packets are processed in the exact order they arrive, with the oldest packet being handled first.\n"
                  "3. Completion: Once a packet has been processed, it is removed from the queue, allowing the next packet to be handled.\n"
                  "4. No Prioritization: All packets are treated equally, with no distinction based on priority.\n\n"
                  "Advantages\n"
                  "1. Simple to understand and implement, making it suitable for various applications.\n"
                  "2. Predictable behavior, as packets are processed in the order they arrive.\n\n"
                  "Disadvantages\n"
                  "1. Can lead to delays for high-priority packets if they arrive after lower-priority ones.\n"
                  "2. Inefficient under high load, as the queue may become congested, leading to increased latency.\n");
    text->setStyleSheet("border:0px;color:black;font:18px");
    text->setReadOnly(true);
    text->show();
    textvec.append(text);


    ui->rateset->hide();
    ui->insert->hide();
    ui->timeseq->hide();
    ui->buffertime->hide();
    ui->numoftimesq->hide();
    ui->packetsv->hide();
    ui->reset->hide();
}


void Fcfs::on_visualise_clicked()
{
    clearmainwindow();
    label = new QLabel(this);
    QPixmap mainpix1("/Users/lakshaygarg/Desktop/Project sem5/images/fifo.png");
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
    ui->buffertime->show();
    ui->numoftimesq->show();
    ui->packetsv->show();
    ui->insert->setEnabled(false);
    ui->timeseq->setEnabled(false);
    ui->reset->show();
}

void Fcfs::on_rateset_clicked()
{
    buffertime = ui->buffertime->text().toInt();
    numoftime = ui->numoftimesq->text().toInt();
    if(buffertime < 0 || buffertime > 10 )
    {
        QMessageBox msg;
        msg.setText("The value of buffer time is out of bounds!");
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


void Fcfs::on_insert_clicked()
{

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
    // qDebug() << "Total packets: " << packetsvec.size() << Qt::endl;

    ui->insert->setEnabled(false);
    ui->timeseq->setEnabled(true);


}


void Fcfs::on_timeseq_clicked()
{
    // if(animationgp) animationgp->clear();
    animationgp = new QSequentialAnimationGroup(this);
    newpackets = packetsvec.at(j);
    packetsdropped = 0;
    ui->timeseq->setText("Next Time Seq.");
    if(j<buffertime)
    {
        for(int i=packetsinbucket;i<packetsinbucket+newpackets;i++)
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
        if(packetsinbucket>10)
        {
            overflow();
        }
        animationgp->start();
    }
    else if(buffertime == 0)
    {

        for(int i=packetsinbucket;i<packetsinbucket+newpackets;i++)
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
        packetssent = packetsinbucket;
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
        animationgp->start();
    }
    else
    {
        packetssent = packetsvec.at(j-buffertime);
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
        bkttop = downtop;
        newpackets = packetsvec[j];

        for(int i=packetsinbucket;i<packetsinbucket+newpackets;i++)
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
        if(packetsinbucket>10)
        {
            overflow();
        }
        animationgp->start();

    }
    j++;

    text = new QTextEdit(this);
    text->setGeometry(602,235,50,170);
    text->setText(QString("10\n%1\n%2\n%3\n%4\n%5\n%6")
                      .arg(buffertime)
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


void Fcfs::on_reset_clicked()
{
    ui->buffertime->clear();
    ui->numoftimesq->clear();
    ui->packetsv->clear();

    buffertime = 0;
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
    QPixmap mainpix1("/Users/lakshaygarg/Desktop/Project sem5/images/fifo.png");
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
    ui->timeseq->setText("First Time Seq.");
    QMessageBox msg;
    msg.setText("Visualizer reset successfully!");
    msg.setStyleSheet("QLabel { color: black; }"
                      "QPushButton { color: black; }"
                      "QMessageBox { background-color: white; }");
    msg.exec();

}

void Fcfs::overflow()
{
    while(packetv.size()>10)
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

void Fcfs::on_leakybtn_clicked()
{
    leaky1 = new Leaky(this);
    leaky1->show();
    this->close();
}


void Fcfs::on_tokenbtn_clicked()
{
    token1 = new Token(this);
    token1->show();
    this->close();
}


void Fcfs::on_robinbtn_clicked()
{
    rrobin1 = new Roundrobin(this);
    rrobin1->show();
    this->close();
}

void Fcfs::on_wrrobinbtn1_clicked()
{
    wrrobin1 = new Wroundrobin(this);
    wrrobin1->show();
    this->close();
}

