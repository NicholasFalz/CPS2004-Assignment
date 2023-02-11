#ifndef VILLAGEWARGAME_QUARRY_H
#define VILLAGEWARGAME_QUARRY_H

#include "ResourceBuilding.h"

class Quarry: public ResourceBuilding {

public:
    Quarry();

    int generateStone(int stone);
};

#endif //VILLAGEWARGAME_QUARRY_H