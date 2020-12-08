#include "topics.h"

topics::topics()
{

}

QString topics::dealfile(QString &text)
{
    QString realtext = QString("%1").arg(Qnum);
    realtext += ".";
    QString answer;
    QStringList Qlist;
    Qlist = text.split('\n');
    for(int i=0;i<Qlist.size();i++)
    {
        if(Qlist[i].contains("答案:",Qt::CaseInsensitive))
        {
            realtext += text.remove(Qlist[i]);
            answer = Qlist[i].remove("答案:");
            break;
        }
    }
    setanswer(answer);
    return realtext;
}
