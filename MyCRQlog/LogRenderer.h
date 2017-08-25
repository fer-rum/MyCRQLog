#pragma once

#include <mycrqlog_global.h>

#include <LogMessage.h>

#include <QSharedPointer>

namespace mycrqlog {

/**
 * @brief The LogRenderer class
 * Renderers get created by the LogManager. Subclasses may have an own
 * constructor and the arguments will be directly forwarded to it from the
 * LogManagers createRenderer(...)-method
 */
class MYCRQLOGSHARED_EXPORT LogRenderer {

public:
    using Pointer = QSharedPointer<LogRenderer>;

    virtual void render(LogMessage::Pointer toRender);

};

} // namespace mycrqlog
