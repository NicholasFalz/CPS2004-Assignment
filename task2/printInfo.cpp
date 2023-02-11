#include "printInfo.h"

void printResourcesInfo(Village village) {
    cout << "Wood: " << village.getResources().wood << endl;
    cout << "Stone: " << village.getResources().stone << endl;
    cout << "Iron: " << village.getResources().iron << endl;
}

void printBuildingsInfo(Village village) {
    cout << "Lumber Mill Level: " << village.getLumberMill().getLevel() << endl;
    cout << "Quarry Level: " << village.getQuarry().getLevel() << endl;
    cout << "Smeltery Level: " << village.getSmeltery().getLevel() << endl;
    cout << "Nord Outpost Level: " << village.getNordOutpost().getLevel() << endl;
    cout << "Archery Range Level: " << village.getArcheryRange().getLevel() << endl;
    cout << "College of Winterhold Level: " << village.getCollegeOfWinterhold().getLevel() << endl;
}

void printTroopsInfo(Village village) {
    cout << "Number of Nords trained: " << village.getNordOutpost().getTrainedTroops() << endl;
    cout << "Number of Khajiit trained: " << village.getNordOutpost().getTrainedTroops() << endl;
    cout << "Number of Bretons trained: " << village.getNordOutpost().getTrainedTroops() << endl;
}