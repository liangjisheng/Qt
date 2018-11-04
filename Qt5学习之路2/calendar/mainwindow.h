#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QCalendarWidget>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void showTime();
    void setData();
private:
    QLabel *label;
    QLineEdit * lineEdit;
    QCalendarWidget *calendarWidget;
};

#endif // MAINWINDOW_H
