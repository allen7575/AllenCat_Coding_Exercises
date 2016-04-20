#include <iostream>
#include "Box.h"
#include "Vector.h"

using namespace std;

int main(){
    Box box(10,2);
    Vector2D Vector1("Allen",1,3), Vector2("chiao",2,4), Vector3;
    
    cout<<"Hello, World!"<<endl;
    cout<< "box area = " << box.getArea() <<endl;
    
    
    cout<< "Vecter1 X="<<Vector1.getX()<<endl;
    cout<< "Vector1 Y="<<Vector1.getY()<<endl;
    
    //Vector1 + Vector2;
    Vector3 = Vector1 + Vector2;
    Vector2D Vector4(Vector3);
    
    cout<<"Vector3 X="<<Vector3.getX()<<endl;
    cout<<"Vector3 Y="<<Vector3.getY()<<endl;
    
    cout<<"Vector4 X="<<Vector4.getX()<<endl;
    cout<<"Vector4 Y="<<Vector4.getY()<<endl;

    cout<<"end"<<endl;
    
    return 0;
}