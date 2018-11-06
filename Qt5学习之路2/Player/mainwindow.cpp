#include "mainwindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QTimerEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    axWidget = new QAxWidget;
    //注册表键值,调用插件
    axWidget->setControl("{22D6F312-B0F6-11D0-94AB-0080C74C7E95}");
    axWidget->setProperty("ShowControls", false);
    axWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    connect(axWidget, SIGNAL(PlayStateChange(int, int)),
            this, SLOT(onPlayStateChange(int, int)));
    connect(axWidget, SIGNAL(ReadyStateChange(ReadyStateConstants)),
            this, SLOT(onReadyStateChange(ReadyStateConstants)));
    connect(axWidget, SIGNAL(PositionChange(double, double)),
            this, SLOT(onPositionChange(double, double)));

    openButton = new QToolButton;
    openButton->setText(tr("浏览.."));
    connect(openButton, SIGNAL(clicked()), this, SLOT(openFile()));

    playPauseButton = new QToolButton;
    playPauseButton->setText(tr("播放"));
    playPauseButton->setEnabled(false);
    connect(playPauseButton, SIGNAL(clicked()), axWidget, SLOT(Play()));

    stopButton = new QToolButton;
    stopButton->setText(tr("停止"));
    stopButton->setEnabled(false);
    connect(stopButton, SIGNAL(clicked()), axWidget, SLOT(Stop()));

    seekSlider = new QSlider(Qt::Horizontal);
    seekSlider->setEnabled(false);
    connect(seekSlider, SIGNAL(valueChanged(int)),
            this, SLOT(sliderValueChanged(int)));
    connect(seekSlider, SIGNAL(sliderPressed()),
            axWidget, SLOT(Pause()));

    //可播放格式，此处简写下面几个
    fileFilters = tr("Video files (*.mpg *.mpeg *.avi *.wmv *.mp4)\n"
    "Audio files (*.mp3 *.wav)");

    //初始化播放时间进度
    updateTimer = 0;

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(openButton);
    buttonLayout->addWidget(playPauseButton);
    buttonLayout->addWidget(stopButton);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(axWidget);
    mainLayout->addLayout(buttonLayout);
    mainLayout->addWidget(seekSlider);

    widget = new QWidget();
    widget->setLayout(mainLayout);
    this->setCentralWidget(widget);
}

void MainWindow::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Select File"), ".",
                                                    fileFilters);

    if (!fileName.isEmpty())
        axWidget->setProperty("FileName", QDir::toNativeSeparators(fileName));
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == updateTimer)
    {
        double curPos = axWidget->property("CurrentPosition").toDouble();
        onPositionChange(-1, curPos);
    }
    else
        QWidget::timerEvent(event);
}

void MainWindow::onPlayStateChange(int , int newState)
{
    playPauseButton->disconnect(axWidget);
    switch (newState) {
    case Stopped:
        if (updateTimer)
        {
        killTimer(updateTimer);
        updateTimer = 0;
        }
    case Paused:
        connect(playPauseButton, SIGNAL(clicked()), axWidget, SLOT(Play()));
        stopButton->setEnabled(false);
        playPauseButton->setText(tr("播放"));
        break;
    case Playing:
        if (!updateTimer)
            updateTimer = startTimer(100);
        connect(playPauseButton, SIGNAL(clicked()),
                axWidget, SLOT(Pause()));
        stopButton->setEnabled(true);
        playPauseButton->setText(tr("暂停"));
    }
}

void MainWindow::onReadyStateChange(ReadyStateConstants ready)
{
    if (ready == Complete)
    {
        double duration = 60 * axWidget->property("Duration").toDouble();
        seekSlider->setMinimum(0);
        seekSlider->setMaximum(int(duration));
        seekSlider->setEnabled(true);
        playPauseButton->setEnabled(true);
    }
}

void MainWindow::onPositionChange(double, double newPos)
{
    seekSlider->blockSignals(true);
    seekSlider->setValue(int(newPos * 60));
    seekSlider->blockSignals(false);
}

void MainWindow::sliderValueChanged(int newValue)
{
    seekSlider->blockSignals(true);
    axWidget->setProperty("CurrentPosition", double(newValue) / 60);
    seekSlider->blockSignals(false);
}

MainWindow::~MainWindow()
{

}
