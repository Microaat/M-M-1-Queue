#ifndef QUEUE_H
#define QUEUE_H

#include "components.h"
#include "t_container.h"

#include <QList>
#include <QDebug>
#include <QObject>

#include <utility>

namespace Simulation {

/*!
 * \class Queue
 * \brief The Queue class acts as a FIFO container to store entities that are
 * waiting to be served.
 */

class Queue : public QObject, public Template::Container {
    Q_OBJECT

public:
    Queue(QObject *parent = nullptr);
    Queue(int max_size, QObject *parent = nullptr);

    //! Removes an entity at the front of the queue.
    Entity* pop();

    //! Returns true if entity was added at the end of the queue. Otherwise it
    //! it returns false if the entity was rejected.
    bool put(Entity *e);

signals:
    void queueAccept();
    void queueReject();
    void dequeue();
    void empty();
};

} // End of Simulation namespace

#endif // QUEUE_H
