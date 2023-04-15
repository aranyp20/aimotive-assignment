#include "empty_field.h"

void empty_field::enter(unsigned int distance_to_here, const neighbor from)
{
    if (attempt_value_change(distance_to_here))
    {
        step_to_neighbors();
    }
}
