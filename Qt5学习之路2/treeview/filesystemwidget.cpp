#include "filesystemwidget.h"
#include <QDir>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QModelIndex>
#include <QString>
#include <QInputDialog>
#include <QMessageBox>
#include <QHeaderView>

FileSystemWidget::FileSystemWidget(QWidget *parent) :
    QWidget(parent)
{
    model = new QFileSystemModel;
    model->setRootPath(QDir::currentPath());

    treeView = new QTreeView(this);
    treeView->setModel(model);
    treeView->setRootIndex(model->index(QDir::currentPath()));

    // 下面4行代码使得点击列头可以进行排序
    treeView->header()->setStretchLastSection(true);
    treeView->header()->setSortIndicator(0, Qt::AscendingOrder);
    treeView->header()->setSortIndicatorShown(true);
    treeView->header()->setSectionsClickable(true);

    QPushButton *mkdirButton = new QPushButton(tr("Make Directory..."), this);
    QPushButton *rmButton = new QPushButton(tr("Remove"), this);
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(mkdirButton);
    buttonLayout->addWidget(rmButton);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(treeView);
    layout->addLayout(buttonLayout);

    setLayout(layout);
    setWindowTitle("File System Model");

    connect(mkdirButton, QPushButton::clicked, this, mkdir);
    connect(rmButton, QPushButton::clicked, this, rm);
}

void FileSystemWidget::mkdir()
{
    QModelIndex index = treeView->currentIndex();
    if (!index.isValid()) {
        return;
    }
    QString dirName = QInputDialog::getText(this,
                                            tr("Create Directory"),
                                            tr("Directory name"));
    if (!dirName.isEmpty()) {
        if (!model->mkdir(index, dirName).isValid()) {
            QMessageBox::information(this,
                                     tr("Create Directory"),
                                     tr("Failed to create the directory"));
        }
    }
}

void FileSystemWidget::rm()
{
    QModelIndex index = treeView->currentIndex();
    if (!index.isValid()) {
        return;
    }
    bool ok;
    if (model->fileInfo(index).isDir()) {
        ok = model->rmdir(index);
    } else {
        ok = model->remove(index);
    }
    if (!ok) {
        QMessageBox::information(this,
                         tr("Remove"),
                         tr("Failed to remove %1").arg(model->fileName(index)));
    }
}
