#ifndef FILESYSTEMWIDGET_H
#define FILESYSTEMWIDGET_H

#include <QWidget>
#include <QFileSystemModel>
#include <QTreeView>

class FileSystemWidget : public QWidget
{
    Q_OBJECT
public:
    FileSystemWidget(QWidget *parent = 0);
    void mkdir();
    void rm();
private:
    QFileSystemModel *model;
    QTreeView *treeView;
};

#endif // FILESYSTEMWIDGET_H
