#include <iostream>
#include "characters.hpp"

Characters::Characters() {
    character_location = 25;
    character_level = 0;
    character_worker = 0;
}

Characters::Characters(int location_id, int level_id, int worker_id) {
    character_location = location_id;
    character_level = level_id;
    character_worker = worker_id;
}

Characters::~Characters() { }

int Characters::get_character_location() const { return character_location; }
int Characters::get_character_level() const { return character_level; }
int Characters::get_character_worker() const { return character_worker; }

void Characters::set_character_location(int new_location) { character_location = new_location; }
void Characters::set_character_level(int new_level) { character_level = new_level; }
void Characters::set_character_worker(int new_worker) { character_worker = new_worker; }

void Characters::move(int move_location, Board gameboard) {

    // Verifies if the location is a valid move
    move_location = location_conversion (this -> get_character_location(), move_location);
    while (gameboard.get_board_occupied(move_location)) {
        std::string tmp{};
        std::cout << "Invalid location to move.  Please enter a new location: ";
        std::cin >> tmp;
        move_location = location_converstion (this -> get_character_location(), relative_location(tmp));
    }

    // Removes object's info from old location
    gameboard.set_board_occupied(this -> get_character_location(), false);
    gameboard.set_board_worker(this -> get_character_location(), 0);

    // Enters object's info to new location
    gameboard.set_board_occupied(move_location, true);
    gameboard.set_board_worker(move_location, this -> get_character_location());

    // Enters new location's info to object
    this -> set_character_location(gameboard.get_board_location(move_location));
    this -> set_character_level(gameboard.get_board_level(move_location));
}

void Characters::build(int build_location, Board gameboard) {

    build_location = location_conversion (this -> get_character_location(), build_location);
    while (gameboard.get_board_occupied(build_location)) {
        std::string tmp{};
        std::cout << "Invalid location to move.  Please enter a new direction: ";
        std::cin >> tmp;
        build_location = location_converstion (this -> get_character_location(), relative_location(tmp));
    }

    build_location = location_converstion(this -> get_character_location(), build_location);

    int build_height{};

    build_height = gameboard.get_board_level() + 1;

    if (build_height == 4) {
        gameboard.set_board_level(build_location, build_height);
        gameboard.set_board_occupied(build_location, true);
        gameboard.set_board_worker(build_location, 7);
    } else {
        gameboard.set_board_level(build_location, build_height);
    }
}