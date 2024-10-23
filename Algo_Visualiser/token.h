#ifndef TOKEN_H
#define TOKEN_H

#include <QMainWindow>
#include <QTextEdit>
#include <QLabel>
#include <QPixmap>
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>
#include <QParallelAnimationGroup>
#include <QVector>
#include <QString>
#include <QMessageBox>
#include <algorithm>
#include "leaky.h"
#include "roundrobin.h"
#include "wroundrobin.h"
#include "fcfs.h"

class Fcfs;
class Leaky;
class Roundrobin;
class Wroundrobin;

namespace Ui {
class Token;
}

class Token : public QMainWindow
{
    Q_OBJECT

public:
    explicit Token(QWidget *parent = nullptr);
    ~Token();

    void drawtokens();
    void drawpackets();
    void reset();
    void clearmainwindow();

private slots:
    void on_explain_clicked();

    void on_visualise_clicked();

    void on_rateset_clicked();

    void on_insert_clicked();

    void on_timeseq_clicked();

    void on_reset_clicked();

    void on_fcfsbtn_clicked();

    void on_wrrobinbtn_clicked();

    void on_leakybtn_clicked();

    void on_robinbtn_clicked();

private:
    Ui::Token *ui;
    QTextEdit *text;
    QLabel *label;
    QPropertyAnimation *animation1;
    QSequentialAnimationGroup *animationgp;
    QParallelAnimationGroup *paranimation;
    QVector<QTextEdit*> textvec;
    QVector<QLabel*> labelvec;
    int tokenrate = -1,tokentop=791,packetscnt=0,tokensinbkt=0;
    QVector<QLabel*> tokenstk;
    QVector<int> packetsvec;
    int numoftime = 0;
    int j=0,n=-1;
    int tokenheight =0;
    Fcfs *fcfs1;
    Leaky *leaky1;
    Roundrobin *rrobin1;
    Wroundrobin *wrrobin1;
};

#endif // TOKEN_H
