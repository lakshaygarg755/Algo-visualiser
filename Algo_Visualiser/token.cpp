#include "token.h"
#include "ui_token.h"

Token::Token(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Token)
{
    ui->setupUi(this);
    ui->rateset->hide();
    ui->insert->hide();
    ui->timeseq->hide();
    ui->tokenrate->hide();
    ui->numoftimesq->hide();
    ui->packetsv->hide();
    ui->reset->hide();
}

Token::~Token()
{
    delete ui;
}

void Token::on_explain_clicked()
{
    clearmainwindow();  // Clear the main window to display new text

    text = new QTextEdit(this);
    text->setGeometry(20, 100, 1200, 700);  // Set the text area dimensions
    text->setText("The Token Bucket Algorithm is a network traffic control algorithm that manages the flow of data packets. "
                  "Imagine a bucket where tokens are added at a constant rate. These tokens are required for packets to be transmitted. "
                  "If there are not enough tokens in the bucket, the packets must wait. "
                  "If enough tokens are available, the packets are transmitted immediately, and the tokens are consumed.\n\n"
                  "Steps Involved in the Algorithm\n"
                  "1. Token Generation: Tokens are added to the bucket at a fixed rate.\n"
                  "2. Token Consumption: Each data packet needs tokens to be transmitted. "
                  "The packet consumes a number of tokens proportional to its size.\n"
                  "3. Bucket Capacity: The bucket has a fixed size. If it is full, no additional tokens are added until tokens are consumed.\n"
                  "4. Packet Transmission: If enough tokens are available, packets are sent immediately; otherwise, they must wait.\n\n"
                  "Advantages\n"
                  "1. Efficiently controls traffic bursts while allowing for large bursts when enough tokens are available.\n"
                  "2. Supports varying data rates while ensuring that long-term transmission remains within the limit.\n\n"
                  "Disadvantages\n"
                  "1. Packets may experience delay if tokens are not available.\n"
                  "2. The system needs careful tuning to match the desired transmission rate and token generation rate.");

    text->setStyleSheet("border:0px;color:black;font:18px");
    text->setReadOnly(true);
    text->show();
    textvec.append(text);

    ui->rateset->hide();
    ui->insert->hide();
    ui->timeseq->hide();
    ui->tokenrate->hide();
    ui->numoftimesq->hide();
    ui->packetsv->hide();
    ui->reset->hide();
}



void Token::on_visualise_clicked()
{
    clearmainwindow();
    label = new QLabel(this);
    QPixmap mainpix1("/Users/lakshaygarg/Desktop/Project sem5/images/tokenpix.png");
    label->setPixmap(mainpix1);
    label->setGeometry(20,60,611,731);
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
    ui->tokenrate->show();
    ui->numoftimesq->show();
    ui->packetsv->show();
    ui->insert->setEnabled(false);
    ui->timeseq->setEnabled(false);
    ui->reset->show();
}


