#include "source.h"

namespace Simulation {

Source::Source(Abstract::Generator *g, QObject *parent):
    QObject(parent),
    Template::Generator(g),
    mLastTArrival(0.0)
{
    setObjectName("source");
}

void Source::reset(){
    mLastTArrival = 0.0;
}

Entity Source::newArrival(double offset){
    mLastTArrival = offset + mGenerator->newValue();

    emit arrival();
    return Entity(mLastTArrival);
}

double Source::lastTArrival() const {
    return mLastTArrival;
}

} // End of namespace Simulation
