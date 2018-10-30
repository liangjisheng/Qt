#ifndef MYLISTVIEW_H
#define MYLISTVIEW_H

#include <QWidget>
#include <QStringListModel>
#include <QListView>

class MyListView : public QWidget
{
    Q_OBJECT
public:
    MyListView(QWidget *parent = 0);
    void insertData();
    void deleteData();
    void showData();
private:
    QStringListModel *model;
    QListView *listView;
};

#endif // MYLISTVIEW_H
