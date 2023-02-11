#ifndef VILLAGEWARGAME_LUMBERMILL_H
#define VILLAGEWARGAME_LUMBERMILL_H

#include "ResourceBuilding.h"

class LumberMill: public ResourceBuilding {

public:
    LumberMill();

    int generateWood(int wood);
};

#endif //VILLAGEWARGAME_LUMBERMILL_H