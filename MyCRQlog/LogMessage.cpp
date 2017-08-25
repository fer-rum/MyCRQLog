#include "LogMessage.h"

using namespace mycrqlog;

QString const LogMessage::FieldName::Message{"message"};
QString const LogMessage::FieldName::Severity{"severity"};
QString const LogMessage::FieldName::Timestamp{"timestamp"};
QString const LogMessage::FieldName::Source{"source"};

LogMessage::LogMessage() :
    m_content{}
{}

void
LogMessage::attachField(QString const& fieldName,
                        QJsonValue const& fieldValue) {
    m_content.insert(fieldName, fieldValue);
}

QJsonObject const
LogMessage::content() const {
    return m_content;
}
