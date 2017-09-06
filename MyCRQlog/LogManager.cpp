#include "LogManager.h"

using namespace mycrqlog;

LogManager LogManager::m_instance{};

LogManager
LogManager::instance() {
    return m_instance;
}

template<class RendererSubclass, typename ...Args>
QSharedPointer<RendererSubclass>
LogManager::createRenderer(Args && ...args) const {

    static_assert(std::is_base_of<LogRenderer, RendererSubclass>::value,
                  "RendererSubclass was not derived from LogRenderer");

    using RendererPointer = QSharedPointer<RendererSubclass>;

    RendererPointer newRenderer = RendererPointer::create(
                                      std::forward<Args>(args)...);
    Q_ASSERT(!newRenderer.isNull());

    m_renderers.append(newRenderer);

    return newRenderer;
}

void
LogManager::deleteRenderer(LogRenderer::Pointer toDelete) {

    if(!m_renderers.contains(toDelete)){
        // Renderer not registered with this log manager
        // Do nothing to avoid side effects
        return;
    }

    // Unregister this Renderer from all loggers
    for(Logger::Pointer logger : m_loggers){
        logger->unregisterRenderer(toDelete);
    }

    // Drop the reference
    m_renderers.removeAll(toDelete);
}

Logger::Pointer
LogManager::createLogger(QString const& id) {

    Logger::Pointer newLogger = Logger::Pointer::create(id);

    Q_ASSERT(!newLogger.isNull());
    m_loggers.append(newLogger);

    return newLogger;
}

void
LogManager::deleteLogger(Logger::Pointer toDelete) {

    if(!m_loggers.contains(toDelete)){
        // Logger not registered with this log manager
        // Do nothing to avoid side effects
        return;
    }

    toDelete->unregisterAllRenderers();

    m_loggers.removeAll(toDelete);
}

QList<LogRenderer::Pointer>
LogManager::renderers() const {
    return m_renderers;
}

QList<Logger::Pointer>
LogManager::loggers() const {
    return m_loggers;
}
