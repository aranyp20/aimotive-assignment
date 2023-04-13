#pragma once

#include <cstddef>
#include <vector>

#include "field.h"

class map
{

    std::vector<std::vector<field *>> fields;
    size_t height;
    size_t width;

    std::vector<field *> read_row() const;

    field *create_field(const char) const;

    void set_neighborhood();
    void set_neighbors_of(unsigned row_num, unsigned col_num);

public:
    void build();
};