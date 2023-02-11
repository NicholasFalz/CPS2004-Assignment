#ifndef VILLAGEWARGAME_SMELTERY_H
#define VILLAGEWARGAME_SMELTERY_H

#include "ResourceBuilding.h"

class Smeltery: public ResourceBuilding {

public:
    Smeltery();

    int generateIron(int iron);
};

#endif //VILLAGEWARGAME_SMELTERY_H