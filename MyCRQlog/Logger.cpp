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

    // Step 1) Acquire a timestamp
    double timestamp;
    {
        using namespace std::chrono;
        timestamp = steady_clock::now().time_since_epoch().count();
    }

    // Step 2) Create the message
    LogMessage::Pointer newMessage = LogMessage::Pointer::create();

    // Step 2) Write the message text, timestamp, source and severity
    newMessage->setText(messageText);
    newMessage->setSource(m_id);
    newMessage->setSeverity(severity);
    newMessage->setTimestamp(timestamp);

    // Step 4) Put the message in the History
    m_history.append(newMessage);

    // Step 5) Notify the renderers
    for(LogRenderer::Pointer renderer : m_renderers){
        renderer->render(newMessage);
    }
}
