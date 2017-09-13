#pragma once

#include <LogRenderer.h>

namespace mycrqlog {

class ConsoleRenderer :
        public LogRenderer {

protected:

    /**
     * @brief formatTimestamp dictates how the timestamp is represented in the
     * output. In the default implementation the number will be fully printed
     * as-is.
     *
     * Inheriting classes may want to override this method for customization.
     *
     * @param timestamp is the point in time at which the message was logged as
     * Milliseconds since epoch.
     * @return
     */
    virtual QString formatTimestamp(double timestamp);

    virtual QString formatSourceString(QString const& source);

    virtual QString formatSeverityString(Severity::Value severity);

    virtual QString formatTextString(QString text);

public:
    ConsoleRenderer();

    virtual void render(LogMessage::Pointer toRender) override;
};

} // namespace mycrqlog
