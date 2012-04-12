#ifndef WEBCAPTURE_H
#define WEBCAPTURE_H

#include "webpage.h"

class WebCapture : public QObject
{
    Q_OBJECT

    public:
        WebCapture();
        void load(const QUrl &url, int zoom, const QString &outputFileName, int width);

    signals:
        void finished();

    private slots:
        void saveResult(bool ok);

    private:
        webPage page_;
        QString fileName_;
        int zoom_;
};


#endif // WEBCAPTURE_H
