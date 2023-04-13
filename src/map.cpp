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

    for (const auto &c : row_as_string)
    {
        std::cout << c << std::endl;
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
}

void map::build()
{

    std::cin >> height;
    std::cin >> width;

    for (unsigned int i = 0; i < height; i++)
    {
        fields.push_back(read_row());
    }
}
