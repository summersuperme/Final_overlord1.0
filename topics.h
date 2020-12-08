#ifndef TOPICS_H
#define TOPICS_H

#include <QString>
#include <QDebug>
class topics
{
public:
    topics();
public:
    void settext(QString &text)
    {
        QString realtext = dealfile(text);
        this->text = realtext;
    }
    void setQnum(int &num)
    {
        this->Qnum = num;
    }

    QString gettext() const
    {
        return this->text;
    }

    int getQnum() const
    {
        return this->Qnum;
    }
    void setanswer(QString &answer)
    {
        this->answer = answer;
    }
    QString getanswer() const
    {
        return this->answer;
    }
    QString dealfile(QString &text);
private:
    QString text;
    int Qnum;
    QString answer;
};

#endif // TOPICS_H
