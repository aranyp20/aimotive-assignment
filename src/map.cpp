#include <iostream>
#include <string>

#include "map.h"
#include "starting_field.h"
#include "empty_field.h"
#include "wall_field.h"
#include "target_field.h"

std::vector<field *> map::read_row()
{
    std::vector<field *> result;

    std::string row_as_string;

    std::cin >> row_as_string;

    for (const auto c : row_as_string)
    {
        result.push_back(create_field(c));
    }

    return result;
}

field *map::create_field(const char c)
{
    switch (c)
    {
    case 'T':
        enter_point = new starting_field();
        return enter_point;
        break;
    case '-':
        return new empty_field();
        break;
    case 'X':
        return new wall_field();
        break;
    default:
        return new target_field();
        break;
    }
}

void map::setup_fields()
{
    std::cin >> height;
    std::cin >> width;

    for (unsigned int i = 0; i < height; i++)
    {
        fields.push_back(read_row());
    }
}

void map::setup_neighborhood()
{
    for (size_t i = 0; i < height; i++)
    {
        for (size_t j = 0; j < width; j++)
        {
            set_neighbors_of(i, j);
        }
    }
}

void map::set_neighbors_of(size_t row_num, size_t col_num)
{
    field &manipulated_field = *(fields[row_num][col_num]);

    if (row_num > 0)
    {
        manipulated_field.set_neighbor(field::neighbor::TOP, fields[row_num - 1][col_num]);
    }
    if (row_num < height - 1)
    {
        manipulated_field.set_neighbor(field::neighbor::BOTTOM, fields[row_num + 1][col_num]);
    }
    if (col_num > 0)
    {
        manipulated_field.set_neighbor(field::neighbor::LEFT, fields[row_num][col_num - 1]);
    }
    if (col_num < width - 1)
    {
        manipulated_field.set_neighbor(field::neighbor::RIGHT, fields[row_num][col_num + 1]);
    }
}

void map::build()
{

    setup_fields();

    setup_neighborhood();
}

void map::start_calculation()
{
    enter_point->start_calculation();
}

unsigned int map::collect_results() const
{
    unsigned int sum = 0;

    for (const auto &a : fields)
    {
        for (const auto &b : a)
        {
            sum += b->collect_result();
        }
    }

    return sum;
}

map::~map()
{
    for (const auto &a : fields)
    {
        for (const auto &b : a)
        {
            delete b;
        }
    }
}

map::fields_iterator::fields_iterator(std::vector<std::vector<field *>> &_through) : row_index(0), column_index(0), through(_through)
{
}
