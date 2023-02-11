#ifndef VILLAGEWARGAME_TROOPBUILDING_H
#define VILLAGEWARGAME_TROOPBUILDING_H

#include "iostream"
#include "Building.h"

using namespace std;

class TroopBuilding: public Building {
protected:
    string troop_type_generated;
    int troops_trained;
public:
    TroopBuilding();

    int getTrainedTroops();

    string getTroopTypeTrained();

    void trainTroops();
};

#endif //VILLAGEWARGAME_TROOPBUILDING_H
