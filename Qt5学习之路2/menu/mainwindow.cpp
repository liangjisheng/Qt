
#include <QAction>
#include <QMenuBar>
#include <QToolBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QDialog>
#include <QDebug>
#include <QString>
#include <QFileDialog>

#include "mainwindow.h"

#include "useragedialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("Main Window"));

    openAction = new QAction(QIcon(":/images/doc-open"), tr("&Open..."), this);
    openAction->setShortcut(QKeySequence::Open);
    openAction->setStatusTip(tr("Open an existing file"));
    // connect(openAction, &QAction::triggered, this, &MainWindow::open);
    connect(openAction, &QAction::triggered, this, &MainWindow::openFile);

    saveAction = new QAction(QIcon(":/images/doc-open"), tr("&Save..."), this);
    saveAction->setShortcut(QKeySequence::Save);
    saveAction->setStatusTip(tr("Save a new file"));
    connect(saveAction, &QAction::triggered, this, &MainWindow::saveFile);

    QMenu *file = menuBar()->addMenu(tr("&File"));
    file->addAction(openAction);
    file->addAction(saveAction);

    QToolBar *toolBar = addToolBar(tr("&File"));
    toolBar->addAction(openAction);
    toolBar->addAction(saveAction);

    textEdit = new QTextEdit(this);
    setCentralWidget(textEdit);

    statusBar();
}

void MainWindow::openFile()
{
    QString path = QFileDialog::getOpenFileName(this,
                                                tr("Open File"),
                                                ".",
                                                tr("Text Files(*.txt)"));
    if (!path.isEmpty())
    {
        QFile file(path);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QMessageBox::warning(this, tr("Read File"),
                                 tr("Cannot open file:\n%1").arg(path));
            return ;
        }
        QTextStream in(&file);
        textEdit->setText(in.readAll());
        file.close();
    }
    else
    {
        QMessageBox::warning(this, tr("Path"),
                             tr("You did not select any file."));
    }
}

void MainWindow::saveFile()
{
    QString path = QFileDialog::getSaveFileName(this,
                                                tr("Open File"),
                                                ".",
                                                tr("Text Files(*.txt)"));
    if (!path.isEmpty())
    {
        QFile file(path);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QMessageBox::warning(this, tr("Write File"),
                                 tr("Cannot open file:\n%1").arg(path));
            return ;
        }
        QTextStream out(&file);
        out << textEdit->toPlainText();
        file.close();
    }
    else
    {
        QMessageBox::warning(this, tr("Path"),
                             tr("You did not select any file."));
    }
}

MainWindow::~MainWindow()
{

}

void MainWindow::open()
{
    // QMessageBox::information(this, tr("Information"), tr("Open"));
    //QDialog dialog(this);
    //dialog.setWindowTitle(tr("Hello, dialog"));
    //dialog.exec();  // exec() 实现应用程序级别的模态对话框
    // open()实现窗口级别的模态对话框

    // 对话框建立在栈上，窗口会一闪而过
    //QDialog dialog;
    //dialog.setWindowTitle(tr("Hello, dialog"));
    //dialog.show();

    /*QDialog *dialog = new QDialog;
    // 窗口关闭的时候销毁窗口对象
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->setWindowTitle(tr("Hello, dialog"));
    dialog->show();*/

    // 对话框与主窗口之间的数据交互
    /*QDialog dialog(this);
    dialog.setWindowTitle(tr("hello, dialog"));
    dialog.exec();
    qDebug() << dialog.result();*/

    /*UserAgeDialog *dialog = new UserAgeDialog(this, 10);
    connect(dialog, &UserAgeDialog::userAgeChanged, this, &MainWindow::setUserAge);
    dialog->show();*/

    /*if (QMessageBox::Yes == QMessageBox::question(this,
                                                  tr("Question"),
                                                  tr("Are you Ok?"),
                                                  QMessageBox::Yes | QMessageBox::No,
                                                  QMessageBox::Yes))
    {
        QMessageBox::information(this, tr("Hmmm..."), tr("I'm glad to hear that!"));
    }
    else
        QMessageBox::information(this, tr("Hmmm..."), tr("I'm sorry!"));*/

    /*QMessageBox msgBox;
    msgBox.setText(tr("The document has been modified."));
    msgBox.setInformativeText(tr("Do you want to save your changes?"));
    msgBox.setDetailedText(tr("Difference here..."));
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard
                              | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);

    int ret = msgBox.exec();
    switch (ret)
    {
    case QMessageBox::Save:
        qDebug() << "Save document!";
        break;
    case QMessageBox::Discard:
        qDebug() << "Discard changes!";
        break;
    case QMessageBox::Cancel:
        qDebug() << "Close document!";
        break;
    }*/
}

void MainWindow::setUserAge(int age)
{
    m_age = age;
}
