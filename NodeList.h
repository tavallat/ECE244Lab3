#ifndef NodeList_h
#define NodeList_h
#include "Node.h"


class NodeList{
private:
    Node* nHead = NULL; //going to initialize nHead to point to NULL

public:
    int totalNodes = 0;
    void insertNode (int ID); //inserts a node in increasing order
    void nHeadsetter(Node* head); //sets nHead
    Node* nHeadviewer(); //accesses the nHead
    Node* findNode(int nID); //finds and returns the adress of the node given its ID
    ~NodeList(); //destructor
    bool checknodevoltage (); //checks if the user has set the voltage (this function ended up being
                                //useless as i decided to implement it inside my solve
    void solve (); //solves the circuit 
    
    

};


#endif /* NodeList_h */
