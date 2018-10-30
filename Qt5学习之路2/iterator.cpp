#include <QCoreApplication>
#include <QDebug>
#include <QList>
#include <QString>
#include <QMap>

void test()
{
    QList<QString> list;
    {
        QString str("This is a test string");
        // str析构的时候，会把自身复制到list指向的指针
        list << str;
    }

    qDebug() << list[0] << "How are you! ";
}

void test1()
{
    QList<int> list;
    list << 1 << 2 << 3 << 4 << 5;
    // 迭代点处在第一个列表项1的前面， 并不是指向该列表项
    // 只读迭代器
    QListIterator<int> i(list);
    for (; i.hasNext();)
        qDebug() << i.next();
}

void test2()
{
    QList<int> list;
    QMutableListIterator<int> i(list);
    for (int j = 0; j < 10; ++j)
        i.insert(j);
    for (i.toFront(); i.hasNext();)
        qDebug() << i.next();

    for (i.toBack(); i.hasPrevious();)
    {
        if (0 == i.previous() % 2)
            i.remove();
        else
            i.setValue(i.peekNext() * 10);
    }

    for (i.toFront(); i.hasNext();)
        qDebug() << i.next();
}

void test3()
{
    QList<int> list;
    for (int j = 0; j < 10; j++)
        list.insert(list.end(), j);

    QList<int>::iterator i;
    for (i = list.begin(); i != list.end(); ++i)
    {
        qDebug() << (*i);
        *i = (*i) * 10;
    }

    QList<int>::const_iterator ci;
    for (ci = list.constBegin(); ci != list.constEnd(); ++ci)
        qDebug() << *ci;
}

void test_map_java_style()
{
    QMap<QString, QString> map;
    map.insert("beijing", "111");
    map.insert("shanghai", "021");
    map.insert("nanjing", "025");
    QMapIterator<QString, QString> i(map);
    for (;i.hasNext();)
        qDebug() << " " << i.key() << " " << i.next().value();

    QMutableMapIterator<QString, QString> mi(map);
    if (mi.findNext("111"))
        mi.setValue("010");
    QMapIterator<QString, QString> modi(map);
    qDebug() << " ";
    for (; modi.hasNext();)
        qDebug() << " " << modi.key() << " " << modi.next().value();
}

void test_map_STL_style()
{
    QMap<QString, QString> map;
    map.insert("beijing", "111");
    map.insert("shanghai", "021");
    map.insert("jinan", "0531");
    QMap<QString, QString>::const_iterator i;
    for (i = map.constBegin(); i != map.constEnd(); ++i)
        qDebug() << " " << i.key() << " " << i.value();
    qDebug() << " ";

   QMap<QString, QString>::iterator mi;
   mi = map.find("beijing");
   if (mi != map.end())
       mi.value() = "010";

   // QMap<QString, QString>::const_iterator i;
   for (i = map.constBegin(); i != map.constEnd(); ++i)
       qDebug() << " " << i.key() << " " << i.value();
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // test();
    // test1();
    // test2();
    // test3();
    // test_map_java_style();
    test_map_STL_style();

    return a.exec();
}
