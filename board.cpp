#include <iostream>
#include "board.hpp"
#include "game.hpp"

Space::Space(int location_id, int level_id, bool occupied_id, int worker_id) {
    space_location = location_id;
    space_level = level_id;
    space_occupied = occupied_id;
    space_worker = worker_id;
    p_next = nullptr;
}

Space::~Space() {
    
}

int Space::get_space_location() const { return space_location; }
int Space::get_space_level() const { return space_level; }
bool Space::get_space_occupied() const { return space_occupied; }
int Space::get_space_worker() const {return space_worker;}
Space * Space::get_next() { return p_next; }

void Space::set_space_location(int new_location) { space_location = new_location; }
void Space::set_space_level(int new_level) { space_level = new_level; }
void Space::set_space_occupied(bool new_occupied) { space_occupied = new_occupied; }
void Space::set_space_worker(int new_worker) { space_worker = new_worker; }
void Space::set_next(Space * p_new_next) { p_next = p_new_next; }

void Space::print() const {
    if (space_occupied) {
        if (space_worker == 7) {
                std::cout << "D";
            } else if (space_worker == 1) {
                std::cout << "a";
            } else if (space_worker == 2) {
                std::cout << "A";
            } else if (space_worker == 3) {
                std::cout << "b";
            } else if (space_worker == 4) {
                std::cout << "B";
            }else if (space_worker== 5) {
                std::cout << "c";
            } else if (space_worker == 6) {
                std::cout << "C";
            }
    } else {
        std::cout << get_space_level();
    }
}



Board::Board() {
    this -> p_head = nullptr;
}

Board::~Board() {
    Space *p_tmp{p_head};

    while (p_tmp != nullptr) {
        Space *p_tmp_old{p_tmp};
        p_tmp = p_tmp -> get_next();
        delete p_tmp_old;
        p_tmp_old = nullptr;
    }

    p_tmp = nullptr;
    p_head = nullptr;
}

void Board::insert_space(Space * p_new_space) {
    if (p_head == nullptr) {
        this -> p_head = p_new_space;
    } else {
        Space * p_traverse;
        while (p_traverse -> get_next() != nullptr) {
            p_traverse = p_traverse -> get_next();
        }
        p_traverse -> set_next(p_new_space);
    }
}

void Board::create_board() {
    for (int k{0}; k < 25; ++k) {
        Space * p_new_space {new Space{k, 0, false, 0}};
        insert_space(p_new_space);
    }
}

void Board::print_board() {
    Space * p_traverse{p_head};
    for (std::size_t row{0}; row < 5; ++row) {
        for (std::size_t column{0}; column < 5; ++column) {
            p_traverse -> print();
            std::cout << "   ";
        }
        std::cout << std::endl;
    }
}

void Board::print_placement_board() {
    for (std::size_t row{0}; row < 5; ++row) {
        for (std::size_t column{0}; column < 5; ++column) {
            if (this -> get_board_occupied((row*5) + column)) {
                this -> print_board();
            } else {
                std::cout << this -> get_board_location((row*5) + column);
            }
        }
        std::cout << std::endl;
    }
}

int Board::get_board_location(int location) const {
    Space * p_traverse{p_head};
    for (std::size_t k{0}; k < location; ++k) {
        p_traverse = p_traverse -> get_next();
    }
    return p_traverse -> get_space_location();
}

int Board::get_board_level(int location) const {
    Space * p_traverse{p_head};
    for (std::size_t k{0}; k < location; ++k) {
        p_traverse = p_traverse -> get_next();
    }
    return p_traverse -> get_space_level();
}

bool Board::get_board_occupied(int location) const {
    Space * p_traverse{p_head};
    for (std::size_t k{0}; k < location; ++k) {
        p_traverse = p_traverse -> get_next();
    }
    return p_traverse -> get_space_occupied();
}

int Board::get_board_worker(int location) const {
    Space * p_traverse{p_head};
    for (std::size_t k{0}; k < location; ++k) {
        p_traverse = p_traverse -> get_next();
    }
    return p_traverse -> get_space_worker();
}

void Board::set_board_location(int location, int new_location) {
    Space * p_traverse{p_head};
    for (std::size_t k{0}; k < location; ++k) {
        p_traverse = p_traverse -> get_next();
    }
    p_traverse -> set_space_location(new_location);
}

void Board::set_board_level(int location, int new_level) {
    Space * p_traverse {p_head};
    for (std::size_t k{0}; k < location; ++k) {
        p_traverse = p_traverse -> get_next();
    }
    p_traverse -> set_space_level(new_level);
}

void Board::set_board_occupied(int location, bool new_occupied) {
    Space * p_traverse{p_head};
    for (std::size_t k{0}; k < location; ++k) {
        p_traverse = p_traverse -> get_next();
    }
    p_traverse -> set_space_occupied(new_occupied);
}

void Board::set_board_worker(int location, int new_worker) {
    Space * p_traverse{p_head};
    for (std::size_t k{0}; k < location; ++k) {
        p_traverse = p_traverse -> get_next();
    }
    p_traverse -> set_space_worker(new_worker);
}

void Board::set_placement() {
    
}

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
        move_location = location_conversion (this -> get_character_location(), relative_location(tmp));
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
        build_location = location_conversion (this -> get_character_location(), relative_location(tmp));
    }

    build_location = location_conversion(this -> get_character_location(), build_location);

    int build_height{};

    build_height = gameboard.get_board_level(build_location) + 1;

    if (build_height == 4) {
        gameboard.set_board_level(build_location, build_height);
        gameboard.set_board_occupied(build_location, true);
        gameboard.set_board_worker(build_location, 7);
    } else {
        gameboard.set_board_level(build_location, build_height);
    }
}