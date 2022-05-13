/*
    Disclaimer:
    I do not own the intellectual property rights to this game
    I am simply recreating this game to test and develop my own coding skills

    If you are interested in buying the actual game, please support them here:
    https://boardgamegeek.com/boardgame/194655/santorini
*/

// g++ -o Santorini main.cpp game.cpp board.cpp characters.cpp -std=c++11

#include <iostream>
#include <cassert>
#include <ctime>
// #include "characters.hpp"
#include "board.hpp"
#include "game.hpp"

int main();

int main() {

    // srand(time(NULL));
    // int god{rand() % 30};  // Allows for random distribution of God Cards, if and when I implement them

    rules(); // Reads rules

    int num_players{};
    num_players = players(); // Initializes the number of players in the game
    Characters workera{}; // Initializes worker objects
    Characters workerA{};
    Characters workerb{};
    Characters workerB{};
    Characters workerc{};
    Characters workerC{};
    Characters character_array[6]{workera, workerA, workerb, workerB, workerc, workerC}; // Allows for easier calls to each worker

    std::cout << " " << std::endl;

    Board gameboard{};
    gameboard.create_board(); // Creates the linked list that is the gameboard

    int capacity{};
    if (num_players < 4) {
        capacity = 4;
    } else {
        capacity = 6;
    }

    int *array{new int[capacity]}; // Creates an array such that all inputs can be accessed later
    placement(array, capacity); // Allows players to place their workers

    for (std::size_t k{1}; k < capacity + 1; ++k) { // Assigns the placement of the workers to the actual board
        std::cout << "test abc" << std::endl;
        gameboard.set_board_occupied(array[k], true);
        std::cout << "test def" << std::endl;
        gameboard.set_board_worker(array[k], k);
        std::cout << "test ghi" << std::endl;
        character_array[k].set_character_location(k);
        std::cout << "test jkl" << std::endl;
    }

    std::cout << "test" << std::endl;

    for (std::size_t turn{0}; true; ++turn) {
        turn %= 3;
        if (turn == 0) {
            std::cout << "Team 1: " << std::endl;
        } else if (turn == 1) {
            std::cout << "Team 2: " << std::endl;
        } else if (turn == 2) {
            std::cout << "Team 3: " << std::endl;
        }

        return 0;

        for (std::size_t test_win{0}; test_win < 6; ++test_win) {
            if (character_array[test_win].get_character_level() == 3) {
                std::cout << "Congratulations! YOU WON ";
                if (turn == 0) {
                    std::cout << "Team 1!" << std::endl;
                } else if (turn == 1) {
                    std::cout << "Team 2!" << std::endl;
                } else if (turn == 2) {
                    std::cout << "Team 3!" << std::endl;
                }
                return 0;
            }
        }
    }

    return 0;
}