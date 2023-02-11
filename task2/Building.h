#ifndef VILLAGEWARGAME_BUILDING_H
#define VILLAGEWARGAME_BUILDING_H
#include <iostream>

using namespace std;

class Building {
protected:
    string name;
    int level;
    int wood_costBuild;
    int stone_costBuild;
    int iron_costBuild;
    int wood_costUpgrade;
    int stone_costUpgrade;
    int iron_costUpgrade;

public:
    Building();

    int getLevel();

    int getWoodCostBuild();

    int getStoneCostBuild();

    int getIronCostBuild();

    int getWoodCostUpgrade();

    int getStoneCostUpgrade();

    int getIronCostUpgrade();

    void build();

    void upgrade();
};

#endif //VILLAGEWARGAME_BUILDING_H