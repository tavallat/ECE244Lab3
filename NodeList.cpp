//
//  NodeList.cpp
//  Resistor Network Simulator
//
//  Created by Tina Tavallaeian on 2017-11-05.
//  Copyright © 2017 Tina Tavallaeian. All rights reserved.
//
#include "NodeList.h"
#include "Node.h"
#include <iomanip>
#include <cmath>

using namespace std;

void NodeList :: nHeadsetter(Node *head){
    nHead = head;
    return;
}

Node* NodeList :: nHeadviewer(){
    return nHead;
}

Node* NodeList :: findNode (int nID){
    Node* tp = nHead;
    while (tp != NULL){
    if (nID == tp->getID()) break;
        tp = tp -> getNextNode();
    }
    return tp; }



void NodeList:: insertNode(int ID){
    if (nHead == NULL){
       nHead = new Node(ID);
    totalNodes ++;
    }
   else {
       if (findNode(ID)!= NULL)
           return; 
       else if (ID < nHead ->getID()){
           Node* temp = nHead;
           nHead = new Node (ID);
           nHead->setNextNode(temp);
           totalNodes ++;

       }
       else {
           Node * n =new Node(ID);
           Node * p = nHead;//current
           totalNodes ++;
           Node * prev = NULL; //one before
           while (p!= NULL && p->getID()<ID){//as long as it is less than the ID, keep going
               prev = p;
               p = p-> getNextNode();
           }
           n -> setNextNode(p); // i have found where it belongs by nowwwww
           if (prev == NULL)
               nHead = n;
           else
               prev->setNextNode(n);
   
       }

}
    
}

bool NodeList::checknodevoltage (){
    bool notset = true;
    Node* current = nHead;
    while (current != NULL){
        if (current->getvoltage()!= 0)
        {notset = false;
            break;}
        
    current = current->getNextNode();

    }
    return true;
    
}

void NodeList::solve (){
    bool checktheloop = true;
    bool everythingisgood = false;
    Node* mainNode = nHead;
    Node* connectedNode = nHead;
    bool repeat = false;
    
    if (mainNode == NULL) {
        cout << "Error: no nodes have their voltage set" << endl;
         repeat = true;
    }
    while (mainNode != NULL) {
        if (mainNode->setbyuser) {
            everythingisgood = true;
            break;
        }
        mainNode = mainNode->getNextNode();
    }
    while (checktheloop == true && everythingisgood == true) { //Iterating over all of them
        Node* tempN = nHead;
        checktheloop = false;
        while (tempN != NULL) {
            if (tempN->setbyuser == false) {
                double denom = 0;
                double numerator = 0;
                Resistor* tempR = tempN->getrHead();
                while (tempR != NULL) {
                    denom += 1 / tempR->getResistance();
                    int impNodeID = 0;
                    if (tempR ->getNode1() == tempN->getID()) {
                        impNodeID = tempR ->getNode2();
                    } else {
                        impNodeID = tempR ->getNode1();
                        
                    }
                    
                    Node* tempV = findNode(impNodeID);
                    
                    numerator += (tempV->getvoltage()) / (tempR->getResistance());
                    
                    tempR = tempR->accesserNext();
                    
                    
                }
                
                float oldVoltage = tempN->getvoltage();
                float newVoltage = numerator / denom;
                
                tempN ->changevolate(newVoltage);
                //checking to see if the values are changing and if they are under threshhold then im good
                if (fabs(newVoltage - oldVoltage) > 0.0001) {
                    checktheloop = true;
                }
                
                if (fabs(newVoltage - oldVoltage) == 0)
                {
                    tempN = tempN->getNextNode();
                }
            } else {
                tempN = tempN->getNextNode();
            }
        }
        // End of one iteration
    } //End of all iterations
    
    if (everythingisgood) {
        
        cout << "Solve: " << endl;
        while (connectedNode != NULL) {
            cout << "  Node" << connectedNode->getID() << " : " << setprecision(2) << fixed << connectedNode->getvoltage() << " V" << endl;
            connectedNode = connectedNode->getNextNode();
        }
    } else {
        if (!repeat) cout << "Error: no nodes have their voltage set" << endl;
      
        
    }
    
}


NodeList::~NodeList(){
    Node* ptr;
    while (nHead !=NULL){
        ptr = nHead;
        nHead = ptr->getNextNode();
        delete ptr;
    }
}







