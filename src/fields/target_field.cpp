#include "target_field.h"

bool target_field::is_valid_enter(const neighbor from) const
{
    return true;
}

void target_field::step_to_neighbors(unsigned int)
{
    return;
}

void target_field::enter(unsigned int distance_to_here, const neighbor from)
{
    if (is_valid_enter(from))
    {
        attempt_value_change(distance_to_here);
    }
}

unsigned int target_field::collect_result() const
{
    if (get_shortest_to_here() == UNTOUCHED)
    {
        return 0;
    }
    return get_shortest_to_here();
}
