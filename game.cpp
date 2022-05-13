#include <iostream>
#include "game.hpp"

void rules() {
    std::cout << "Welcome to Santorini" << std::endl << std::endl;

    std::cout << "If you are unfamiliar with the rules, please read them here: " << std::endl <<
                    "https://www.ultraboardgames.com/santorini/game-rules.php" << std::endl << std::endl;

    std::cout << "Players 1 and 4 will be represented by A's" << std::endl <<
                "Players 2 and 5 will be represented by B's" << std::endl << 
                "Players 3 and 6 will be represented by C's" << std::endl <<
                "Domes will be represented by D's" << std::endl <<
                "And the levels will be represented with 0, 1, 2, and 3 respectively" << std::endl << std::endl;
}

int players() {
    int num_players{0};

    std::cout << "Great! Before we get started, how many players are participating?" << std::endl;
    while (num_players < 2 || num_players > 6) {

        std::cin >> num_players;

        if (num_players < 2) {
            std::cout << "You cannot have less than 2 players" << std::endl;
        } else if (num_players > 6) {
            std::cout << "You cannot have more than 6 players" << std::endl;
        }
    }

    return num_players;
}

void placement(int *& placement_array, int capacity) {

    int spaces_array[25]{};

    for (std::size_t k{0}; k < 25; ++k) {
        spaces_array[k] = k;
    }

    int loop_count{};
    loop_count = capacity + 1;

    for (std::size_t i{1}; i < loop_count; ++i) {

        placement_board(spaces_array);

        if (i == 1 || i == 2) {
            std::cout << "Team 1: ";
        } else if (i == 3 || i == 4) {
            std::cout << "Team 2: ";
        } else if (i == 5 || i == 6) {
            std::cout << "Team 3: ";
        }

        int tmp{};
        std::cout << "Please choose a location to place your worker: ";
        std::cin >> tmp;

        while (tmp < 0 || tmp > 24) {
            std::cout << "Invalid location.  Please enter a new location: ";
            std::cin >> tmp;

            for (std::size_t j{0}; j < 6; ++j) {
                if (placement_array[j] == tmp) {
                    tmp = 25;
                }
            }
        }

        std::cout << std::endl;
        placement_array[i-1] = tmp;
        spaces_array[tmp] = -i;
    }
}

void placement_board(int array []) {
    for (std::size_t row{0}; row < 5; ++row) {
        for (std::size_t column{0}; column < 5; ++column) {
            if ((array[(row*5) + column]) < 0) {
                if ((array[(row*5) + column]) == -1) {
                    std::cout << 'a';
                } else if ((array[(row*5) + column]) == -2) {
                    std::cout << 'A';
                } else if ((array[(row*5) + column]) == -3) {
                    std::cout << 'b';
                } else if ((array[(row*5) + column]) == -4) {
                    std::cout << 'B';
                } else if ((array[(row*5) + column]) == -5) {
                    std::cout << 'c';
                } else if ((array[(row*5) + column]) == -6) {
                    std::cout << 'C';
                }
            } else {
                std::cout << array[(row*5) + column];
            }

            if (array[(row*5) + column] < 10) {
                std::cout << "   ";
            } else {
                std::cout << "  ";
            }
        }
        std::cout << std::endl;
    }
}

int location_conversion(int const board_location, int const relative_location) {
    int converted_location{};
    int row{};
    int column{};

    row = (relative_location - 1) /  3;
    column = (relative_location - 1) % 3;

    if (column != 1) {
        if (((board_location % 5) == 0) || (((board_location + 1) % 5) == 0)) {
            return 25;
        }
    }

    converted_location = board_location + ((row - 1) * 5);
    converted_location += (column - 1);

    if (converted_location < 0 || converted_location > 24) {
        return 25;
    } else { 
        return converted_location;
    }
}

int relative_location(std::string direction) {
    if (direction == "NW") {
        return 1;
    } else if (direction == "N") {
        return 2;
    } else if (direction == "NE") {
        return 3;
    } else if (direction == "W") {
        return 4;
    } else if (direction == "E") {
        return 6;
    } else if (direction == "SW") {
        return 7;
    } else if (direction == "S") {
        return 8;
    } else if (direction == "SE") {
        return 9;
    } else {
        std::cout << "Invalid direction. Please enter a new direction: ";
        std::cin >> direction;
        return relative_location(direction);
    }
}