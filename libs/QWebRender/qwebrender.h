#ifndef QWEBRENDER_H
#define QWEBRENDER_H

#include <QObject>
#include "QWebRender_global.h"
#include <QSize>
#include <QFile>
#include <QUrl>
#include <webcapture.h>
#include <QPointer>


#include <QDebug>

class QWEBRENDERSHARED_EXPORT QWebRender : public QObject{
    Q_OBJECT
public:
    QWebRender();
    void setSize(const QSize &size);
    inline void setWidth(int width) { m_size.setWidth(width);}
    inline void setHeight(int height) { m_size.setHeight(height);}
    inline void setZoom(int zoom) { m_zoom = zoom;}
    void renderImage(const QString &fileName, int width, int height, int zoom);
    void renderImage(const QString &fileName, QSize size, int zoom);
    void renderImage(const QString &fileName, QSize size);
    void renderImage(const QString &fileName);
    void load(const QString &url);
    void load(const QUrl &url);
    void cleanUp();

signals:
    void loaded(bool);

private slots:
    void loadFinished(bool ok);

private:
    QSize m_size;
    int m_zoom;
    WebCapture *webCapture;
};

#endif // QWEBRENDER_H
