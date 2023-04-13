#include "starting_field.h"

void starting_field::enter(unsigned int distance_to_here, const neighbor from)
{
    return;
}

void starting_field::start_calculation()
{
    set_shortest_to_here(0);
    step_to_neighbors(0);
}
