#ifndef MM1QUEUE_H
#define MM1QUEUE_H

#include <QDebug>
#include <iostream>

/*!
 * \class MM1Queue_base
 * \brief This class provides getters and setters for {lambda} and {mu} which are used in M/M/1 Queue.
 *
 * This class provides getters and setters for {lambda} and {mu} which are used
 * in M/M/1 queues. Any class that needs to store lambda and mu should inherit
 * this class.
 */
class MM1Queue_base {
protected:
    double mLambda;
    double mMu;

public:
    MM1Queue_base():
        mLambda(0.0), mMu(0.0){}
    MM1Queue_base(double la, double mu):
        mLambda(la), mMu(mu){}

    virtual ~MM1Queue_base(){}

    // Setters
    virtual void setLambda(double lambda){ mLambda = lambda; }
    virtual void setMu(double mu){ mMu = mu; }

    // Getters
    double getLambda() const { return mLambda; }
    double getMu() const { return mMu; }
};

/*!
 * \class MM1Queue
 * \brief The MM1Queue class provides methods to obtain mean totals using {lambda} and {mu}.
 */
class MM1Queue : public MM1Queue_base {
public:
    MM1Queue(): MM1Queue_base() {}
    MM1Queue(double lambda, double mu):
        MM1Queue_base(lambda, mu){}

    //! Returns the average utilization of the service system (commonly denoted as rho).
    double meanUtilization() const { return mLambda / mMu; }

    //! Returns the average amount of items in the system being handled by the queue.
    double meanAmountInSystem() const { return meanUtilization() / (1 - meanUtilization()); }

    //! Returns the average time spent in the system.
    double meanTimeInSystem() const { return 1.0 / (mMu - mLambda); }

    //! Returns the average size of the queue.
    double meanQueueSize() const { return mLambda * meanQueueTime(); }

    //! Returns the average waiting time which is the time spent in the queue.
    double meanQueueTime() const { return meanTimeInSystem() - 1.0/mMu; }

    friend QDebug operator <<(QDebug d, const MM1Queue& q){
        QDebugStateSaver saver(d);
        return d.nospace() << "MM1Queue: Lambda = " << q.getLambda() << ", Mu = " << q.getMu();
    }
};


#endif // MM1QUEUE_H
