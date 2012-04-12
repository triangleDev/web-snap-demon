#ifndef WEBCAPTURE_H
#define WEBCAPTURE_H

#include "webpage.h"

class WebCapture : public QObject
{
    Q_OBJECT

    public:
        WebCapture();
        void load(const QUrl &url);
        bool image(const QString &outputFileName, int width, int height ,int zoom);
    signals:
        void finished();

    private slots:
        void saveResult(bool ok);

    private:
        webPage page_;
        int zoom_;
};


#endif // WEBCAPTURE_H
