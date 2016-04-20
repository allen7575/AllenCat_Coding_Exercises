#include <iostream>
#include <string>
#include "Vector.h"

using namespace std;

Vector2D::Vector2D(const Vector2D& inputVec){
    this->name = inputVec.name;
    this->X = inputVec.getX();
    this->Y = inputVec.getY();
    cout<<"copy a 2D Vector with name="<< this->name <<" X="<< this->X <<" Y="<< this->Y <<endl;
}

Vector2D::Vector2D(string VecName, double inputX, double inputY):name(VecName),X(inputX),Y(inputY){
    cout<<"create a 2D Vector with name="<< this->name <<" x="<< this->X << " Y=" << this->Y <<endl;    
}

Vector2D::Vector2D(){
    name = "";
    X=0;
    Y=0;
    cout<<"create a 2D Vector without parameters"<<endl;
}

Vector2D::~Vector2D(){
    cout<<"Destructed Vector2D "<< this->name << endl;    
}

Vector2D Vector2D::operator+(const Vector2D& inputVec){
    Vector2D resultVec(this->name+inputVec.name, this->getX()+inputVec.getX(), this->getY()+inputVec.getY());
    cout<<"add two vector: "<<this->name << " and "<<inputVec.name <<endl;
    return resultVec;
}

void Vector2D::operator=(const Vector2D& inputVec){
    this->name = inputVec.name;
    this->X = inputVec.getX();
    this->Y = inputVec.getY();
    cout<<"assign a 2D Vector with name="<< this->name<<" X="<< this->X <<" Y="<< this->Y <<endl;
    //return this;
}

double Vector2D::getX() const{
    //this->X = 10;
    return X;
}

double Vector2D::getY() const{
    return Y;
}