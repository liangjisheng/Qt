#include <QString>
#include <QtTest>
#include "area.h"

class TestArea : public QObject
{
    Q_OBJECT

public:
    TestArea();

private Q_SLOTS:
    void toAreaTest();
};

TestArea::TestArea()
{
}

void TestArea::toAreaTest()
{
    Area area(1);
    // 验证条件是否为true，为true程序继续执行，否则终止
    QVERIFY(qAbs(area.CountArea() - 3.14) < 0.0000001);
    // 验证条件是否为true，为true程序继续执行，否则输出第二个参数作为输出信息
    QVERIFY2(true, "Failure");
}

// 实现main函数，并初始化QApplication对象和测试类
QTEST_APPLESS_MAIN(TestArea)

#include "tst_testarea.moc"
