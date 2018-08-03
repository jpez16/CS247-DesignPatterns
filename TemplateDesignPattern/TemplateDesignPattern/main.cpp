//
//  main.cpp
//  TemplateDesignPattern
//
//  Created by Justin Pezzack on 2018-08-03.
//  Copyright © 2018 Justin Pezzack. All rights reserved.
//

#include <iostream>

class Miata {
    std::string brand() {
        return "Mazda";
    };
    std::string creator() {
        return "Tom Montano";
    };
    virtual std::string color() = 0;
};

// In this example subclasses cannot change the fact that miatas are mazda's and created by tom montano, but they can however change the paint colour of the car!

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
