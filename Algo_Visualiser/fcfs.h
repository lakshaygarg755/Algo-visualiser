#ifndef FCFS_H
#define FCFS_H

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
#include "leaky.h"
#include "token.h"
#include "roundrobin.h"
#include "wroundrobin.h"
// #include "mainwindow.h"

class Leaky;
class Token;
class Roundrobin;
class Wroundrobin;
// class MainWindow;

namespace Ui {
class Fcfs;
}

class Fcfs : public QMainWindow
{
    Q_OBJECT

public:
    explicit Fcfs(QWidget *parent = nullptr);
    ~Fcfs();

    void clearmainwindow();
    void overflow();

private slots:
    void on_explain_clicked();

    void on_visualise_clicked();

    void on_rateset_clicked();

    void on_insert_clicked();

    void on_timeseq_clicked();

    void on_reset_clicked();

    void on_leakybtn_clicked();

    void on_tokenbtn_clicked();

    void on_robinbtn_clicked();

    void on_wrrobinbtn1_clicked();

private:
    Ui::Fcfs *ui;

    QTextEdit *text;
    QLabel *label;
    QPropertyAnimation *animation1;
    QSequentialAnimationGroup *animationgp;
    QParallelAnimationGroup *paranimation;
    QVector<QTextEdit*> textvec;
    QVector<QLabel*> labelvec;
    int buffertime=0,numoftime=0;
    int packetsinbucket=0,packetsdropped=0,packetssent,newpackets;
    int bkttop = 791;
    QVector<int> packetsvec;
    QVector<QLabel*> packetv;
    int j = 0;
    Leaky *leaky1;
    Token *token1;
    Roundrobin *rrobin1;
    Wroundrobin *wrrobin1;
    // MainWindow *mainwin;
};

#endif // FCFS_H
