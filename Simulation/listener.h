#ifndef LISTENER_H
#define LISTENER_H

#include "a_listener.h"
#include "components.h"

namespace Simulation { namespace Listener {

class Arrival : public Abstract::Listener {
protected:
    void updateStats(const Abstract::Simulator *s /* unused */);

public:
    Arrival(Statistics *stats);
};


class Service : public Abstract::Listener {
protected:
    void updateStats(const Abstract::Simulator *s /* unused */);

public:
    Service(Statistics *stats);
};


class Departure : public Abstract::Listener {
protected:
    void updateStats(const Abstract::Simulator *s /* unused */);

public:
    Departure(Statistics *stats);
};


class QueuePosDuration : public Abstract::Listener {

protected:
    void updateStats(const Abstract::Simulator *s);

public:
    QueuePosDuration(Statistics *stats);
};

}} // End of namesace


#endif // LISTENER_H
