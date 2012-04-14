#ifndef DEMON_H
#define DEMON_H

#include <QObject>
#include <qwebrender.h>

class Demon : public QObject
{
    Q_OBJECT
public:
    explicit Demon(QObject *parent = 0);
    
signals:
    
public slots:
    void saveImage(bool ok);
private:
    QWebRender render;
};

#endif // DEMON_H
