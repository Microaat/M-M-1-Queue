#ifndef TIME_H
#define TIME_H

#include "components.h"

#include <QDebug>
#include <QTime>
#include <QString>

namespace Simulation {

/*!
 * \class Clock
 * \brief The Clock class is used to keep track of the time in the Simulation.
 */
class Time {
public:

    Time();
    Time(int h, int m, int s = 0);
    Time(double value, TimeUnit u = TimeUnit::SECONDS);

    virtual ~Time(){}

    void setHMS(int h, int m, int s);
    void setDblTime(double t);
    void setTimeUnit(TimeUnit u);
    void incDblTime(double amount);
    void decDblTime(double amount);

    const QTime& getTime() const;
    double getDblTime() const;
    double getDblTimeSec() const;
    TimeUnit getTimeUnit() const;

    QString getTimeUnitName() const;
    void reset();

    // Overloaded Operators
    bool operator ==(const Time& t) const { return mQTime == t.getTime(); }
    bool operator !=(const Time& t) const { return !(*this == t); }
    bool operator <=(const Time& t) const { return mQTime <= t.getTime(); }
    bool operator <(const Time& t) const { return mQTime < t.getTime(); }
    bool operator >(const Time& t) const { return mQTime > t.getTime(); }
    bool operator >=(const Time& t) const { return mQTime >= t.getTime(); }

    // Assume time is same units as this instance.
    Time operator +(double time) const;

    // Addition and Subtraction operators.
    Time& operator =(const Time& t);
    Time operator +(const Time& t) const;
    Time operator -(const Time& t) const;
    Time& operator +=(const Time& t);
    Time& operator -=(const Time& t);


    friend QDebug operator<<(QDebug d, const Time& c);

protected:
    /*!
     * \variable mDblTime
     * \brief mDblTime is used by Clock to keep track of the supplied time by
     * the user since mds from QTime is private.
     */

    QTime mQTime;
    double mDblTime;
    TimeUnit mTUnit;

    //! Function updates the interal time of this class.
    void updateTime();
    //! Function updates the time in QTime.
    void updateQTime();
};

} // End of Simulation namespace

#endif // TIME_H
