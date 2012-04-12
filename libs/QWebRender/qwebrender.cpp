#include "qwebrender.h"


// shamelessly copied from Qt Demo Browser
static QUrl guessUrlFromString(const QString &string)
{
    QString urlStr = string.trimmed();
    QRegExp test(QLatin1String("^[a-zA-Z]+\\:.*"));

    // Check if it looks like a qualified URL. Try parsing it and see.
    bool hasSchema = test.exactMatch(urlStr);
    if (hasSchema) {
        QUrl url(urlStr, QUrl::TolerantMode);
        if (url.isValid())
            return url;
    }

    // Might be a file.
    if (QFile::exists(urlStr))
        return QUrl::fromLocalFile(urlStr);

    // Fall back to QUrl's own tolerant parser.
    if (hasSchema)
        return QUrl(string, QUrl::TolerantMode);

    // Might be a shorturl - try to detect the schema.
    int dotIndex = urlStr.indexOf(QLatin1Char('.'));
    if (dotIndex != -1) {
        QString prefix = urlStr.left(dotIndex).toLower();
        QString schema = (prefix == QLatin1String("ftp")) ? prefix : QLatin1String("http");
        QUrl url(schema + QLatin1String("://") + urlStr, QUrl::TolerantMode);
        if (url.isValid())
            return url;
        }
     return QUrl(string, QUrl::TolerantMode);
}

QWebRender::QWebRender()
    :QObject()
{
    m_size = QSize(350,600);
    m_zoom = 100;
    QObject::connect(&webCapture, SIGNAL(finished()), this, SLOT(loadFinished()));
}

void QWebRender::setSize(const QSize &size)
{
    m_size = size;
}

void QWebRender::renderImage( const QString &fileName, int width, int height, int zoom)
{
    webCapture.image(fileName, width, height, zoom);
}

void QWebRender::renderImage( const QString &fileName, QSize size, int zoom)
{
    renderImage(fileName, size.width(), size.height(), zoom);
}

void QWebRender::renderImage( const QString &fileName, QSize size)
{
    renderImage(fileName, size, m_zoom);
}

void QWebRender::renderImage( const QString &fileName)
{
    renderImage(fileName, m_size, m_zoom);
}

void QWebRender::load(const QString &url)
{
    load(guessUrlFromString(url));
}

void QWebRender::load(const QUrl &url)
{
    webCapture.load(url);
}

void QWebRender::loadFinished()
{
    emit(loaded());
}

