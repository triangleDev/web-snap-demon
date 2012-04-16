#include "demon.h"
#include <QDebug>
#include <QWebFrame>

Demon::Demon(QObject *parent) :
    QObject(parent)
{
    QObject::connect(&render, SIGNAL(loaded(bool)),this, SLOT(saveImage(bool)));
    task = false;
    timout = 90000;
    path_tmp = QDir::tempPath() + QDir::toNativeSeparators("/");
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(requestTask()));
    client = new xmlrpc::Client();
    connect( client, SIGNAL(done( int, QVariant )),
                     this, SLOT(processReturnValue( int, QVariant )) );
    connect( client, SIGNAL(failed( int, int, QString )),
                     this, SLOT(processFault( int, int, QString )) );
    meta_js = "function getMetaContents(mn){var m = document.getElementsByTagName('meta');for(var i in m){ if(m[i].name == mn){return m[i].content;}}}getMetaContents('%1');";

    QString host;
    QString path;
    int port = 80;
    QStringList _argv = qApp->arguments();
    for(int i = 0; i < _argv.count(); ++i) {
        if ( _argv[i] == "-h")
            host = _argv[++i];
        if ( _argv[i] == "-p")
            port = QString(_argv[++i]).toInt();
        if ( _argv[i] == "-path")
            path = _argv[++i];
    }

    if (host.isEmpty()){
        qFatal("host must be not empty");
        exit(-2);
    }

    timer->start(timout);
    client->setHost(host,port,path);
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
    QWebFrame *frame = render.getFrame();
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
        if (f.exists() && ok){
            QImage image(path_tmp + file);
            QByteArray byteArray;
            QBuffer buffer(&byteArray);
            image.save(&buffer,shot.value("ext","PNG").toString().toUpper().toLocal8Bit());
            image_.insert("image", byteArray.toBase64());
            image_.insert("file", file);
            image_.insert("url_title", render.documentTitle());

            image_.insert("url_keywords", frame->evaluateJavaScript(meta_js.arg("keywords")).toString().toLocal8Bit());
            image_.insert("url_description", frame->evaluateJavaScript(meta_js.arg("description")).toString().toLocal8Bit());
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
