#include "mainwindow.h"
#include <QApplication>
#include <QPixmap>
#include <QSplashScreen>

// QSplashScrenn类实现了在程序启动过程中显示启动画面的功能。
// 当运行程序时，在显示器的中央出现一个启动画面，经过一段时间，应用程序完成初始化工作，
// 启动画面隐去，出现程序的主窗口界面

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QPixmap pixmap("Qt.png");
    QSplashScreen splash(pixmap);
    splash.show();      // 显示启动图片
    a.processEvents();  // 使程序在显示启动画面的同时仍能响应鼠标等其他事件

    MainWindow w;
    w.show();

    // 表示在主窗体对象初始化完成后，结束启动画面
    splash.finish(&w);

    return a.exec();
}