void Token::on_rateset_clicked()
{
    tokenrate = ui->tokenrate->text().toInt();
    numoftime = ui->numoftimesq->text().toInt();
    if(tokenrate < 1 || tokenrate > 10 )
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


void Token::on_insert_clicked()
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


void Token::on_timeseq_clicked()
{
    if(j>=numoftime)
    {
        QMessageBox msg;
        msg.setText("Time Sequence Completed");
        msg.setStyleSheet("QLabel { color: black; }"
                          "QPushButton { color: black; }"
                          "QMessageBox { background-color: white; }");
        msg.exec();
        return;
    }
    animationgp = new QSequentialAnimationGroup(this);
    ui->timeseq->setText("Next Time Seq.");
    packetscnt = packetsvec[j];
    qDebug() << packetscnt <<Qt::endl;
    j++;
    drawtokens();
    drawpackets();
    animationgp->start();

    text = new QTextEdit(this);
    text->setGeometry(613,238,30,180);
    text->setText(QString("10\n%1\n%2\n%3\n%4\n%5")
                      .arg(j)
                      .arg(packetsvec.at(j-1))
                      .arg(n)
                      .arg(std::min(packetscnt,tokensinbkt+packetscnt))
                      .arg(tokenrate+tokenheight>10?tokenrate+tokenheight-10:0));
    text->setStyleSheet("border:0px;color:black;font:18px");
    text->setReadOnly(true);
    text->show();
    textvec.append(text);
    tokenheight = tokenstk.size();
}


void Token::on_reset_clicked()
{
    tokensinbkt = 0;
    packetscnt = 0;
    tokentop = 791;
    tokenrate = -1;
    numoftime = 0;
    j = 0;

    packetsvec.clear();
    // tokenstk.clear();

    ui->tokenrate->clear();
    ui->numoftimesq->clear();
    ui->packetsv->clear();

    ui->rateset->setEnabled(true);
    ui->insert->setEnabled(false);
    ui->timeseq->setEnabled(false);
    ui->timeseq->setText("Start Time Seq.");
    while(!tokenstk.empty())
    {
        tokenstk.front()->hide();
        tokenstk.pop_front();
    }
    QMessageBox msg;
    msg.setText("Visualizer reset successfully!");
    msg.setStyleSheet("QLabel { color: black; }"
                      "QPushButton { color: black; }"
                      "QMessageBox { background-color: white; }");
    msg.exec();
}

void Token::clearmainwindow()
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

void Token::drawtokens()
{
    for(int i=tokensinbkt;i<tokenrate+tokensinbkt;i++)
    {
        QLabel *label1 = new QLabel(this);
        QPixmap tknpix("/Users/lakshaygarg/Desktop/Project sem5/images/token.png");
        QPixmap tknscl = tknpix.scaled(100,25);
        label1->setPixmap(tknscl);
        label1->setGeometry(QRect(280,392,100,25));
        label1->show();
        labelvec.append(label1);
        tokenstk.append(label1);
        animation1 = new QPropertyAnimation(tokenstk.at(i),"geometry");
        animation1->setDuration(1200-100*tokensinbkt);
        animation1->setEndValue(QRect(280,tokentop-=25,100,25));
        animationgp->addAnimation(animation1);
    }

    tokensinbkt+=tokenrate;

    if(tokenstk.size()>10)
    {
        while(tokenstk.size()>10)
        {
            animation1 = new QPropertyAnimation(tokenstk.at(10),"geometry");
            animation1->setDuration(1300);
            animation1->setKeyValueAt(0.3,QRect(280,516,100,25));
            animation1->setKeyValueAt(0.7,QRect(450,516,100,25));
            animation1->setEndValue(QRect(450,660,68,24));
            animation1->setEasingCurve(QEasingCurve::Type::OutBounce);
            animationgp->addAnimation(animation1);
            tokensinbkt--;
            tokenstk.removeAt(10);
            tokentop+=25;
        }
    }
}

void Token::drawpackets()
{
    n = tokensinbkt<packetscnt?tokensinbkt:packetscnt;

    for(int i=0;i<n;i++)
    {
        paranimation = new QParallelAnimationGroup(this);
        QLabel *label1 = new QLabel(this);
        QPixmap pktpix("/Users/lakshaygarg/Desktop/Project sem5/images/packet.png");
        QPixmap pktscl = pktpix.scaled(100,25);
        label1->setPixmap(pktscl);
        label1->setGeometry(QRect(280,342,100,25));
        label1->show();
        labelvec.append(label1);

        animation1 = new QPropertyAnimation(tokenstk.back(),"geometry");
        animation1->setDuration(1200);
        animation1->setKeyValueAt(0.6,QRect(280,510,100,25));
        animation1->setEndValue(QRect(520,510,100,25));
        paranimation->addAnimation(animation1);

        animation1 = new QPropertyAnimation(label1,"geometry");
        animation1->setDuration(1200);
        animation1->setKeyValueAt(0.6,QRect(280,510,100,25));
        animation1->setEndValue(QRect(520,510,100,25));
        paranimation->addAnimation(animation1);
        animationgp->addAnimation(paranimation);

        tokentop+=25;
        tokenstk.pop_back();
    }

    tokensinbkt -= n;
    packetscnt -= n;
    for(int i=0;i<packetscnt;i++)
    {
        QLabel *label1 = new QLabel(this);
        QPixmap pktpix("/Users/lakshaygarg/Desktop/Project sem5/images/packet.png");
        QPixmap pktscl = pktpix.scaled(100,25);
        label1->setPixmap(pktscl);
        label1->setGeometry(QRect(280,342,100,25));
        label1->show();
        labelvec.append(label1);

        animation1 = new QPropertyAnimation(label1,"geometry");
        animation1->setDuration(1500);
        animation1->setKeyValueAt(0.3,QRect(280,510,100,25));
        animation1->setKeyValueAt(0.7,QRect(450,510,100,25));
        animation1->setEndValue(QRect(450,660,68,24));
        animation1->setEasingCurve(QEasingCurve::Type::OutBounce);
        animationgp->addAnimation(animation1);
    }
}

void Token::on_fcfsbtn_clicked()
{
    fcfs1 = new Fcfs(this);
    fcfs1->show();
    this->close();
}


void Token::on_wrrobinbtn_clicked()
{
    wrrobin1 = new Wroundrobin(this);
    wrrobin1->show();
    this->close();
}


void Token::on_leakybtn_clicked()
{
    leaky1 = new Leaky(this);
    leaky1->show();
    this->close();
}


void Token::on_robinbtn_clicked()
{
    rrobin1 = new Roundrobin(this);
    rrobin1->show();
    this->close();
}

