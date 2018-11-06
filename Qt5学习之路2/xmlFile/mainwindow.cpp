#include "mainwindow.h"
#include <QFile>
#include <QXmlStreamWriter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    explainL = new QLabel(this);
    explainL->setText(tr("text"));
    explainL->setGeometry(QRect(50,50,300,100));

    createBt = new QPushButton(this);
    createBt->setText("创建 XML 文件");
    createBt->setGeometry(QRect(50,180,100,25));
    connect(createBt,SIGNAL(clicked()),this,SLOT(createFile()));
}

void MainWindow::createFile()
{
    QString xmlPath = "D:/a001.xml";
    QFile file(xmlPath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QXmlStreamWriter stream(&file);
        stream.setAutoFormatting(true);
        // 文档头
        stream.writeStartDocument();
        // 根节点
        stream.writeStartElement("Root");
        // 元素、值
        QXmlStreamAttribute attr("href", "http://qt.nokia.com/");
        stream.writeAttribute(attr);
        // 节点内容
        stream.writeTextElement("title", "Qt Home");
        stream.writeEndElement();
        stream.writeEndDocument();

        file.close();
    }
}

MainWindow::~MainWindow()
{

}
