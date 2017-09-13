#include <QTest>

#include <LogManagerTest.h>
#include <ConsoleRendererTest.h>

int
main(int argc, char* argv[]){

    QTest::qExec(new LogManagerTest(), argc, argv);
    QTest::qExec(new ConsoleRendererTest(), argc, argv);

    return 0;
}
