#ifndef WEBCAPTURE_H
#define WEBCAPTURE_H

#include "webpage.h"

class WebCapture : public QObject
{
    Q_OBJECT

    public:
        WebCapture();
        void load(const QUrl &url);
        void image(const QString &outputFileName, int width, int height ,int zoom);
    signals:
        void finished(bool);

    private slots:
        void saveResult(bool ok);
        void showProgress(int percent);
    private:
        webPage page_;
        int zoom_;
};


#endif // WEBCAPTURE_H
