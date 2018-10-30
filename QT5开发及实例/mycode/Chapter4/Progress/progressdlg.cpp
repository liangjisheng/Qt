#include "progressdlg.h"
#include <QProgressDialog>
#include <QFont>

ProgressDlg::ProgressDlg(QWidget *parent)
    : QDialog(parent)
{
    QFont font("ZYSont18030", 12);
    setFont(font);
    setWindowTitle(tr("Progress"));

    FileNumLabel = new QLabel;
    FileNumLabel->setText(tr("文件数目:"));
    FileNumLineEdit = new QLineEdit;
    FileNumLineEdit->setText(tr("100000"));

    ProgressTypeLabel = new QLabel;
    ProgressTypeLabel->setText(tr("显示类型:"));
    comboBox = new QComboBox;
    comboBox->addItem(tr("progressBar"));
    comboBox->addItem(tr("progressDialog"));
    progressBar = new QProgressBar;

    startBtn = new QPushButton();
    startBtn->setText(tr("开始"));

    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(FileNumLabel, 0, 0);
    mainLayout->addWidget(FileNumLineEdit, 0, 1);
    mainLayout->addWidget(ProgressTypeLabel, 1, 0);
    mainLayout->addWidget(comboBox, 1, 1);
    mainLayout->addWidget(progressBar, 2, 0, 1, 2);
    mainLayout->addWidget(startBtn, 3, 1);
    mainLayout->setMargin(15);
    mainLayout->setSpacing(10);

    connect(startBtn, &QPushButton::clicked, this, startProgress);
}

void ProgressDlg::startProgress()
{
    bool ok;
    int num = FileNumLineEdit->text().toInt(&ok);

    if (0 == comboBox->currentIndex())      // ProgressBar
    {
        progressBar->setRange(0, num);
        for (int i = 0; i < num +1; i++)
            progressBar->setValue(i);
    }
    else if (1 == comboBox->currentIndex()) // ProgressDialog
    {
        QProgressDialog *progressDialog = new QProgressDialog(this);
        QFont font("ZYSong18030", 12);
        progressDialog->setFont(font);
        // 设置进度对话框采用模态方式进行显示，即显示进度的同时，其他窗口将不响应输入信号
        progressDialog->setWindowModality(Qt::WindowModal);
        // 设置进度对话框出现需等待的时间，默认为4秒，此处设置为5秒
        progressDialog->setMinimumDuration(5);
        progressDialog->setWindowTitle(tr("Please Wait"));
        progressDialog->setLabelText(tr("Copying..."));
        progressDialog->setCancelButtonText(tr("Cancel"));
        progressDialog->setRange(0, num);

        for (int i = 1; i < num + 1; i++)
        {
            progressDialog->setValue(i);
            if (progressDialog->wasCanceled())
                return;
        }
    }
}

ProgressDlg::~ProgressDlg()
{

}
