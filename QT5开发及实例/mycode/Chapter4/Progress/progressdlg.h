#ifndef PROGRESSDLG_H
#define PROGRESSDLG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QProgressBar>
#include <QComboBox>
#include <QPushButton>
#include <QGridLayout>

class ProgressDlg : public QDialog
{
    Q_OBJECT

public:
    ProgressDlg(QWidget *parent = 0);
    ~ProgressDlg();
private slots:
    void startProgress();
private:
    QLabel *FileNumLabel;
    QLineEdit *FileNumLineEdit;
    QLabel *ProgressTypeLabel;
    QComboBox *comboBox;
    QProgressBar *progressBar;
    QPushButton *startBtn;
    QGridLayout *mainLayout;
};

#endif // PROGRESSDLG_H
