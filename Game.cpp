//
//  Game.cpp
//  Taipan
//
//  Created by Matthew Finkel on 10/15/23.
//

#include "Game.hpp"

using namespace std;


void Game::printBlock() {
    std::cout << "------------------------------------\n";
}


int Game::rng(int a, int b) {
    //srand (time(NULL));
    int ret = rand() % b + a;
    return ret;
}


void Game::changeDate(int time) {
    monthInt += time;
    if (monthInt > 11) {
        monthInt -= 12;
        year++;
    }
    month = months[(size_t)monthInt];
}


int numDigits(int number) {
    int digits = 0;
    if (number < 0) digits = 1;
    while (number) {
        number /= 10;
        digits++;
    }
    if (digits == 0) {
        return 1;
    }
    return digits;
}


void Game::wait(int waitTime) {
    // Wait time in milliseconds
    using namespace std::this_thread;
    using namespace std::chrono_literals;
    using std::chrono::system_clock;
    std::this_thread::sleep_for(std::chrono::milliseconds(waitTime));
}


Game::Game() { }


Game::Game(std::string &name) : pName(name),
    cash(startingCash), bank(startingBank), debt(startingDebt),
    currLocation(loc0), currLocationInt(0), month("Jan"),
    monthInt(0), year(1860), shipHealth(100), shipCount(5),
    shipVal(500), guns(startingGuns), gameEnd(false),
    ceiling(1000), mobAnger(3.5)
{
    vIH.reserve(5);
    vIH.push_back(0);
    vIH.push_back(0);
    vIH.push_back(0);
    vIH.push_back(0);
    vIH.push_back(IH_BASE); // Base is 10,000
    
    vWH.reserve(5);
    vWH.push_back(0);
    vWH.push_back(0);
    vWH.push_back(0);
    vWH.push_back(0);
    vWH.push_back(WH_BASE); // Base is 2,500,000
    
    locations.reserve(7);
    locations.push_back(Location(loc0));
    locations.push_back(Location(loc1));
    locations.push_back(Location(loc2));
    locations.push_back(Location(loc3));
    locations.push_back(Location(loc4));
    locations.push_back(Location(loc5));
    locations.push_back(Location(loc6));
    
    months.reserve(12);
    months.push_back("Jan");
    months.push_back("Feb");
    months.push_back("Mar");
    months.push_back("Apr");
    months.push_back("May");
    months.push_back("Jun");
    months.push_back("Jul");
    months.push_back("Aug");
    months.push_back("Sep");
    months.push_back("Oct");
    months.push_back("Nov");
    months.push_back("Dec");
}


void Game::printFinalData() {
    system("clear");
    cout << "User selected \"QUIT\"\n\n";
    cout << "Final game statistics:\n";
    
    // TODO: Print the final data from the game to be seen in the terminal window
    
    
    cout << "\nThank you for playing Taipan!!\n\n";
}


