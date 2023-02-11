#include "UserChoiceMenus.h"

int getNumberofPlayers() {
    int playernum = 0;

    while (playernum < 1 || playernum > 9) {
        cout << "How many players will be playing? (max 9)\n";
        cin >> playernum;
        if (playernum < 1 || playernum > 9) cout << "Invalid input\n";
    }
    return playernum;
}

int getNumberofAI(int playernum) {
    int ainum = 0;

    while (ainum < 0 || ainum > (9 - playernum)) {
        if (playernum == 9) {
            ainum = 0;
            break;
        }
        cout << "How many AI players would you like to have playing?\n";
        cin >> ainum;
        if (ainum < 0) cout << "Invalid input\n";
        if (ainum > (9 - playernum)) cout << "Maximum number of players exceeded\n";
    }
    return ainum;
}

int choose_option(int i) {
    int option;

    cout << "\nPlayer "<< i+1 <<"'s Turn\n\n";
    cout << "Select an option (Input a number):\n";
    cout << "1. Build/Upgrade Buildings\n";
    cout << "2. Train Troops\n";
    cout << "3. Attack a Village\n";
    cout << "4. Pass Turn\n";
    cout << "5. Surrender (Die)\n";
    cout << "6. Resources Info\n";
    cout << "7. Buildings Info\n";
    cout << "8. Troops Info\n";

    cin >> option;

    return option;
}

int buildOrUpgrade() {
    int build_or_upgrade_option = 0;

    while (build_or_upgrade_option < 1 || build_or_upgrade_option > 3) {
        cout << "What would you like to do?\n";
        cout << "1. Build\n";
        cout << "2. Upgrade\n";
        cin >> build_or_upgrade_option;

        if (build_or_upgrade_option < 1 || build_or_upgrade_option > 3) cout << "Invalid\n\n";
    }

    return build_or_upgrade_option;
}

int choose_build() {
    int build_option = 0;

    do {
        cout << "Which would you like to build?\n\n";
        cout << "1. Lumber Mill - Generates Wood (Cost: 2 Wood)\n";
        cout << "2. Quarry - Generates Stone (Cost: 2 Stone)\n";
        cout << "3. Smeltery - Generates Iron (Cost: 2 Iron)\n";
        cout << "4. Nord Outpost - Trains Nords (Cost: 1 Wood and 1 Iron)\n";
        cout << "5. Archery Range - Trains Khajiit (Cost: 1 Wood and 2 Stone)\n";
        cout << "6. College of Winterhold - Trains Bretons (Cost: 1 Wood, 4 Stone and 2 Iron)\n";

        cin >> build_option;

        if (build_option < 1 || build_option > 6) cout << "Invalid input\n\n";

    } while(build_option < 1 || build_option > 6);
    return build_option;
}

int choose_upgrade(Village village) {
    int upgrade_option = 0;
    bool accepted = false;

    if (village.getLumberMill().getLevel() == 0 && village.getQuarry().getLevel() == 0 && village.getSmeltery().getLevel() == 0 && village.getNordOutpost().getLevel() == 0 && village.getArcheryRange().getLevel() == 0 && village.getCollegeOfWinterhold().getLevel() == 0) {
        cout << "You have not built any Buildings yet!\n";
    }
    else {
        cout << "Which of your buildings would you like to upgrade?\n\n";
        if (village.getLumberMill().getLevel() > 0) {
            cout << "1. Lumber Mill\n";
        }
        if (village.getQuarry().getLevel() > 0) {
            cout << "2. Quarry\n";
        }
        if (village.getSmeltery().getLevel() > 0) {
            cout << "3. Smeltery\n";
        }
        if (village.getNordOutpost().getLevel() > 0) {
            cout << "4. Nord Outpost\n";
        }
        if (village.getArcheryRange().getLevel() > 0) {
            cout << "5. Archery Range\n";
        }
        if (village.getCollegeOfWinterhold().getLevel() > 0) {
            cout << "6. College of Winterhold\n";
        }

        cin >> upgrade_option;
    }
    return upgrade_option;
}

