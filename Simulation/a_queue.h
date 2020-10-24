#ifndef A_QUEUE_H
#define A_QUEUE_H

#include "t_container.h"

#include <QList>

namespace Simulation { namespace Abstract {

class Queue : public Template::Container {

public:
    Queue();
    Queue(int max_size);
    virtual ~Queue(){}

    Entity* pop();
};

}} // End of namespace


#endif // A_QUEUE_H
