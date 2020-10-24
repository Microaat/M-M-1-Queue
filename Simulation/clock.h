#ifndef CLOCK_H
#define CLOCK_H

#include "time.h"

#include <QSharedPointer>

namespace Simulation {

class Clock : public Time {
public:
    Clock();
    Clock(double amount, TimeUnit time_unit = TimeUnit::SECONDS);

    void reset();
    void advance(double amount);
    const Time currentTime() const;
    double dblTime() const;

    operator double() const { return dblTime(); }
};

} // End of Simulation namespace

#endif // CLOCK_H
