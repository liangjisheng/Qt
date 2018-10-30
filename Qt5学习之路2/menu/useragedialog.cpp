#include "useragedialog.h"

UserAgeDialog::UserAgeDialog(QWidget *parent, int age)
    : QDialog(parent), m_age(age)
{

}

void UserAgeDialog::accept()
{
    emit userAgeChanged(m_age);
    QDialog::accept();
}
