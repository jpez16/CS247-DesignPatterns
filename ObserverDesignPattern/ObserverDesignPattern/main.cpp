//
//  main.cpp
//  ObserverDesignPattern
//
//  Created by Justin Pezzack on 2018-08-02.
//  Copyright © 2018 Justin Pezzack. All rights reserved.
//

#include <iostream>
#include <vector>

class Race;
// observers
class Miata {
    std::string vin;
    int year;
    int max_speed;
    Race * race;
public:
    void updateStatus();
    void setRace(Race *);
};

// subject
class Race {
    float track_distance;
    int lap_record;
    std::string current_flag;
    std::vector<Miata *> cars;
public:
    Race(float track_distance = 0.00, int lap_record = 0, std::string current_flag = "YELLOW"): track_distance(track_distance), lap_record(lap_record), current_flag(current_flag) {};
    // subscribe
    void addMiata(Miata * m) {
        cars.push_back(m);
        m->setRace(this);
    }
    // unsubscribe
    void removeMiata(Miata * m) {
        for(size_t i = 0; i < cars.size(); i++)
            if(cars.at(i) == m) {
                delete cars.at(i);
                cars.erase(cars.begin() + i);
            }
    }
    //notify
    void notifyCars() {
        for(size_t i = 0; i < cars.size(); i++){
            cars.at(i)->updateStatus();
        }
    }
    
    void updateFlag(std::string flag) {
        current_flag = flag;
        notifyCars();
    }
    
    std::string getFlag() {
        return current_flag;
    }

};

void Miata::updateStatus() {
    if (race->getFlag() == "YELLOW")
        max_speed = 50;
    else
        max_speed = 120;
    
}
void Miata::setRace(Race * r) {
    race = r;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