void Game::printData() {
    // TODO: Uncomment when playing in terminal window
    system("clear");
    // END TODO
    
    printBlock();
    cout << "|Cargo     " << "In Hold" << "        " << "Warehouse|\n";
    cout << "| " << res0;
    for (size_t i = 0; i < 12 - res0.size(); ++i) {
        cout << " ";
    }
    cout << vIH[0];
    for (size_t n = 0; n < (size_t)(13 - numDigits(vIH[0])); ++n) {
        cout << " ";
    }
    cout << vWH[0];
    for (size_t l = 0; l < (size_t)(8 - numDigits(vWH[0])); ++l) {
        cout << " ";
    }
    cout << "|\n";
    
    cout << "| " << res1;
    for (size_t i = 0; i < 12 - res1.size(); ++i) {
        cout << " ";
    }
    cout << vIH[1];
    for (size_t n = 0; n < (size_t)(13 - numDigits(vIH[1])); ++n) {
        cout << " ";
    }
    cout << vWH[1];
    for (size_t l = 0; l < (size_t)(8 - numDigits(vWH[1])); ++l) {
        cout << " ";
    }
    cout << "|\n";
    
    cout << "| " << res2;
    for (size_t i = 0; i < 12 - res2.size(); ++i) {
        cout << " ";
    }
    cout << vIH[2];
    for (size_t n = 0; n < (size_t)(13 - numDigits(vIH[2])); ++n) {
        cout << " ";
    }
    cout << vWH[2];
    for (size_t l = 0; l < (size_t)(8 - numDigits(vWH[2])); ++l) {
        cout << " ";
    }
    cout << "|\n";
    
    cout << "| " << res3;
    for (size_t i = 0; i < 12 - res3.size(); ++i) {
        cout << " ";
    }
    cout << vIH[3];
    for (size_t n = 0; n < (size_t)(13 - numDigits(vIH[3])); ++n) {
        cout << " ";
    }
    cout << vWH[3];
    for (size_t l = 0; l < (size_t)(8 - numDigits(vWH[3])); ++l) {
        cout << " ";
    }
    cout << "|\n";
    
    cout << "| " << res4;
    for (size_t i = 0; i < 12 - res4.size(); ++i) {
        cout << " ";
    }
    cout << vIH[4];
    for (size_t n = 0; n < (size_t)(13 - numDigits(vIH[4])); ++n) {
        cout << " ";
    }
    cout << vWH[4];
    for (size_t l = 0; l < (size_t)(8 - numDigits(vWH[4])); ++l) {
        cout << " ";
    }
    cout << "|\n";
    
    printBlock();
    
    
    cout << "|Cash: ";
    int cashSize = numDigits(cash);
    for (int i = 0; i < 15 - cashSize; ++i) {
        cout << " ";
    }
    cout << cash << " |  " << month << " " << year << " |\n";
    cout << "|Bank: ";
    int bankSize = numDigits(bank);
    for (int i = 0; i < 15 - bankSize; ++i) {
        cout << " ";
    }
    cout << bank << " | Ship: " << shipHealth << "%";
    int shDigits = numDigits(shipHealth);
    for (int i = 0; i < 3 - shDigits; ++i) {
        cout << " ";
    }
    cout << "|\n";
    cout << "|Debt: ";
    int debtSize = numDigits(debt);
    for (int i = 0; i < 15 - debtSize; ++i) {
        cout << " ";
    }
    cout << debt << " | Guns: " << guns;
    for (size_t i = 0; i < (size_t)(4 - numDigits(guns)); ++i) {
        cout << " ";
    }
    cout << "|\n";
    
    printBlock();
}


void Game::printSpot() {
    cout << "|Spot: ";
    for (int i = 0; i < (int)(5 - res0.size()); ++i) {
        cout << " ";
    }
    cout << res0 << ": " << locations[(size_t)currLocationInt].locResource(res0) << " ";
    for (int i = 0; i < (int)(9 - res1.size()); ++i) {
        cout << " ";
    }
    cout << res1 << ": " << locations[(size_t)currLocationInt].locResource(res1);
    int res1Len = numDigits(locations[(size_t)currLocationInt].locResource(res1));
    for (int i = 0; i < (int)(5 - res1Len); ++i) {
        cout << " ";
    }
    cout << "|\n";
        
    
    cout << "|    ";
    for (int i = 0; i < (int)(7 - res2.size()); ++i) {
        cout << " ";
    }
    cout << res2 << ": " << locations[(size_t)currLocationInt].locResource(res2) << " ";
    for (int i = 0; i < (int)(10 - res3.size()); ++i) {
        cout << " ";
    }
    cout << res3 << ": " << locations[(size_t)currLocationInt].locResource(res3);
    int res3Len = numDigits(locations[(size_t)currLocationInt].locResource(res3));
    for (int i = 0; i < (int)(6 - res3Len); ++i) {
        cout << " ";
    }
    cout << "|\n";
    
    printBlock();
}


