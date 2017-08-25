#include "Severity.h"

using namespace mycrqlog;

QMetaEnum Severity::m_metaEnum = QMetaEnum::fromType<Severity::Value>();

QString
Severity::toString(Severity::Value toConvert) {

    // Sanity check
    Q_ASSERT(m_metaEnum.isValid());

    return {m_metaEnum.valueToKey(toConvert)};
}

Severity::Value
Severity::fromString(QString const& toConvert,
                     Value defaultValue){

    // Sanity check
    Q_ASSERT(m_metaEnum.isValid());

    // QString -> QByteArray -> char*
    QByteArray asLatin1 = toConvert.toLatin1();
    char const* asChar = asLatin1.data();
    Q_CHECK_PTR(asChar);

    // Get the Value
    bool ok;
    int valueAsInt = m_metaEnum.keyToValue(asChar, &ok);

    if(!ok){
        return defaultValue;
    } else {
        return (Value)valueAsInt;
    }
}
