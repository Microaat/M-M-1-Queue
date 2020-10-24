#include "entity.h"

namespace Simulation {

int Entity::mCurrId = 0;

Entity::Entity():
    mId(mCurrId),
    mQueueAccepted(false),
    mTArrival(0.0),
    mTService(0.0),
    mTDepart(0.0)
{
    mCurrId++;
}

Entity::Entity(double tarrival, double tservice, double tdepart):
    mId(mCurrId),
    mQueueAccepted(false),
    mTArrival(tarrival),
    mTService(tservice),
    mTDepart(tdepart)
{
    mCurrId++;
}

int Entity::getId() const { return mId; }

bool Entity::getQueueAccepted() const { return mQueueAccepted; }
double Entity::getTArrival() const { return mTArrival; }
double Entity::getTService() const { return mTService; }
double Entity::getTDepart() const { return mTDepart; }

void Entity::queueAccepted(){ mQueueAccepted = true; }
void Entity::setTArrival(double value){ mTArrival = value; }
void Entity::setTService(double value){ mTService = value; }
void Entity::setTDepart(double value){ mTDepart = value; }

double Entity::totalWaitTime() const {
    double total = mTDepart + mTArrival;
    return (total <= 0.0)? 0.0 : total;
}

double Entity::totalQueueTime() const {
    double total = mTService + mTArrival;
    return (total <= 0.0)? 0.0 : total;
}

double Entity::totalServiceTime() const {
    double total = mTDepart + mTService;
    return (total <= 0.0)? 0.0 : total;
}

QDebug operator <<(QDebug d, const Entity& e){
    QDebugStateSaver saver(d);
    return d.nospace() << "Entity (" << e.mId << "): "
                       << "Queue Accepted = " << e.mQueueAccepted << ", "
                       << "TArrival = " << e.mTArrival << ", "
                       << "TService = " << e.mTService << ", "
                       << "TDepart = " << e.mTDepart;
}

} // End of Simulation namespace
