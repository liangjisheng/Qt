#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUrl>

class QNetworkReply;
class QNetworkAccessManager;
class QFile;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void startRequest(QUrl url);
private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *manager;

    QNetworkReply *reply;
    QUrl url;
    QFile *file;
private slots:
    void replyFinished(QNetworkReply *);
    void httpFinished();
    void httpReadyRead();
    void updateDataReadProgress(qint64, qint64);
    void on_downloadBtn_clicked();
};

#endif // MAINWINDOW_H
