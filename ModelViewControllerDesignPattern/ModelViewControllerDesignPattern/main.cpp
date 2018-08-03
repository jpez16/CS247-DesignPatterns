//
//  main.cpp
//  ModelViewControllerDesignPattern
//
//  Created by Justin Pezzack on 2018-08-02.
//  Copyright © 2018 Justin Pezzack. All rights reserved.
//

#include <iostream>
#include <vector>

class MiataView;

class Miata {
    int _engine_size;
    bool forced_induction;
    int jdm_points;
    std::vector<MiataView *> views;
public:
    void notifyViews();
    int engine_size() {
        return _engine_size;
    }
    void setEngineSize(int displacement) {
        _engine_size = displacement;
        notifyViews();
    }
};

class MiataController {
    Miata * miata;
public:
    MiataController(Miata * miata): miata(miata) {}
    void engineSwap(int displacment) {
        miata->setEngineSize(displacment);
    }
    
};

class MiataView {
    Miata * miata;
    MiataController * miata_controller;
public:
    MiataView(MiataController * mc, Miata * miata):  miata_controller(mc), miata(miata) {}
    void update() {
        output();
    }
    void output() {
        std::cout << miata->engine_size();
    }
    void engineSwap(int displacement)  {
        miata_controller->engineSwap(displacement);
    }
};


void Miata::notifyViews() {
    for (size_t i = 0; i < views.size(); i++) {
        views.at(i)->update();
    }
}
int main( int argc, char * argv[] ) {
    // Initialize gtkmm with the command line arguments,
    // as appropriate.
    
    Miata miata_model; // Create model
    MiataController miata_controller( &miata_model ); // Create controller
    MiataView miata_view( &miata_controller, &miata_model ); // Create view
} // main
