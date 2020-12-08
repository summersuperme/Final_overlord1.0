#include "mainwin.h"
#include "ui_mainwin.h"

MainWin::MainWin(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWin)
{
    QFont font = QFont("Microsoft YaHei",20,2);
    ui->setupUi(this);
    ui->textEdit->setFont(font);
    first = 1;
}

MainWin::~MainWin()
{
    delete ui;
}


void MainWin::on_open_clicked()
{
    topics temp;
    int i=1;
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    "/home",
                                                    tr("ALL files(*.*);;Images (*.png *.xpm *.jpg)"));
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this,"文件","打开失败");
        return;
    }
    QTextStream txtInput(&file);
    QString linestr;
    QString line;
    while (!file.atEnd()) {
        while(!line.contains("答案:", Qt::CaseInsensitive))
        {
            line = file.readLine();
            linestr += line;
        }
        temp.setQnum(i);
        temp.settext(linestr);
        list.append(temp);
        i++;
        linestr.clear();
        line = file.readLine();
        linestr += line;
    }
    file.close();
    this->ui->textEdit->setText(list.at(0).gettext());
    curnum = 0;
}

void MainWin::on_next_clicked()
{
    if(first){
        {
            if(curnum < list.size()-1)
            {
                curnum++;
                this->ui->textEdit->setText(list.at(curnum).gettext());
            }else{
                QMessageBox::warning(this,"错误","当前是最后一题!!");
                return;
            }
        }
    }
}

void MainWin::on_last_clicked()
{
    if(curnum > 0)
    {
        curnum--;
        this->ui->textEdit->setText(list.at(curnum).gettext());
    }else{
        QMessageBox::warning(this,"错误","当前是第一题!!");
        return;
    }
}

void MainWin::on_answer_1_clicked()
{
    if(list.at(curnum).getanswer() != 'A')
    {
        QMessageBox::information(this,"信息","判断错误!");
    }else{
        QMessageBox::information(this,"信息","回答正确!");
        on_next_clicked();
    }
}

void MainWin::on_answer_2_clicked()
{
    if(list.at(curnum).getanswer() != 'B')
    {
        QMessageBox::information(this,"信息","判断错误!");
    }else{
        QMessageBox::information(this,"信息","回答正确!");
        on_next_clicked();
    }
}

void MainWin::on_answer_3_clicked()
{
    if(list.at(curnum).getanswer() != 'C')
    {
        QMessageBox::information(this,"信息","判断错误!");
    }else{
        QMessageBox::information(this,"信息","回答正确!");
        on_next_clicked();
    }
}

void MainWin::on_answer_4_clicked()
{
    if(list.at(curnum).getanswer() != 'D')
    {
        QMessageBox::information(this,"信息","判断错误!");
    }else{
        QMessageBox::information(this,"信息","回答正确!");
        on_next_clicked();
    }
}
