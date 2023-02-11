#ifndef VILLAGEWARGAME_TROOPS_H
#define VILLAGEWARGAME_TROOPS_H

#include <iostream>

using namespace std;

class Troops{
protected:
    string name;
    string description;
    int wood_cost;
    int stone_cost;
    int iron_cost;
    int health;
    int attackdamage;
    int carryingcapacity;
    int marchingspeed;

public:
    void attack();

    void defend();

    int getWoodCost();

    int getStonecost();

    int getIronCost();
};

#endif //VILLAGEWARGAME_TROOPS_H