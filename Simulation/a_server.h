#ifndef A_SERVER_H
#define A_SERVER_H

#include "t_generator.h"
#include "entity.h"

#include <QObject>

namespace Simulation { namespace Abstract {

class Server : public Template::Generator {

protected:
    //! This variable should be updated with the last departure time.
    double mLastTDepart;
    //! This variable should be updated with the number of departures.
    int mTotalDeparts;

    //! Function processes the serving entity.
    virtual void serving(Entity *e, double time) = 0;
    virtual int removeFromServer(double time) = 0;

public:
    Server(Abstract::Generator *g = nullptr);

    virtual ~Server(){}

    //! If an entity got served, then it is departing. Function returns the
    //! number of entities that were served at a specific time.
    virtual int served(double time);

    //! Add a new entity to the server.
    bool addToServer(Entity *e, double time);

    //! True if the server is serving entities, otherwise false.
    virtual bool isServing() const = 0;

    virtual void reset() = 0;

    double lastTDepart() const { return mLastTDepart; }
    int totalDeparts() const { return mTotalDeparts; }
};

}}


#endif // A_SERVER_H
