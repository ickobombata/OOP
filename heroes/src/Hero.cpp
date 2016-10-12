#include "Hero.h"

Hero::Hero()
{
    //ctor
}

Hero::~Hero()
{
    //dtor
}


void Hero::set_coordinates(int x, int y)
{
    this->coords = std::pair<int, int>(x, y);
}

std::pair<int, int> Hero::get_coordinates() const
{
    return this->coords;
}

std::pair<int, int> Hero::move(std::pair<int, int> dir)
{
    this->coords = std::pair<int, int>(dir.first + coords.first, dir.second + coords.second);
    return coords;
}

void Hero::print() const
{
    std::cout << 'X';
}
