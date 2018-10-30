#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void setUserAge(int age);

private:
    int m_age;
    void open();
    QTextEdit *textEdit;
    QAction *openAction;
    QAction *saveAction;
    void openFile();
    void saveFile();
};

#endif // MAINWINDOW_H
