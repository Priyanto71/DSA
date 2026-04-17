#include<iostream>
using namespace std;

struct Node{
    int DATA;
    Node* NEXT;
};

Node* getNode(Node*& AVAIL){

    if(AVAIL == NULL){
        return NULL;
    }
    Node* temp = AVAIL;
    AVAIL = AVAIL->NEXT;
    return temp;
}

void Traversal(Node* START){
    Node* PTR = START;
    while(PTR != NULL){
        cout << PTR->DATA << " -> ";
        PTR = PTR->NEXT;
    }
    cout << "NULL" << endl;
}

Node* INSLOC(Node* START, Node*& AVAIL, Node* LOC, int ITEM){
    if(AVAIL == NULL){
        cout << "Overflow\n";
        return START;
    }
    Node* NEW = getNode(AVAIL);
    NEW->DATA = ITEM;
    if(LOC == NULL){
        NEW->NEXT = START;
        START = NEW;
    }else{
        NEW->NEXT = LOC->NEXT;
        LOC->NEXT = NEW;
    }
    return START;
}

int main(){
    Node* START = NULL;
    Node* AVAIL = new Node();
    AVAIL->NEXT = new Node();
    AVAIL->NEXT->NEXT = new Node();
    AVAIL->NEXT->NEXT->NEXT = new Node();
    AVAIL->NEXT->NEXT->NEXT->NEXT = NULL;

    START = INSLOC(START, AVAIL, NULL, 10);
    START = INSLOC(START, AVAIL, START, 20);
    START = INSLOC(START, AVAIL, START->NEXT, 30);

    Traversal(START);
    Node* LOC = START->NEXT;
    START = INSLOC(START, AVAIL, LOC, 25);
    Traversal(START);
    return 0;
}