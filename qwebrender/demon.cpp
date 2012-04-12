#include "demon.h"

Demon::Demon(QObject *parent) :
    QObject(parent)
{
    QObject::connect(&render, SIGNAL(loaded()),this, SLOT(saveImage()));
    render.load("http://google.com/");
}

void Demon::saveImage()
{
    render.renderImage("/opt/blabla.png");
}
