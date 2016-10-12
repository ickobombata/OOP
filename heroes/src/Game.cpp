#include "Game.h"

Game::Game(std::string path)
    :used_monsters(0), battle(NULL), hero(NULL)
{
    this->level = 0;
    hero = new Hero();
    srand(time(NULL));

    read_map(path);
}

Game::~Game()
{
    for(int i = used_monsters; i < monsters.size(); ++i)
        delete monsters[i];
    if(battle)
        delete battle;
}


bool Game::in_battle() const
{
    return battle;
}
void Game::won_battle()
{
    int hero_x = hero->get_coordinates().first;
    int hero_y = hero->get_coordinates().second;
    std::pair<int, int> m_coords = battle->get_monster_coordinates();

    map.set_cell(new Empty(), m_coords.first, m_coords.second);
    map.swap(m_coords, std::pair<int, int>(hero_x, hero_y));

    hero->set_coordinates(m_coords.first, m_coords.second);
    delete battle;
    battle = NULL;
    alive_monsters--;
}
const Map* Game::get_map() const
{
    return &map;
}

void Game::move_hero(std::pair<int, int> dir)
{
    int hero_x = hero->get_coordinates().first;
    int hero_y = hero->get_coordinates().second;
    int new_x = dir.first + hero_x;
    int new_y = dir.second + hero_y;

    if(dynamic_cast<const Empty*>(map.get_cell(new_x, new_y)))
    {
        map.swap(std::pair<int, int>(new_x, new_y), std::pair<int, int>(hero_x, hero_y));
        hero->set_coordinates(new_x, new_y);
    }
    else if(dynamic_cast<const Monster*>(map.get_cell(new_x, new_y)))
    {
        battle = new Battle(hero, (Monster*)map.get_cell(new_x, new_y), std::pair<int, int>(new_x, new_y));
    }
}

void Game::read_monsters(std::ifstream* input)
{
    std::string line;

    while(input->good())
    {
        std::getline(*input, line);
        if(line.length() > 1)
            monsters.push_back(generate_monster(line));
        else
            break;
    }
    alive_monsters = monsters.size();
}

void Game::read_items(std::ifstream* input)
{
    std::string line;

    while(input->good())
    {
        std::getline(*input, line);

        if(line.length() > 0)
            items.push_back(generate_item(line));
        else
            break;
    }

}

void Game::generate()
{
    int length = monsters.size();
    int bound = std::min(used_monsters + NUMBER_MONSTERS, length);

    map.generate_map(hero, monsters, std::pair<int, int>(used_monsters, bound));

    alive_monsters = bound - used_monsters;
    used_monsters += bound - used_monsters;
}

void Game::update()
{
    if(alive_monsters == 0)
    {
        map.set_raw_cell(new Empty(), hero->get_coordinates().first, hero->get_coordinates().second);
        map.free_map();
        generate();
    }
}

void Game::read_map(std::string path)
{
    std::ifstream input;
    input.open((path + "items").c_str());
    if(input)
        read_items(&input);
    else
        throw 42;
    input.close();

    input.open((path + "monsters").c_str());
    if(input)
        read_monsters(&input);
    else
        throw 42;
    input.close();

    generate();
}

Monster* Game::generate_monster(std::string name) const
{
    Monster* mon = new Monster();

    return mon;
}

Item Game::generate_item(std::string name) const
{
    Item item;

    return item;
}
