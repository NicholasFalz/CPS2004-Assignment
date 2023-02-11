#ifndef VILLAGEWARGAME_VILLAGE_H
#define VILLAGEWARGAME_VILLAGE_H

#include "Resources.h"
#include "LumberMill.h"
#include "Quarry.h"
#include "Smeltery.h"
#include "NordOutpost.h"
#include "ArcheryRange.h"
#include "CollegeOfWinterhold.h"
#include "Nord.h"
#include "Khajiit.h"
#include "Breton.h"

class Village{
    int owner;
    int health;
    bool playing;
    // Resources:
    Resources resources;
    // Buildings:
    LumberMill lumberMill;
    Quarry quarry;
    Smeltery smeltery;
    NordOutpost nordOutpost;
    ArcheryRange archeryRange;
    CollegeOfWinterhold collegeOfWinterhold;
    // Troops:
    Nord nord;
    Khajiit khajiit;
    Breton breton;
public:
    pair<int,int> location;
    Village();

    void setOwner(int i);

    int getOwner();

    pair<int,int>& getLocation();

    bool getPlaying();

    void destroyVillage();

    Resources& getResources();

    LumberMill& getLumberMill();
    Quarry& getQuarry();
    Smeltery& getSmeltery();
    NordOutpost& getNordOutpost();
    ArcheryRange& getArcheryRange();
    CollegeOfWinterhold& getCollegeOfWinterhold();

    Nord& getNords();
    Khajiit& getKhajiit();
    Breton& getBretons();

    void printValues();
};

#endif //VILLAGEWARGAME_VILLAGE_H