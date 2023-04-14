#include <iostream>

#include "map.h"

#include "hexa_converter.h"

int main(void)
{

    hexa_converter hc;

    map main_map;
    main_map.build();
    main_map.start_calculation();
    std::cout << main_map.collect_results() << std::endl;

    return EXIT_SUCCESS;
}