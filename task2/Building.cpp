#include "Building.h"

    Building::Building() {
        level = 0;
    }

    int Building::getLevel() {
        return level;
    }

    int Building::getWoodCostBuild() {
        return wood_costBuild;
    }
    int Building::getStoneCostBuild() {
        return stone_costBuild;
    }
    int Building::getIronCostBuild() {
        return iron_costBuild;
    }
    int Building::getWoodCostUpgrade() {
        return wood_costUpgrade;
    }
    int Building::getStoneCostUpgrade() {
        return stone_costUpgrade;
    }
    int Building::getIronCostUpgrade() {
        return iron_costUpgrade;
    }

    void Building::build() {
        level = 1;
    }

    void Building::upgrade() {
        level++;
    }
