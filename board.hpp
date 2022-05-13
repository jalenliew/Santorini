#include <iostream>

class Space {
    public:
        Space(int location_id, int level_id, bool occupied_id, int worker_id);
        ~Space();

        int get_space_location() const;
        int get_space_level() const;
        bool get_space_occupied() const;
        int get_space_worker() const;
        Space * get_next();

        void set_space_location(int new_location);
        void set_space_level(int new_level);
        void set_space_occupied(bool new_occupied);
        void set_space_worker(int new_worker);
        void set_next(Space * p_new_next);

        void print() const;
    
    private:
        int space_location;
        int space_level;
        bool space_occupied;
        int space_worker;
        Space * p_next;

};

class Board {
    public:
        Board();
        ~Board();

        void insert_space(Space * p_new_space);
        void create_board();
        void print_board();
        void reset_board();
        void print_placement_board();

        int get_board_location(int location) const;
        int get_board_level(int location) const;
        bool get_board_occupied(int location) const;
        int get_board_worker(int location) const;

        void set_board_location(int location, int new_location);
        void set_board_level(int location, int new_level);
        void set_board_occupied(int location, bool new_occupied);
        void set_board_worker(int location, int new_worker);
        void set_placement();

    private:
        Space *p_head;

};

class Characters {
    public:
        Characters();
        Characters(int location_id, int level_id, int worker_id);
        virtual ~Characters();

        virtual int get_character_location() const;
        virtual int get_character_level() const;
        virtual int get_character_worker() const;

        virtual void set_character_location(int new_location);
        virtual void set_character_level(int new_level);
        virtual void set_character_worker(int new_worker);

        virtual void move(int move_location, Board gameboard);
        virtual void build(int build_location, Board gameboard);

    protected:
        int character_location;
        int character_level;
        int character_worker;
};