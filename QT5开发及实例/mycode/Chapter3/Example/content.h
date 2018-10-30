#ifndef CONTENT_H
#define CONTENT_H

#include <QFrame>
#include <QStackedWidget>
#include <QPushButton>
#include "baseinfo.h"
#include "contact.h"
#include "detail.h"

class Content : public QFrame
{
    Q_OBJECT
public:
    explicit Content(QWidget *parent = nullptr);

    QStackedWidget *stack;
    QPushButton *AmendBtn;
    QPushButton *CloseBtn;

    BaseInfo *baseInfo;
    Contact *contact;
    Detail *detail;

signals:

public slots:
};

#endif // CONTENT_H
