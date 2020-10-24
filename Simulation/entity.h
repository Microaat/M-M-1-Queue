#ifndef ENTITY_H
#define ENTITY_H

#include "time.h"

#include <QDebug>

namespace Simulation {

/*!
 * \class Simulation::Entity
 * \brief The Entity class is used by the Simulation class.
 *
 * The Entity class represent the objects that are placed in a queue and served
 * in the Simulation class.
 */
class Entity {
    static int mCurrId;

    int mId;
    bool mQueueAccepted;
    double mTArrival;
    double mTService;
    double mTDepart;

public:
    Entity();
    Entity(double tarrival, double tservice = 0.0, double tdepart = 0.0);

    static void resetId(){ mCurrId = 0; }

    // Getters
    int getId() const;
    bool getQueueAccepted() const;
    double getTArrival() const;
    double getTService() const;
    double getTDepart() const;

    // Setters
    void queueAccepted();
    void setTArrival(double value);
    void setTService(double value);
    void setTDepart(double value);

    double totalWaitTime() const;
    double totalQueueTime() const;
    double totalServiceTime() const;

    friend QDebug operator <<(QDebug d, const Entity& e);
};

} // End of Simulation Namespace

#endif // ENTITY_H
