#ifndef DEMON_H
#define DEMON_H

#include <QObject>
#include <qwebrender.h>
#include <QTimer>
#include "xmlrpc/client.h"

class Demon : public QObject
{
    Q_OBJECT
public:
    explicit Demon(QObject *parent = 0);
    
signals:
    
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
    xmlrpc::Client *client;
};

#endif // DEMON_H
