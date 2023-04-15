#include <string>
#include "target_field.h"

bool target_field::is_valid_enter(const neighbor from) const
{
    std::bitset<4> mask(0001);

    return ((mask << from) & gate_bin_representation) != 0;
}

target_field::target_field(const char hexa_num) : gate_bin_representation(std::stoi(std::string(&hexa_num, 1), nullptr, 16))
{
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
