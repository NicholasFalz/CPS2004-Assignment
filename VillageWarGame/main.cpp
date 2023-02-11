#include <iostream>
#include <time.h>
#include <algorithm>
#include <vector>

using namespace std;

class Map {
    int r;
    int c;
    string **cells;

public:

    Map(int r,int c) {
        this->r = r;
        this->c = c;
        cells = generateMap(r,c);
    }

    string** generateMap(int r, int c) {
        string** map = new string*[r];

        for (int i=0; i<r; i++) {
            map[i] = new string[r];
            for (int j=0; j<c; j++) {
                map[i][j] = "##";
            }
        }
        return map;
    }

    void printMap() {
        for (int i = 0; i < 5; i++) { // row
            for (int j = 0; j < 5; j++) { // column
                cout << cells[i][j] + " ";
            }
            cout << "\n"; // change line on console
        }
    }

    void updateMap(Map, int index, pair<int,int> location) {
        if (index == 0) cells[location.first][location.second] = "V1";
        else if (index == 1) cells[location.first][location.second] = "V2";
        else if (index == 2) cells[location.first][location.second] = "V3";
        else if (index == 3) cells[location.first][location.second] = "V4";
        else if (index == 4) cells[location.first][location.second] = "V5";
        else if (index == 5) cells[location.first][location.second] = "V6";
        else if (index == 6) cells[location.first][location.second] = "V7";
        else if (index == 7) cells[location.first][location.second] = "V8";
        else if (index == 8) cells[location.first][location.second] = "V9";
        else if (index == 9) cells[location.first][location.second] = "V10";
    }
};

class Building {
protected:
    string name;
    int level;
    int wood_costBuild;
    int stone_costBuild;
    int iron_costBuild;
    int wood_costUpgrade;
    int stone_costUpgrade;
    int iron_costUpgrade;

public:
    Building() {
        level = 0;
    }

    int getLevel() {
        return level;
    }

    int getWoodCostBuild() {
        return wood_costBuild;
    }
    int getStoneCostBuild() {
        return stone_costBuild;
    }
    int getIronCostBuild() {
        return iron_costBuild;
    }
    int getWoodCostUpgrade() {
        return wood_costUpgrade;
    }
    int getStoneCostUpgrade() {
        return stone_costUpgrade;
    }
    int getIronCostUpgrade() {
        return iron_costUpgrade;
    }

    void build() {
        level = 1;
    }

    void upgrade() {
        level++;
    }
};

class ResourceBuilding: public Building {
protected:
    string resource_generated;
public:
    ResourceBuilding() {

    }
};

class LumberMill: public ResourceBuilding {

public:
    LumberMill() {
        name = "Lumber Mill";
        resource_generated = "wood";
        wood_costBuild = 2;
        stone_costBuild = 0;
        iron_costBuild = 0;
        wood_costUpgrade = 2;
        stone_costUpgrade = 0;
        iron_costUpgrade = 0;
    }

    int generateWood(int wood) {
        if (level == 0) {
            cout << "No";
        }
        if (level == 1) {
            return wood + 1;
        }
        if (level == 2) {
            return wood + 2;
        }
        if (level == 3) {
            return wood + 4;
        }
        return 0;
    }
};

class Quarry: public ResourceBuilding {

public:
    Quarry() {
        name = "Quarry";
        resource_generated = "stone";
        wood_costBuild = 0;
        stone_costBuild = 2;
        iron_costBuild = 0;
        wood_costUpgrade = 0;
        stone_costUpgrade = 2;
        iron_costUpgrade = 0;
    }

    int generateStone(int stone) {
        if (level == 0) {
            cout << "No";
        }
        if (level == 1) {
            return stone + 1;
        }
        if (level == 2) {
            return stone + 2;
        }
        if (level == 3) {
            return stone + 4;
        }
        return 0;
    }
};

class Smeltery: public ResourceBuilding {

public:
    Smeltery() {
        name = "Smeltery";
        resource_generated = "iron";
        wood_costBuild = 0;
        stone_costBuild = 0;
        iron_costBuild = 2;
        wood_costUpgrade = 0;
        stone_costUpgrade = 0;
        iron_costUpgrade = 2;
    }

    int generateIron(int iron) {
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
};

class TroopBuilding: public Building {
protected:
    string troop_generated;
    int troops_trained;
public:
    TroopBuilding() {
        troops_trained = 0;
    }

    int getTroops() {
        return troops_trained;
    }

