//
//  Node.cpp
//  Resistor Network Simulator
//
//  Created by Tina Tavallaeian on 2017-11-05.
//  Copyright © 2017 Tina Tavallaeian. All rights reserved.
//

#include "Node.h"
#include <iostream>
#include <string>
using namespace std;

Node:: Node(int nID){
    ID = nID; 

}

int Node::getID(){
    return ID;
}

Node* Node:: getNextNode(){
    return nextNode;}

void Node:: setNextNode(Node* Adress){
    nextNode = Adress;
    return;

}

Resistor* Node::getrHead(){
    return rList.rHeadviewer();
}

void Node::insertaresistor (string name_,float resistance_,int endpoints_[2]){
    rList.addResistor(name_, resistance_, endpoints_);
    counter ++; 

}

void Node::printresistors(){
    if (counter !=0){
    cout << "Connections at node " << ID << ": " << counter <<  " resistor(s)" << endl;
        rList.printResistor();}
    return;
    
}
void Node::deleteresistors(){
    counter = 0;
    rList.~ResistorList();
}

void Node::printsingleres(string name){
    rList.printSingle(name);
}

Resistor* Node::findsingleres(string name){
   return rList.findRes(name);
}


void Node::deletesingleres(string name){
    rList.deletesingle(name);
    if (counter !=0)
    counter = counter -1;
}

float Node::getvoltage(){
    return voltage;
}


void Node:: changevolate(float value){
    voltage = value;
    return;
}












