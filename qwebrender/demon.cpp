#include "demon.h"
#include <QDebug>

Demon::Demon(QObject *parent) :
    QObject(parent)
{
    QObject::connect(&render, SIGNAL(loaded(bool)),this, SLOT(saveImage(bool)));
    task = false;
    timout = 90000;
    path_tmp = QDir::tempPath() + QDir::toNativeSeparators("/");
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(requestTask()));
    timer->start(timout);
    client = new xmlrpc::Client();
    client->setHost("speeddial",80,"/demon");
    connect( client, SIGNAL(done( int, QVariant )),
                     this, SLOT(processReturnValue( int, QVariant )) );
    connect( client, SIGNAL(failed( int, int, QString )),
                     this, SLOT(processFault( int, int, QString )) );
}

void Demon::reportBroken(const QMap<QString,xmlrpc::Variant> &item)
{
    client->request("speeddial.brokenImage",item);
}

void Demon::saveImage(bool ok)
{
    if (shots.isEmpty()){
        return;
    }
    foreach(QVariant item, shots)
    {
        QVariantMap shot = item.toMap();
        QString tmp_file = shot.value("id").toString() + shot.value("link").toString();
        QString file = QString(QCryptographicHash::hash(tmp_file.toLocal8Bit(),QCryptographicHash::Md5).toHex())
                + "." + shot.value("ext","png").toString();
        render.renderImage(path_tmp + file, shot.value("width", 500).toInt(),shot.value("height", 400).toInt(),100);
        QMap<QString,xmlrpc::Variant> image_;

        foreach(QString key, shot.keys()){
            QVariant val = shot.value(key);
            image_.insert(key, val.toString());
        }

        QFile f(path_tmp + file);
        if (f.exists() && ! ok){
            QImage image(path_tmp + file);
            QByteArray byteArray;
            QBuffer buffer(&byteArray);
            image.save(&buffer,shot.value("ext","PNG").toString().toUpper().toLocal8Bit());
            image_.insert("image", byteArray.toBase64());
            image_.insert("file", file);
            client->request("speeddial.saveImage",image_);
        }
        else {
            reportBroken(image_);
        }
    }
    timer->start(timout);
}

void Demon::requestTask()
{

    timer->stop();
    requestId = client->request("speeddial.gettask");
    task = true;
}

void Demon::processReturnValue(int requestId, QVariant value)
{
    if (task)
    {
        task = false;
        if (value.toList().isEmpty())
        {
            timer->start(timout);
            return;
        }
        shots = value.toList();
        QVariantMap first= shots.first().toMap();
        render.load(first.value("link").toString());
    }
}

void Demon::processFault(int requestId, int errorCode, QString errorString)
{
    qDebug()<<errorCode<<errorString;
}
