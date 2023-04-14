#include <iostream>

#include "map.h"

int main(void)
{

    map main_map;
    main_map.build();
    main_map.start_calculation();
    std::cout << main_map.collect_results() << std::endl;

    return EXIT_SUCCESS;
}