#include <QApplication>
#include <demon.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Demon demon;

    return a.exec();
}