void Game::shipAttack() {
    // TODO: Ships attack
    int numShips = rng(2, 10 * guns);
    int runAway = 0;
    bool finished = false;
    int choice;
    int round = 0;
    while (!finished) {
        
        // TODO: make there a chance that the mob organization is the pirate crew (increase the amount of ships attacking)
        
        // TODO: make there a chance that mob boss helps fight
        
        printData();
        if (numShips < 1) {
            cout << "You have sunk all the ships!\n";
            wait(2000);
            finished = true;
            break;
        }
        if (round == 0) {
            cout << "Watch out, " << pName << "! " << numShips << " ships are\napproaching!\n";
            cout << "What do you choose to do?\n";
            cout << "1. Fight    2. Run\n";
        }
        else {
            cout << numShips << " ships remaining!\n";
            cout << "What do you choose to do?\n";
            cout << "1. Fight    2. Run\n";
        }
        cin >> choice;
        // TODO: make ship lose cargo when fighting
        if (choice == 1) {
            shipVal -= rng(1, numShips / 2);
            shipHealth = shipVal / shipCount;
            int tempGuns = guns;
            while (tempGuns > 0 && numShips > 0) {
                int sinkBoats = rng(1, 5);
                numShips -= sinkBoats;
                tempGuns--;
            }
            round++;
        }
        else if (choice == 2) {
            // TODO: make it harder to escape when carrying more cargo
            shipVal -= rng(1, numShips / 2);
            shipHealth = shipVal / shipCount;
            runAway = rng(0, numShips / 2);
            if (runAway == 1) {
                cout << "You escaped!\n";
                wait(2000);
                finished = true;
                break;
            }
            round++;
        }
        else {
            printData();
            cout << "Invalid choice\nChose to Fight (1) or Run (2)\n";
            wait(3000);
        }
        
        // TODO: make a choice to throw cargo overboard
    }
}


bool Game::callEvent(int var) {
    if (var >= 10 && var < 15) { // 5 : 0.05 chance
        // Ships attack
        cout << "\n";
        shipAttack();
        return true;
    }
    else if (var >= 15 && var < 30) { // 15 : 0.15 chance
        // Storm
        // TODO: chance that some ships sink when carrying too much cargo
        cout << "\n";
        printData();
        cout << "There's a storm approaching!\n";
        int temp = rng(0, 6);
        while (temp == currLocationInt) {
            temp = rng(0, 6);
        }
        currLocation = locations[(size_t)temp].toString();
        currLocationInt = temp;
        cout << "We were blown to " << currLocation << ".\n";
        wait(4000);
        return true;
    }
    else if (var >= 30 && var < 40) { // 10 : 0.1 chance
        // Mob boss wants to see you
        cout << "\n";
        printData();
        cout << mob << " has sent a lieutenant,\n"
            << pName << ". He says his admiral\n"
            << "wishes to see you in " << loc0 << "\n"
            << "posthaste!\n";
        locations[0].switchMobReq(true);
        wait(5000);
        return true;
    }
    return false;
}


