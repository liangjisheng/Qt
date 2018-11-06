#include "runnable.h"

Runnable::Runnable(QProgressBar *progressBar)
   : QRunnable(), m_ProgressBar(progressBar)
{
    for (int i = 0; i < 100000; i++)
        progressBar->setValue(i);
}

Runnable::~Runnable() {}

void Runnable::run() {}