    void trainTroops() {
        troops_trained++;
    }
};

class NordOutpost: public TroopBuilding {

public:
    NordOutpost() {
        troop_generated = "Nord";
        wood_costBuild = 1;
        stone_costBuild = 0;
        iron_costBuild = 1;
        wood_costUpgrade = 1;
        stone_costUpgrade = 0;
        iron_costUpgrade = 1;
    }
};

class ArcheryRange: public TroopBuilding {

public:
    ArcheryRange() {
        troop_generated = "Khajiit";
        wood_costBuild = 1;
        stone_costBuild = 2;
        iron_costBuild = 0;
        wood_costUpgrade = 1;
        stone_costUpgrade = 2;
        iron_costUpgrade = 0;
    }
};

class CollegeOfWinterhold: public TroopBuilding {

public:
    CollegeOfWinterhold() {
        troop_generated = "Breton";
        wood_costBuild = 1;
        stone_costBuild = 4;
        iron_costBuild = 2;
        wood_costUpgrade = 1;
        stone_costUpgrade = 4;
        iron_costUpgrade = 2;
    }
};

class Troops{
protected:
    string name;
    string description;
    int wood_cost;
    int stone_cost;
    int iron_cost;
    int health;
    int attackdamage;
    int carryingcapacity;
    int marchingspeed;

public:

    void attack() {

    };

    void defend() {

    };

    int getWoodCost() {
        return wood_cost;
    }

    int getStonecost() {
        return stone_cost;
    }

    int getIronCost() {
        return iron_cost;
    }
};

class Nord: public Troops {
public:
    Nord() {
        name = "Nord";
        description = "";
        wood_cost = 1;
        stone_cost = 0;
        iron_cost = 1;
        health = 20;
        attackdamage = 20;
        carryingcapacity = 10;
        marchingspeed = 2;
    }
};

class Khajiit: public Troops {
public:
    Khajiit() {
        name = "Khajit";
        description = "";
        wood_cost = 1;
        stone_cost = 2;
        iron_cost = 0;
        health = 20;
        attackdamage = 20;
        carryingcapacity = 10;
        marchingspeed = 2;
    }
};

class Breton: public Troops {
public:
    Breton() {
        name = "Breton";
        description = "";
        wood_cost = 1;
        stone_cost = 4;
        iron_cost = 2;
        health = 20;
        attackdamage = 20;
        carryingcapacity = 10;
        marchingspeed = 2;
    }
};

class Resources{

public:
    int iron;
    int wood;
    int stone;

    Resources() {
        wood = 10;
        stone = 10;
        iron = 10;
    }


};

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
    Village() {
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

    void setOwner(int i) {
        owner = i;
    }

    int getOwner() {
        return owner;
    }

    pair<int,int>& getLocation() {
        return location;
    }

    bool getPlaying() {
        return playing;
    }

    void destroyVillage() {
        playing = false;
    }

    Resources& getResources() {
        return resources;
    }

    LumberMill& getLumberMill() {
        return lumberMill;
    }
    Quarry& getQuarry() {
        return quarry;
    }
    Smeltery& getSmeltery() {
        return smeltery;
    }
    NordOutpost& getNordOutpost() {
        return nordOutpost;
    }
    ArcheryRange& getArcheryRange() {
        return archeryRange;
    }
    CollegeOfWinterhold& getCollegeOfWinterhold() {
        return collegeOfWinterhold;
    }

    Nord& getNords() {
        return nord;
    }
    Khajiit& getKhajiit() {
        return khajiit;
    }
    Breton& getBretons() {
        return breton;
    }



  /*  void buildLumberMill() {
        lumberMill.build();
        resources.wood -= 2;
    }
    void buildQuarry() {
        quarry.build();
        resources.stone -= 2;
    }
    void buildSmeltery() {
        smeltery.build();
        resources.iron -= 2;
    }
    void buildNordOutpost() {
        nordOutpost.build();
        resources.wood--;
        resources.iron--;
    }
    void buildArcheryRange() {
        archeryRange.build();
        resources.wood--;
        resources.stone -= 2;
    }
    void buildCollegeOfWinterhold() {
        collegeOfWinterhold.build();
        resources.wood--;
        resources.stone -= 4;
        resources.iron -= 2;
    } */

  /*  void upgradeLumberMill() {
        lumberMill.upgrade();
        resources.wood -= 2;
    }
    void upgradeQuarry() {
        quarry.upgrade();
        resources.stone -= 2;
    }
    void upgradeSmeltery() {
        smeltery.upgrade();
        resources.iron -= 2;
    }
    void upgradeNordOutpost() {
        nordOutpost.upgrade();
        resources.wood--;
        resources.iron--;
    }
    void upgradeArcheryRange() {
        archeryRange.upgrade();
        resources.wood--;
        resources.stone -= 2;
    }
    void upgradeCollegeOfWinterhold() {
        collegeOfWinterhold.upgrade();
        resources.wood--;
        resources.stone -= 4;
        resources.iron -= 2;
    } */


    void printValues() {
        cout << owner << endl;
        cout << location.first;
        cout << location.second << endl;
        cout << health << endl;
        cout << endl;
    }
};

void generateVillageLocations(int playernum, int i, Village villages[playernum]) {
    int x;
    int y;
    bool accept = false;
    pair<int,int> location;

    while(!accept) {
        x = rand() % 5;
        y = rand() % 5;

        location = make_pair(x,y);

        for (int j = 0; j < playernum; j++) {
            if (location != villages[j].getLocation())  {
                accept = true;
            }
        }
        if (accept) {
            villages[i].location = location;
        }
    }
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
        cout << "Number of Nords trained: " << village.getNordOutpost().getTroops() << endl;
        cout << "Number of Khajiit trained: " << village.getNordOutpost().getTroops() << endl;
        cout << "Number of Bretons trained: " << village.getNordOutpost().getTroops() << endl;
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

int main() {
    int playernum = 0;
    int ainum = -1;
    int r;
    int c;
    bool playing = true;
    srand (time(NULL));
    int option;

    while (playernum < 1 || playernum > 9) {
        cout << "How many players will be playing? (max 9)\n";
        cin >> playernum;
        if (playernum < 1 || playernum > 9) cout << "Invalid input\n";
    }
    while (ainum < 0 || ainum > (9 - playernum)) {
        if (playernum == 9) {
            ainum = 0;
            break;
        }
        cout << "How many AI players would you like have playing?\n";
        cin >> ainum;
        if (ainum < 0) cout << "Invalid input\n";
        if (ainum > (9 - playernum)) cout << "Maximum number of players exceeded\n";
    }

    r = 5; // number of rows in the map
    c = 5; // number of columns in the map

    Map map(r,c);

  /*  map.printMap();
    cout << endl; */

    Village villages[playernum];

    for (int i = 0; i < playernum; ++i) {
        generateVillageLocations(playernum, i, villages);
    }

    for (int i=0; i<playernum; i++) {
        map.updateMap(map,i,villages[i].getLocation());
    }

    cout << "\nMAP:\n\n";

    map.printMap();

  /*  for (int i=0; i<playernum; i++) {
        villages[i].printValues();
    } */

    for (int i = 0; i < playernum; i++) {
        villages[i].setOwner(i+1);
    }


    int build_or_upgrade_option = 0;
    int build_option = 0;
    int upgrade_option = 0;
    int train_option = 0;
    string attack_option;
    int stillplaying = 0;

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
                cout << "Wood Increased\n";
            }
            if (villages[i].getQuarry().getLevel() > 0) {
                villages[i].getResources().stone = villages[i].getQuarry().generateStone(villages[i].getResources().stone);
                cout << "Stone Increased\n";
            }
            if (villages[i].getSmeltery().getLevel() > 0) {
                villages[i].getResources().iron = villages[i].getSmeltery().generateIron(villages[i].getResources().iron);
                cout << "Iron Increased\n";
            }
        }

