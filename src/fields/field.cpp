#include "field.h"

std::unordered_map<field::neighbor, field::neighbor> field::neighbor_opposite = std::unordered_map<field::neighbor, field::neighbor>{{BOTTOM, TOP}, {TOP, BOTTOM}, {RIGHT, LEFT}, {LEFT, RIGHT}};

void field::step_to_neighbors(unsigned int jump_length)
{
    for (auto it = neighbors.begin(); it != neighbors.end(); it++)
    {
        it->second->enter(shortest_to_here + jump_length, neighbor_opposite[it->first]);
    }
}

bool field::attempt_value_change(unsigned int distance_to_here)
{
    if (shortest_to_here == UNTOUCHED || distance_to_here < shortest_to_here)
    {
        shortest_to_here = distance_to_here;
        return true;
    }
    return false;
}

unsigned int field::get_shortest_to_here() const
{
    return shortest_to_here;
}

unsigned int field::collect_result() const
{
    return 0;
}

void field::set_neighbor(const neighbor which, field *to_what)
{
    neighbors[which] = to_what;
}
