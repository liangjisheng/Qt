#include "mainwindow.h"
#include <QApplication>
#include "mylistview.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // MainWindow w;
    // w.show();

    MyListView listview;
    listview.show();

    return a.exec();
}
