#ifndef GAME_H
#define GAME_H

#include "Map.h"

#define NUMBER_MONSTERS 4

class Game
{
private:
    int level;
    Map map;
    Hero* hero;
    Battle* battle;
    std::vector<Item> items;
    std::vector<Monster*> monsters;
    int used_monsters;
    int alive_monsters;
public:
    Game(std::string path);
    ~Game();

    Battle* get_battle() { return battle; }

    bool is_hero_alive() const { return hero->get_health() != 0; }
    bool in_battle() const;
    void won_battle();
    bool is_over() const { if(in_battle()) return battle->is_over(); else return false;}
    const Map* get_map() const;

    void move_hero(std::pair<int, int> dir);
    void update();
private:
    void read_map(std::string path);
    void read_monsters(std::ifstream* input);
    void read_items(std::ifstream* input);

    void generate();

    Monster* generate_monster(std::string name) const;
    Item generate_item(std::string name) const;
};

#endif // GAME_H
