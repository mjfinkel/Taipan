//
//  main.cpp
//  Taipan
//
//  Created by Matthew Finkel on 10/15/23.
//

#include "Game.hpp"
#include <iostream>

using namespace std;


int main() {
    system("clear");
    
    string name = "Taipan";
    
    cout << "What is your name, Captain?\n";
    cin >> name;
    if (name == "") {
        name = defaultName;
    }
    
    Game g(name);
    cout << '\n' << "Welcome to " << gameTitle << " " << name << "!\n";
    g.wait(2000);
    
    g.runGame();
    
    return 0;
}
