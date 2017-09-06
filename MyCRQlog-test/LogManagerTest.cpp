#include <LogManagerTest.h>

#include <LogManager.h>

#include <QString>

using namespace mycrqlog;

LogManagerTest::LogManagerTest() :
    QObject()
{}

void LogManagerTest::testDefaultInstance() {

    LogManager uut = LogManager::instance();

    Q_ASSERT(uut.loggers().isEmpty());
    Q_ASSERT(uut.renderers().isEmpty());

}
