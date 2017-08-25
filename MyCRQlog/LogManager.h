#pragma once

#include <mycrqlog_global.h>

#include <Logger.h>
#include <LogRenderer.h>

#include <QList>
#include <QSharedPointer>


namespace mycrqlog {

class MYCRQLOGSHARED_EXPORT LogManager {

private:
    LogManager() = default;
    static LogManager m_instance;

    QList<LogRenderer::Pointer> m_renderers;
    QList<Logger::Pointer> m_loggers;

public:

    static LogManager instance();

    template<class RendererSubclass, typename ...Args>
    QSharedPointer<RendererSubclass> createRenderer(Args && ...args) const;
    void deleteRenderer(LogRenderer::Pointer toDelete);

    Logger::Pointer createLogger(QString const& id);
};

} // namespace mycrqlog
