#ifndef STATISTICS_H
#define STATISTICS_H

#include "components.h"
#include "entity.h"
#include "time.h"

#include <QVector>
#include <QHash>
#include <utility>

namespace Simulation {

class Statistics {
public:
    typedef QHash<State, int> HashTotals;
    typedef std::pair<double, int> SumAverage;

private:
    double mServingDuration;
    double mTimeInQueue;
    SumAverage mTimeInSystem;
    SumAverage mQueueSizes;
    HashTotals mTotals;
    double mClock;

    double calAverage(const SumAverage& s) const;

public:
    Statistics();

    void reset();

    void setClock(double clock){ mClock = clock; }

    void incTotal(State s);
    void addQueueSize(int size);
    void addEntityTimeInSystem(const Entity& e);
    void addEntityTimeInQueue(const Entity& e);
    void addEntityServingDuration(const Entity& e);

    double getTotalServingDuration() const;
    double getTotalTimeInSystem() const;
    double getTotalTimeInQueue() const;
    double getTotalQueueSize() const;

    double getMeanServingDuration() const;
    double getMeanTimeInSystem() const;
    double getMeanTimeInQueue() const;
    double getMeanQueueSize() const;
    int getTotal(State s) const;
    const HashTotals& getTotals() const;
};

} // End of Simulation namespace

#endif // STATISTICS_H