void Game::runGame() {
    while (!gameEnd) {
        double tempDebt = debt * 1.0;
        tempDebt *= 1.02;
        debt = (int)ceil(tempDebt);
        if (currLocation == loc0 && locations[0].mobReqCheck()) {
            // TODO: make it so higher mobReqCheck when carrying lots of cargo
            printData();
            cout << mob << " requests a donation\n"
                << "to his criminal organization\n";
            int paymentBound = numDigits(cash) - 5;
            int payment = rng(50, 500);
            if (paymentBound > 1) {
                payment = rng(50, 500 * paymentBound);
            }
            cout << "Will you pay " << payment << "?\n";
            cout << "\'1\' for yes or \'2\' for no: ";
            int answer;
            cin >> answer;
            if (answer == 1) {
                if (cash - payment >= 0) {
                    cash -= payment;
                }
                else {
                    cash = 0;
                    debt += (payment - cash);
                }
                locations[0].switchMobReq(false);
                double mobDec = ((double)rng(100, 200)) / 100.0; // can decrease by 1.00 to 2.00
                if (mobAnger - mobDec <= 1.0) {
                    mobAnger = 1.0;
                }
                else {
                    mobAnger -= mobDec;
                }
            }
        }
        else if (locations[0].mobReqCheck()) {
            printData();
            cout << mob << " has sent a lieutenant,\n"
                << pName << ". He says his admiral\n"
                << "wishes to see you in " << loc0 << "\n"
                << "posthaste!\n";
            wait(5000);
            double mobInc = ((double)rng(0, 20)) / 100.0; // can increase by 0.00 to 0.20
            mobAnger += mobInc;
        }
        if (currLocation == loc0 && shipHealth < 100) {
            printData();
            int repairPrice = rng((100 - shipHealth), (100 - shipHealth) * numDigits(shipCount) + 500);
            cout << "Would you like to repair your\n";
            cout << "fleet for " << repairPrice << "?\n\n";
            cout << "\'1\' for yes or \'2\' for no\n";
            int payPrice;
            cin >> payPrice;
            if (payPrice == 1) {
                if (cash - repairPrice >= 0) {
                    cash -= repairPrice;
                    shipHealth = 100;
                }
                else {
                    printData();
                    cout << "You do not have enough cash,\n" << pName << "!\n";
                    wait(2500);
                }
            }
        }
        if (currLocation == loc0 && year >= 1865) {
            if (debt > 0 && cash >= debt) {
                printData();
                cout << "Would you like to repay your debt\n";
                cout << "of " << debt << " cash?\n";
                cout << "1. Yes    2. No\n";
                char opt;
                cin >> opt;
                if (opt == '1') {
                    cash -= debt;
                    debt = 0;
                }
            }
            else {
                int loanChance = rng(1, 3);
                if (loanChance == 2) {
                    printData();
                    int tempcash = cash;
                    if (tempcash < 1000) {
                        tempcash = 1000;
                    }
                    int debtRNG = rng(numDigits(cash), cash / 10);
                    cout << "Would you like to take out " << debtRNG;
                    cout << "\ncash as debt?\n";
                    cout << "1. Yes    2. No\n";
                    char opt;
                    cin >> opt;
                    if (opt == '1') {
                        debt += debtRNG;
                        cash += debtRNG;
                    }
                }
            }
        }
        if (/*currLocation == loc0 && */((year == 1860 && monthInt >= 5) || year != 1860)) {
            printData();
            int perGunPrice = (int)(rng(100, 500) * sqrt(guns));
            int amountGuns = rng(1, numDigits(cash));
            cout << "Would you like to buy\n";
            cout << amountGuns << " guns for " << perGunPrice * amountGuns << "\n";
            cout << "1. Yes    2. No\n";
            int answer;
            cin >> answer;
            if (answer == 1 && cash >= perGunPrice * amountGuns) {
                guns += amountGuns;
                cash -= perGunPrice * amountGuns;
            }
        }
        cout << "\n";
        printData();
        printSpot();
        cout << "Your orders, " << pName << "?\n";
        cout << "1. Buy  2. Sell\n" << "3. Leave Port";
        if (currLocation == loc0) {
            cout << "  4. Visit Bank\n5. Transport Cargo";
        }
        cout << " 9. Leave Game\n";
        int choice;
        cin >> choice;
        if (choice == 9) {
            gameEnd = true;
            break;
        }
        cout << "\n";
        printData();
        if (choice == 1) {
            printSpot();
            cout << "What do you wish to buy, " << pName << "?\n";
            cout << "1. " << res0;
            for (size_t i = 0; i < (size_t)(8 - res0.size()); ++i) {
                cout << " ";
            }
            cout << "2. " << res1;
            for (size_t i = 0; i < (size_t)(8 - res2.size()); ++i) {
                cout << " ";
            }
            cout << "3. " << res2 << "\n";
            cout << "4. " << res3;
            for (size_t i = 0; i < (size_t)(12 - res2.size()); ++i) {
                cout << " ";
            }
            cout << "5. Go Back\n";
            cin >> choice;
            if (choice == 1) {
                printData();
                printSpot();
                cout << "Buy how much " << res0 << "?\n";
                int cap = 0;
                cap = (int)floor(cash / locations[(size_t)currLocationInt].locResource(res0));
                if (cap > vIH[4]) {
                    cap = vIH[4];
                }
                cout << "(You can afford " << cap << ")\n";
                int amountToBuy = 0;
                cin >> amountToBuy;
                if (amountToBuy > 0 && amountToBuy <= cap && amountToBuy <= vIH[4]) {
                    vIH[0] += amountToBuy;
                    cash -= locations[(size_t)currLocationInt].locResource(res0) * amountToBuy;
                    vIH[4] -= amountToBuy;
                }
                else {
                    printData();
                    printSpot();
                    cout << "Invalid amount of " << res0 << ".\n";
                    wait(3000);
                }
            }
            else if (choice == 2) {
                printData();
                printSpot();
                cout << "Buy how much " << res1 << "?\n";
                int cap = 0;
                cap = (int)floor(cash / locations[(size_t)currLocationInt].locResource(res1));
                if (cap > vIH[4]) {
                    cap = vIH[4];
                }
                cout << "(You can afford " << cap << ")\n";
                int amountToBuy = 0;
                cin >> amountToBuy;
                if (amountToBuy > 0 && amountToBuy <= cap && amountToBuy <= vIH[4]) {
                    vIH[1] += amountToBuy;
                    cash -= locations[(size_t)currLocationInt].locResource(res1) * amountToBuy;
                    vIH[4] -= amountToBuy;
                }
                else {
                    printData();
                    printSpot();
                    cout << "Invalid amount of " << res1 << ".\n";
                    wait(3000);
                }
            }
            else if (choice == 3) {
                printData();
                printSpot();
                cout << "Buy how much " << res2 << "?\n";
                int cap = 0;
                cap = (int)floor(cash / locations[(size_t)currLocationInt].locResource(res2));
                if (cap > vIH[4]) {
                    cap = vIH[4];
                }
                cout << "(You can afford " << cap << ")\n";
                int amountToBuy = 0;
                cin >> amountToBuy;
                if (amountToBuy > 0 && amountToBuy <= cap && amountToBuy <= vIH[4]) {
                    vIH[2] += amountToBuy;
                    cash -= locations[(size_t)currLocationInt].locResource(res2) * amountToBuy;
                    vIH[4] -= amountToBuy;
                }
                else {
                    printData();
                    printSpot();
                    cout << "Invalid amount of " << res2 << ".\n";
                    wait(3000);
                }
            }
            else if (choice == 4) {
                printData();
                printSpot();
                cout << "Buy how much " << res3 << "?\n";
                int cap = 0;
                cap = (int)floor(cash / locations[(size_t)currLocationInt].locResource(res3));
                if (cap > vIH[4]) {
                    cap = vIH[4];
                }
                cout << "(You can afford " << cap << ")\n";
                int amountToBuy = 0;
                cin >> amountToBuy;
                if (amountToBuy >= 0 && amountToBuy <= cap && amountToBuy <= vIH[4]) {
                    vIH[3] += amountToBuy;
                    cash -= locations[(size_t)currLocationInt].locResource(res3) * amountToBuy;
                    vIH[4] -= amountToBuy;
                }
                else {
                    printData();
                    printSpot();
                    cout << "Invalid amount of " << res3 << ".\n";
                    wait(3000);
                }
            }
        }
        else if (choice == 2) {
            printSpot();
            cout << "What do you wish to sell, " << pName << "?\n";
            cout << "1. " << res0;
            for (size_t i = 0; i < (size_t)(8 - res0.size()); ++i) {
                cout << " ";
            }
            cout << "2. " << res1;
            for (size_t i = 0; i < (size_t)(8 - res2.size()); ++i) {
                cout << " ";
            }
            cout << "3. " << res2 << "\n";
            cout << "4. " << res3;
            for (size_t i = 0; i < (size_t)(12 - res2.size()); ++i) {
                cout << " ";
            }
            cout << "5. Go Back\n";
            cin >> choice;
            if (choice == 1) {
                printData();
                printSpot();
                cout << "Sell how much " << res0 << "?\n";
                int cap = vIH[0];
                cout << "(You can sell " << cap << ")\n";
                int amountToSell = 0;
                cin >> amountToSell;
                if (amountToSell > 0 && amountToSell <= cap) {
                    vIH[0] -= amountToSell;
                    cash += locations[(size_t)currLocationInt].locResource(res0) * amountToSell;
                    vIH[4] += amountToSell;
                }
                else {
                    printData();
                    printSpot();
                    cout << "Invalid amount of " << res0 << ".\n";
                    wait(3000);
                }
            }
            else if (choice == 2) {
                printData();
                printSpot();
                cout << "Sell how much " << res1 << "?\n";
                int cap = vIH[1];
                cout << "(You can sell " << cap << ")\n";
                int amountToSell = 0;
                cin >> amountToSell;
                if (amountToSell > 0 && amountToSell <= cap) {
                    vIH[1] -= amountToSell;
                    cash += locations[(size_t)currLocationInt].locResource(res1) * amountToSell;
                    vIH[4] += amountToSell;
                }
                else {
                    printData();
                    printSpot();
                    cout << "Invalid amount of " << res1 << ".\n";
                    wait(3000);
                }
            }
            else if (choice == 3) {
                printData();
                printSpot();
                cout << "Sell how much " << res2 << "?\n";
                int cap = vIH[2];
                cout << "(You can sell " << cap << ")\n";
                int amountToSell = 0;
                cin >> amountToSell;
                if (amountToSell > 0 && amountToSell <= cap) {
                    vIH[2] -= amountToSell;
                    cash += locations[(size_t)currLocationInt].locResource(res2) * amountToSell;
                    vIH[4] += amountToSell;
                }
                else {
                    printData();
                    printSpot();
                    cout << "Invalid amount of " << res2 << ".\n";
                    wait(3000);
                }
            }
            else if (choice == 4) {
                printData();
                printSpot();
                cout << "Sell how much " << res3 << "?\n";
                int cap = vIH[3];
                cout << "(You can sell " << cap << ")\n";
                int amountToSell = 0;
                cin >> amountToSell;
                if (amountToSell > 0 && amountToSell <= cap) {
                    vIH[3] -= amountToSell;
                    cash += locations[(size_t)currLocationInt].locResource(res3) * amountToSell;
                    vIH[4] += amountToSell;
                }
                else {
                    printData();
                    printSpot();
                    cout << "Invalid amount of " << res3 << ".\n";
                    wait(3000);
                }
            }
        }
        else if (choice == 3) {
            cout << "Where do you wish to sail, " << pName << "?\n";
            cout << "1. " << loc0 << "  2. " << loc1 << "\n"
            << "3. " << loc2 << "  4. " << loc3 << "\n"
            << "5. " << loc4 << "  6. " << loc5 << "\n"
            << "7. " << loc6 << "\n";
            cin >> choice;
            cout << "\n";
            std::string newLocation = locations[(size_t)(choice - 1)].toString();
            if (currLocation == newLocation) {
                printData();
                cout << "You're already here, " << pName << ".\n";
                wait(2500);
            }
            else {
                currLocation = newLocation;
                currLocationInt = choice - 1;
                changeDate(rng(0, 3));
                printData();
                locations[(size_t)(choice - 1)].randomizeCosts();
                cout << "Arriving at " << locations[(size_t)(choice - 1)].toString() << "\n";
                for (size_t n = 0; n < 10; ++n) {
                    wait(250);
                    // TODO: add if you can figure out why it is not adding the "'" to the terminal window
                    //cout << "\'\'\'";
                    int var = rng(0, ceiling);
                    bool event = callEvent(var);
                    if (event) {
                        n = 10;
                        printData();
                        cout << "Arriving at " << locations[(size_t)(choice - 1)].toString() << "\n";
                        wait(2500);
                    }
                }
                wait(500);
            }
        }
        else if (choice == 4 && currLocation == loc0) {
            // TODO: Finish section
            cout << "TODO: Finish section";
        }
        else if (choice == 5 && currLocation == loc0) {
            //printBlock();
            cout << "What would you like to do?\n";
            cout << "1. Store   2. Retrive\n";
            char opt;
            cin >> opt;
            if (opt == '1') {
                printData();
                cout << "What and how much would you\n";
                cout << "like to store?\n";
                cout << "1. Opium     2. Silk\n";
                cout << "3. Arms      4. General\n";
                char storeOpt;
                int amount;
                cin >> storeOpt;
                printData();
                cout << "How much?\n";
                cin >> amount;
                if (storeOpt == '1' && vWH[4] - amount >= 0) {
                    if (vIH[0] >= amount) {
                        vIH[0] -= amount;
                        vWH[0] += amount;
                        vIH[4] -= amount;
                        vWH[4] += amount;
                    }
                    else {
                        printData();
                        cout << "Unable to store that amount\n";
                        wait(3000);
                    }
                }
                else if (storeOpt == '2' && vWH[4] - amount >= 0) {
                    if (vIH[1] >= amount) {
                        vIH[1] -= amount;
                        vWH[1] += amount;
                        vIH[4] -= amount;
                        vWH[4] += amount;
                    }
                    else {
                        printData();
                        cout << "Unable to store that amount\n";
                        wait(3000);
                    }
                }
                else if (storeOpt == '3' && vWH[4] - amount >= 0) {
                    if (vIH[2] >= amount) {
                        vIH[2] -= amount;
                        vWH[2] += amount;
                        vIH[4] -= amount;
                        vWH[4] += amount;
                    }
                    else {
                        printData();
                        cout << "Unable to store that amount\n";
                        wait(3000);
                    }
                }
                else if (storeOpt == '4' && vWH[4] - amount >= 0) {
                    if (vIH[3] >= amount) {
                        vIH[3] -= amount;
                        vWH[3] += amount;
                        vIH[4] -= amount;
                        vWH[4] += amount;
                    }
                    else {
                        printData();
                        cout << "Unable to store that amount\n";
                        wait(3000);
                    }
                }
                else {
                    printData();
                    cout << "Unable to store that amount\n";
                    wait(3000);
                }
            }
            else if (opt == '2') {
                printData();
                cout << "What and how much would you\n";
                cout << "like to retrive?\n";
                cout << "1. Opium     2. Silk\n";
                cout << "3. Arms      4. General\n";
                char storeOpt;
                char amount;
                cin >> storeOpt;
                printData();
                cout << "How much?\n";
                cin >> amount;
                if (storeOpt == '1' && vIH[4] - amount >= 0) {
                    if (vWH[0] >= amount) {
                        vIH[0] += amount;
                        vWH[0] -= amount;
                        vIH[4] += amount;
                        vWH[4] -= amount;
                    }
                    else {
                        printData();
                        cout << "Unable to store that amount\n";
                        wait(3000);
                    }
                }
                else if (storeOpt == '2' && vIH[4] - amount >= 0) {
                    if (vWH[1] >= amount) {
                        vIH[1] += amount;
                        vWH[1] -= amount;
                        vIH[4] += amount;
                        vWH[4] -= amount;
                    }
                    else {
                        printData();
                        cout << "Unable to store that amount\n";
                        wait(3000);
                    }
                }
                else if (storeOpt == '3' && vIH[4] - amount >= 0) {
                    if (vWH[2] >= amount) {
                        vIH[2] += amount;
                        vWH[2] -= amount;
                        vIH[4] += amount;
                        vWH[4] -= amount;
                    }
                    else {
                        printData();
                        cout << "Unable to store that amount\n";
                        wait(3000);
                    }
                }
                else if (storeOpt == '4' && vIH[4] - amount >= 0) {
                    if (vWH[3] >= amount) {
                        vIH[3] += amount;
                        vWH[3] -= amount;
                        vIH[4] += amount;
                        vWH[4] -= amount;
                    }
                    else {
                        printData();
                        cout << "Unable to store that amount\n";
                        wait(3000);
                    }
                }
                else {
                    printData();
                    cout << "Unable to store that amount\n";
                    wait(3000);
                }
            }
        }
    }
    printFinalData();
    //cout << "User selected \"QUIT\"\nThanks for playing!\n\n";
}
