//
//  Location.hpp
//  Taipan
//
//  Created by Matthew Finkel on 10/15/23.
//

#ifndef Location_hpp
#define Location_hpp

#include "Resource.hpp"

#include <cmath>


class Location {
private:
    
    std::string name;
    std::vector<std::pair<std::string, int>> resourcesCosts;
    bool mobReq;
    
    
public:
    
    int rng(int a, int b);
    
    Location();
    
    Location(std::string loc);
    
    void randomizeCosts();
    
    int locResource(std::string resourceName);
    
    std::string toString();
    
    bool mobReqCheck();
    
    void switchMobReq(bool tf);
};

#endif /* Location_hpp */
