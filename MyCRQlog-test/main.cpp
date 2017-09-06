#include <QTest>

#include <LogManagerTest.h>

int
main(int argc, char* argv[]){

    QTest::qExec(new LogManagerTest(), argc, argv);

    return 0;
}
