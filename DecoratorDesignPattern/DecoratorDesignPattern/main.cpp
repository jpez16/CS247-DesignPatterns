//
//  main.cpp
//  DecoratorDesignPattern
//
//  Created by Justin Pezzack on 2018-08-03.
//  Copyright © 2018 Justin Pezzack. All rights reserved.
//

#include <iostream>


class Miata {
public:
    virtual float value() const = 0;
    virtual std::string color() const = 0;
    virtual int mileage() const = 0;
    virtual ~Miata() {};
    virtual void description() const = 0;
};

class StockMiata: public Miata {
    std::string _color;
    std::string _generation;
    int _value;
    int _mileage;
public:
    StockMiata(std::string color="Mariner Blue", std::string generation = "NA6", int value = 15999, int mileage = 0): _color(color), _generation(generation), _value(value), _mileage(mileage) {}
    
    virtual void description() const override {
        std::cout << _color << " " << _generation;
    }
    virtual float value() const override {
        return _value;
    }
    virtual int mileage() const override {
        return _mileage;
    }
    virtual std::string color() const override {
        return _color;
    }
    
};


class Decorator: public Miata {
protected:
    Miata * _component;
public:
    Decorator(Miata *m) : _component(m) {}
    virtual ~Decorator() {
        delete _component;
    }
};


class Coilovers: public Decorator {
public:
    Coilovers(Miata * m): Decorator(m) {} // Decorator(m) calls the base class constructor
    void description() const override {
        _component->description();
        std::cout << " + " << "Coilovers";
    }
    float value() const override {
        return _component->value() + 1000;
    }
    int mileage() const override {
        return _component->mileage();
    }
    std::string color() const override {
        return _component->color();
    }
};

class Wheels: public Decorator {
public:
    Wheels(Miata * m): Decorator(m) {} // Decorator(m) calls the base class constructor
    void description() const override {
        _component->description();
        std::cout << " + " << "Wheels";
    }
    float value() const override {
        return _component->value() + 1200;
    }
    int mileage() const override {
        return _component->mileage();
    }
    std::string color() const override {
        return _component->color();
    }
};

class FlyinMiataTurboKit: public Decorator {
public:
    FlyinMiataTurboKit(Miata * m): Decorator(m) {} // Decorator(m) calls the base class constructor
    void description() const override {
        _component->description();
        std::cout << " + " << "FlyinMiataTurboKit";
    }
    float value() const override {
        return _component->value() + 5200;
    }
    int mileage() const override {
        return _component->mileage();
    }
    std::string color() const override {
        return _component->color();
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    Miata * m = new StockMiata();
    m->description();
    m = new FlyinMiataTurboKit(m);
    std::cout << std::endl;
    m->description();
    return 0;
}
