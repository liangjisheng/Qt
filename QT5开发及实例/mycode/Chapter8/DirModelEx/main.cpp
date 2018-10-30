#include "mainwindow.h"
#include <QApplication>
#include <QAbstractItemModel>
#include <QAbstractItemView>
#include <QItemSelectionModel>

#include <QDirModel>
#include <QTreeView>
#include <QListView>
#include <QTableView>
#include <QSplitter>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    QDirModel model;
    QTreeView tree;
    QListView list;
    QTableView table;

    tree.setModel(&model);
    list.setModel(&model);
    table.setModel(&model);

    // 设置QTreeView对象的选择方式为多选
    tree.setSelectionMode(QAbstractItemView::MultiSelection);
    // 设置与QTreeView对象使用相同的选择模型
    list.setSelectionModel(tree.selectionModel());
    table.setSelectionModel(tree.selectionModel());

    QObject::connect(&tree, &QTreeView::doubleClicked,
                     &list, &QListView::setRootIndex);
    QObject::connect(&tree, &QTreeView::doubleClicked,
                     &table, &QTableView::setRootIndex);

    QSplitter *splitter = new QSplitter;
    splitter->addWidget(&tree);
    splitter->addWidget(&list);
    splitter->addWidget(&table);
    splitter->setWindowTitle(QObject::tr("Model/View"));
    splitter->show();

    return a.exec();
}
