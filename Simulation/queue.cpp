#include "queue.h"

#include <limits>

namespace Simulation {

Queue::Queue(QObject *parent):
    QObject(parent),
    Template::Container(-1)
{
    setObjectName("queue");
}

Queue::Queue(int max_size, QObject *parent):
    QObject(parent), Template::Container(max_size)
{
    setObjectName("queue");
}

Entity *Queue::pop(){
    if(mContainer.isEmpty()){
        emit empty();
        return nullptr;
    }

    emit dequeue();
    return mContainer.takeFirst();
}

bool Queue::put(Entity *e){
    if(append(e)){
        e->queueAccepted();
        emit queueAccept();
        return true;
    }

    emit queueReject();
    return false;
}

} // End of Simulation namespace
