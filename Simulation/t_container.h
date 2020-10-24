#ifndef CONTAINER_H
#define CONTAINER_H

#include "components.h"
#include "entity.h"

namespace Simulation { namespace Template {

class Container {
protected:
    EntityList mContainer;
    int mMaxSize;

    int maxSize() const;

public:
    Container(): mMaxSize(1){}
    Container(int max_size): mMaxSize(max_size){}

    virtual ~Container(){}

    void setMaxSize(int max_size){
        mMaxSize = max_size;
    }
    int getMaxSize() const { return mMaxSize; }

    int size(){ return mContainer.size(); }
    void clear(){ mContainer.clear(); }

    const EntityList& container() const;
    EntityList& container();

    bool append(Entity *e);

    const Entity* first() const;
    Entity* first();
    const Entity* last() const;
    Entity* last();

    friend QDebug operator<<(QDebug d, const Container& c);
};

}} // End of Simulation namespace


#endif // CONTAINER_H
