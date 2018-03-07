//
//  Rparser.cpp
//  Resistor Network Simulator
//
//  Created by Tina Tavallaeian on 2017-11-05.
//  Copyright © 2017 Tina Tavallaeian. All rights reserved.
//  PLEASE READ:
//  in this program, Rparser only does the printing and thats it

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include "Rparser.h"
using namespace std;

void setV (int nodeID, float voltage) {
    cout << setprecision(2) << fixed;
    cout << "Set: node " << nodeID << " to " << voltage << " Volts" << endl;
    return;
}

void unsetV (int nodeID){
    cout << "Unset: the solver will determine the voltage of node " << nodeID << endl;
    return;
    
}

void deleteR (string name){
    cout << "Deleted: resistor " << name << endl;
    return;
}

void insertR (string name, float resistance, int nodeID1, int nodeID2){
    cout << setprecision(2) << fixed;
    cout << "Inserted: resistor " << name << " " << resistance << " Ohms " << nodeID1 << " -> " << nodeID2 <<endl;
    return;
}

void modifyR (string name, float newresistance, float oldresistance){
    cout << setprecision(2) << fixed;
    cout << "Modified: resistor " << name << " from " <<  oldresistance << " Ohms to " << newresistance
    << " Ohms" <<endl;
    return;
}




