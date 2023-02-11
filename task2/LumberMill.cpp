#include "LumberMill.h"

    LumberMill::LumberMill() {
        name = "Lumber Mill";
        resource_generated = "wood";
        wood_costBuild = 1;
        stone_costBuild = 2;
        iron_costBuild = 1;
        wood_costUpgrade = 1;
        stone_costUpgrade = 2;
        iron_costUpgrade = 1;
    }

    int LumberMill::generateWood(int wood) {
        if (level == 0) {
            cout << "No";
        }
        if (level == 1) {
            return wood + 1;
        }
        if (level == 2) {
            return wood + 2;
        }
        if (level == 3) {
            return wood + 4;
        }
        return 0;
    }