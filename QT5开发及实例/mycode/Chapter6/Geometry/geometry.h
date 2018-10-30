#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <QDialog>
#include <QLabel>
#include <QGridLayout>
#include <QMoveEvent>
#include <QResizeEvent>

class Geometry : public QDialog
{
    Q_OBJECT

public:
    Geometry(QWidget *parent = 0);
    ~Geometry();

    void updateLabel();
private:
    QLabel *xLabel;
    QLabel *xValueLabel;
    QLabel *yLabel;
    QLabel *yValueLabel;
    QLabel *FrmLabel;
    QLabel *FrmValueLabel;
    QLabel *posLabel;
    QLabel *posValueLabel;
    QLabel *geoLabel;
    QLabel *geoValuelLabel;
    QLabel *widthLabel;
    QLabel *widthValueLabel;
    QLabel *heightLabel;
    QLabel *heightValueLabel;
    QLabel *rectLabel;
    QLabel *rectValueLabel;
    QLabel *sizeLabel;
    QLabel *sizeValueLabel;
    QGridLayout *mainLayout;
protected:
    void moveEvent(QMoveEvent *);
    void resizeEvent(QResizeEvent *);
};

#endif // GEOMETRY_H
