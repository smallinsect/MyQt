#ifndef TESTLIB01_GLOBAL_H
#define TESTLIB01_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(TESTLIB01_LIBRARY)
#  define TESTLIB01SHARED_EXPORT Q_DECL_EXPORT
#else
#  define TESTLIB01SHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // TESTLIB01_GLOBAL_H
