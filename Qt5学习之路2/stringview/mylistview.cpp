#include "mylistview.h"
#include <QStringList>
#include <QHBoxLayout>
#include <QPushButton>
#include <QVBoxLayout>
#include <QInputDialog>
#include <QLineEdit>
#include <QString>
#include <QModelIndex>
#include <QMessageBox>


MyListView::MyListView(QWidget *parent)
    : QWidget(parent)
{
    QStringList data;
    data << "Letter A" << "Letter B" << "Letter C";
    model = new QStringListModel(this);
    model->setStringList(data);

    listView = new QListView(this);
    listView->setModel(model);

    QHBoxLayout *btnLayout = new QHBoxLayout;
    QPushButton *insertBtn = new QPushButton(tr("insert"), this);
    connect(insertBtn, QPushButton::clicked, this, insertData);
    QPushButton *delBtn = new QPushButton(tr("Delete"), this);
    connect(delBtn, QPushButton::clicked, this, deleteData);
    QPushButton *showBtn = new QPushButton(tr("Show"), this);
    connect(showBtn, QPushButton::clicked, this, showData);
    btnLayout->addWidget(insertBtn);
    btnLayout->addWidget(delBtn);
    btnLayout->addWidget(showBtn);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(listView);
    mainLayout->addLayout(btnLayout);
    setLayout(mainLayout);
}

void MyListView::insertData()
{
    bool isOK;
    QString text = QInputDialog::getText(this, "Insert",
                                         "Please input new data:",
                                         QLineEdit::Normal,
                                         "You are inserting new data.",
                                         &isOK);
    if (isOK) {
        int row = listView->currentIndex().row();
        model->insertRows(row, 1);
        QModelIndex index = model->index(row);
        model->setData(index, text);
        listView->setCurrentIndex(index);
        listView->edit(index);
    }
}

void MyListView::deleteData()
{
    if (model->rowCount() > 1) {
        model->removeRows(listView->currentIndex().row(), 1);
    }
}

void MyListView::showData()
{
    QStringList data = model->stringList();
    QString str;
    foreach(QString s, data) {
        str += s + "\n";
    }
    QMessageBox::information(this, "Data", str);
}
