#include <QCoreApplication>
#include <QFile>
#include <QDebug>
#include <QByteArray>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QStringList>
#include <QJsonObject>
#include <QJsonArray>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QFile loadFile("test.json");
    if (!loadFile.open(QIODevice::ReadOnly))
    {
        qDebug() << "could't open project json";
        return -1;
    }

    QByteArray allData = loadFile.readAll();
    loadFile.close();

    QJsonParseError json_error;
    QJsonDocument jsonDoc(QJsonDocument::fromJson(allData, &json_error));
    if (json_error.error != QJsonParseError::NoError)
    {
        qDebug() <<"json error!";
        return -2;
    }

    QJsonObject rootObj = jsonDoc.object();
    //输出所有key，这一步是非必须的，放最后的话，你可能读不到任何key
    QStringList keys = rootObj.keys();
    for (int i = 0; i < keys.size(); ++i)
        qDebug() << "key" << i << " is " << keys.at(i);
    qDebug() << "";

    //因为是预先定义好的JSON数据格式，所以这里可以这样读取
    QString firstFruit = "first fruit";
    if (rootObj.contains(firstFruit))
    {
        QJsonObject subObj = rootObj.value(firstFruit).toObject();
        qDebug() << "describe is:" << subObj["describe"].toString();
        qDebug() << "icon is:" << subObj["icon"].toString();
        qDebug() << "name is:" << subObj["name"].toString();
    }
    qDebug() << "";

    QString secondFruit = "second fruit";
    if (rootObj.contains(secondFruit))
    {
        QJsonObject subObj = rootObj.value(secondFruit).toObject();
        qDebug() << "describe is:" << subObj.value("describe").toString();
        qDebug() << "icon is:" << subObj.value("icon").toString();
        qDebug() << "name is:" << subObj.value("name").toString();
    }
    qDebug() << "";

    QString arr = "three fruit array";
    if (rootObj.contains(arr));
    {
        QJsonArray subArray = rootObj.value(arr).toArray();
        for (int i = 0; i < subArray.size(); ++i)
            qDebug() << i << " value is:" << subArray.at(i).toString();
    }

    return a.exec();
}
