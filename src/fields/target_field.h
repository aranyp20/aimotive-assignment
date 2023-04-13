#pragma once

#include "field.h"

class target_field : public field
{

    short gate_bin_representation;

    bool is_valid_enter(const neighbor from) const;

    void step_to_neighbors(unsigned int) override;

public:
    void enter(unsigned int distance_to_here, const neighbor from) override;
};