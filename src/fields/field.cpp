#include "field.h"

void field::step_to_neighbors()
{
    for (auto it = neighbors.begin(); it != neighbors.end(); it++)
    {
        it->second.enter(shortest_to_here + 1, neighbor_opposite[it->first]);
    }
}

void field::attempt_value_change(unsigned int distance_to_here)
{
    if (shortest_to_here == std::numeric_limits<unsigned int>::max() || distance_to_here < shortest_to_here)
    {
        shortest_to_here = distance_to_here;

        step_to_neighbors();
    }
}

unsigned int field::collect_result() const
{
    return 0;
}
