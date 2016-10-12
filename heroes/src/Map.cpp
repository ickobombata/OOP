#include "Map.h"

Map::Map()
    : map(MAP_HEIGHT, std::vector<Cell*>(MAP_WIDTH))
{
}

Map::~Map()
{
    free_map();
}

void Map::free_map()
{
    for(int i = 0 ; i < map.capacity(); ++i)
        for(int j = 0; j < map[0].capacity(); ++j)
        {
            delete map[i][j];
            map[i][j] = NULL;
        }
}
void Map::swap(std::pair<int, int> a, std::pair<int, int> b)
{
    std::swap(map[a.first][a.second], map[b.first][b.second]);
}
const Cell* Map::get_cell(int x, int y) const
{
    return this->map[x][y];
}
void Map::set_cell(Cell* cell, int x, int y)
{
    //check if the cell is okay to be copied
    if(this->map[x][y] != NULL)
        delete map[x][y];
    this->map[x][y] = cell;// need factory
}
void Map::set_raw_cell(Cell* cell, int x, int y)
{
    this->map[x][y] = cell;
}
int Map::height() const
{
    return map.capacity();
}
int Map::width() const
{
    return map[0].capacity();
}

void Map::randomize_block(int h_from, int h_to, int w_from, int w_to)
{
    for(int i = h_from; i < h_to; ++i)
    {
        for(int j = w_from; j < w_to; ++j)
        {
            if(this->map[i][j])
                continue;
            if(rand() % 2 == 1) // 50%
                this->map[i][j] = new Wall();
            else
                this->map[i][j] = new Empty();
        }
    }
}

void Map::set_hero(std::vector< std::pair<int, int> >& used, Hero* hero)
{
    hero->set_coordinates(rand() % (map.capacity() - 2) + 1 , rand() % (map[0].capacity() - 2) + 1);

    map[hero->get_coordinates().first][hero->get_coordinates().second] = hero;

    used.push_back(hero->get_coordinates());
}

void Map::set_monsters(std::vector< std::pair<int, int> >& used, std::vector<Monster*> monsters, std::pair<int, int> from_to)
{
    std::pair<int ,int> m_coords;

    for(int i = from_to.first; i < from_to.second; ++i)
    {
        while(true)
        {
            m_coords = std::pair<int, int>( rand() % (map.capacity() - 2) + 1,
                                            rand() % (map[0].capacity() - 2) + 1);
            for(int j = 0; j < used.size(); ++j)
            {
                int first = m_coords.first - used[j].first;
                int second = m_coords.second - used[j].second;
                if(first*first + second*second < 2)
                    continue;
            }
            used.push_back(m_coords);
            break;
        }
        map[m_coords.first][m_coords.second] = monsters[i];
    }
}

void Map::generate_map(Hero* hero, std::vector<Monster*> monsters, std::pair<int, int> from_to)
{
    free_map();

    std::vector< std::pair<int, int> > used;

    set_hero(used, hero);

    set_monsters(used, monsters, from_to);

    int x,y;
    for(int i = 0 ; i < 30; ++i)
    {
        x = rand() % (map.capacity() - 2) + 1;
        y = rand() % (map[0].capacity() - 2) + 1;

        if(!map[x][y])
            map[x][y] = new Wall();
    }

    for(int i = 0 ; i < map.capacity(); ++i)
    {
        map[i][0] = new Wall();
        map[i][map[0].capacity() - 1] = new Wall();
    }
    for(int i = 0 ; i < map[0].capacity(); ++i)
    {
        map[0][i] = new Wall();
        map[map.capacity()-1][i] = new Wall();
    }
    for(int i = 1 ; i < map.capacity()-1; ++i)
        for(int j = 1; j < map[0].capacity()-1; ++j)
            if(!map[i][j])
                map[i][j] = new Empty();
}


void Map::print() const
{
    for(int i = 0 ; i < map.capacity(); ++i)
    {
        for(int j = 0; j < map[0].capacity(); ++j)
            map[i][j]->print();
        std::cout << std::endl;
    }
}
