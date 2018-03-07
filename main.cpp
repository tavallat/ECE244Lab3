//
//  main.cpp
//  Resistor Network Simulator
//
//  Created by Tina Tavallaeian on 2017-11-05.
//  Copyright © 2017 Tina Tavallaeian. All rights reserved.
//

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include "RParser.h"
#include "Node.h"
#include "Resistor.h"
#include "ResistorList.h"
#include "NodeList.h"
using namespace std;

struct Rlist{
    string rName;
    int node1;
    int node2;

};
typedef struct Rlist Rlist;



int main(int argc, char** argv) {
    int rescounter = 0;
    NodeList nodeList; //statically defining the NodeList
    string command, line, input;
    Rlist resList [50];
     int i = 0;
    cout << "> ";
        getline(cin, line);
    
    while (!cin.eof()) {
        
        stringstream linestream(line);
        
        //command is retracted from line stream
        linestream >> command;
        //going through each command and applying what is needed

        //***** insertR COMMAND *****
         if (command == "insertR") {
            string Rname, extra;
            float Rvalue;
            int node1, node2;
            bool resishere = false;
            
           
            
            //initializing each variable
            linestream >> Rname;
            linestream >> Rvalue;
            linestream >> node1;
            linestream >> node2;
            int nodes[2] = {node1, node2};
            
            
        
            //i have to check if the resistor exists
            for (int j=0;j<50;j++){
                if (resList[j].rName == Rname)
                    resishere = true;
            }
            
            
            if (resishere == false){
                
            //inserts the nodes
            nodeList.insertNode(node1);
            nodeList.insertNode(node2);
                
            Node* temp1;
            temp1 = nodeList.findNode(node1);
            temp1 ->insertaresistor (Rname, Rvalue,nodes);
            Node* temp2;
            temp2 = nodeList.findNode(node2);
            temp2 ->insertaresistor (Rname, Rvalue,nodes);
                //add to my list to make it easier for me to find where each resistor belongs
                resList[i].rName = Rname;
                resList[i].node1 = node1;
                resList[i].node2 = node2;
                i++;
                rescounter++;
                insertR(Rname, Rvalue, node1, node2);
            }
        
            if (resishere == true) //check if the name already exsists
                cout << "Error: resistor " <<Rname << " already exists" << endl;
        }


        //***** printNode COMMAND *****
        
        else if (command == "printNode") {
            int nodevalue;
            linestream >> nodevalue;
            //if the user says they want to print all
                if (linestream.fail()){
                    linestream.clear();
                    string allinput;
                    linestream >> allinput;
                    if (allinput == "all") //checking if its all
                        cout << "Print:" << endl;
                        for (int i=-50; i <= 10000; i++){
                       Node* temp;
                            
                        temp = nodeList.findNode(i);
                            
                            if (temp != NULL){
                                
                                temp -> printresistors();}
                        }}else{
                    Node* temp;
                    temp = nodeList.findNode(nodevalue);
                    if (temp == NULL)
                        cout << "Error: node " << nodevalue << " not found" << endl;
                    else {
                        cout << "Print:" << endl;
                        temp -> printresistors();}}
        }

        //****** PRINTR COMMAND ***************
        
        else if (command == "printR") {
            string Rname;
            //get the input from stream
            linestream >> Rname;
            int whichnode;
            
            if (nodeList.nHeadviewer() == NULL)//if linked list is empty
                cout << "resistor " << Rname << " not found" << endl;
            
            else {
            for (int i = 0; i < 50; i++){
            if (resList[i].rName == Rname)
                whichnode = resList[i].node1;
            }
            
                if (nodeList.findNode(whichnode)==NULL)//if i cant find the node
                    cout << "Error: resistor " << Rname << " not found" << endl;
                else {
                cout << "Print:" << endl;
                Node* temp = nodeList.findNode(whichnode);
                    temp ->  printsingleres (Rname);}}
                  }
        
        
        //***** deleteR COMMAND *****
        
        else if (command == "deleteR") { //in RParser, i have my deleteR function but i dont use it here!
            string Rname;
            linestream >> Rname;
            if (Rname == "all"){
                for (int i=0; i <= 10000; i++){
                    Node* temp;
                    temp = nodeList.findNode(i);
                    if (temp != NULL)
                        temp -> deleteresistors();
                    for (int k=0; k<rescounter;k++)
                        resList[k].rName = "TAVALLAEIAN";
                }
                cout <<"Deleted: all resistors"<<endl;
            }
            else {
                int whichnode1, whichnode2,i;
                bool itexsists = false;
                if (nodeList.nHeadviewer()==NULL) //if the linked list is empty
                    cout << "resistor " << Rname << " not found" << endl;
                else{
                for (int j=0;j<50;j++){//finding which two nodes the resistor belongs to
                    if (resList[j].rName==Rname){
                        whichnode1=resList[j].node1;
                        whichnode2=resList[j].node2;
                        itexsists = true;
                        resList[j].rName = "TAVALLAEIANTONEKABONI";
                      
                    }}
                    
                    if (nodeList.findNode(whichnode1)==NULL || nodeList.findNode(whichnode2)==NULL)
                        cout << "Error: resistor " << Rname << " not found" << endl;
                    else{

                    Node*temp1=nodeList.findNode(whichnode1);
                    temp1->deletesingleres(Rname);
                    Node*temp2=nodeList.findNode(whichnode2);
                    temp2->deletesingleres(Rname);
                    
                    cout << "Deleted: resistor " << Rname << endl;
                    }}}}

        //**********MODIFYR COMMAND ***********
        else if (command == "modifyR") {
            string name;
            float newvalue;
            float oldvalue;
            int node1, node2;
            linestream >> name >> newvalue;
            //modifyR(Rname, newvalue, oldvalue);
            for (int i = 0; i < 50; i++){
                if (resList[i].rName == name){
                    node1 = resList[i].node1;
                    node2 = resList[i].node2;
                }}
            if (nodeList.nHeadviewer() == NULL)  cout << "resistor " << name << " not found" << endl;
            else
                if (nodeList.findNode(node1)==NULL || nodeList.findNode(node2) == NULL )
                cout << "Error: resistor " << name << " not found" << endl;
            
            else {
                Node* temp1 = nodeList.findNode(node1);
                Resistor* restemp1 = temp1 ->findsingleres(name);
                oldvalue = restemp1->getResistance();
                restemp1->setResistance(newvalue);
                Node* temp2 = nodeList.findNode(node2);
                Resistor* restemp2 = temp2 ->findsingleres(name);
                oldvalue = restemp2->getResistance();
                restemp2->setResistance(newvalue);
                modifyR (name,  newvalue, oldvalue);
            }}
        
        else if (command == "solve") {
            nodeList.solve();
    
        }
        else if (command == "setV"){
            int node;
            float voltage;
            linestream >> node >> voltage;
            Node* temp=nodeList.findNode(node);//finding the adress of which node the user is refering to
            if (temp == NULL){
                cout << "Error: node " << node << " not found" << endl;
            }
            else{
                temp->changevolate(voltage);//setting the voltage of the node
                temp->setbyuser=true; //my boolean that the user has set the voltage
                cout << "Set: node " <<node << " to " <<voltage << " Volts" <<endl;
            }
        }
    
        else if (command == "unsetV"){
            int node;
            linestream >> node;
            Node* temp=nodeList.findNode(node);
            if (temp == NULL){
                cout << "Error: node " << node << " not found" << endl;
            }
            else{
                temp->changevolate(0); //manually disconnecting the node
                temp->setbyuser=false; 
                cout << "Unset: the solver will determine the voltage of node " << node << endl;
            }
        
        
        
        }
        

        
        linestream.ignore(1000, '\n');
        
        command = "hehe...nottoday"; //this is to ensure if the user
        //presses enter i dont get invalid command
        
        cout << "> ";
        getline(cin, line);
        
    
    
       
        
    }
    
    return (0);
    
}

