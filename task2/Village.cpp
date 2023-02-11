#include "Village.h"

    Village::Village() {
        owner = 0;
        health = 100;
        playing = true;
        resources = Resources();
        lumberMill = LumberMill();
        quarry = Quarry();
        smeltery = Smeltery();
        nordOutpost = NordOutpost();
        archeryRange = ArcheryRange();
        collegeOfWinterhold = CollegeOfWinterhold();
        nord = Nord();
        khajiit = Khajiit();
        breton = Breton();
    }

    void Village::setOwner(int i) {
        owner = i;
    }

    int Village::getOwner() {
        return owner;
    }

    pair<int,int>& Village::getLocation() {
        return location;
    }

    bool Village::getPlaying() {
        return playing;
    }

    void Village::destroyVillage() {
        playing = false;
    }

    Resources& Village::getResources() {
        return resources;
    }

    LumberMill& Village::getLumberMill() {
        return lumberMill;
    }
    Quarry& Village::getQuarry() {
        return quarry;
    }
    Smeltery& Village::getSmeltery() {
        return smeltery;
    }
    NordOutpost& Village::getNordOutpost() {
        return nordOutpost;
    }
    ArcheryRange& Village::getArcheryRange() {
        return archeryRange;
    }
    CollegeOfWinterhold& Village::getCollegeOfWinterhold() {
        return collegeOfWinterhold;
    }

    Nord& Village::getNords() {
        return nord;
    }
    Khajiit& Village::getKhajiit() {
        return khajiit;
    }
    Breton& Village::getBretons() {
        return breton;
    }

    void Village::printValues() {
        cout << owner << endl;
        cout << location.first;
        cout << location.second << endl;
        cout << health << endl;
        cout << endl;
    }
