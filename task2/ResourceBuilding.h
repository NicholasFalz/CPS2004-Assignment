#ifndef VILLAGEWARGAME_RESOURCEBUILDING_H
#define VILLAGEWARGAME_RESOURCEBUILDING_H

#include "Building.h"

class ResourceBuilding: public Building {
protected:
    string resource_generated;
public:
    ResourceBuilding();
};

#endif //VILLAGEWARGAME_RESOURCEBUILDING_H