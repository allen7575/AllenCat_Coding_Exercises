#include <iostream>
#include "Tires.h"
#include "Car.h"

using namespace std;

int main(){
    Tires tires;
    Car car(tires);
    
    cout<<"number of Tires="
        <<car.getTiresNum()
        <<endl;
        
    return 0;
}