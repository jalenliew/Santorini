/*
    Disclaimer:
    I do not own the intellectual property rights to this game
    I am simply recreating this game to test and develop my own coding skills

    If you are interested in buying the actual game, please support them here:
    https://boardgamegeek.com/boardgame/194655/santorini
*/

// g++ -o Santorini -std=c++11

#include <iostream>
#include <cassert>
#include <ctime>

//////////////////// Board Setup Start ////////////////////

// Class Declarations

// This class is used to create objects for each individual space on the board
class Space {
    friend class Action;
    public:
        
        // Constructor
        Space( unsigned int space_location, unsigned int space_level, bool space_occupied, unsigned int space_worker );

        // Destructor
        ~Space();

        // Get Functions
        unsigned int get_location() const;
        unsigned int get_level() const;
        bool get_occupied() const;
        unsigned int get_worker() const;
        Space * get_next();

        // Set Functions
        void set_location( unsigned int new_location );
        void set_level( unsigned int new_level );
        void set_occupied( bool new_occupied );
        void set_worker( unsigned int new_worker );
        void set_next( Space *p_new_next );

        // Print Functions
        void print_location();
        void print_level();
        void print_worker();

    private:

        // Private Variables
        unsigned int location;
        unsigned int level;
        bool occupied;
        unsigned int worker;
        Space * p_next;
                
};

// This class is a linked list to compile the board together
class Board {
    friend class Action;
    public:

        // Constructor
        Board();

        // Destructor
        ~Board();

        // Public Member Functions
        void create_board();
        void insert( Space *p_new_space );

        void print();
        void print_placement_board();

        Space *get_p_head();        

    private:

        Space *p_head;
        Space *p_worker1;
        Space *p_worker2;
        Space *p_worker3;
        Space *p_worker4;
        Space *p_worker5;
        Space *p_worker6;
};

class Action {
    public:

        // Constructor
        Action();

        // Destructor
        ~Action();

        // Turn Order Functions
        int get_turn();
        bool get_valid();
        int get_selected();

        // Action Functions
        void move();
        void build();
        void place();
        void select();

    private:

        // Turn Order Variables
        int turn_order;
        bool valid;
        int selected;
};

// Function Declarations

// Class Definitions

Space::Space(unsigned int space_location, unsigned int space_level, bool space_occupied, unsigned int space_worker) {
    location = space_location;
    level = space_level;
    occupied = space_occupied;
    worker = space_worker;

    p_next = nullptr;
}

Space::~Space () {
    // No dynamically allocated memory
}

unsigned int Space::get_location() const { return location; }
unsigned int Space::get_level() const { return level; }
bool Space::get_occupied() const { return occupied; }
unsigned int Space::get_worker() const { return worker; }
Space *Space::get_next() { return p_next; }

void Space::set_location( unsigned int new_location ) { location = new_location; }
void Space::set_level( unsigned int new_level ) { level = new_level; }
void Space::set_occupied( bool new_occupied ) { occupied = new_occupied; }
void Space::set_worker ( unsigned int new_worker ) { worker = new_worker; }
void Space::set_next ( Space *p_new_next ) { p_next = p_new_next; }

void Space::print_location() {
    std::cout << this -> get_location();
}

void Space::print_level() {
    std::cout << this -> get_level();
}

void Space::print_worker() {
    if (worker == 1) {
        std::cout << "a";
    } else if (worker == 2) {
        std::cout << "A";
    } else if (worker == 3) {
        std::cout << "b";
    } else if (worker == 4) {
        std::cout << "B";
    } else if (worker == 5) {
        std::cout << "c";
    } else if (worker == 6) {
        std::cout << "C";
    } else {
        std::cout << "D";
    }
}

Board::Board() {
    this -> p_head = nullptr;
    this -> p_worker1 = nullptr;
    this -> p_worker2 = nullptr;
    this -> p_worker3 = nullptr;
    this -> p_worker4 = nullptr;
    this -> p_worker5 = nullptr;
    this -> p_worker6 = nullptr;

}

Board::~Board() {

    Space * p_tmp{p_head};

    while (p_tmp != nullptr) {
        Space * p_tmp_old{p_tmp};
        p_tmp = p_tmp -> get_next();
        delete p_tmp_old;
        p_tmp_old = nullptr;
    }

    p_head = nullptr;
    p_tmp = nullptr;
}

void Board::create_board() {
    for (std::size_t i{0}; i < 25; ++i) {
        Space * p_new_space = new Space(i, 0, false, 0);
        Board::insert(p_new_space);
    }
}

void Board::insert( Space *p_new_space ) {

    if (p_head == nullptr) {
        this -> p_head = p_new_space;
    } else {
        Space * p_traverse{p_head};

        while (p_traverse -> get_next() != nullptr) {
            p_traverse = p_traverse -> get_next();
        }

        p_traverse -> set_next(p_new_space);
    }
}

void Board::print() {

    Space * p_traverse{p_head};

    for (std::size_t i{1}; i < 26; ++i) {

        if (p_traverse -> get_occupied()) {
            p_traverse -> print_worker();
        } else {
            p_traverse -> print_level();
        }

        std::cout << "   ";
        if ((i%5) == 0 ) {
            std::cout << std::endl;
        }

        p_traverse = p_traverse -> get_next();
    }

    p_traverse = nullptr;
}

void Board::print_placement_board() {

    Space * p_traverse{p_head};

    for (std::size_t i{1}; i < 26; ++i) {

        if (p_traverse -> get_occupied()) {
            p_traverse -> print_worker();
        } else {
            p_traverse -> print_location();
        }


        if (i < 10) {
            std::cout << "   ";
        } else {
            std::cout << "  ";
        }

        if ((i%5) == 0) {
            std::cout << std::endl;
        }

        p_traverse = p_traverse -> get_next();
    }

    p_traverse = nullptr;
}

Action::Action() {
    turn_order = 0;
    valid = false;
    selected = 0;
}

Action::~Action() {
    // No dynamically allocated memory
}

int Action::get_turn() { return turn_order; }
bool Action::get_valid() { return valid; }
int Action::get_selected() { return selected; }

void Action::move() {

}
void Action::build() {

}
void Action::place() {

}
void Action::select() {

}

// Function Definitions

//////////////////// Board Setup Finish ////////////////////

//////////////////// Main Start ////////////////////

int main();
int main() {

    Board gameboard{};
    gameboard.create_board();
    // gameboard.print();
    gameboard.print_placement_board();

    return 0;
}

//////////////////// Main Finish ////////////////////
