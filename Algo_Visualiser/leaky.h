#ifndef LEAKY_H
#define LEAKY_H

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
#include "token.h"
#include "roundrobin.h"
#include "wroundrobin.h"
#include "fcfs.h"

class Fcfs;
class Token;
class Roundrobin;
class Wroundrobin;

namespace Ui {
class Leaky;
}

class Leaky : public QMainWindow
{
    Q_OBJECT

public:
    explicit Leaky(QWidget *parent = nullptr);
    ~Leaky();
    void clearmainwindow();

private slots:
    void on_explain_clicked();

    void on_visualise_clicked();

    void on_rateset_clicked();

    void on_insert_clicked();

    void on_timeseq_clicked();

    void on_reset_clicked();

    void on_fcfsbtn_clicked();

    void on_tokenbtn_clicked();

    void on_robinbtn_clicked();

    void on_wrrobinbtn_clicked();

private:
    Ui::Leaky *ui;
    QTextEdit *text;
    QLabel *label;
    QPropertyAnimation *animation1;
    QSequentialAnimationGroup *animationgp;
    QParallelAnimationGroup *paranimation;
    QVector<QTextEdit*> textvec;
    QVector<QLabel*> labelvec;
    int outputFlowRate=0,numoftime=0;
    int packetsinbucket=0,packetsdropped=0,packetssent,newpackets;
    int bkttop = 791;
    QVector<int> packetsvec;
    QVector<QLabel*> packetv;
    int j = 0;
    Fcfs *fcfs1;
    Token *token1;
    Roundrobin *rrobin1;
    Wroundrobin *wrrobin1;
};

#endif // LEAKY_H
