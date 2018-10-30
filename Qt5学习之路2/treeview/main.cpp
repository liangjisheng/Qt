#include "mainwindow.h"
#include <QApplication>
#include "filesystemwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // MainWindow w;
    // w.show();

    FileSystemWidget test;
    test.resize(500, 300);
    test.show();

    return a.exec();
}
