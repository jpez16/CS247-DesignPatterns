//
//  main.cpp
//  VisitorDesignPattern
//
//  Created by Justin Pezzack on 2018-08-03.
//  Copyright © 2018 Justin Pezzack. All rights reserved.
//

#include <iostream>

class Car;
class Miata;


// Visitor
class Driver {
public:
    Driver() {}
    ~Driver() {}
    void drive(Car * c) {}
    
};

class Car {
    virtual void beDrivenBy(Driver * d) = 0;
};

// Object to be visited
class Miata: public Car {
public:
    Miata() {}
    void beDrivenBy(Driver * d) override {
        d->drive(this);
    }
};



int main(int argc, const char * argv[]) {

}
