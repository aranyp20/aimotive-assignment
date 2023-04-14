#pragma once

#include <cstddef>
#include <vector>

#include "starting_field.h"

class map
{

    std::vector<std::vector<field *>> fields;
    size_t height;
    size_t width;

    class fields_iterator
    {
    private:
        std::vector<std::vector<field *>> &through;
        size_t row_index;
        size_t column_index;

    public:
        fields_iterator(std::vector<std::vector<field *>> &);
    };

    starting_field *enter_point;

    std::vector<field *> read_row();
    field *create_field(const char);
    void setup_fields();
    void setup_neighborhood();
    void set_neighbors_of(size_t row_num, size_t col_num);

public:
    map(const map &) = delete;
    map &operator=(const map &) = delete;
    map() = default;
    ~map();

    void build();
    void start_calculation();
    unsigned int collect_results() const;
};