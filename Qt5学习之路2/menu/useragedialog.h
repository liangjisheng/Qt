#ifndef USERAGEDIALOG_H
#define USERAGEDIALOG_H

#include <QDialog>
#include <QWidget>

class UserAgeDialog : public QDialog
{
    Q_OBJECT

public:
    UserAgeDialog(QWidget *parent = 0, int age = 0);

    void accept();

signals:
    void userAgeChanged(int newAge);

private:
    int m_age;
};

#endif // USERAGEDIALOG_H
