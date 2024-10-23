#ifndef WROUNDROBIN_H
#define WROUNDROBIN_H

#include <QMainWindow>
#include <QTextEdit>
#include <QLabel>
#include <QPixmap>
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>
#include <QParallelAnimationGroup>
#include <QVector>
#include <QStack>
#include <QString>
#include <QMessageBox>
#include <algorithm>
#include <QFrame>
#include "leaky.h"
#include "roundrobin.h"
// #include "wroundrobin.h"
#include "fcfs.h"
#include "token.h"

class Fcfs;
class Leaky;
class Token;
class Roundrobin;

namespace Ui {
class Wroundrobin;
}

class Wroundrobin : public QMainWindow
{
    Q_OBJECT

public:
    explicit Wroundrobin(QWidget *parent = nullptr);
    ~Wroundrobin();
    void clearwindow();

private slots:
    void on_explain_clicked();

    void on_visualise_clicked();

    void on_insert_clicked();

    void on_start_clicked();

    void on_reset_clicked();

    void on_fcfsbtn_clicked();

    void on_leakybtn_clicked();

    void on_tokenbtn_clicked();

    void on_robinbtn_clicked();

private:
    Ui::Wroundrobin *ui;
    int packetqnta,flowcnt,pktscnt,stacky,stackx = 10,i=0;
    QLabel *label;
    QTextEdit *text;
    QVector<QTextEdit*> textvec;
    QVector<QLabel*> labelvec;
    QFrame *rect;
    QStack<QLabel*> flowstk;
    QStack<QLabel*> end;
    QVector<QStack<QLabel*>> waitq;
    QVector<int> weights;
    int w=0;
    QPropertyAnimation *animation1;
    QSequentialAnimationGroup *seqanimation;
    QParallelAnimationGroup *paranimation;
    Fcfs *fcfs1;
    Leaky *leaky1;
    Token *token1;
    Roundrobin *rrobin1;
};

#endif // WROUNDROBIN_H
