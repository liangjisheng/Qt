#ifndef LANGSWITCH_H
#define LANGSWITCH_H

#include <QWidget>
#include <QComboBox>
#include <QLabel>

class LangSwitch : public QWidget
{
    Q_OBJECT

public:
    LangSwitch(QWidget *parent = 0);
    ~LangSwitch();
private slots:
    void changeLang(int index);
private:
    void createScreen();    // 创建基本的界面
    void changeTr(const QString& langCode); // 改变语言
    void refreshLabel();    // 设置标签的内容

    QComboBox *combo;
    QLabel *label;
};

#endif // LANGSWITCH_H
