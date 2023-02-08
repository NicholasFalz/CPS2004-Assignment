#include <iostream>
#include <time.h>
using namespace std;

class Building{

};

class Troops{

};

class Village{
    int owner;
    pair<int,int> location;
    int health;
//    Building buildings[];
//    Troops troops[];
//    Resources resources[];
public:
    Village() {
        owner = 1;
        location = generateVillageLocations();
        health = 100;
    }

    pair<int,int> generateVillageLocations() {
        int x;
        int y;

        x = rand() % 5;
        y = rand() % 5;
        location.first = x;
        location.second = y;

        return location;
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
};

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

void printMap(string** map) {
    for (int i = 0; i < 5; i++) { // row
        for (int j = 0; j < 5; j++) { // column
            cout << map[i][j] + " ";
        }
        cout << "\n"; // change line on console
    }
}

void updateMap(string** map, int index, pair<int,int> location) {
    if (index == 0) map[location.first][location.second] = "V1";
    else if (index == 1) map[location.first][location.second] = "V2";
    else if (index == 2) map[location.first][location.second] = "V3";
    else if (index == 3) map[location.first][location.second] = "V4";
    else if (index == 4) map[location.first][location.second] = "V5";
    else if (index == 5) map[location.first][location.second] = "V6";
    else if (index == 6) map[location.first][location.second] = "V7";
    else if (index == 7) map[location.first][location.second] = "V8";
    else if (index == 8) map[location.first][location.second] = "V9";
    else if (index == 9) map[location.first][location.second] = "V10";
}

int main() {
    int playernum = 0;
    int ainum = -1;
    int r;
    int c;
    string **map;
    srand (time(NULL));

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

    map = generateMap(r,c);

    printMap(map);
    cout << endl;

    Village villages[playernum];

    for (int i=0; i<playernum; i++) {
        updateMap(map,i,villages[i].getLocation());
    //    printMap(map);
    }

    printMap(map);

    for (int i=0; i<playernum; i++) {
        villages[i].printValues();
    }

    for(int i = 0; i < r; i++) {
        delete[] map[i];
    }
    //Free the array of pointers
    delete[] map;

    return 0;
}



