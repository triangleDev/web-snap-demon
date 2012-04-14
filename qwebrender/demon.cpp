#include "demon.h"
#include <QDebug>

Demon::Demon(QObject *parent) :
    QObject(parent)
{
    QObject::connect(&render, SIGNAL(loaded(bool)),this, SLOT(saveImage(bool)));
    ///render.load("http://krug/");
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(requestTask()));
    //timer->start(90000);
    client = new xmlrpc::Client();
    client->setHost("speeddial",80,"/demon");
    connect( client, SIGNAL(done( int, QVariant )),
                     this, SLOT(processReturnValue( int, QVariant )) );
    connect( client, SIGNAL(failed( int, int, QString )),
                     this, SLOT(processFault( int, int, QString )) );
    requestId = client->request("speeddial.gettask");
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

void Demon::requestTask()
{
    qDebug()<< "request for task";
    timer->stop();
}

void Demon::processReturnValue(int requestId, QVariant value)
{
    qDebug()<<value;
}

void Demon::processFault(int requestId, int errorCode, QString errorString)
{
    qDebug()<<errorCode<<errorString;
}
