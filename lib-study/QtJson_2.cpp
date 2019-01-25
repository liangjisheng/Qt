#include <QCoreApplication>
#include <QJsonObject>
#include <QJsonDocument>
#include <QByteArray>
#include <QString>
#include <QDebug>
#include <QJsonParseError>
#include <QJsonValue>
#include <QJsonArray>

void test1()
{
    QJsonObject json;
    json.insert("name", QString("Qt"));
    json.insert("version", 5);
    json.insert("windows", true);

    QJsonDocument doc;
    doc.setObject(json);
    QByteArray byte_array = doc.toJson(QJsonDocument::Compact);
    QString json_str(byte_array);
    qDebug() << json_str << "\n";

    QJsonParseError json_error;
    QJsonDocument parse_doc = QJsonDocument::fromJson(byte_array, &json_error);
    if (json_error.error == QJsonParseError::NoError)
    {
        if (parse_doc.isObject())
        {
            QJsonObject obj = parse_doc.object();
            if (obj.contains("name"))
            {
                QJsonValue name_value = obj.take("name");
                if (name_value.isString())
                {
                    QString name = name_value.toString();
                    qDebug() << name << "\n";
                }
            }

            if (obj.contains("version"))
            {
                QJsonValue version_value = obj.take("version");
                if (version_value.isDouble())
                {
                    int version = version_value.toVariant().toInt();
                    qDebug() << version << "\n";
                }
            }

            if (obj.contains("windows"))
            {
                QJsonValue flag_value = obj.take("windows");
                if (flag_value.isBool())
                {
                    bool flag = flag_value.toBool();
                    qDebug() << flag << "\n";
                }
            }
        }
    }
}

void test2()
{
    QJsonArray json;
    json.insert(0, QString("Qt"));
    json.insert(1, QString("version"));
    json.insert(2, true);

    QJsonDocument doc;
    doc.setArray(json);
    QByteArray byte_array = doc.toJson(QJsonDocument::Compact);
    QString json_str(byte_array);
    qDebug() << json_str << "\n";

    QJsonParseError json_error;
    QJsonDocument parse_doc = QJsonDocument::fromJson(byte_array, &json_error);
    if (json_error.error == QJsonParseError::NoError)
    {
        if (parse_doc.isArray())
        {
            QJsonArray array = parse_doc.array();
            int size = array.size();
            for (int i = 0; i < size; ++i)
            {
                QJsonValue value = array.at(i);
                if (value.isString())
                {
                    QString str = value.toString();
                    qDebug() << str;
                }
                else if (value.isBool())
                    qDebug() << value.toBool();
            }
        }
    }
}


int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    test2();

    return app.exec();
}
