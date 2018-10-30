#ifndef CONTACT_H
#define CONTACT_H

// 用户联系方式

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QLineEdit>
#include <QCheckBox>

class Contact : public QWidget
{
    Q_OBJECT
public:
    explicit Contact(QWidget *parent = nullptr);
private:
    QLabel *EmailLabel;
    QLineEdit *EmailLineEdit;
    QLabel *AddrLabel;
    QLineEdit *AddrLineEdit;
    QLabel *CodeLabel;
    QLineEdit *CodeLineEdit;
    QLabel *MoviTelLabel;
    QLineEdit *MoviTelLineEdit;
    QCheckBox *MoviTelCheckBox;
    QLabel *ProTelLabel;
    QLineEdit *ProTelLineEdit;
    QGridLayout *mainLayout;

signals:

public slots:
};

#endif // CONTACT_H
