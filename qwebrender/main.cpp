#include <QApplication>
#include <demon.h>
#include <QSystemTrayIcon>
#include <QPainter>
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
    ;
    tray->setIcon(img);
    tray->show();

    return a.exec();
}
