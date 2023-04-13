#include <iostream>
#include <string>

#include "map.h"
#include "starting_field.h"
#include "empty_field.h"
#include "wall_field.h"
#include "target_field.h"

std::vector<field *> map::read_row() const
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

field *map::create_field(const char c) const
{
    switch (c)
    {
    case 'T':
        return new starting_field();
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

void map::set_neighborhood()
{
    for (unsigned i = 0; i < height; i++)
    {
        for (unsigned j = 0; j < width; j++)
        {
            set_neighbors_of(i, j);
        }
    }
}

void map::set_neighbors_of(unsigned row_num, unsigned col_num)
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

    std::cin >> height;
    std::cin >> width;

    for (unsigned int i = 0; i < height; i++)
    {
        fields.push_back(read_row());
    }

    set_neighborhood();
}
