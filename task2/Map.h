#ifndef VILLAGEWARGAME_MAP_H
#define VILLAGEWARGAME_MAP_H
#include <iostream>

#include "Village.h"

using namespace std;

class Map {
    int r;
    int c;
    string **cells;

public:

    Map(int r, int c);

    string **generateMap(int r, int c);

    void printMap();

    void updateMap(Map, int index, pair<int, int> location);

    void generateVillageLocations(int playernum, int i, int r, int c, Village villages[playernum]);

};

#endif //VILLAGEWARGAME_MAP_H
