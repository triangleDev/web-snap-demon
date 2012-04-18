#include <QApplication>
#include <demon.h>
#include <QSystemTrayIcon>
#include <QPainter>
#include <QDebug>

#include <QFile>
#include <QStringList>
#include <QProcess>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Demon demon;
    QPixmap img("/opt/hg/allwebsuite/survey/media/img/icons/box-table-password.png");
    QPainter p(&img);
    p.drawEllipse(7,10, 7,7);
    p.fillRect(7,10, 7,7,QBrush(Qt::green));
    p.drawText(10,15,QString::number(12));
    p.end();
    QSystemTrayIcon *tray = new QSystemTrayIcon();
    qDebug()<<QApplication::applicationPid();
    int pid = QApplication::applicationPid();
    QFile file(QString("/proc/%1/status").arg(pid));
    file.open(QIODevice::ReadOnly);
    QString content = file.readAll();
    QString pattern = "%1:\\s+(\\d+)";
    int total;
    QStringList memoryVars = QStringList() << "VmSize"<< "VmHWM" << "VmRSS"
                             << "VmData" << "VmLib" << "VmSwap";
    foreach(QString key, memoryVars) {
        QRegExp reg(pattern.arg(key));
        int pos = reg.indexIn(content);
        if ( pos > -1) {qDebug()<<reg.cap(1).toInt();
            total += reg.cap(1).toInt();
        }
    }
    if (total > 4874228) {
        QString program = a.applicationFilePath();
        QProcess *myProcess = new QProcess();
        myProcess->start(a.applicationFilePath(), a.arguments());
        myProcess->waitForStarted();
        qDebug()<< myProcess->pid();
        exit(0);
    }
    tray->setIcon(img);
    tray->show();

    return a.exec();
}
