#ifndef RUNNABLE_H
#define RUNNABLE_H

#include <QRunnable>
#include <QProgressBar>

class Runnable : public QRunnable
{
public:
    Runnable(QProgressBar *progressBar);
    virtual ~Runnable();
    void run();
private:
    QProgressBar *m_ProgressBar;
};

#endif // RUNNABLE_H
