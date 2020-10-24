#include "statistics.h"

#include <algorithm>
#include <numeric>

namespace Simulation {


Statistics::Statistics():
    mServingDuration(0.0),
    mTimeInQueue(0.0),
    mTimeInSystem(0.0, 0),
    mQueueSizes(0.0, 0),
    mClock(0.0)
{}

void Statistics::reset(){
    mTotals.clear();
    mClock = 0.0;
    mQueueSizes= {0.0, 0};
    mTimeInQueue = 0.0;
    mTimeInSystem = {0.0, 0};
    mServingDuration = 0.0;
}

double Statistics::calAverage(const Statistics::SumAverage &s) const {
    return s.first / s.second;
}

void Statistics::incTotal(State s){
    mTotals[s]++;
}

void Statistics::addQueueSize(int size){
    mQueueSizes.first += size;
    mQueueSizes.second++;
}

void Statistics::addEntityTimeInSystem(const Entity &e){
    mTimeInSystem.first += e.totalWaitTime();
    mTimeInSystem.second++;
}

void Statistics::addEntityTimeInQueue(const Entity &e){
    mTimeInQueue += e.totalQueueTime();
}
void Statistics::addEntityServingDuration(const Entity &e){
    mServingDuration += e.totalServiceTime();
}
double Statistics::getTotalServingDuration() const {
    return mServingDuration;
}
double Statistics::getTotalTimeInSystem() const {
    return mTimeInSystem.first;
}
double Statistics::getTotalTimeInQueue() const {
    return mTimeInQueue;
}
double Statistics::getTotalQueueSize() const {
    return mQueueSizes.first;
}

double Statistics::getMeanServingDuration() const {
    return mServingDuration / mClock;
}
double Statistics::getMeanTimeInSystem() const {
    return calAverage(mTimeInSystem);
}
double Statistics::getMeanTimeInQueue() const {
    return mTimeInQueue / mClock;
}
double Statistics::getMeanQueueSize() const {
    return calAverage(mQueueSizes);
}

int Statistics::getTotal(State s) const {
    return mTotals.value(s);
}

const Statistics::HashTotals& Statistics::getTotals() const {
    return mTotals;
}

} // End of Simulation namespace
