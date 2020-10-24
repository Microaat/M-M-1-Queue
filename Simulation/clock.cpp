#include "clock.h"

namespace Simulation {

Clock::Clock():
    Time()
{}

Clock::Clock(double amount, TimeUnit time_unit):
    Time(amount, time_unit)
{}

void Clock::reset(){ Time::reset(); }
void Clock::advance(double amount){
    incDblTime(amount);
}
const Time Clock::currentTime() const { return Time(mDblTime, getTimeUnit()); }
double Clock::dblTime() const { return mDblTime; }


} // End of Simulation namespace
