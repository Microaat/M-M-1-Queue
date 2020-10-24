#include "time.h"

namespace Simulation {

Time::Time():
    mQTime(0, 0, 0),
    mDblTime(0.0),
    mTUnit(TimeUnit::SECONDS)
{}

Time::Time(int h, int m, int s):
    mQTime(h, m, s)
{
    updateTime();
}

Time::Time(double value, TimeUnit u):
    mTUnit(u)
{
    setDblTime(value);
    updateQTime();
}

void Time::setHMS(int h, int m, int s){
    mQTime.setHMS(h, m, s);
    updateTime();
}
void Time::setDblTime(double t){
    mDblTime = (t < 0.0)? 0.0 : t;
    updateQTime();
}
void Time::setTimeUnit(TimeUnit u){
    mTUnit = u;
    updateQTime();
}
void Time::incDblTime(double amount){
    setDblTime(getDblTime() + amount);
}
void Time::decDblTime(double amount){
    setDblTime(getDblTime() - amount);
}

const QTime &Time::getTime() const { return mQTime; }
double Time::getDblTime() const { return mDblTime; }
double Time::getDblTimeSec() const { return mDblTime * static_cast<int>(mTUnit); }
TimeUnit Time::getTimeUnit() const { return mTUnit; }

QString Time::getTimeUnitName() const {
    switch(mTUnit){
        case TimeUnit::SECONDS: return QString("seconds");
        case TimeUnit::MINUTES: return QString("minutes");
        default: return QString("hours");
    }
}

void Time::reset(){ setDblTime(0.0); }

Time &Time::operator =(const Time &t){
    setDblTime(t.getDblTime());
    setTimeUnit(t.getTimeUnit());
    return *this;
}

// Time Addition and Subtraction Operators
Time Time::operator +(const Time &t) const {
    return Time(getDblTimeSec() + t.getDblTimeSec());
}
Time Time::operator -(const Time &t) const {
    return Time(getDblTimeSec() - t.getDblTimeSec());
}
Time &Time::operator +=(const Time &t){
    auto time = getDblTimeSec() + t.getDblTimeSec();
    setDblTime(time * static_cast<int>(mTUnit));
    return *this;
}
Time &Time::operator -=(const Time &t){
    auto time = getDblTimeSec() - t.getDblTimeSec();
    setDblTime(time * static_cast<int>(mTUnit));
    return *this;
}

Time Time::operator +(double time) const {
    return Time(*this + Time(time, getTimeUnit()));
}


QDebug operator<<(QDebug d, const Time &c){
     QDebugStateSaver saver(d);
     return d.nospace() << "Clock: h = " << c.mQTime << " | raw = "
                        << c.mDblTime << " " << c.getTimeUnitName();
}

// Private Methods
void Time::updateTime(){
    mDblTime = mQTime.hour() * static_cast<int>(TimeUnit::HOURS)
                 + mQTime.minute() * static_cast<int>(TimeUnit::MINUTES)
                 + mQTime.second() * static_cast<int>(TimeUnit::SECONDS);
}
void Time::updateQTime(){
    auto time = static_cast<int>(mDblTime * static_cast<int>(mTUnit));

    auto h = (time / static_cast<int>(TimeUnit::HOURS)) % 24;
    auto m = (time / static_cast<int>(TimeUnit::MINUTES)) % 60;
    auto s = (time / static_cast<int>(TimeUnit::SECONDS)) % 60;

    mQTime.setHMS(h, m, s);
}

} // End of Simulation namespace
