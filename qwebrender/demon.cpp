#include "demon.h"
#include <QDebug>

Demon::Demon(QObject *parent) :
    QObject(parent)
{
    QObject::connect(&render, SIGNAL(loaded(bool)),this, SLOT(saveImage(bool)));
    render.load("http://krugfff/");
}

void Demon::saveImage(bool ok)
{
    if (! ok)
    {
        qDebug()<< "error";
        return;
    }
    render.renderImage("/opt/blabla.jpg");
}
