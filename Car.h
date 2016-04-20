//#include <iostream>
#include "Tires.h"
//using namespace std;

//class Tires; // Tried taking out forward declaration but still didn't work

class Car
{
private:
    Tires tires;

public:
    Car(const Tires& _tires);   // Edited. Thanks to Noah for pointing out.
    int getTiresNum();
};