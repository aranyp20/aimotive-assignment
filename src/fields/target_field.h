#pragma once

#include <bitset>
#include "field.h"

class target_field : public field
{
    std::bitset<4> gate_bin_representation;

    bool is_valid_enter(const neighbor from) const;
    void step_to_neighbors(unsigned int) override;

public:
    target_field(const char hexa_num);
    void enter(unsigned int distance_to_here, const neighbor from) override;
    unsigned int collect_result() const override;
};