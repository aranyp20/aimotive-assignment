#pragma once

#include "field.h"

class starting_field : public field
{

public:
    void enter(unsigned int distance_to_here, const neighbor from) override;

    void start_calculation();
};