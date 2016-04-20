#include <iostream>
#include "Box.h"

using namespace std;

Box::Box(int inputWidth, int inputHeight):width(inputWidth),height(inputHeight){
    cout<<"create a box with width = "<<width<<" and height = "<<height<<endl;
}

Box::~Box(){
    
}

int Box::getArea(){
    return width*height;
}