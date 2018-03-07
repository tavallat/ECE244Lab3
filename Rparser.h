//
//  Rparser.h
//  Resistor Network Simulator
//
//  Created by Tina Tavallaeian on 2017-11-05.
//  Copyright © 2017 Tina Tavallaeian. All rights reserved.
//
#ifndef Rparser_h
#define Rparser_h
#include <string>
using namespace std;


//in this program, all Rparser does is it acts as the frontend and just displays

void setV (int nodeID, float voltage);
void unsetV (int nodeID);
void deleteR (string name);
void insertR (string name, float resistance, int nodeID1, int nodeID2);
void modifyR (string name, float newresistance, float oldresistance);


#endif /* Rparser_h */
