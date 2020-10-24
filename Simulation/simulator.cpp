#include "simulator.h"

#include <QtGlobal>
#include <QtAlgorithms>

namespace Simulation { namespace Simulator {

void Simple::runSim(){
    //mClock.setDblTime(qMin(mSource.lastTArrival(), mServer.nextTDepart()));
    mClock.setDblTime(mSource.lastTArrival());

    //qDebug() << "\n>> Current Time: " << mClock.getDblTime();
    if(mServer.served(mClock)){
        mClock.setDblTime(mServer.lastTDepart());
        mServer.addToServer(mQueue.pop(), mClock);
        return;
    }

    //qDebug() << "Current Queue Size: " << mQueue.size();

    mEntities.append(mSource.newArrival(mClock));
    mQueue.put(&(mEntities.back()));

    if(!mServer.isServing()) mServer.addToServer(mQueue.pop(), mClock);


    //qDebug() << "Arrival = " << mSource.lastTArrival() << " | Next Depart = " << mServer.nextTDepart();
    //qDebug() << "New Time: " << mClock.getDblTime();
}

}} // End of Simulation Namespace
