#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QWidget>
#include <QSettings>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    QGridLayout *gLayout;
    QWidget *widget;
    QLabel *filePathL;
    QLineEdit *filePath;
    QLabel *nodeL;
    QLineEdit *nodeEdit;
    QLabel *keyL;
    QLineEdit *keyEdit;
    QLabel *valL;
    QLineEdit *valEdit;
    QPushButton *writeBt;
    QSettings *writeIni;
private slots:
    void writeFile();
};

#endif // MAINWINDOW_H
