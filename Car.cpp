#include <iostream>
#include "Car.h"
#include "Tires.h"
using namespace std;

Car::Car(const Tires& _tires):tires(_tires){
    cout<<"created a car with "<<tires.getnumTires()<<" Tires."<<endl;
}

int Car::getTiresNum(){
    return tires.getnumTires();
}