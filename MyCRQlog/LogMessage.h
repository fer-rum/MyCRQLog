#pragma once

#include <mycrqlog_global.h>
#include <Severity.h>

#include <QJsonObject>
#include <QJsonValue>
#include <QObject>
#include <QSharedPointer>
#include <QString>

namespace mycrqlog {

/**
 * @brief The LogMessage class
 *
 * NOTE: Timestamps are not created by the message itself, since the logger may
 * prepare messages in advance and actually log them later.
 */
class MYCRQLOGSHARED_EXPORT LogMessage {
    friend class QSharedPointer<LogMessage>; // so it can call the default constructor

public:
    using Pointer = QSharedPointer<LogMessage>;

    /**
     * @brief The FieldName struct contains field names for the message that are
     * reserved for the most common use cases.
     * Make sure that your custom field names do not clash with these ones.
     */
    struct FieldName {
        static const QString Text;
        static const QString Severity;
        static const QString Timestamp;
        static const QString Source;
    };

private:
    QJsonObject m_content;

    // The common fields are also cached in their un-JASON-ed form to reduce
    // continuous wrapping and unwrapping overhead.
    QString m_text;
    Severity::Value m_severity;
    double m_timestamp;
    QString m_source;

    /**
     * @brief The LogMessage constructor is private so only the friendly shared
     * pointer class can access it. This prevents the direct creation of
     * instances that are not accessed via a shared pointer.
     **/
    LogMessage();

public:

    void attachField(QString const& fieldName,
                     QJsonValue const& fieldValue);

    QJsonObject const toJoson() const;

    // --- Common Setters ---
    void setText(QString const& text);
    void setSeverity(Severity::Value const& severity);
    void setTimestamp(double timestamp);
    void setSource(QString const& source);

    // --- Common getters ---
    QString text() const;
    Severity::Value severity() const;
    double timestamp() const;
    QString source() const;
};

} // namespace mycrqlog
