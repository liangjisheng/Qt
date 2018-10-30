#include "dialog.h"
#include <QApplication>
#include "content.h"
#include <QTextCodec>
#include <QSplitter>
#include <QListWidget>
#include <QFont>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Dialog w;
    //w.show();

    QFont font("AR PL Kaitim GB", 12);
    a.setFont(font);

    QSplitter *splitterMain = new QSplitter(Qt::Horizontal, 0);
    splitterMain->setOpaqueResize(true);
    QListWidget *list = new QListWidget(splitterMain);
    list->insertItem(0, QObject::tr("基本信息"));
    list->insertItem(1, QObject::tr("联系方式"));
    list->insertItem(2, QObject::tr("详细资料"));

    Content *content = new Content(splitterMain);
    QObject::connect(list, &QListWidget::currentRowChanged,
                     content->stack, &QStackedWidget::setCurrentIndex);
    splitterMain->setWindowTitle(QObject::tr("修改用户资料"));
    splitterMain->setMinimumSize(splitterMain->minimumSize());
    splitterMain->setMaximumSize(splitterMain->maximumSize());
    splitterMain->show();

    return a.exec();
}
