#include "field.h"

void field::step_to_neighbors(unsigned int jump_length)
{
    for (auto it = neighbors.begin(); it != neighbors.end(); it++)
    {
        it->second.enter(shortest_to_here + jump_length, neighbor_opposite[it->first]);
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

void field::set_shortest_to_here(unsigned int val)
{
    shortest_to_here = val;
}

unsigned int field::collect_result() const
{
    return 0;
}
