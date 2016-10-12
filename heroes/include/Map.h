#ifndef MAP_H
#define MAP_H

#include "Cell.h"
#include "Weapon.h"
#include "Chest.h"
#include "Boots.h"
#include "Monster.h"
#include "Hero.h"
#include "Wall.h"
#include "Empty.h"
#include "Battle.h"
#include <vector>
#include <string>
#include <fstream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <algorithm>
#include <math.h>
#include <iostream>

#define MAP_HEIGHT 20
#define MAP_WIDTH 40

class Map
{
private:
    std::vector< std::vector<Cell*> > map;
public:
    Map();
    ~Map();

    void free_map();

    const Cell* get_cell(int x, int y) const;
    void set_cell(Cell* cell, int x, int y);
    void set_raw_cell(Cell* cell, int x, int y);

    int height() const;
    int width() const;
    void swap(std::pair<int, int> a, std::pair<int, int> b);
    // not done
    void save(std::string path);
    void load(std::string path);

    void print() const;
    void generate_map(Hero* hero, std::vector<Monster*> monsters, std::pair<int, int> from_to);
private:

    void randomize_block(int h_from, int h_to, int w_from, int w_to);
    void set_monsters(std::vector< std::pair<int, int> >& used, std::vector<Monster*> monsters, std::pair<int, int> from_to);
    void set_hero(std::vector< std::pair<int, int> >& used, Hero* hero);
private:
    Map(const Map& other);
    Map& operator=(const Map& other);
};

#endif // MAP_H
