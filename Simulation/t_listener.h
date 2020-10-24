#ifndef T_LISTENER_H
#define T_LISTENER_H

#include "components.h"
#include "a_listener.h"
#include "a_simulator.h"

#include <QSharedPointer>
#include <QHash>

namespace Simulation { namespace Template {

class Listener {
    typedef QHash<StateFlags, QSharedPointer<Abstract::Listener>> ListenerHash;
    ListenerHash mListeners;
public:
    Listener();
    virtual ~Listener(){}


    void addListener(StateFlags state, Abstract::Listener *listener);
    void notifyListeners(const Abstract::Simulator *s);
    void notifyListeners(StateFlags states);
};

}} // End of namespace

#endif // T_LISTENER_H
