//  Lab3
//
//  Created by Tina Tavallaeian (1003363022)
//  Copyright © 2017 Tina Tavallaeian. All rights reserved.
//
#include "Resistor.h"
#include <iomanip>

using namespace std;
//the defualt constructor

//the constructor
Resistor:: Resistor(string name_,double resistance_,int endpoints_[2]){
    Rname = name_;
    resistance = resistance_;
    endpointNodeIDs [0] = endpoints_[0];
    endpointNodeIDs [1] = endpoints_[1];
}

void Resistor :: setrNext (Resistor* nextRes){
    rNext = nextRes;
}

Resistor* Resistor :: accesserNext () const{
    return rNext;}

//resistor destructor
Resistor::~Resistor() {
    
}

//this function returns the name of resistor
string Resistor::getName() const
{
    return Rname;
}

//this function returns the resistor value of the resistor
double Resistor::getResistance() const
{
    return resistance;
}

int Resistor::getNode1() const
{
    return endpointNodeIDs[0];
}

int Resistor::getNode2() const
{
    return endpointNodeIDs[1];
}

//sets the resistance of the resistor to the given value
void Resistor::setResistance(double resistance_)
{
    resistance = resistance_;
}

