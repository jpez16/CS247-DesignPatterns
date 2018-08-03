//
//  main.cpp
//  TemplateDesignPattern
//
//  Created by Justin Pezzack on 2018-08-02.
//  Copyright © 2018 Justin Pezzack. All rights reserved.
//

#include <iostream>
using namespace std;



// Miata = Abstract Base Class
class Miata {
public:
    virtual int engine_size() = 0;
    virtual bool forced_induction() = 0;
    virtual int jdm_points() = 0;
    void type() {
        cout << typeid(this).name() << endl;
        cout << engine_size() << endl;
        cout << forced_induction() << endl;
        cout << jdm_points() << endl;
    }
};

class NA6: public Miata {
    int _engine_size;
    bool _forced_induction;
public:
    NA6(): _engine_size(1597), _forced_induction(false) {}
    int engine_size() override {
        return _engine_size;
    }
    bool forced_induction() override {
        return false;
    }
    int jdm_points() override {
        return 420*10;
    }
};

class NA8: public Miata {
    int _engine_size;
    bool _forced_induction;
public:
    NA8(): _engine_size(1801), _forced_induction(false) {}
    int engine_size() override {
        return _engine_size;
    }
    bool forced_induction() override {
        return false;
    }
    int jdm_points() override {
        return 240*10;
    }

};

class MSM: public Miata {
    int _engine_size;
    bool _forced_induction;
public:
    MSM(): _engine_size(1804), _forced_induction(true) {}
    int engine_size() override {
        return _engine_size;
    }
    bool forced_induction() override {
        return true;
    }
    int jdm_points() override {
        return 99999;
    }
};

int main(int argc, const char * argv[]) {
    MSM x;
    x.type();
}
