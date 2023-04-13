#include "target_field.h"

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
