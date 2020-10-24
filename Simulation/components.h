#ifndef COMPONENTS_H
#define COMPONENTS_H

#include <QList>
#include <QSharedPointer>

// Components
namespace Simulation {

namespace Abstract {
    class Simulator;
    class Listener;
    class Generator;
}
class Entity;

enum State {
    NONE = 0,
    ARRIVAL = 1 << 0,
    SERVICE = 1 << 1,
    DEPARTURE = 1 << 2,

    // If arrival was accepted into queue
    QUEUE_ACCEPT = 1 << 3,
    // If arrival was rejected into queue
    QUEUE_REJECT = 1 << 4,
    QUEUE_EMPTY
};

Q_DECLARE_FLAGS(StateFlags, State)
Q_DECLARE_OPERATORS_FOR_FLAGS(StateFlags)


enum TimeUnit {
    SECONDS = 1,
    MINUTES = 60,
    HOURS = 3600
};

typedef QList<Entity*> EntityList;
typedef QList<Entity> Entities;

} // End of Simulation namespace

#endif // COMPONENTS_H
