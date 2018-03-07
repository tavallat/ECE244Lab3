#include "string"
#include "Resistor.h"
#include "ResistorList.h"
#include "NodeList.h"

#ifndef NODE_H
#define NODE_H

class Node
{
private:
    int ID; //this is the NodeID
    ResistorList rList;//resistor list
    Node* nextNode = NULL;//pointing to next node
    float voltage =0.0; //initializing the voltage
    
public:
    bool setbyuser = false;
    int counter = 0;
    Node(int nID);//constructor of Node
    int getID(); //gets the ID
    Node* getNextNode(); //gets the adress of the next connected res
    void setNextNode(Node* Adress); //sets the address of next
    Resistor* getrHead(); //gives back rHead of the node
    void insertaresistor (string name_,float resistance_,int endpoints_[]);//inserts a resistor
    void printresistors(); //prints all resistors
    void printsingleres(string name);//prints a single resistor
    Resistor* findsingleres (string name); //finds and returns the adress of a single resistor within the list
    void deleteresistors();//deletes all resistors
    void deletesingleres(string name); //deletes the desired resistor
    float getvoltage(); //gives the voltage of the node
    void changevolate(float value); //sets the voltage of the node 
 
    
        
    
 

    
    
    
    

};

#endif	/* NODE_H */

