#ifndef ROUNDROBIN_H
#define ROUNDROBIN_H

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
#include "token.h"
#include "wroundrobin.h"
#include "fcfs.h"

class Fcfs;
class Leaky;
class Token;
class Wroundrobin;

namespace Ui {
class Roundrobin;
}

class Roundrobin : public QMainWindow
{
    Q_OBJECT

public:
    explicit Roundrobin(QWidget *parent = nullptr);
    ~Roundrobin();

    void clearwindow();

private slots:
    void on_visualise_clicked();

    void on_insert_clicked();

    void on_start_clicked();

    void on_reset_clicked();

    void on_fcfsbtn_clicked();

    void on_leakybtn_clicked();

    void on_tokenbtn_clicked();

    void on_wrrobinbtn_clicked();

    void on_explain_clicked();

private:
    Ui::Roundrobin *ui;
    int packetqnta,flowcnt,pktscnt,stacky,stackx = 10,i=0;
    QLabel *label;
    QTextEdit *text;
    QVector<QTextEdit*> textvec;
    QVector<QLabel*> labelvec;
    QFrame *rect;
    QStack<QLabel*> flowstk;
    QStack<QLabel*> end;
    QVector<QStack<QLabel*>> waitq;

    QPropertyAnimation *animation1;
    QSequentialAnimationGroup *seqanimation;
    QParallelAnimationGroup *paranimation;
    Fcfs *fcfs1;
    Leaky *leaky1;
    Token *token1;
    Wroundrobin *wrrobin1;
};

#endif // ROUNDROBIN_H
