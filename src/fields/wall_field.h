#pragma once

#include "field.h"

class wall_field : public field
{
public:
    void enter(unsigned int distance_to_here, const neighbor from);
};