#include "Map.h"

    Map::Map(int r,int c) {
        this->r = r;
        this->c = c;
        cells = generateMap(r,c);
    }

    string** Map::generateMap(int r, int c) {
        string** map = new string*[r];

        for (int i=0; i<r; i++) {
            map[i] = new string[r];
            for (int j=0; j<c; j++) {
                map[i][j] = "##";
            }
        }
        return map;
    }

    void Map::printMap() {
        for (int i = 0; i < r; i++) { // row
            for (int j = 0; j < c; j++) { // column
                cout << cells[i][j] + " ";
            }
            cout << "\n"; // change line on console
        }
    }

    void Map::updateMap(Map, int index, pair<int,int> location) {
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

    void Map::generateVillageLocations(int playernum, int i, int r, int c, Village villages[playernum]) {
        int x;
        int y;
        bool accept = false;
        pair<int,int> location;

        while(!accept) {
            x = rand() % r;
            y = rand() % c;

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