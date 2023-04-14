#pragma once

#include <cstddef>
#include <vector>

#include "starting_field.h"

class map
{

    std::vector<std::vector<field *>> fields;
    size_t height;
    size_t width;

    starting_field *enter_point;

    std::vector<field *> read_row();
    /* Sets the enter_point if it created a starting_field. */
    field *create_field(const char);
    void setup_fields();
    void setup_neighborhood();
    void set_neighbors_of(size_t row_num, size_t col_num);

public:
    /* Shallow copy in our use-case leads to unintended behaviour. */
    map(const map &) = delete;
    map &operator=(const map &) = delete;

    map() = default;
    ~map();

    void build();
    void start_calculation();
    unsigned int collect_results() const;
};