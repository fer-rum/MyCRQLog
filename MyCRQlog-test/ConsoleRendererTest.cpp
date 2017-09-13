#include "ConsoleRendererTest.h"

#include <LogMessage.h>
#include <Severity.h>

#include <renderers/ConsoleRenderer.h>

using namespace mycrqlog;

ConsoleRendererTest::ConsoleRendererTest(){}

void
ConsoleRendererTest::testMessageRendering() {

    // These tests are designed to see if the formatting breaks under certain
    // circumstances

    QList<LogMessage::Pointer> testMessages;

    // --- create all the test messages ---
    {
        LogMessage::Pointer testMessage = LogMessage::Pointer::create();
        testMessage->setText("This is a message to test the output generation of the ConsoleRenderer - class");
        testMessage->setSeverity(Severity::Default);
        testMessage->setSource("Test System");
        testMessage->setTimestamp(123456789.123);
        testMessages.append(testMessage);
    }

    {
        LogMessage::Pointer testMessage = LogMessage::Pointer::create();
        testMessage->setText("This is a message to test long source names");
        testMessage->setSeverity(Severity::Default);
        testMessage->setSource("Another Test System with long source name");
        testMessage->setTimestamp(123456789.123);

        testMessages.append(testMessage);
    }

    // --- run all the test messages ---

    ConsoleRenderer uut{};

    for(LogMessage::Pointer testMessage : testMessages){
        uut.render(testMessage);
    }
}


