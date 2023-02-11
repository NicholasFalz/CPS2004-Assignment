#ifndef VILLAGEWARGAME_USERCHOICEMENUS_H
#define VILLAGEWARGAME_USERCHOICEMENUS_H

#include "Village.h"

int getNumberofPlayers();

int getNumberofAI(int playernum);

int choose_option(int i);

int buildOrUpgrade();

int choose_build();

int choose_upgrade(Village village);

int choose_train(Village village, int i);

string choose_attack(int playernum, int i, Village villages[playernum]);

pair <int,int> choose_army(Village village);

#endif //VILLAGEWARGAME_USERCHOICEMENUS_H