//
//  ResistorList.cpp
//  Resistor Network Simulator
//
//  Created by Tina Tavallaeian on 2017-11-05.
//  Copyright © 2017 Tina Tavallaeian. All rights reserved.
//
#include "ResistorList.h"
#include "Resistor.h"
#include <string>
#include <iomanip>
using namespace std;

void ResistorList:: rHeadsetter(Resistor *head){
    rHead = head;
    return;
}

Resistor* ResistorList :: rHeadviewer(){
    return rHead;
}
void ResistorList::addResistor(string name_,double resistance_,int endpoints_[2])
{
    if (rHead == NULL)
    {
        rHead = new Resistor(name_, resistance_, endpoints_);
        rHead->setrNext(NULL);
        
        
    }
    else if (rHead != NULL)
    {
        Resistor* current = rHead;
        while (current->accesserNext()!= NULL)
        {
            current= current->accesserNext();
        }
        current->setrNext(new Resistor(name_, resistance_, endpoints_));
        
    }
}

void ResistorList::printResistor(){
    Resistor* tp = rHead;
    while (tp != NULL){
        cout << "  ";
        std::cout.width(20); std::cout << std::left << tp->getName();
        std::cout.width(8); std::cout << std::right << tp->getResistance() << " Ohms " << tp->getNode1() << " -> " << tp->getNode2() << endl;
        tp = tp -> accesserNext();
    }
}


Resistor* ResistorList :: findRes(string name){
    Resistor* tp = rHead;
    while (tp != NULL){
        if (name == tp->getName()) break;
        tp = tp -> accesserNext();
    }
    return tp; }

void ResistorList:: printSingle(string name){
    Resistor *current = findRes(name);
    if (current == NULL)
        cout << "Error: resistor " << name << " not found" << endl;
    else {
    std::cout.width(20); std::cout << std::left << current->getName();
    std::cout.width(8); std::cout << std::right << current->getResistance() << " Ohms " << current->getNode1() << " -> " << current->getNode2() << endl;
    }
}

ResistorList::~ResistorList(){
    Resistor* ptr;
    while (rHead !=NULL){
        ptr = rHead;
        rHead = ptr->accesserNext();
        delete ptr;
    }
   
}
void ResistorList::deletesingle (string name){
    Resistor* p = rHead;
    Resistor* prev =NULL;
    while (p!= NULL && p->getName()!= name){
        prev = p;
        p = p -> accesserNext();
    }
    if (p == NULL)
        return;
    
    if (prev == NULL)
        rHead = p->accesserNext();
    else{
        prev->setrNext(p->accesserNext());
        
    }
    delete p;
    return;
    
}



