#pragma once

#include <mycrqlog_global.h>
#include <LogMessage.h>
#include <LogRenderer.h>
#include <Severity.h>

#include <QSharedPointer>
#include <QString>

namespace mycrqlog {

class MYCRQLOGSHARED_EXPORT Logger {
    friend class QSharedPointer<Logger>; // so it can call the default constructor

public:
    using Pointer = QSharedPointer<Logger>;

private:
    QString m_id;
    QList<LogMessage::Pointer> m_history;
    QList<LogRenderer::Pointer> m_renderers;

    Logger(QString const& id);

public:

    void registerRenderer(LogRenderer::Pointer toRegister);
    void unregisterRenderer(LogRenderer::Pointer toUnregister);
    void unregisterAllRenderers();

    void log(QString const& messageText, Severity::Value severity);
};

} // namespace mycrqlog
