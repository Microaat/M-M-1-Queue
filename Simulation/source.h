#ifndef SOURCE_H
#define SOURCE_H

#include "entity.h"
#include "t_generator.h"

#include <QObject>

namespace Simulation {

class Source : public QObject, public Template::Generator {
    Q_OBJECT

    double mLastTArrival;

public:
    Source(Abstract::Generator *g = nullptr, QObject *parent = nullptr);
    virtual ~Source(){}

    void reset();
    Entity newArrival(double offset = 0.0);
    double lastTArrival() const;

signals:
    void arrival();
};

} // End of namespace Simulation


#endif // SOURCE_H
