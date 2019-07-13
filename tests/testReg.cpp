#include <QApplication>
#include <QObject>
#include <QDebug>
#include <QRegularExpression>
#include <QRegExp>
#include <QString>
#include <QStringList>


int main(int argc, char *argv[])
{
    QApplication ax(argc, argv);
    QString str("<dadada>    <https://dasdada.com/djadadada/dad> <img src=\"qqq\">");
    QRegExp regexp("<img(.+)>");
    QRegExp regexp2("src=\"(.+)\"");
    QRegExp regexpq("\\s+");
    
    regexp.setMinimal(true);
    regexp2.setMinimal(true);
    int pos = 0;
    int pos2 = 0;
    while((pos = regexp.indexIn(str, pos)) != -1) {
        QString ans = regexp.cap(1);
        qDebug()<<ans<< " | " << pos;
        pos += regexp.matchedLength(); 
        regexp2.indexIn(ans, 0);
        qDebug()<<regexp2.cap(1);
    }
    qDebug()<<str.replace(regexpq, "|||");
    return ax.exec();
}
