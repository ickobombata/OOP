#ifndef CHARACTER_H
#define CHARACTER_H

#include <Cell.h>
#include <string>

struct Directions
{
    std::pair<int, int> left;
    std::pair<int, int> right;
    std::pair<int, int> up;
    std::pair<int, int> down;

    Directions(): left(0, -1), right(0, 1), up(-1, 0), down(1, 0) {}
};

class Character : public Cell
{
private:
    static const Directions DIRECTION;
    std::string name;
    int health;
    int mana;
    int damage;
    int speed;
    int resistance;
    int armor;
public:
    Character();
    virtual ~Character();

    std::string get_name() const { return this->name; }
    int get_health() const;
    int get_mana() const;
    int get_damage() const;
    int get_armor() const;
    int get_speed() const;
    int get_resistance() const;

    void set_health(int x);
    void set_mana(int x);
    void set_damage(int x);
    void set_speed(int x);
    void set_resistance(int x);
    void set_armor(int x);

    bool is_alive() const { return get_health() != 0;}

    void autoattack(const Character* attacker);

};

#endif // CHARACTER_H