        // Player Actions
        i = 0;
        while(i < playernum) {


        /*    for (int j = 0; j < playernum; j++) {
                cout << "Player " << j+1 << " resources:\n";
                cout << "Wood: " << villages[j].getResources().wood << endl;
                cout << "Stone: " << villages[j].getResources().stone << endl;
                cout << "Iron: " << villages[j].getResources().iron << "\n" << endl;
            }

            for (int j = 0; j < playernum; j++) {
                cout << "Player " << j+1 << " troops:\n";
                cout << "Nord: " << villages[j].getNordOutpost().getTroops() << endl;
                cout << "Khajiit: " << villages[j].getArcheryRange().getTroops() << endl;
                cout << "Breton: " << villages[j].getCollegeOfWinterhold().getTroops()<< "\n" << endl;
            }

            cout << "Player 1 Lumber Mill level: " << villages[0].getLumberMill().getLevel() << endl;
            cout << "Player 1 Quarry level: " << villages[0].getQuarry().getLevel() << "\n" << endl;
            cout << "Player 2 Lumber Mill level: " << villages[1].getLumberMill().getLevel() << endl;
            cout << "Player 2 Quarry level: " << villages[1].getQuarry().getLevel() << "\n" << endl;
            cout << "Player 3 Lumber Mill level: " << villages[2].getLumberMill().getLevel() << endl;
            cout << "Player 3 Quarry level: " << villages[2].getQuarry().getLevel() << "\n" << endl;

            cout << "Player 1 Nord Outpost level: " << villages[0].getNordOutpost().getLevel() << endl;
            cout << "Player 2 Archery Range level: " << villages[1].getArcheryRange().getLevel() << endl;
            cout << "Player 3 College of Winterhold level: " << villages[2].getCollegeOfWinterhold().getLevel() << endl; */

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
                                        //accepted = true;
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
                                        //accepted = true;
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
                                        //accepted = true;
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
                                        //accepted = true;
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
                                        //accepted = true;
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
                                        //accepted = true;
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

                    cout << "Case 3\n";
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

   /* //Free each sub-array
    for(int i = 0; i < 5; ++i) {
        delete[] map[i];
    }
    //Free the array of pointers
    delete[] map; */

    return 0;
}