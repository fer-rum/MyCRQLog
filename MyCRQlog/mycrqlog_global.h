#pragma once

#include <QtCore/qglobal.h>

#if defined(MYCRQLOG_LIBRARY)
#  define MYCRQLOGSHARED_EXPORT Q_DECL_EXPORT
#else
#  define MYCRQLOGSHARED_EXPORT Q_DECL_IMPORT
#endif
