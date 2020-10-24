#ifndef SERVER_H
#define SERVER_H

#include "t_generator.h"
#include "entity.h"

#include <QObject>

namespace Simulation {

/*!
 * \class Server Class
 * \brief The Server class is the same as Abstract::Server, however this class cannot be extended.
 *
 * Simulation::Server is the same as Abstract::Server except that this class defines
 * all virtual functions of Abstract::Server and cannot be extended.
 */
class Server : public QObject, public Template::Generator {
    Q_OBJECT

    Entity *mEntity;
    Entity *mLastEntity;

public:
    Server(Abstract::Generator *g = nullptr, QObject *parent = nullptr);
    virtual ~Server(){}

    //! Add a new entity to the server if the server is not serving an entity.
    bool addToServer(Entity *e, double time);

    //! If an entity got served, then it is departing. Function returns the
    //! number of entities that were served at a specific time.
    bool served(double time);

    bool isServing() const;
    const Entity& servingEntity() const;
    const Entity& lastEntityServed() const;
    double lastTDepart() const;
    double nextTDepart() const;

    void reset();

signals:
    //! Emitted an entity was added to the server
    void service();

    //! Emitted when entity departs
    void depart();
};

/*namespace Server {

class Single : public Abstract::Server {
    Entity *mEntity;

    void serving(Entity *e, double time);
    int removeFromServer(double time);

public:
    Single(Abstract::Generator *g = nullptr);

    bool isServing() const;
    void reset();
};

}*/
} // End of namespace


#endif // SERVER_H
