//
//  main.cpp
//  FactoryDesignPattern
//
//  Created by Justin Pezzack on 2018-08-03.
//  Copyright © 2018 Justin Pezzack. All rights reserved.
//

#include <iostream>

class MazdaVehicle {
public:
    std::string vin;
    MazdaVehicle(std::string vin): vin(vin) {};
};

class Miata : public MazdaVehicle {
public:
    Miata(std::string vin): MazdaVehicle(vin) {}
};

class RX7: public MazdaVehicle {
public:
    RX7(std::string vin): MazdaVehicle(vin) {}
};


class MazdaManufacturingPlant {
public:
    virtual ~MazdaManufacturingPlant() {};
    virtual MazdaVehicle * buildCar() = 0;
};

class HiroshimaManufacturingPlant: public MazdaManufacturingPlant {
public:
    HiroshimaManufacturingPlant(): MazdaManufacturingPlant() {}
    ~HiroshimaManufacturingPlant() {};
    MazdaVehicle * buildCar() {
        MazdaVehicle * vehicle = new Miata("JM1NA");
        return vehicle;
    }
    
};

class KoyotoManufacturingPlant: public MazdaManufacturingPlant {
public:
    KoyotoManufacturingPlant(): MazdaManufacturingPlant() {}
    ~KoyotoManufacturingPlant() {}
    MazdaVehicle * buildCar() {
        MazdaVehicle * vehicle = new RX7("JM1FD");
        return vehicle;
    }
};

int main(int argc, const char * argv[]) {
    MazdaManufacturingPlant * plant = new HiroshimaManufacturingPlant();
    MazdaVehicle * vehicle = plant->buildCar();
    std::cout << vehicle->vin << std::endl;
    delete plant;
    plant = new KoyotoManufacturingPlant();
    delete vehicle;
    vehicle = plant->buildCar();
    std::cout << vehicle->vin << std::endl;
}
