//
//  ResistorList.h
//  Resistor Network Simulator
//
//  Created by Tina Tavallaeian on 2017-11-05.
//  Copyright © 2017 Tina Tavallaeian. All rights reserved.
//

#ifndef ResistorList_h
#define ResistorList_h
#include "Resistor.h"
#include <string>

class ResistorList
{
private:
    Resistor* rHead = NULL; //going to initialize the rHead to be pointing to NULL
public:
    void rHeadsetter (Resistor* head);//sets rHead
    Resistor* rHeadviewer(); //accesses rHead
    void addResistor(string name_,double resistance_,int endpoints_[2]);//given the info, it adds a
                                                                    //resistor to the end of the list
    void printResistor ();//prints all resistors
    Resistor* findRes(string name); //finds the resistor adress given its name
    void printSingle (string name); //prints a single resistor
    ~ResistorList(); //destructor
    void deletesingle (string name); //deletes a single resistor 
    
    
    
    
    


    
    
    
    

};


#endif /* ResistorList_h */
