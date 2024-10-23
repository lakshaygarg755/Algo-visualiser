#include "roundrobin.h"
#include "ui_roundrobin.h"

Roundrobin::Roundrobin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Roundrobin)
{
    ui->setupUi(this);

    ui->line1->hide();
    ui->line3->hide();
    ui->insert->hide();
    ui->start->hide();
    ui->reset->hide();
}

Roundrobin::~Roundrobin()
{
    delete ui;
}

void Roundrobin::on_explain_clicked()
{
    clearwindow();
    text = new QTextEdit(this);
    text->setGeometry(20,100,1200,700);
    text->setText("The Round Robin (RR) scheduling algorithm is a widely used method in computing, particularly for time-sharing systems. "
                  "It allocates a fixed time unit (quantum) to each process in the queue, ensuring that all processes receive equal opportunity to execute.\n\n"
                  "Steps Involved in the Algorithm\n"
                  "1. Process Queue: Incoming processes are placed in a queue, waiting for their turn to execute.\n"
                  "2. Time Quantum Allocation: Each process is assigned a fixed time slice to run, after which it is moved to the back of the queue if it does not finish.\n"
                  "3. Context Switching: If a process does not complete within its allocated time, it is paused, and the CPU switches to the next process in the queue.\n"
                  "4. Repeating Cycle: The cycle continues, allowing each process to be processed in turn until all are completed.\n\n"
                  "Advantages\n"
                  "1. Fairness: All processes get an equal share of CPU time, which prevents starvation.\n"
                  "2. Simplicity: Easy to understand and implement, making it a popular choice for various applications.\n\n"
                  "Disadvantages\n"
                  "1. Time Overhead: Frequent context switching can lead to increased overhead and reduced efficiency, especially if the time quantum is too small.\n"
                  "2. Non-Optimal for Short Processes: Longer processes may cause delays for shorter processes if they frequently occupy the CPU for their full time slice.\n");
    text->setStyleSheet("border:0px;color:black;font:18px");
    text->setReadOnly(true);
    text->show();
    textvec.append(text);

    ui->line1->hide();
    ui->line3->hide();
    ui->insert->hide();
    ui->start->hide();
    ui->reset->hide();
    // rect->hide();
}


void Roundrobin::on_visualise_clicked()
{
    clearwindow();
    label = new QLabel(this);
    QPixmap mainpix1("/Users/lakshaygarg/Desktop/Project sem5/images/roundrobin.png");
    label->setPixmap(mainpix1);
    label->setGeometry(20,70,740,669);
    rect = new QFrame(this);
    rect->setGeometry(30,560,410,5);
    rect->setStyleSheet("background-color:black; border: 1px solid black");
    rect->show();
    label->show();
    labelvec.append(label);
    label = new QLabel("Waiting Queue",this);
    label->setGeometry(30,570,410,20);
    label->setStyleSheet("font:bold;color:black");
    label->setAlignment(Qt::AlignCenter);
    label->show();
    labelvec.append(label);
    ui->line1->show();
    ui->line3->show();
    ui->insert->show();
    ui->start->show();
    ui->reset->show();

}

void Roundrobin::clearwindow()
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

void Roundrobin::on_insert_clicked()
{
    seqanimation = new QSequentialAnimationGroup(this);
    pktscnt = ui->line3->text().toInt();
    if(pktscnt>9 || pktscnt < 1)
    {
        QMessageBox msg;
        msg.setText("Packets count are out of bound");
        msg.setStyleSheet("QLabel { color: black; }"
                          "QPushButton { color: black; }"
                          "QMessageBox { background-color: white; }");
        msg.exec();
        return;
    }
    if(waitq.size()==10)
    {
        QMessageBox msg;
        msg.setText("flow counts are out of bound");
        msg.setStyleSheet("QLabel { color: black; }"
                          "QPushButton { color: black; }"
                          "QMessageBox { background-color: white; }");
        msg.exec();
        return;
    }
    stacky = 560;
    stackx+=40;
    paranimation = new QParallelAnimationGroup(this);
    flowstk.clear();
    for(int i=0;i<pktscnt;i++)
    {
        QLabel *label1 = new QLabel(this);
        QPixmap pktpix("/Users/lakshaygarg/Desktop/Project sem5/images/rrpacket.png");
        label1->setPixmap(pktpix);
        label1->setGeometry(QRect(10,10,20,40));
        label1->show();
        labelvec.append(label1);
        flowstk.append(label1);
        animation1 = new QPropertyAnimation(label1,"geometry");
        animation1->setDuration(1000);
        animation1->setStartValue(QRect(440,stacky-=40,20,40));
        animation1->setEndValue(QRect(stackx,stacky,20,40));
        paranimation->addAnimation(animation1);
    }
    waitq.append(flowstk);
    seqanimation->addAnimation(paranimation);
    seqanimation->start();
}


void Roundrobin::on_start_clicked()
{
    ui->start->setText("Next time seq.");
    ui->insert->setEnabled(false);
    packetqnta = ui->line1->text().toInt();
    if(packetqnta < 1)
    {
        QMessageBox msg;
        msg.setText("Packets Qunata out of bound");
        msg.setStyleSheet("QLabel { color: black; }"
                          "QPushButton { color: black; }"
                          "QMessageBox { background-color: white; }");
        msg.exec();
        return;
    }
    if(waitq.empty())
    {
        QMessageBox msg;
        msg.setText("waiting queue is already empty");
        msg.setStyleSheet("QLabel { color: black; }"
                          "QPushButton { color: black; }"
                          "QMessageBox { background-color: white; }");
        msg.exec();
        return;
    }
    ui->line1->setReadOnly(true);
    ui->line3->setReadOnly(true);
    seqanimation = new QSequentialAnimationGroup(this);
    if (i >= waitq.size()) {
        i=0;
    }
    paranimation = new QParallelAnimationGroup(this);
    int mini = std::min(static_cast<int>(waitq.at(i).size()), packetqnta);
    for(int j=0;j<mini;j++)
    {
        if (waitq.at(i).isEmpty()) break;
        animation1 = new QPropertyAnimation(waitq.at(i).back(),"geometry");
        animation1->setDuration(1500);
        animation1->setEndValue(QRect(130,100,20,40));
        paranimation->addAnimation(animation1);
        end.push(waitq.at(i).back());
        waitq[i].pop_back();
    }
    if(waitq.at(i).size() == 0)
    {

        waitq.removeAt(i);
    }
    else
    {
        i++;
    }
    seqanimation->addAnimation(paranimation);
    seqanimation->start();
}
void Roundrobin::on_reset_clicked()
{
    stackx = 10;
    i=0;
    ui->start->setText("First Time Seq.");
    while(!waitq.empty())
    {
        waitq[0].top()->hide();
        waitq[0].pop();
        if(waitq[0].empty()) waitq.pop_front();
    }
    while(!end.empty())
    {
        end.top()->hide();
        end.pop_back();
    }
    ui->line1->clear();
    ui->line3->clear();
    ui->line1->setReadOnly(false);
    ui->line3->setReadOnly(false);
}


void Roundrobin::on_fcfsbtn_clicked()
{
    fcfs1 = new Fcfs(this);
    fcfs1->show();
    this->close();
}


void Roundrobin::on_leakybtn_clicked()
{
    leaky1 = new Leaky(this);
    leaky1->show();
    this->close();
}


void Roundrobin::on_tokenbtn_clicked()
{
    token1 = new Token(this);
    token1->show();
    this->close();
}


void Roundrobin::on_wrrobinbtn_clicked()
{
    wrrobin1 = new Wroundrobin(this);
    wrrobin1->show();
    this->close();
}
