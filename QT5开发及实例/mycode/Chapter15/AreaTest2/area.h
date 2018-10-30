#ifndef AREA_H
#define AREA_H

#include <QtCore>
#include <QObject>

class Area : public QObject
{
public:
    Area() {}
    ~Area() {}
    Area(const Area &area) { m_r = area.m_r; }
    Area(int r) { m_r = r; }
    double CountArea() { return 3.14 * m_r * m_r; }
private:
    double m_r;
};

// 该宏将Area定义为元类型，这样所有基于模板的函数都可以使用Area.
Q_DECLARE_METATYPE(Area)

#endif // AREA_H
