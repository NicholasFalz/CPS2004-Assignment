#include <iostream>
#include <ctime>
#include <algorithm>

#include "Map.h"
#include "Village.h"
#include "UserChoiceMenus.h"
#include "printInfo.h"

using namespace std;

int main() {
    srand (time(NULL));

    int playernum = getNumberofPlayers();
    int ainum = getNumberofAI(playernum);

    int r; // number of rows in the map
    int c; // number of columns in the map

    if (playernum < 4) {
        r = 5;
        c = 5;
    }
    else if (playernum < 7){
        r = 8;
        c = 8;
    }
    else {
        r = 10;
        c = 10;
    }

    Map map(r,c);

    Village villages[playernum];

    for (int i = 0; i < playernum; ++i) {
        map.generateVillageLocations(playernum, i, r, c, villages);
    }

    for (int i=0; i<playernum; i++) {
        map.updateMap(map,i,villages[i].getLocation());
    }

    cout << "\nGAME MAP: \n\n";

    map.printMap();

    for (int i = 0; i < playernum; i++) {
        villages[i].setOwner(i+1);
    }

    int build_or_upgrade_option;
    int build_option;
    int upgrade_option;
    int train_option;
    string attack_option;
    pair<int,int> army_option;
    char finished_option = false;
    bool finished = false;
    int stillplaying = 0;

    bool playing = true;
    int option;

    // Game Loop:
    int i = 0;
    while (playing) {
        cout << "\nROUND " << i+1 << endl;

        // Friendly Troop Arrival

        // Enemy Troop Arrival

        // Resource Earning
        for (i = 0; i < playernum; i++) {
            if (villages[i].getLumberMill().getLevel() > 0) {
                villages[i].getResources().wood = villages[i].getLumberMill().generateWood(villages[i].getResources().wood);
            }
            if (villages[i].getQuarry().getLevel() > 0) {
                villages[i].getResources().stone = villages[i].getQuarry().generateStone(villages[i].getResources().stone);
            }
            if (villages[i].getSmeltery().getLevel() > 0) {
                villages[i].getResources().iron = villages[i].getSmeltery().generateIron(villages[i].getResources().iron);
            }
        }

        // Player Actions
        i = 0;
        while(i < playernum) {
            option = choose_option(i);

            switch (option) {
                case 1:
                    build_or_upgrade_option = buildOrUpgrade();

                    switch (build_or_upgrade_option) {
                        case 1:
                            build_option = choose_build();

                            switch(build_option) {
                                case 1: {
                                    if (villages[i].getResources().wood < 2) {
                                        cout << "Insufficient resources available\n";
                                    } else if (villages[i].getLumberMill().getLevel() != 0) {
                                        cout << "You have already built a Lumber Mill\n";
                                    } else {
                                        villages[i].getLumberMill().build();
                                        cout << "Lumber Mill Built\n";
                                        villages[i].getResources().wood -= villages->getLumberMill().getWoodCostBuild();
                                        villages[i].getResources().stone -= villages->getLumberMill().getStoneCostBuild();
                                        villages[i].getResources().iron -= villages->getLumberMill().getIronCostBuild();
                                    }
                                }
                                    break;
                                case 2: {
                                    if (villages[i].getResources().stone < 2) {
                                        cout << "Insufficient resources available\n";
                                    } else if (villages[i].getQuarry().getLevel() != 0) {
                                        cout << "You have already built a Quarry\n";
                                    } else {
                                        villages[i].getQuarry().build();
                                        cout << "Quarry Built\n";
                                        villages[i].getResources().wood -= villages->getQuarry().getWoodCostBuild();
                                        villages[i].getResources().stone -= villages->getQuarry().getStoneCostBuild();
                                        villages[i].getResources().iron -= villages->getQuarry().getIronCostBuild();
                                    }
                                }
                                    break;
                                case 3: {
                                    if (villages[i].getResources().iron < 2) {
                                        cout << "Insufficient resources available\n";
                                    } else if (villages[i].getSmeltery().getLevel() != 0) {
                                        cout << "You have already built a Smeltery\n";
                                    } else {
                                        villages[i].getSmeltery().build();
                                        cout << "Smeltery Built\n";
                                        villages[i].getResources().wood -= villages->getSmeltery().getWoodCostBuild();
                                        villages[i].getResources().stone -= villages->getSmeltery().getStoneCostBuild();
                                        villages[i].getResources().iron -= villages->getSmeltery().getIronCostBuild();
                                    }
                                }
                                    break;
                                case 4: {
                                    if (villages[i].getResources().wood < 1 || villages[i].getResources().iron < 1) {
                                        cout << "Insufficient resources available\n";
                                    } else if (villages[i].getNordOutpost().getLevel() != 0) {
                                        cout << "You have already built a Nord Outpost\n";
                                    } else {
                                        villages[i].getNordOutpost().build();
                                        cout << "Nord Outpost Built\n";
                                        villages[i].getResources().wood -= villages->getNordOutpost().getWoodCostBuild();
                                        villages[i].getResources().stone -= villages->getNordOutpost().getStoneCostBuild();
                                        villages[i].getResources().iron -= villages->getNordOutpost().getIronCostBuild();
                                    }
                                }
                                    break;
                                case 5: {
                                    if (villages[i].getResources().wood < 1 || villages[i].getResources().stone < 2) {
                                        cout << "Insufficient resources available\n";
                                    } else if (villages[i].getArcheryRange().getLevel() != 0) {
                                        cout << "You have already built an Archery Range\n";
                                    } else {
                                        villages[i].getArcheryRange().build();
                                        cout << "Archery Range Built\n";
                                        villages[i].getResources().wood -= villages->getArcheryRange().getWoodCostBuild();
                                        villages[i].getResources().stone -= villages->getArcheryRange().getStoneCostBuild();
                                        villages[i].getResources().iron -= villages->getArcheryRange().getIronCostBuild();
                                    }
                                }
                                    break;
                                case 6: {
                                    if (villages[i].getResources().wood < 2 || villages[i].getResources().stone < 4 ||
                                        villages[i].getResources().iron < 2) {
                                        cout << "Insufficient resources available\n";
                                    } else if (villages[i].getCollegeOfWinterhold().getLevel() != 0) {
                                        cout << "You have already built the College of Winterhold\n";
                                    } else {
                                        villages[i].getCollegeOfWinterhold().build();
                                        cout << "College of Winterhold Built\n";
                                        villages[i].getResources().wood -= villages->getCollegeOfWinterhold().getWoodCostBuild();
                                        villages[i].getResources().stone -= villages->getCollegeOfWinterhold().getStoneCostBuild();
                                        villages[i].getResources().iron -= villages->getCollegeOfWinterhold().getIronCostBuild();
                                    }
                                }
                                    break;
                                default:
                                    cout << "Invalid\n\n";
                                    break;
                            }
                            i++;
                            break;
                        case 2:
                            upgrade_option = choose_upgrade(villages[i]);

                            switch (upgrade_option) {
                                case 1: {
                                    if (villages[i].getLumberMill().getLevel() == 0) {
                                        cout << "Invalid input\n";
                                    }
                                    else if (villages[i].getResources().wood < 2) {
                                        cout << "Insufficient resources available\n";
                                    }
                                    else {
                                        villages[i].getLumberMill().upgrade();
                                    }
                                }
                                    break;
                                case 2: {
                                    if (villages[i].getQuarry().getLevel() == 0) {
                                        cout << "Invalid input\n";
                                    }
                                    else if (villages[i].getResources().stone < 2) {
                                        cout << "Insufficient resources available\n";
                                    }
                                    else {
                                        villages[i].getQuarry().upgrade();
                                    }
                                }
                                    break;
                                case 3: {
                                    if (villages[i].getSmeltery().getLevel() == 0) {
                                        cout << "Invalid input\n";
                                    }
                                    else if (villages[i].getResources().iron < 2) {
                                        cout << "Insufficient resources available\n";
                                    }
                                    else {
                                        villages[i].getSmeltery().upgrade();
                                    }
                                }
                                    break;
                                case 4: {
                                    if (villages[i].getNordOutpost().getLevel() == 0) {
                                        cout << "Invalid input\n";
                                    }
                                    else if (villages[i].getResources().wood < 1 || villages[i].getResources().iron < 1) {
                                        cout << "Insufficient resources available\n";
                                    }
                                    else {
                                        villages[i].getNordOutpost().upgrade();
                                    }
                                }
                                    break;
                                case 5: {
                                    if (villages[i].getArcheryRange().getLevel() == 0) {
                                        cout << "Invalid input\n";
                                    }
                                    else if (villages[i].getResources().wood < 1 || villages[i].getResources().stone < 2) {
                                        cout << "Insufficient resources available\n";
                                    }
                                    else {
                                        villages[i].getArcheryRange().upgrade();
                                    }
                                }
                                    break;
                                case 6: {
                                    if (villages[i].getCollegeOfWinterhold().getLevel() == 0) {
                                        cout << "Invalid input\n";
                                    }
                                    else if (villages[i].getResources().wood < 1 || villages[i].getResources().stone < 4 || villages[i].getResources().iron < 2) {
                                        cout << "Insufficient resources available\n";
                                    }
                                    else {
                                        villages[i].getCollegeOfWinterhold().upgrade();
                                    }
                                }
                                    break;
                                default:
                                    cout << "Invalid\n\n";
                            }
                            i++;
                            break;
                        default:
                            cout << "Invalid";
                            break;
                    }
                    break;
                case 2:
                    train_option = choose_train(villages[i], i);

                    switch (train_option) {
                        case 1: {
                            villages[i].getNordOutpost().trainTroops();
                            cout << "A Nord has been trained\n";
                            villages[i].getResources().wood -= villages->getNords().getWoodCost();
                            villages[i].getResources().stone -= villages->getNords().getStonecost();
                            villages[i].getResources().iron -= villages->getNords().getIronCost();
                        }
                        break;
                        case 2: {
                            villages[i].getArcheryRange().trainTroops();
                            cout << "A Khajiit has been trained\n";
                            villages[i].getResources().wood -= villages->getKhajiit().getWoodCost();
                            villages[i].getResources().stone -= villages->getKhajiit().getStonecost();
                            villages[i].getResources().iron -= villages->getKhajiit().getIronCost();
                        }
                        break;
                        case 3: {
                            villages[i].getCollegeOfWinterhold().trainTroops();
                            cout << "A Breton has been trained\n";
                            villages[i].getResources().wood -= villages->getBretons().getWoodCost();
                            villages[i].getResources().stone -= villages->getBretons().getStonecost();
                            villages[i].getResources().iron -= villages->getBretons().getIronCost();
                        }
                        break;
                        default:
                            cout << "Invalid\n";
                            break;
                    }
                    i++;
                    break;
                case 3:
                    attack_option = choose_attack(playernum, i, villages);
                    finished = false;

                    while (!finished) {
                        army_option = choose_army(villages[i]);

                        cout << "Do you wish to send any more troops? (Y/N)\n";
                        cin >> finished_option;

                        if (finished_option == 'Y') {
                            continue;
                        }
                        else if (finished_option == 'N') {
                            finished = true;
                        }
                        else cout << "Invalid input\n";
                    }
                    i++;
                    break;
                case 4:
                    cout << "Player " << i+1 << " Passed\n";
                    i++;
                    continue;
                case 5:
                    villages[i].destroyVillage();
                    cout << "Village Destroyed\n";
                    i++;
                    break;
                case 6:
                    printResourcesInfo(villages[i]);
                    break;
                case 7:
                    printBuildingsInfo(villages[i]);
                    break;
                case 8:
                    printTroopsInfo(villages[i]);
                    break;
                default:
                    cout << "Invalid\n\n";
            }
        }
        stillplaying = 0;
        for (int j = 0; j < playernum; j++) {
            if (villages[j].getPlaying()) {
                stillplaying++;
            }
        }
        if (stillplaying == 1) {
            for (int j = 0; j < playernum; j++) {
                if (villages[j].getPlaying()) {
                    cout << "Player " << j+1 << " has won the game!\n";
                    playing = false;
                }
            }
        }
    }

    return 0;
}