#include "Logger.h"

#include <QMetaEnum>

#include <chrono>

using namespace mycrqlog;

Logger::Logger(QString const& id) :
    m_id{id},
    m_history{},
    m_renderers{}
{}

void
Logger::registerRenderer(LogRenderer::Pointer toRegister) {

    Q_ASSERT(!toRegister.isNull());

    // Don't add it twice
    if(m_renderers.contains(toRegister)){
        return;
    }

    m_renderers.append(toRegister);
}

void
Logger::unregisterRenderer(LogRenderer::Pointer toUnregister) {

    m_renderers.removeAll(toUnregister);
}

void
Logger::unregisterAllRenderers() {

    m_renderers.clear();
}

void
Logger::log(QString const& messageText, Severity::Value severity){

    // Step 1) Create the message
    LogMessage::Pointer newMessage = LogMessage::Pointer::create();

    // Step 2) Write the message text, source and severity
    newMessage->attachField(LogMessage::FieldName::Message,
                            QJsonValue(messageText));

    newMessage->attachField(LogMessage::FieldName::Source,
                            QJsonValue(m_id));

    newMessage->attachField(LogMessage::FieldName::Severity,
                            QJsonValue(Severity::toString(severity)));

    // Step 3) Acquire a timestamp and put it in the message as well
    unsigned long timestamp;
    {
        using namespace std::chrono;
        timestamp = duration_cast<milliseconds>(
                        steady_clock::now().time_since_epoch()
                        ).count();
    }
    newMessage->attachField(LogMessage::FieldName::Timestamp,
                            QJsonValue((qint64)timestamp));

    // Step 4) Put the message in the History
    m_history.append(newMessage);

    // Step 5) Notify the renderers
    for(LogRenderer::Pointer renderer : m_renderers){
        renderer->render(newMessage);
    }
}
