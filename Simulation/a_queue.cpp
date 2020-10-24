#include "a_queue.h"

namespace Simulation { namespace Abstract {

Queue::Queue():
    Template::Container(-1)
{}
Queue::Queue(int max_size):
    Template::Container(max_size)
{}


}}