int choose_train(Village village, int i) {
    int train_option = 0;
    bool accepted = true;

    if (village.getNordOutpost().getLevel() == 0 && village.getArcheryRange().getLevel() == 0 && village.getCollegeOfWinterhold().getLevel() == 0) {
        cout << "You have not built any troop-training buildings yet!\n";
    }

    else {
        cout << "Which troop would you like to train?\n\n";
        if (village.getNordOutpost().getLevel() > 0) {
            cout << "1. Nord\n";
        }
        if (village.getArcheryRange().getLevel() > 0) {
            cout << "2. Khajiit\n";
        }
        if (village.getCollegeOfWinterhold().getLevel() > 0) {
            cout << "3. Breton\n";
        }

        cin >> train_option;

        if (train_option == 1) {
            if (village.getResources().wood < 1 || village.getResources().iron < 1) {
                cout << "Insufficient resources available";
                accepted = false;
            }
        }
        if (train_option == 2) {
            if (village.getResources().wood < 1 || village.getResources().stone < 2) {
                cout << "Insufficient resources available";
                accepted = false;
            }
        }
        if (train_option == 3) {
            if (village.getResources().wood < 1 || village.getResources().stone < 4 || village.getResources().iron < 2) {
                cout << "Insufficient resources available";
                accepted = false;
            }
        }
    }
    return train_option;
}

string choose_attack(int playernum, int i, Village villages[playernum]) {
    string attack_option;

    cout << "Which village would you like to attack?\n";
    for (int j = 0; j < playernum; ++j) {
        if (villages[j].getPlaying() && villages[j].getOwner() != villages[i].getOwner()) {
            cout << "V" << j+1 << endl;
        }
    }
    cin >> attack_option;

    return attack_option;
}

pair <int,int> choose_army(Village village) {
    int troop_option = 0;
    int number_option = 0;
    int army_option = 0;
    char finished_option;
    bool accept = false;
    bool finished = false;
    pair <int,int> options;

    if (village.getNordOutpost().getTrainedTroops() == 0 && village.getArcheryRange().getTrainedTroops() == 0 && village.getCollegeOfWinterhold().getTrainedTroops() == 0) {
        cout << "You have not trained any troops yet!\n";
        accept = true;
    }
    else {
        do {
            cout << "Which troops would you like to send?\n";
            cout << village.getNordOutpost().getTroopTypeTrained() << " (You have " << village.getNordOutpost().getTrainedTroops() << " Trained)\n";
            cout << village.getArcheryRange().getTroopTypeTrained() << " (You have " << village.getArcheryRange().getTrainedTroops() << " Trained)\n";
            cout << village.getCollegeOfWinterhold().getTroopTypeTrained() << " (You have " << village.getCollegeOfWinterhold().getTrainedTroops() << " Trained)\n";

            cin >> troop_option;

            if (troop_option == 0) {
                if (village.getNordOutpost().getTrainedTroops() == 0) {
                    cout << "You do not have any troops of this type available\n";;
                }
                else accept = true;
            }
            if (troop_option == 1) {
                if (village.getArcheryRange().getTrainedTroops() == 0) {
                    cout << "You do not have any troops of this type available\n";;
                }
                else accept = true;
            }
            if (village.getCollegeOfWinterhold().getTrainedTroops() == 0) {
                cout << "You do not have any troops of this type available\n";;
            }
            else accept = true;
        } while(!accept);

        accept = false;

        do {
            cout << "How many of these troops would you like to send?\n";
            cin >> number_option;

            if (troop_option == 0) {
                if (number_option > village.getNordOutpost().getTrainedTroops()) {
                    cout << "Insufficient number of troops available\n";
                }
                else accept = true;
            }
            if (troop_option == 1) {
                if (number_option > village.getArcheryRange().getTrainedTroops()) {
                    cout << "Insufficient number of troops available\n";
                }
                else accept = true;
            }
            if (troop_option == 2) {
                if (number_option > village.getCollegeOfWinterhold().getTrainedTroops()) {
                    cout << "Insufficient number of troops available\n";
                }
                else accept = true;
            }

        } while (!accept);
    }
    options.first = troop_option;
    options.second = number_option;

    return options;
}