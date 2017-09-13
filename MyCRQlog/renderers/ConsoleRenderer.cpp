#include "ConsoleRenderer.h"

#include <iostream>

using namespace mycrqlog;

QString
ConsoleRenderer::formatTimestamp(double timestamp) {

    return QString::number(timestamp, 'f', 3);

}

QString
ConsoleRenderer::formatSourceString(const QString& source) {

    int const targetSize = 12;
    QChar const fillChar{' '};

    QString sourceString = source;

    if(sourceString.size() > targetSize) {
        sourceString.resize(targetSize - 1); // leave space for "…"
        sourceString = sourceString.append("…");
    } else {
        sourceString = sourceString.rightJustified(targetSize, fillChar);
    }

    return sourceString;
}

QString
ConsoleRenderer::formatSeverityString(Severity::Value severity) {

    int const targetSize = 10;
    QChar const fillChar{' '};

    QString severityString = Severity::toString(severity);

    if(severityString.size() > targetSize) {
        severityString.resize(targetSize - 1); // leave space for "…"
        severityString = severityString.append("…");
    } else {
        severityString = severityString.leftJustified(targetSize, fillChar);
    }

    severityString = severityString.toUpper();
    return severityString;
}

QString
ConsoleRenderer::formatTextString(QString text) {

    // Currently no special formatting is applied here
    return text;
}

ConsoleRenderer::ConsoleRenderer()
{

}

void
ConsoleRenderer::render(LogMessage::Pointer toRender) {

    Q_ASSERT(!toRender.isNull());

    QString timestampString = formatTimestamp(toRender->timestamp());
    QString sourceString    = formatSourceString(toRender->source());
    QString severityString  = formatSeverityString(toRender->severity());
    QString textString      = formatTextString(toRender->text());

    QString output = QString("[%1] %2: %3 %4")
                     .arg(timestampString)
                     .arg(sourceString)
                     .arg(severityString)
                     .arg(textString);

    std::cout << output.toStdString() << std::endl;
}

