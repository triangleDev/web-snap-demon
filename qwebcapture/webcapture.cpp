
#include <QtWebKit>

#include "webcapture.h"

WebCapture::WebCapture()
    : QObject(), zoom_(100)
{
    connect(&page_, SIGNAL(loadFinished(bool)), this, SLOT(saveResult(bool)));

    QWebSettings *settings = page_.settings();

    settings->setAttribute(QWebSettings::AutoLoadImages, true);
    settings->setAttribute(QWebSettings::DnsPrefetchEnabled, true);
    settings->setAttribute(QWebSettings::JavascriptEnabled, true);
    settings->setAttribute(QWebSettings::PluginsEnabled, true);
    settings->setAttribute(QWebSettings::JavascriptCanOpenWindows, false);
    settings->setAttribute(QWebSettings::JavascriptCanAccessClipboard, false);
    settings->setAttribute(QWebSettings::DeveloperExtrasEnabled, false);
    settings->setAttribute(QWebSettings::LinksIncludedInFocusChain, false);
    settings->setAttribute(QWebSettings::ZoomTextOnly, false);
    settings->setAttribute(QWebSettings::PrintElementBackgrounds, true);
}


void WebCapture::load(const QUrl &url, int zoom, const QString &outputFileName, int width)
{
    zoom_ = zoom;
    fileName_ = outputFileName;

    QWebFrame *frame = page_.mainFrame();
    frame->load(url);
    frame->setScrollBarPolicy(Qt::Vertical, Qt::ScrollBarAlwaysOff);
    frame->setScrollBarPolicy(Qt::Horizontal, Qt::ScrollBarAlwaysOff);

    qreal factor = static_cast<qreal>(zoom_) / 100.0;
#if QT_VERSION < 0x040500
    page_.setViewportSize(QSize(width, 3 * width / 4) / factor);
#else
    page_.mainFrame()->setZoomFactor(factor);
    page_.setViewportSize(QSize(width, 3 * width / 4));
#endif
}

void WebCapture::saveResult(bool ok)
{
    if (!ok) {
        emit( finished() );
        qApp->exit( -1 );
        return;
    }

    // create the image for the buffer
    QSize size = page_.mainFrame()->contentsSize();
    // we dont need more
    const int maxHeight = size.width() + 100;
    if(size.height() > maxHeight )
        size.setHeight( maxHeight );

    QImage image = QImage(size, QImage::Format_ARGB32);
    image.fill(Qt::transparent);

    // render the web page
    QPainter p(&image);
    p.setRenderHint(QPainter::Antialiasing, true);
    p.setRenderHint(QPainter::TextAntialiasing, true);
    p.setRenderHint(QPainter::SmoothPixmapTransform, true);
    page_.setViewportSize(size);
    page_.mainFrame()->render(&p);
    p.end();

#if QT_VERSION < 0x040500
    // scale, since we don't have full page zoom
    qreal factor = static_cast<qreal>(zoom_) / 100.0;
    image = image.scaled(size * factor, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
#endif
    image = image.scaled(QSize(250,381), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    image.save( fileName_ );
    emit( finished() );
}
