#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QProgressBar>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    QPushButton *startButton;
    QProgressBar *progressBar;
    QProgressBar *progressBar2;
private slots:
    void startFun();
};

#endif // MAINWINDOW_H
