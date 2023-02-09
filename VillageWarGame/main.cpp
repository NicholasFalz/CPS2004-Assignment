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
    bool resource;
    bool troop;
    int level;

public:
    Building() {
        level = 1;
    }

    void trainTroops() {

    }
};

class ResourceBuilding: public Building {
protected:
    string resource_generated;
public:
    ResourceBuilding() {
        resource = true;
        troop = false;
    }
};

class TroopBuilding: public Building {
protected:
    string troop_generated;
public:
    TroopBuilding() {
        resource = false;
        troop = true;
    }
};

class LumberMill: public ResourceBuilding {
public:
    LumberMill() {
        resource_generated = "wood";
    }
};

class Quarry: public ResourceBuilding {
public:
    Quarry() {
        resource_generated = "stone";
    }
};

class Smeltery: public ResourceBuilding {
public:
    Smeltery() {
        resource_generated = "iron";
    }
};

class Troops{
protected:
    string name;
    string description;
    int trainingcost;
    int health;
    int attackdamage;
    int carryingcapacity;
    int marchingspeed;

public:

    void attack() {

    };

    void defend() {

    };
};

class Nord: public Troops {
public:
    Nord() {
        name = "Nord";
        description = "";
        trainingcost = 10;
        health = 20;
        attackdamage = 20;
        carryingcapacity = 10;
        marchingspeed = 2;
    }
};

class Khajit: public Troops {
public:
    Khajit() {
        name = "Khajit";
        description = "";
        trainingcost = 10;
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
        trainingcost = 10;
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
        wood = 0;
        stone = 0;
        iron = 0;
    }


};

class Village{
    int owner;
    int health;
    pair<int,int> location;
    int buildings[6];
    int troops[3];
    Resources village_resources;

public:
    Village() {
        owner = 1;
        location = make_pair(rand() % 5, rand() % 5);
        health = 100;
        for (int i = 0; i < 6; i++) buildings[i] = 0;
        for (int i = 0; i < 3; i++) troops[i] = 0;
        village_resources = Resources();
    }

    pair<int,int> generateVillageLocations() {
        int x;
        int y;
        bool accept = false;
        pair<int,int> locations;

        x = rand() % 5;
        y = rand() % 5;

        cout << getLocation().first;
        cout << getLocation().second;

        locations = make_pair(x,y);

        return locations;

        /*      while(!accept) {
                  x = rand() % 5;
                  y = rand() % 5;

                  locations = make_pair(x,y);

                  if (locations == ) {
                      cout << "Already set";
                      continue;
                  }
                  else {



                      cout << endl;
                      accept = true;
                  }
              } */
        return locations;
    }

    pair<int,int> getLocation() {
        return location;
    }

    void printValues() {
        cout << owner << endl;
        cout << location.first;
        cout << location.second << endl;
        cout << health << endl;
        cout << endl;
    }

    Resources getResources() {
        return village_resources;
    }

    void increaseWood() {
        if (buildings)
        village_resources.wood += 1;
    }

    void increaseStone() {
        village_resources.stone += 1;
    }

    void increaseIron() {
        village_resources.iron += 1;
    }
};

void build() {
    int build_option = 0;

    do {
        cout << "Which would you like to build?\n\n";
        cout << "1. LumberMill (Generates Wood)\n";
        cout << "2. Quarry (Generates Stone)\n";
        cout << "3. Smeltery (Generates Iron)\n";
        cout << "4. LumberMill (Generates Wood)\n";
        cout << "5. LumberMill (Generates Wood)\n";
        cout << "6. LumberMill (Generates Wood)\n";

        cin >> build_option;

        switch(build_option) {
            case 1: {
                LumberMill lumbermill;
                cout << "LumberMill Built\n";
                break;
            }
            case 2: {
                Quarry quarry;
                cout << "Quarry Built\n";
                break;
            }
            case 3: {
                Smeltery smeltery;
                cout << "Smeltery Built\n";
                break;
            }

            case 4: {
                cout << "LumberMill Built\n";
                break;
            }

            case 5: {
                cout << "LumberMill Built\n";
                break;
            }

            case 6: {
                cout << "LumberMill Built\n";
                break;
            }
            default:
                cout << "Invalid\n\n";
        }
    } while(build_option < 1 || build_option > 6);
}

void upgrade() {
    int upgrade_option = 0;

    cout << "Which of your buildings would your like to upgrade?\n\n";
    // list current built buildings
    // add a case if no buildings are built

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

    while (playernum < 1 || playernum > 10) {
        cout << "How many players will be playing? (max 10)\n";
        cin >> playernum;
        if (playernum < 1 || playernum > 10) cout << "Invalid input\n";
    }
    while (ainum < 0 || ainum > (10 - playernum)) {
        cout << "How many AI players would you like have playing?\n";
        cin >> ainum;
        if (ainum < 0) cout << "Invalid input\n";
        if (ainum > (10 - playernum)) cout << "Maximum number of players exceeded\n";
    }

    r = 5; // number of rows in the map
    c = 5; // number of columns in the map

    Map map(r,c);

    map.printMap();
    cout << endl;

    Village villages[playernum];

    for (int i=0; i<playernum; i++) {
        map.updateMap(map,i,villages[i].getLocation());
    }

    map.printMap();

    for (int i=0; i<playernum; i++) {
        villages[i].printValues();
    }

    Village v1;
  //  cout << v1.getResources();
    for (int i = 0; i < 3; ++i) {
//        cout << ptr[i];
    }

    int build_or_upgrade_option = 0;

    int i;
    Resources ptr;
    int resources[3];
    // Game Loop:
    while (playing) {
        // Friendly Troop Arrival

        // Enemy Troop Arrival

        // Resource Earning
        for (i = 0; i < playernum; i++) {
            ptr = villages[i].getResources();

            if (ptr.wood > 0) {
                villages[i].increaseWood();
                cout << "Wood Increased\n";
            }
            if (ptr.stone > 0) {
                villages[i].increaseStone();
                cout << "Stone Increased\n";
            }
            if (ptr.iron > 0) {
                villages[i].increaseIron();
                cout << "Iron Increased\n";
            }
        }

        i = 0;
        while(i < 10) {
            cout << "Player "<< i+1 <<"'s Turn\n\n";
            cout << "Select an option (Input a number):\n";
            cout << "1. Build/Upgrade Buildings\n";
            cout << "2. Train Troops\n";
            cout << "3. Attack a Village\n";
            cout << "4. Pass Turn\n";
            cout << "5. Surrender (Die)\n";
            cin >> option;

            switch (option) {
                case 1:
                    build_or_upgrade_option = buildOrUpgrade();

                    switch (build_or_upgrade_option) {
                        case 1:
                            build();
                            i++;
                            break;
                        case 2:
                            upgrade();
                            i++;
                            break;
                    }
                    break;
                case 2:
                    i++;
                    cout << "Case 2\n";
                    break;
                case 3:
                    i++;
                    cout << "Case 3\n";
                    break;
                case 4:
                    cout << "Player " << i << " Passed";
                    i++;
                    continue;
                    break;
                case 5:
                    i++;
                    cout << "Case 5\n";
                    break;
                default:
                    cout << "Invalid\n\n";
            }
            if (i > 9) {
                playing = false;
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