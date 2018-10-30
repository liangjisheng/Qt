#include "mainwindow.h"
#include "paintedwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // MainWindow w;
    // w.show();

    PaintedWidget paint;
    paint.show();

    return a.exec();
}
