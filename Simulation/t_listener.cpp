#include "t_listener.h"

#include "listener.h"

namespace Simulation { namespace Template {

Listener::Listener(){}

void Listener::addListener(StateFlags state, Abstract::Listener *listener){
    mListeners.insert(state, QSharedPointer<Abstract::Listener>(listener));
}

void Listener::notifyListeners(StateFlags states){
    QSharedPointer<Abstract::Listener> listener = mListeners.value(states);
    if(!listener.isNull()){

    }
}



}} // End of namespace
