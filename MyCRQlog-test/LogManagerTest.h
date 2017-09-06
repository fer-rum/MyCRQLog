#pragma once

#include <QtTest>

class LogManagerTest :
        public QObject
{
    Q_OBJECT

public:
    LogManagerTest();

private slots:
    void testDefaultInstance();
};
