#pragma once

#include <QTest>

class ConsoleRendererTest :
        public QObject
{
    Q_OBJECT

public:
    ConsoleRendererTest();

private slots:
    void testMessageRendering();
};
