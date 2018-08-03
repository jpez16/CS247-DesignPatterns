//
//  main.cpp
//  CompositeDesignPattern
//
//  Created by Justin Pezzack on 2018-08-03.
//  Copyright © 2018 Justin Pezzack. All rights reserved.
//

#include <iostream>
#include <vector>




class Component {
public:
    virtual int design_product() = 0;
    virtual ~Component() {}
    
};

// Composite
class Team: public Component {
    int team_name;
    std::vector<Component *> subordinates;
public:
    int design_product() override { return 0;}
    void add(Component * c) {
        subordinates.push_back(c);
    }
    void remove(Component * c) {
        for (size_t i = 0; i < subordinates.size(); i++)
            if(subordinates.at(i) == c) {
                delete subordinates.at(i);
                subordinates.erase(subordinates.begin() + i);
            }
    }
};

// Leaf
class Engineer: public Component {
public:
    int person_name;
    int design_product() override {return 0;}
    
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
