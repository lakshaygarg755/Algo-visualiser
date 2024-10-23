#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QLabel>
#include <QPixmap>
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>
#include <QParallelAnimationGroup>
#include "leaky.h"
#include "token.h"
#include "roundrobin.h"
#include "wroundrobin.h"
#include "fcfs.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void clearmainwindow();

private slots:
    void on_fcfsbtn_clicked();

    void on_leakybtn_clicked();

    void on_tokenbtn_clicked();

    void on_robinbtn_clicked();

    void on_wrrobinbtn_clicked();

    void closewindow();

private:
    Ui::MainWindow *ui;

    QTextEdit *text1,*text2,*text3,*text4,*text5;
    QLabel *packet1,*packet2,*packet3,*question;
    QLabel *img;
    QPropertyAnimation *ani1,*ani2,*ani3,*ani4;
    QSequentialAnimationGroup *seqani;
    QParallelAnimationGroup *parani;
    Fcfs *fcfs1;
    Leaky *leaky1;
    Token *token1;
    Roundrobin *rrobin1;
    Wroundrobin *wrrobin1;
};
#endif // MAINWINDOW_H
