#pragma once

#include <mycrqlog_global.h>

#include <QMetaEnum>
#include <QObject>

#include <limits>

namespace mycrqlog {

class MYCRQLOGSHARED_EXPORT Severity {

    Q_GADGET

public:
    enum Value {
        Undefined   = std::numeric_limits<int>::min(), // (1)
        Lowest      = Undefined + 1,
        Highest     = std::numeric_limits<int>::max(),
        Default     = 0,
        Error       = Highest / 2,
        Critical    = (Highest/4) * 3,
        Verbose     = Lowest / 2,
        Debug       = (Lowest/4) *3,
    };
    Q_ENUM(Value)

    /*
     * (1) NOTE: The number space is asymetrical since the negative number
     * region is bigger by one, since 0 is counted towards the positive numbers.
     * For this reason, the lowest number has been chopped of for representing
     * an unknown severity, which might come in handy when attempting to write
     * robust code. As a side effect, the remaining number space is symmetrical
     * again.
     */

private:

    static QMetaEnum m_metaEnum;

    // Prevent anyone from instantiating objects of this class
    Severity() = delete;

public:

    /**
     * @brief toString tries to obtain a string representation for the given
     * enum value.
     * @param toConvert
     * @return A string representation or a null-string if an invalid argument
     * was passed
     */
    static QString toString(Value toConvert);

    /**
     * @brief fromString attempts to convert a given string representation back
     * to the enum value.
     * @param toConvert
     * @param defaultValue
     * @return The according enum value or the provided default value if the
     * conversion failed.
     */
    static Severity::Value fromString(QString const& toConvert,
                                      Value defaultValue = Value::Undefined);
};

} // namespace mycrqlog
