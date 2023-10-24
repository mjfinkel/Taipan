//
//  Game.hpp
//  Taipan
//
//  Created by Matthew Finkel on 10/15/23.
//

#ifndef Game_hpp
#define Game_hpp

#include "Location.hpp"
#include <chrono>
#include <thread>
#include <vector>
#include <cmath>
#include <stdlib.h>

#include <iostream>

class Game {
private:
    
    std::string pName;
    int cash;
    int bank;
    int debt;
    std::string currLocation;
    int currLocationInt;
    std::string month;
    int monthInt;
    int year;
    int shipHealth;
    int shipCount;
    int shipVal;
    int guns;
    std::vector<int> vIH;
    std::vector<int> vWH;
    std::vector<Location> locations;
    bool gameEnd;
    std::vector<std::string> months;
    int ceiling;
    
    double mobAnger; // scale of 1.0-10.0
    
public:
    
    void printBlock();
    
    int rng(int a, int b);
    
    void changeDate(int time);
    
    void wait(int waitTime);
    
    Game();
    
    Game(std::string &name);
    
    void printFinalData();
    
    void printData();
    
    void printSpot();
    
    void shipAttack();
    
    bool callEvent(int var);
    
    void runGame();
    
};

#endif /* Game_hpp */
