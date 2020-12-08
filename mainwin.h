#ifndef MAINWIN_H
#define MAINWIN_H

#include <QWidget>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <QList>
#include "topics.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWin; }
QT_END_NAMESPACE

class MainWin : public QWidget
{
    Q_OBJECT

public:
    MainWin(QWidget *parent = nullptr);
    ~MainWin();

private slots:
    void on_open_clicked();

    void on_next_clicked();

    void on_last_clicked();

    void on_answer_1_clicked();

    void on_answer_2_clicked();

    void on_answer_3_clicked();

    void on_answer_4_clicked();

private:
    Ui::MainWin *ui;
    QList<topics> list;
    int curnum;
    int first;
};
#endif // MAINWIN_H
