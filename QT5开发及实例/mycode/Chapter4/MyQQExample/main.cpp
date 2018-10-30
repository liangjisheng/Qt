#include "dialog.h"
#include <QApplication>
#include "drawer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Dialog w;
    //w.show();

    Drawer drawer;
    drawer.show();

    return a.exec();
}
