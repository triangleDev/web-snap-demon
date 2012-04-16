#ifndef DEMON_H
#define DEMON_H

#include <QObject>
#include <qwebrender.h>
#include <QTimer>
#include "xmlrpc/client.h"
#include <QVariantList>

class Demon : public QObject
{
    Q_OBJECT
public:
    explicit Demon(QObject *parent = 0);
    
signals:
    
private:
    void reportBroken(const QMap<QString,xmlrpc::Variant> &item);
public slots:
    void saveImage(bool ok);
private slots:
    void requestTask();
    void processReturnValue(int requestId, QVariant value);
    void processFault( int requestId, int errorCode, QString errorString );
private:
    QWebRender render;
    QTimer *timer;
    int requestId;
    bool task;
    QVariantList shots;
    int timout;
    QString path_tmp;
    xmlrpc::Client *client;
    QString meta_js;
};

#endif // DEMON_H
