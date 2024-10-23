#include "wroundrobin.h"
#include "ui_wroundrobin.h"

Wroundrobin::Wroundrobin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Wroundrobin)
{
    ui->setupUi(this);
    ui->line1->hide();
    ui->line2->hide();
    ui->line3->hide();
    ui->insert->hide();
    ui->start->hide();
    ui->reset->hide();
}

Wroundrobin::~Wroundrobin()
{
    delete ui;
}

void Wroundrobin::on_explain_clicked()
{
    clearwindow();
    text = new QTextEdit(this);
    text->setGeometry(20,100,1200,700);
    text->setText("The Weighted Round Robin (WRR) scheduling algorithm is an enhancement of the traditional Round Robin method. "
                  "It assigns different weights to tasks, processes, or packets, allowing for priority handling. The higher the weight, the more CPU time or bandwidth is allocated to that process.\n\n"
                  "Steps Involved in the Algorithm\n"
                  "1. Process Queue with Weights: Incoming processes or packets are placed in a queue, each assigned a weight according to priority.\n"
                  "2. Time Quantum Distribution: Based on the assigned weights, each process receives a proportion of time quantum. Higher-weight processes receive more time compared to lower-weight ones.\n"
                  "3. Scheduling Cycle: The scheduler allocates CPU or bandwidth in rounds, giving more resources to higher-weight processes, while still ensuring that all processes get a chance to run.\n"
                  "4. Repeating Cycle: This cycle repeats, ensuring processes with more weight receive more resources, while maintaining fairness across the queue.\n\n"
                  "Advantages\n"
                  "1. Fair Resource Allocation: Ensures that processes are given resources based on their importance or priority.\n"
                  "2. Flexibility: Can handle scenarios where some processes need more resources without starving smaller tasks.\n\n"
                  "Disadvantages\n"
                  "1. Complexity: More complex to implement than standard Round Robin due to the calculation of weights and dynamic allocation.\n"
                  "2. Potential Inefficiency: If weights are improperly assigned, lower-priority tasks may still experience delays or underutilization.\n");
    text->setStyleSheet("border:0px;color:black;font:18px");
    text->setReadOnly(true);
    text->show();
    textvec.append(text);

    ui->line1->hide();
    ui->line2->hide();
    ui->line3->hide();
    ui->insert->hide();
    ui->start->hide();
    ui->reset->hide();
    // rect->hide();
}


void Wroundrobin::on_visualise_clicked()
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
    ui->line2->show();
    ui->line3->show();
    ui->insert->show();
    ui->start->show();
    ui->reset->show();

}

void Wroundrobin::clearwindow()
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

void Wroundrobin::on_insert_clicked()
{
    seqanimation = new QSequentialAnimationGroup(this);
    pktscnt = ui->line3->text().toInt();
    int t = ui->line2->text().toInt();
    if(t>9 || t < 1)
    {
        QMessageBox msg;
        msg.setText("weight is out of bound");
        msg.setStyleSheet("QLabel { color: black; }"
                          "QPushButton { color: black; }"
                          "QMessageBox { background-color: white; }");
        msg.exec();
        return;
    }
    weights.append(t);
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


void Wroundrobin::on_start_clicked()
{
    ui->start->setText("Next time seq.");
    ui->insert->setEnabled(false);  // Disable insert during scheduling process

    // Get the packet quanta from the input field
    packetqnta = ui->line1->text().toInt();

    // Validate packet quantum
    if(packetqnta < 1)
    {
        QMessageBox msg;
        msg.setText("Packets Quanta out of bound");
        msg.setStyleSheet("QLabel { color: black; }"
                          "QPushButton { color: black; }"
                          "QMessageBox { background-color: white; }");
        msg.exec();
        return;
    }
    if(waitq.empty())
    {
        QMessageBox msg;
        msg.setText("Waiting queue is already empty");
        msg.setStyleSheet("QLabel { color: black; }"
                          "QPushButton { color: black; }"
                          "QMessageBox { background-color: white; }");
        msg.exec();
        return;
    }

    ui->line1->setReadOnly(true);
    ui->line3->setReadOnly(true);

    if (i >= waitq.size()) {
        i = 0;
    }

    if(w == 0)
    {
        w = weights.at(i);
    }

    if(w > 0)
    {
        seqanimation = new QSequentialAnimationGroup(this);
        paranimation = new QParallelAnimationGroup(this);
        int mini = std::min(static_cast<int>(waitq.at(i).size()), packetqnta);

        for(int j = 0; j < mini; j++)
        {
            if (waitq.at(i).isEmpty()) break;  // Check if the flow is empty
            animation1 = new QPropertyAnimation(waitq.at(i).back(), "geometry");
            animation1->setDuration(1500);
            animation1->setEndValue(QRect(130, 100, 20, 40));  // Example coordinates (adjust as needed)
            paranimation->addAnimation(animation1);

            end.push(waitq.at(i).back());
            waitq[i].pop_back();
        }

        w--;

        if(waitq.at(i).isEmpty())
        {
            waitq.removeAt(i);
            weights.removeAt(i);

            if (i >= waitq.size()) {
                i = 0;
            }

            w = 0;
        }
        else if (w == 0)
        {
            i++;
            if (i >= waitq.size()) {
                i = 0;
            }
        }
        seqanimation->addAnimation(paranimation);
        seqanimation->start();
    }
    else
    {
        i++;
    }
}


void Wroundrobin::on_reset_clicked()
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
    weights.clear();
    ui->line1->clear();
    ui->line3->clear();
    ui->line1->setReadOnly(false);
    ui->line3->setReadOnly(false);
}


void Wroundrobin::on_fcfsbtn_clicked()
{
    fcfs1 = new Fcfs(this);
    fcfs1->show();
    this->close();
}


void Wroundrobin::on_leakybtn_clicked()
{
    leaky1 = new Leaky(this);
    leaky1->show();
    this->close();
}


void Wroundrobin::on_tokenbtn_clicked()
{
    token1 = new Token(this);
    token1->show();
    this->close();
}


void Wroundrobin::on_robinbtn_clicked()
{
    rrobin1 = new Roundrobin(this);
    rrobin1->show();
    this->close();
}

