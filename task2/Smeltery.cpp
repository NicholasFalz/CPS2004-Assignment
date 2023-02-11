#include "Smeltery.h"

    Smeltery::Smeltery() {
        name = "Smeltery";
        resource_generated = "iron";
        wood_costBuild = 3;
        stone_costBuild = 4;
        iron_costBuild = 0;
        wood_costUpgrade = 3;
        stone_costUpgrade = 4;
        iron_costUpgrade = 0;
    }

    int Smeltery::generateIron(int iron) {
        if (level == 0) {
            cout << "No";
        }
        if (level == 1) {
            return iron + 1;
        }
        if (level == 2) {
            return iron + 2;
        }
        if (level == 3) {
            return iron + 4;
        }
        return 0;
    }