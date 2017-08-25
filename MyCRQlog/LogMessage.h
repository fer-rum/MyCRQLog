#pragma once

#include <mycrqlog_global.h>

#include <QJsonObject>
#include <QJsonValue>
#include <QObject>
#include <QSharedPointer>
#include <QString>

namespace mycrqlog {

class MYCRQLOGSHARED_EXPORT LogMessage {
    friend class QSharedPointer<LogMessage>; // so it can call the default constructor

public:
    using Pointer = QSharedPointer<LogMessage>;

    struct FieldName {
        static const QString Message;
        static const QString Severity;
        static const QString Timestamp;
        static const QString Source;
    };

private:
    QJsonObject m_content;

    LogMessage();

public:

    void attachField(QString const& fieldName,
                     QJsonValue const& fieldValue);

    QJsonObject const content() const;
};

} // namespace mycrqlog
