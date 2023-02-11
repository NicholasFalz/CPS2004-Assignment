#include "Quarry.h"

    Quarry::Quarry() {
        name = "Quarry";
        resource_generated = "stone";
        wood_costBuild = 3;
        stone_costBuild = 0;
        iron_costBuild = 3;
        wood_costUpgrade = 3;
        stone_costUpgrade = 0;
        iron_costUpgrade = 3;
    }

    int Quarry::generateStone(int stone) {
        if (level == 0) {
            cout << "No";
        }
        if (level == 1) {
            return stone + 1;
        }
        if (level == 2) {
            return stone + 2;
        }
        if (level == 3) {
            return stone + 4;
        }
        return 0;
    }

