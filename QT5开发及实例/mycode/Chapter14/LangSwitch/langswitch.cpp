#include "langswitch.h"
#include <QVBoxLayout>
#include <QTranslator>
#include <QApplication>

LangSwitch::LangSwitch(QWidget *parent)
    : QWidget(parent)
{
    createScreen();
}

void LangSwitch::createScreen()
{
    combo = new QComboBox;
    combo->addItem("English", "en");
    combo->addItem("Chinese", "zh");
    combo->addItem("Latin", "la");

    label = new QLabel;
    refreshLabel();

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(combo, 1);
    layout->addWidget(label, 5);

    setLayout(layout);

    connect(combo, SIGNAL(currentIndexChanged(int)),this,SLOT(changeLang(int)));
}

void LangSwitch::refreshLabel()
{
    // 第一个参数为字符串ID，第二个参数提供注释作用，在取不到第一个参数时，第二个
    // 参数会被采用
    label->setText(tr("TXT_HELLO_WORLD", "Hello World"));
}

void LangSwitch::changeLang(int index)
{
    QString langCode = combo->itemData(index).toString();
    changeTr(langCode);     // 读取相应的.qm文件
    refreshLabel();
}

void LangSwitch::changeTr(const QString &langCode)
{
    static QTranslator* translator;
    if (NULL != translator)
    {
        qApp->removeTranslator(translator);
        delete translator;
        translator = NULL;
    }

    translator = new QTranslator;
    QString qmFilename = "lang_" + langCode;
    if (translator->load(QString("../LangSwitch/") + qmFilename))
    {
        qApp->installTranslator(translator);
    }
}

LangSwitch::~LangSwitch()
{

}
