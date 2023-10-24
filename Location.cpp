//
//  Location.cpp
//  Taipan
//
//  Created by Matthew Finkel on 10/15/23.
//

#include "Location.hpp"

using namespace std;


int Location::rng(int a, int b) {
    int ret = (rand() % (b - a)) + a;
    return ret;
}


Location::Location() { }


Location::Location(string loc) : name(loc), mobReq(false) {
    resourcesCosts.reserve(RLS);
    int rng0 = rng(res0_low, res0_high);
    std::pair<std::string,double> rngIn0 (res0, rng0);
    resourcesCosts.push_back(rngIn0);
    int rng1 = rng(res1_low, res1_high);
    std::pair<std::string,double> rngIn1 (res1, rng1);
    resourcesCosts.push_back(rngIn1);
    int rng2 = rng(res2_low, res2_high);
    std::pair<std::string,double> rngIn2 (res2, rng2);
    resourcesCosts.push_back(rngIn2);
    int rng3 = rng(res3_low, res3_high);
    std::pair<std::string,double> rngIn3 (res3, rng3);
    resourcesCosts.push_back(rngIn3);
}


void Location::randomizeCosts() {
    int rng0 = rng(res0_low, res0_high);
    resourcesCosts[0].second = rng0;
    int rng1 = rng(res1_low, res1_high);
    resourcesCosts[1].second = rng1;
    int rng2 = rng(res2_low, res2_high);
    resourcesCosts[2].second = rng2;
    int rng3 = rng(res3_low, res3_high);
    resourcesCosts[3].second = rng3;
}


int Location::locResource(std::string resourceName) {
    for (size_t i = 0; i < resourcesCosts.size(); ++i) {
        if (resourcesCosts[i].first == resourceName) {
            return resourcesCosts[i].second;
        }
    }
    return 0;
}


std::string Location::toString() {
    return name;
}


bool Location::mobReqCheck() {
    return mobReq;
}


void Location::switchMobReq(bool tf) {
    mobReq = tf;
}
