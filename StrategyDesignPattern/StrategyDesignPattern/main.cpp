//
//  main.cpp
//  StrategyDesignPattern
//
//  Created by Justin Pezzack on 2018-08-02.
//  Copyright © 2018 Justin Pezzack. All rights reserved.
//

#include <iostream>

class Fuel {
public:
    Fuel() {}
    virtual ~Fuel();
    virtual int timing_advance() = 0;
};

class Octane87: public Fuel {
    int _timing_advance;
public:
    Octane87(): _timing_advance(0) {}
    int timing_advance() override {
        return _timing_advance;
    }
};


class Octane93: public Fuel {
    int _timing_advance;
public:
    Octane93(): _timing_advance(4) {}
    int timing_advance() override {
        return _timing_advance;
    }
    
};


class E85: public Fuel {
    int _timing_advance;
public:
    E85(): _timing_advance(8) {}
    int timing_advance() override {
        return _timing_advance;
    }
    
};
class Miata {
    Fuel * fuel;
public:
    Miata(): fuel(new Octane87()) {};
    Miata(Fuel * f): fuel(f) {};
    
    Fuel * fuel_type() {
        return fuel;
    }
    void changeFuel(Fuel * f) {
        delete fuel;
        fuel = f;
    }
    void startCar() {
        for (size_t i = 0; i < fuel->timing_advance(); i++) {
            std::cout << "BRAPBRAP" << std::endl;
        }
    }
};



int main(int argc, const char * argv[]) {
    // insert code here...
}
