#include "t_container.h"

namespace Simulation { namespace Template {

int Container::maxSize() const {
    if(mMaxSize < 0 ) return std::numeric_limits<int>::max();
    return mMaxSize;
}

const EntityList &Container::container() const {
    return mContainer;
}
EntityList &Container::container(){
    return mContainer;
}

bool Container::append(Entity *e){
    if(size() >= maxSize()) return false;
    mContainer.append(e);
    return true;
}

const Entity *Container::first() const {
    if(mContainer.isEmpty()) return nullptr;
    return mContainer.constFirst();
}
Entity *Container::first(){
    if(mContainer.isEmpty()) return nullptr;
    return mContainer.first();
}
const Entity *Container::last() const {
    if(mContainer.isEmpty()) return nullptr;
    return mContainer.constLast();
}
Entity *Container::last() {
    if(mContainer.isEmpty()) return nullptr;
    return mContainer.last();
}

QDebug operator<<(QDebug d, const Container &c){
    QDebugStateSaver saver(d);
    return d.nospace() << "Container: " << c.mContainer;
}

}} // End of Simulation namespace
