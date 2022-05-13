#include <iostream>

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

        virtual void move(int move_location);
        virtual void build(int build_location);

    protected:
        int character_location;
        int character_level;
        int character_worker;
};