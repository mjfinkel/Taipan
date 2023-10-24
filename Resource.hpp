//
//  Resource.hpp
//  Taipan
//
//  Created by Matthew Finkel on 10/15/23.
//

#ifndef Resource_hpp
#define Resource_hpp

//#include "Consts.h"

#include <stdio.h>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <utility>
#include <algorithm>
#include <functional>
#include <cstdint>
#include <cstdlib>
#include <iostream>


const int IH_BASE = 10000;
const int WH_BASE = 2500000;

const std::string mob = "Li Yuen";

const std::string loc0 = "Hong Kong";
const std::string loc1 = "Shanghai";
const std::string loc2 = "Nagasaki";
const std::string loc3 = "Saigon";
const std::string loc4 = "Manila";
const std::string loc5 = "Sigapore";
const std::string loc6 = "Batvia";

const std::string res0 = "Opium";
const int res0_high = 10000;
const int res0_low = 2000; // 5x potential
const std::string res1 = "Silk";
const int res1_high = 2000;
const int res1_low = 500; // 4x potential
const std::string res2 = "Arms";
const int res2_high = 100;
const int res2_low = 50; // 2x potential
const std::string res3 = "General";
const int res3_high = 50;
const int res3_low = 33; // 1.515x potential
const int RLS = 4;
const std::string resourcesList[RLS] = { res0, res1, res2, res3 };
const std::string res4 = "Vacant";

const std::string defaultName = "Wilhelm";
const int startingCash = 2000;
const int startingBank = 0;
const int startingDebt = 0;
const int startingGuns = 5;

const std::string gameTitle = "Taipan!";

class Resource {
private:
    std::string name;
    //int price;
    //int available;
    bool leave;
    
public:
    
    Resource(char opt) {
        leave = false;
        if (opt == '1') {
            name = res0;
        }
        else if (opt == '2') {
            name = res1;
        }
        else if (opt == '3') {
            name = res2;
        }
        else if (opt == '4') {
            name = res3;
        }
        else {
            leave = true;
        }
    }
    
    
    bool checkLeave() {
        return leave;
    }
};

#endif /* Resource_hpp */
