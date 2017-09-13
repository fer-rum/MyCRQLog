#include "LogMessage.h"

using namespace mycrqlog;

QString const LogMessage::FieldName::Text{"text"};
QString const LogMessage::FieldName::Severity{"severity"};
QString const LogMessage::FieldName::Timestamp{"timestamp"};
QString const LogMessage::FieldName::Source{"source"};

LogMessage::LogMessage() :
    m_content{},
    m_text{},
    m_severity{},
    m_timestamp{},
    m_source{}
{}

void
LogMessage::attachField(QString const& fieldName,
                        QJsonValue const& fieldValue) {

    // TODO deny writing the reserved fields this way

    m_content.insert(fieldName, fieldValue);
}

QJsonObject const
LogMessage::toJoson() const {
    return m_content;
}

// --- Common Setters ---
void
LogMessage::setText(QString const& text){
    m_text = text;
    m_content.insert(FieldName::Text, text);
}

void
LogMessage::setSeverity(Severity::Value const& severity){
    m_severity = severity;
    m_content.insert(FieldName::Severity, Severity::toString(severity));
}

void
LogMessage::setTimestamp(double timestamp){
    m_timestamp = timestamp;
    m_content.insert(FieldName::Timestamp, timestamp);
}

void
LogMessage::setSource(QString const& source){
    m_source = source;
    m_content.insert(FieldName::Source, source);
}

// --- Common getters ---
QString
LogMessage::text() const {
    return m_text;
}

Severity::Value
LogMessage::severity() const {
    return m_severity;
}

double
LogMessage::timestamp() const {
    return m_timestamp;
}

QString
LogMessage::source() const {
    return m_source;
}
