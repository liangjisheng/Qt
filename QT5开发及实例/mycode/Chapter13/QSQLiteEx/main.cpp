#include <QCoreApplication>
#include <QtCore>
#include <QTextCodec>
#include <QSqlDatabase>
// #include <QMessageBox>
#include <QTime>
#include <QSqlError>
#include <QtDebug>
#include <QSqlDriver>
#include <QSqlRecord>
#include <QSqlQuery>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    // 设置中文显示
    QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());

    // 以QSQLITE为数据库类型，在本进程地址空间内创建一个SQLite数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("liangjisheng");     // 数据库主机名
    db.setDatabaseName("qtDB.db");      // 数据库名
    db.setUserName("liangjisheng");     // 用户名
    db.setPassword("123456");           // 密码
    db.open();  // 打开连接

    // 创建数据库表
    QSqlQuery query;
    bool success=query.exec("create table automobil(id int primary key,attribute varchar,type varchar,kind varchar,nation int,carnumber int,elevaltor int,distance int,oil int,temperature int)");
    if(success)
        qDebug()<<QObject::tr("数据库表创建成功");
    else
        qDebug()<<QObject::tr("数据库表创建失败");

    // select
    query.exec("select * from automobil");
    QSqlRecord rec = query.record();
    qDebug() << QObject::tr("automobil表字段数: ") << rec.count();

    // insert
    QTime t;
    t.start();
    query.prepare("insert into automobil values(?,?,?,?,?,?,?,?,?,?)");

    long records=100;
    for(int i=0;i<records;i++)
    {
        query.bindValue(0,i);
        query.bindValue(1,"四轮");
        query.bindValue(2,"轿车");
        query.bindValue(3,"富康");
        query.bindValue(4,rand()%100);
        query.bindValue(5,rand()%10000);
        query.bindValue(6,rand()%300);
        query.bindValue(7,rand()%200000);
        query.bindValue(8,rand()%52);
        query.bindValue(9,rand()%100);

        success=query.exec();
        if(!success)
        {
            QSqlError lastError=query.lastError();
            qDebug()<<lastError.driverText()<<QString(QObject::tr("插入失败"));
        }
    }
    qDebug()<<QObject::tr("插入 %1 条记录，耗时：%2 ms").arg(records).arg(t.elapsed());

    // sort
    t.restart();
    success = query.exec("select * from automobil order by id desc");
    if(success)
        qDebug()<<QObject::tr("排序 %1 条记录，耗时：%2 ms").arg(records).arg(t.elapsed());
    else
        qDebug()<<QObject::tr("排序失败！");

    // update
    t.restart();
    for(int i=0;i<records;i++)
    {
       query.clear();
       query.prepare(QString("update automobil set attribute=?,type=?,"
                             "kind=?,nation=?,"
                             "carnumber=?,elevaltor=?,"
                             "distance=?,oil=?,"
                             "temperature=? where id=%1").arg(i));

       query.bindValue(0,"四轮");
       query.bindValue(1,"轿车");
       query.bindValue(2,"富康");
       query.bindValue(3,rand()%100);
       query.bindValue(4,rand()%10000);
       query.bindValue(5,rand()%300);
       query.bindValue(6,rand()%200000);
       query.bindValue(7,rand()%52);
       query.bindValue(8,rand()%100);

       success=query.exec();
       if(!success)
       {
           QSqlError lastError=query.lastError();
           qDebug()<<lastError.driverText()<<QString(QObject::tr("更新失败"));
       }
    }
    qDebug()<<QObject::tr("更新 %1 条记录，耗时：%2 ms").arg(records).arg(t.elapsed());

    // delete
    t.restart();
    query.exec("delete from automobil where id=15");
    qDebug()<<QObject::tr("删除一条记录，耗时：%1 ms").arg(t.elapsed());
    db.close();

    return a.exec();
}
