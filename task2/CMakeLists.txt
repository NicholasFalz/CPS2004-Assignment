cmake_minimum_required(VERSION 3.23)
project(VillageWarGame)

set(CMAKE_CXX_STANDARD 20)

add_executable(VillageWarGame main.cpp Resources.cpp Resources.h Map.cpp Map.h Building.cpp Building.h ResourceBuilding.cpp ResourceBuilding.h LumberMill.cpp LumberMill.h Quarry.cpp Quarry.h Smeltery.cpp Smeltery.h TroopBuilding.cpp TroopBuilding.h NordOutpost.cpp NordOutpost.h ArcheryRange.cpp ArcheryRange.h CollegeOfWinterhold.cpp CollegeOfWinterhold.h Troops.cpp Troops.h Nord.cpp Nord.h Khajiit.cpp Khajiit.h Breton.cpp Breton.h Village.cpp Village.h UserChoiceMenus.cpp UserChoiceMenus.h printInfo.cpp printInfo.h)
