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
    QString str("<dadada> <https://dasdada.com/djadadada/dad>");
    QRegExp regexp("<(.+)>");
    
    regexp.setMinimal(true);
    int pos = 0;
    qDebug()<<regexp.indexIn(str, pos);
    while((pos = regexp.indexIn(str, pos)) != -1) {
        qDebug()<<regexp.cap(1)<< " | " << pos;
        pos += regexp.matchedLength();    
    }
    return ax.exec();
}
