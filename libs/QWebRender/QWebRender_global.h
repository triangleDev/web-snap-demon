#ifndef QWEBRENDER_GLOBAL_H
#define QWEBRENDER_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(QWEBRENDER_LIBRARY)
#  define QWEBRENDERSHARED_EXPORT Q_DECL_EXPORT
#else
#  define QWEBRENDERSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // QWEBRENDER_GLOBAL_H