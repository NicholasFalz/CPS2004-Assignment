#include "TroopBuilding.h"

    TroopBuilding::TroopBuilding() {
        troops_trained = 0;
    }

    int TroopBuilding::getTrainedTroops() {
        return troops_trained;
    }

    string TroopBuilding::getTroopTypeTrained() {
        return troop_type_generated;
    }

    void TroopBuilding::trainTroops() {
        troops_trained++;
    }