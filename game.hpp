#include <iostream>

void rules();
int players();
void placement(int *& placement_array, int capacity);
void placement_board(int spaces_array[]);
int location_conversion(int const board_location, int const relative_location);
int relative_location(std::string direction);