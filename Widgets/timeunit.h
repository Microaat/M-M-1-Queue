#ifndef TIMEUNIT_H
#define TIMEUNIT_H

#include "Simulation/components.h"

#include <QComboBox>

namespace Widget {

class TimeUnit : public QComboBox {
    Q_OBJECT

    Simulation::TimeUnit mTUnit;

    //! If true, then names of time units are shorten (seconds = secs).
    bool mShortName;

    void addShortNames();
    void addLongNames();
    void createNames();
    void shortenNames(bool value = true);

public:
    explicit TimeUnit(bool shortnames = true, QWidget *parent = nullptr);
    ~TimeUnit(){}

};

} // End of namespace


#endif // TIMEUNIT_H
