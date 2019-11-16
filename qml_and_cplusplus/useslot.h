#ifndef USESLOT_H
#define USESLOT_H

#include <QObject>

class UseSlot :public QObject
{
    Q_OBJECT
public:
    UseSlot();
public slots:
    void mySlots();
};

#endif // USESLOT_H
