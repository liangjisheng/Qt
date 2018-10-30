#include <QCoreApplication>
#include <QFile>
#include <QtDebug>
#include <QTextStream>

void QFileReadFile()
{
    QFile file("textFile1.txt");
    if (file.open(QIODevice::ReadOnly))
    {
        char buffer[2048] = { 0 };
        qint64 lineLen = file.readLine(buffer, sizeof(buffer));
        if (lineLen != -1)
            qDebug() << buffer;
    }
}

void QTextStreamReadFile()
{
    QFile data("data.txt");
    if (data.open(QFile::WriteOnly | QFile::Truncate))
    {
        QTextStream out(&data);
        out << QObject::tr("score:") << qSetFieldWidth(10) << left << 90 << endl;
        data.close();
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTextStreamReadFile();

    return a.exec();
}
